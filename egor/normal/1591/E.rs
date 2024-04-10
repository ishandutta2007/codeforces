use std::io::Write;
use std::time::SystemTime;
use std::ops::Rem;
use std::ops::SubAssign;
use std::ops::RemAssign;
use std::marker::PhantomData;
use std::ops::DerefMut;
use std::fmt::Display;
use std::cmp::Ordering;
use std::ops::MulAssign;
use std::ops::Div;
use std::mem::swap;
use std::collections::HashSet;
use std::thread;
use std::ops::Deref;
use std::ops::Add;
use std::ops::DivAssign;
use std::ops::AddAssign;
use std::ops::Index;
use std::cell::Cell;
use std::ops::Mul;
use std::ops::IndexMut;
use std::io::Read;
use std::ops::Sub;

pub enum Direction {
    Left,
    Right,
}

const NN: usize = 312;
const MM: usize = 156;
const MATRIX_A: u64 = 0xB5026F5AA96619E9;
const UM: u64 = 0xFFFFFFFF80000000;
const LM: u64 = 0x7FFFFFFF;
const F: u64 = 6364136223846793005;
const MAG01: [u64; 2] = [0, MATRIX_A];

pub struct Random {
    mt: [u64; NN],
    index: usize,
}

impl Random {
    pub fn new(seed: u64) -> Self {
        let mut res = Self {
            mt: [0u64; NN],
            index: NN,
        };
        res.mt[0] = seed;
        for i in 1..NN {
            res.mt[i] = F
                .wrapping_mul(res.mt[i - 1] ^ (res.mt[i - 1] >> 62))
                .wrapping_add(i as u64);
        }
        res
    }

    pub fn gen(&mut self) -> u64 {
        if self.index == NN {
            for i in 0..(NN - MM) {
                let x = (self.mt[i] & UM) | (self.mt[i + 1] & LM);
                self.mt[i] = self.mt[i + MM] ^ (x >> 1) ^ MAG01[(x & 1) as usize];
            }
            for i in (NN - MM)..(NN - 1) {
                let x = (self.mt[i] & UM) | (self.mt[i + 1] & LM);
                self.mt[i] = self.mt[i + MM - NN] ^ (x >> 1) ^ MAG01[(x & 1) as usize];
            }
            let x = (self.mt[NN - 1] & UM) | (self.mt[0] & LM);
            self.mt[NN - 1] = self.mt[MM - 1] ^ (x >> 1) ^ MAG01[(x & 1) as usize];
            self.index = 0;
        }
        let mut x = self.mt[self.index];
        self.index += 1;
        x ^= (x >> 29) & 0x5555555555555555;
        x ^= (x << 17) & 0x71D67FFFEDA60000;
        x ^= (x << 37) & 0xFFF7EEE000000000;
        x ^= x >> 43;
        x
    }
}

static mut RAND: Option<Random> = None;

pub fn random() -> &'static mut Random {
    unsafe {
        if RAND.is_none() {
            RAND = Some(Random::new(
                (SystemTime::UNIX_EPOCH.elapsed().unwrap().as_nanos() & 0xFFFFFFFFFFFFFFFF) as u64,
            ));
        }
        RAND.as_mut().unwrap()
    }
}

pub struct TreapNode<Key: Ord, Data: Updateable>(Option<Box<TreapNodeInner<Key, Data>>>);

struct TreapNodeInner<Key: Ord, Data: Updateable> {
    priority: u64,
    key: Key,
    data: Data,
    left: TreapNode<Key, Data>,
    right: TreapNode<Key, Data>,
}

impl<Key: Ord, Data: Updateable> TreapNodeInner<Key, Data> {
    fn new(key: Key, data: Data) -> Self {
        Self {
            priority: random().gen(),
            key,
            data,
            left: TreapNode::NONE,
            right: TreapNode::NONE,
        }
    }

    fn update(&mut self) {
        let left_data = self.left.0.as_ref().map(|node| &node.data);
        let right_data = self.right.0.as_ref().map(|node| &node.data);
        self.data.update(left_data, right_data);
    }
}

impl<Key: Ord, Data: Updateable> TreapNode<Key, Data> {
    pub const NONE: Self = Self(None);

    pub fn new(key: Key, data: Data) -> Self {
        Self(Some(Box::new(TreapNodeInner::new(key, data))))
    }

    pub fn key(&self) -> Option<&Key> {
        self.0.as_ref().map(|node| &node.key)
    }

    pub fn data(&self) -> Option<&Data> {
        self.0.as_ref().map(|node| &node.data)
    }

    pub fn replace_data(&mut self, key: Key, mut data: Data) -> Option<Data> {
        match self.0.as_mut() {
            None => {
                *self = TreapNode::new(key, data);
                None
            }
            Some(node) => {
                assert!(node.left.0.is_none() && node.right.0.is_none());
                swap(&mut node.data, &mut data);
                Some(data)
            }
        }
    }

    pub fn split(&mut self, split_key: &Key, to_left: bool) -> (Self, Self) {
        match self.0.take() {
            Some(mut node) => {
                let ordering = node.key.cmp(split_key);
                if ordering == Ordering::Less || to_left && ordering == Ordering::Equal {
                    let (left, right) = node.right.split(split_key, to_left);
                    node.right = left;
                    node.update();
                    (Self(Some(node)), right)
                } else {
                    let (left, right) = node.left.split(split_key, to_left);
                    node.left = right;
                    node.update();
                    (left, Self(Some(node)))
                }
            }
            None => (Self::NONE, Self::NONE),
        }
    }

    pub fn iter(&self) -> Box<dyn Iterator<Item = &Self> + '_> {
        match &self.0 {
            None => Box::new(std::iter::empty()),
            Some(node) => Box::new(
                node.left
                    .iter()
                    .chain(std::iter::once(self))
                    .chain(node.right.iter()),
            ),
        }
    }

    pub fn priority(&self) -> u64 {
        self.0.as_ref().map(|node| node.priority).unwrap_or(0)
    }

    pub fn merge(&mut self, mut right: Self) {
        if self.0.is_none() {
            *self = right;
        } else if right.0.is_some() {
            if self.priority() > right.priority() {
                let node = self.0.as_mut().unwrap();
                node.right.merge(right);
                node.update();
            } else {
                let mut node = right.0.take().unwrap();
                self.merge(Self(node.left.0.take()));
                node.left = Self(self.0.take());
                node.update();
                *self = Self(Some(node));
            }
        }
    }

    pub fn binary_search<'s, F>(&'s self, mut f: F)
    where
        F: FnMut(&'s Key, &'s Data, Option<&'s Data>, Option<&'s Data>) -> Option<Direction>,
    {
        if let Some(node) = &self.0 {
            let direction = f(&node.key, &node.data, node.left.data(), node.right.data());
            if let Some(direction) = direction {
                match direction {
                    Direction::Left => {
                        node.left.binary_search(f);
                    }
                    Direction::Right => {
                        node.right.binary_search(f);
                    }
                }
            }
        }
    }

    pub fn find(&self, key: &Key) -> &Self {
        match self.0.as_ref() {
            None => self,
            Some(node) => {
                let ordering = node.key.cmp(key);
                match ordering {
                    Ordering::Less => node.right.find(key),
                    Ordering::Equal => self,
                    Ordering::Greater => node.left.find(key),
                }
            }
        }
    }

    pub fn is_some(&self) -> bool {
        self.0.is_some()
    }

    pub fn is_none(&self) -> bool {
        self.0.is_none()
    }
}

impl<Key: Ord, Data: Updateable> From<TreapNode<Key, Data>> for Option<Data> {
    fn from(data: TreapNode<Key, Data>) -> Self {
        data.0.map(|node| node.data)
    }
}

impl<Key: Ord, Data: Updateable> Default for TreapNode<Key, Data> {
    fn default() -> Self {
        Self::NONE
    }
}

pub trait Updateable {
    fn update(&mut self, left: Option<&Self>, right: Option<&Self>);
}

impl Updateable for u32 {
    fn update(&mut self, left: Option<&Self>, right: Option<&Self>) {
        *self = 1 + *left.unwrap_or(&0) + *right.unwrap_or(&0)
    }
}

struct TreapValue<V> {
    size: u32,
    value: V,
}

impl<V> Updateable for TreapValue<V> {
    fn update(&mut self, left: Option<&Self>, right: Option<&Self>) {
        self.size =
            1 + left.map(|node| node.size).unwrap_or(0) + right.map(|node| node.size).unwrap_or(0)
    }
}

pub struct TreapMap<T: Ord, V> {
    root: TreapNode<T, TreapValue<V>>,
}

impl<T: Ord, V> TreapMap<T, V> {
    pub fn new() -> Self {
        Self {
            root: TreapNode::NONE,
        }
    }

    pub fn len(&self) -> usize {
        self.root.data().map(|data| data.size).unwrap_or(0) as usize
    }

    pub fn insert(&mut self, key: T, value: V) -> Option<V> {
        let (left, mut right) = self.root.split(&key, false);
        let (mut node, right) = right.split(&key, true);
        let res = node
            .replace_data(key, TreapValue { size: 1, value })
            .map(|data| data.value);
        self.root = left;
        self.root.merge(node);
        self.root.merge(right);
        res
    }

    pub fn remove(&mut self, key: &T) -> Option<V> {
        let (left, mut right) = self.root.split(key, false);
        let (node, right) = right.split(key, true);
        self.root = left;
        self.root.merge(right);
        <TreapNode<T, TreapValue<V>> as Into<Option<TreapValue<V>>>>::into(node)
            .map(|data| data.value)
    }

    pub fn index(&mut self, key: &T) -> Option<usize> {
        let (left, mut right) = self.root.split(key, false);
        let (node, right) = right.split(key, true);
        let res = node
            .data()
            .map(|_| left.data().map(|data| data.size as usize).unwrap_or(0));
        self.root = left;
        self.root.merge(node);
        self.root.merge(right);
        res
    }

    pub fn lower_bound(&mut self, key: &T) -> usize {
        let (left, right) = self.root.split(key, false);
        let res = left.data().map(|data| data.size).unwrap_or(0) as usize;
        self.root = left;
        self.root.merge(right);
        res
    }

    pub fn get_at(&mut self, mut at: usize) -> Option<(&T, &V)> {
        if at >= self.len() {
            None
        } else {
            let mut res = None;
            self.root.binary_search(|key, value, left, _| {
                let to_left = left.map(|data| data.size as usize).unwrap_or(0);
                match to_left {
                    v if v > at => Some(Direction::Left),
                    v if v == at => {
                        res = Some((key, &value.value));
                        None
                    }
                    v if v < at => {
                        at -= to_left + 1;
                        Some(Direction::Right)
                    }
                    _ => panic!("unreachable"),
                }
            });
            res
        }
    }

    pub fn keys(&self) -> impl Iterator<Item = &T> + '_ {
        self.root.iter().map(|node| node.key().unwrap())
    }

    pub fn values(&self) -> impl Iterator<Item = &V> + '_ {
        self.root.iter().map(|node| &node.data().unwrap().value)
    }

    pub fn iter(&self) -> impl Iterator<Item = (&T, &V)> + '_ {
        self.root
            .iter()
            .map(|node| (node.key().unwrap(), &node.data().unwrap().value))
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn clear(&mut self) {
        self.root = TreapNode::NONE
    }

    pub fn get(&self, key: &T) -> Option<&V> {
        self.root.find(key).data().map(|data| &data.value)
    }

    pub fn contains(&self, key: &T) -> bool {
        self.root.find(key).is_some()
    }
}

impl<T: Ord, V> Default for TreapMap<T, V> {
    fn default() -> Self {
        Self::new()
    }
}

impl<T: Ord, V> Index<&T> for TreapMap<T, V> {
    type Output = V;

    fn index(&self, index: &T) -> &Self::Output {
        self.get(index).unwrap()
    }
}

#[derive(Default)]
pub struct TreapSet<T: Ord>(TreapMap<T, ()>);

impl<T: Ord> TreapSet<T> {
    pub fn new() -> Self {
        Self(TreapMap::new())
    }

    pub fn insert(&mut self, key: T) -> bool {
        self.0.insert(key, ()).is_some()
    }

    pub fn remove(&mut self, key: &T) -> bool {
        self.0.remove(key).is_some()
    }

    pub fn get_at(&mut self, idx: usize) -> Option<&T> {
        self.0.get_at(idx).map(|(key, _)| key)
    }

    pub fn iter(&self) -> impl Iterator<Item = &T> + '_ {
        self.0.keys()
    }
}

impl<T: Ord> Deref for TreapSet<T> {
    type Target = TreapMap<T, ()>;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl<T: Ord> DerefMut for TreapSet<T> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.0
    }
}

pub trait Addable: Add<Output = Self> + AddAssign + Copy {}
impl<T: Add<Output = Self> + AddAssign + Copy> Addable for T {}

pub trait AddSub: Addable + Sub<Output = Self> + SubAssign {}
impl<T: Addable + Sub<Output = Self> + SubAssign> AddSub for T {}
pub trait ZeroOne {
    fn zero() -> Self;
    fn one() -> Self;
}

macro_rules! zero_one_integer_impl {
    ($t: ident) => {
        impl ZeroOne for $t {
            fn zero() -> Self {
                0
            }

            fn one() -> Self {
                1
            }
        }
    };
}

zero_one_integer_impl!(i128);
zero_one_integer_impl!(i64);
zero_one_integer_impl!(i32);
zero_one_integer_impl!(i16);
zero_one_integer_impl!(i8);
zero_one_integer_impl!(isize);
zero_one_integer_impl!(u128);
zero_one_integer_impl!(u64);
zero_one_integer_impl!(u32);
zero_one_integer_impl!(u16);
zero_one_integer_impl!(u8);
zero_one_integer_impl!(usize);

macro_rules! zero_one_float_impl {
    ($t: ident) => {
        impl ZeroOne for $t {
            fn zero() -> Self {
                0.
            }

            fn one() -> Self {
                1.
            }
        }
    };
}

zero_one_float_impl!(f32);
zero_one_float_impl!(f64);

pub trait Qty {
    fn qty_bound(&self, bound: usize) -> Vec<usize>;
    fn qty(&self) -> Vec<usize>;
}

impl Qty for &[usize] {
    fn qty_bound(&self, bound: usize) -> Vec<usize> {
        let mut res = vec![0; bound];
        for i in self.iter() {
            res[*i] += 1;
        }
        res
    }

    fn qty(&self) -> Vec<usize> {
        if self.is_empty() {
            Vec::new()
        } else {
            self.qty_bound(self.iter().max().unwrap() + 1)
        }
    }
}

pub trait Bounds<T: Ord> {
    fn lower_bound(&self, el: &T) -> usize;
    fn upper_bound(&self, el: &T) -> usize;
    fn bin_search(&self, el: &T) -> Option<usize>;
}

impl<T: Ord> Bounds<T> for &[T] {
    fn lower_bound(&self, el: &T) -> usize {
        let mut left = 0;
        let mut right = self.len();
        while left < right {
            let mid = left + ((right - left) >> 1);
            if &self[mid] < el {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }

    fn upper_bound(&self, el: &T) -> usize {
        let mut left = 0;
        let mut right = self.len();
        while left < right {
            let mid = left + ((right - left) >> 1);
            if &self[mid] <= el {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        left
    }

    fn bin_search(&self, el: &T) -> Option<usize> {
        let at = self.lower_bound(el);
        if at == self.len() || &self[at] != el {
            None
        } else {
            Some(at)
        }
    }
}

#[macro_export]
macro_rules! compress {
    ($($vs:expr),+) => { {
        let mut size = 0;
        $(size += $vs.len();)+
        let mut all = Vec::with_capacity(size);
        $(for a in $vs.iter() {
            all.push(a.clone());
        })+
        all.sort();
        all.dedup();
        let arrs = ($(
            {
                let mut cur = Vec::with_capacity($vs.len());
                for i in 0..$vs.len() {
                    cur.push((&all[..]).bin_search(&$vs[i]).unwrap());
                }
                cur
            },
        )+);
        (all, arrs)
    } }
}

pub trait IncDec {
    fn inc_by_one(self) -> Self;
    fn dec_by_one(self) -> Self;
}

impl<T: AddSub + ZeroOne> IncDec for Vec<T> {
    fn inc_by_one(mut self) -> Self {
        self.iter_mut().for_each(|i| *i += T::one());
        self
    }

    fn dec_by_one(mut self) -> Self {
        self.iter_mut().for_each(|i| *i -= T::one());
        self
    }
}

impl<T: AddSub + ZeroOne, U: AddSub + ZeroOne> IncDec for Vec<(T, U)> {
    fn inc_by_one(mut self) -> Self {
        self.iter_mut().for_each(|(i, j)| {
            *i += T::one();
            *j += U::one();
        });
        self
    }

    fn dec_by_one(mut self) -> Self {
        self.iter_mut().for_each(|(i, j)| {
            *i -= T::one();
            *j -= U::one();
        });
        self
    }
}
pub trait EdgeId: Clone {
    fn new() -> Self;
    fn id(&self) -> usize;
    fn set_id(&mut self, id: usize);
}

#[derive(Clone)]
pub struct WithId {
    id: u32,
}

impl EdgeId for WithId {
    fn new() -> Self {
        Self { id: 0 }
    }

    fn id(&self) -> usize {
        self.id as usize
    }

    fn set_id(&mut self, id: usize) {
        self.id = id as u32;
    }
}

#[derive(Clone)]
pub struct NoId {}

impl EdgeId for NoId {
    fn new() -> Self {
        Self {}
    }

    fn id(&self) -> usize {
        panic!("Id called on no id")
    }

    fn set_id(&mut self, _: usize) {}
}
pub trait EdgeTrait: Clone {
    const REVERSABLE: bool;
    const BIDIRECTIONAL: bool;

    fn to(&self) -> usize;
    fn id(&self) -> usize;
    fn set_id(&mut self, id: usize);
    fn reverse_id(&self) -> usize;
    fn set_reverse_id(&mut self, reverse_id: usize);
    fn reverse_edge(&self, from: usize) -> Self;
}

pub trait IterPartialEqExt<T: PartialEq>: Iterator<Item = T> + Sized {
    fn find(mut self, item: T) -> Option<usize> {
        self.position(|r| r == item)
    }
}

impl<T: PartialEq, I: Iterator<Item = T>> IterPartialEqExt<T> for I {}

pub trait IterExt<T>: Iterator<Item = T> + Sized {
    fn enumerate_sort_by<F>(self, mut f: F) -> Vec<(usize, T)>
    where
        F: FnMut(&T, &T) -> Ordering,
    {
        let mut res: Vec<_> = self.enumerate().collect();
        res.sort_by(|(i, vi), (j, vj)| {
            let res = f(vi, vj);
            if res != Ordering::Equal {
                res
            } else {
                i.cmp(j)
            }
        });
        res
    }
    fn collect_vec(self) -> Vec<T> {
        self.collect()
    }
}

impl<T, I: Iterator<Item = T> + Sized> IterExt<T> for I {}

pub trait IterOrdExt<T: Ord>: IterExt<T> {
    fn enumerate_sort(self) -> Vec<(usize, T)> {
        self.enumerate_sort_by(|a, b| a.cmp(b))
    }

    fn max_position(self) -> Option<usize> {
        let mut res = None;
        let mut val: Option<T> = None;
        for (i, cur) in self.enumerate() {
            if val.is_none() || *val.as_ref().unwrap() < cur {
                val = Some(cur);
                res = Some(i);
            }
        }
        res
    }

    fn min_position(self) -> Option<usize> {
        let mut res = None;
        let mut val = None;
        for (i, cur) in self.enumerate() {
            if val.is_none() || *val.as_ref().unwrap() > cur {
                val = Some(cur);
                res = Some(i);
            }
        }
        res
    }
}

impl<T: Ord, I: Iterator<Item = T> + Sized> IterOrdExt<T> for I {}
// 1.50
pub trait LegacyFill<T: Clone> {
    fn legacy_fill(&mut self, val: T);
}

impl<T: Clone> LegacyFill<T> for [T] {
    fn legacy_fill(&mut self, val: T) {
        for el in self.iter_mut() {
            *el = val.clone();
        }
    }
}

impl<T: Clone> LegacyFill<T> for Vec<T> {
    fn legacy_fill(&mut self, val: T) {
        for el in self.iter_mut() {
            *el = val.clone();
        }
    }
}

#[derive(Clone)]
pub struct DSU {
    id: Vec<Cell<u32>>,
    size: Vec<u32>,
    count: usize,
}

impl DSU {
    pub fn new(n: usize) -> Self {
        Self {
            id: (0..n).map(|i| Cell::new(i as u32)).collect_vec(),
            size: vec![1; n],
            count: n,
        }
    }

    pub fn size(&self, i: usize) -> usize {
        self.size[self.get(i)] as usize
    }

    #[allow(clippy::len_without_is_empty)]
    pub fn len(&self) -> usize {
        self.id.len()
    }

    pub fn iter(&self) -> impl Iterator<Item = usize> + '_ {
        self.id.iter().enumerate().filter_map(|(i, id)| {
            if (i as u32) == id.get() {
                Some(i)
            } else {
                None
            }
        })
    }

    pub fn count(&self) -> usize {
        self.count
    }

    pub fn join(&mut self, mut a: usize, mut b: usize) -> bool {
        a = self.get(a);
        b = self.get(b);
        if a == b {
            false
        } else {
            self.size[a] += self.size[b];
            self.id[b].replace(a as u32);
            self.count -= 1;
            true
        }
    }

    pub fn get(&self, i: usize) -> usize {
        if self.id[i].get() != i as u32 {
            let res = self.get(self.id[i].get() as usize);
            self.id[i].replace(res as u32);
        }
        self.id[i].get() as usize
    }

    pub fn clear(&mut self) {
        self.count = self.id.len();
        self.size.legacy_fill(1);
        self.id.iter().enumerate().for_each(|(i, id)| {
            id.replace(i as u32);
        });
    }
}

pub trait FlowEdgeTrait<C: AddSub + PartialOrd + Copy + ZeroOne>: EdgeTrait {
    fn capacity(&self) -> C;
    fn capacity_mut(&mut self) -> &mut C;
    fn flow(&self, graph: &Graph<Self>) -> C;
    fn push_flow(&self, flow: C) -> (usize, usize, C) {
        (self.to(), self.reverse_id(), flow)
    }
}

pub struct Graph<E: EdgeTrait> {
    edges: Vec<Vec<E>>,
    edge_count: usize,
}

impl<E: EdgeTrait> Graph<E> {
    pub fn new(vertex_count: usize) -> Self {
        Self {
            edges: vec![Vec::new(); vertex_count],
            edge_count: 0,
        }
    }

    pub fn add_edge(&mut self, from: usize, mut edge: E) -> usize {
        let to = edge.to();
        assert!(to < self.edges.len());
        let direct_id = self.edges[from].len();
        edge.set_id(self.edge_count);
        self.edges[from].push(edge);
        if E::REVERSABLE {
            let rev_id = self.edges[to].len();
            self.edges[from][direct_id].set_reverse_id(rev_id);
            let mut rev_edge = self.edges[from][direct_id].reverse_edge(from);
            rev_edge.set_id(self.edge_count);
            rev_edge.set_reverse_id(direct_id);
            self.edges[to].push(rev_edge);
        }
        self.edge_count += 1;
        direct_id
    }

    pub fn add_vertices(&mut self, cnt: usize) {
        self.edges.resize(self.edges.len() + cnt, Vec::new());
    }

    pub fn clear(&mut self) {
        self.edge_count = 0;
        for ve in self.edges.iter_mut() {
            ve.clear();
        }
    }

    pub fn vertex_count(&self) -> usize {
        self.edges.len()
    }

    pub fn edge_count(&self) -> usize {
        self.edge_count
    }

    pub fn is_tree(&self) -> bool {
        if !E::BIDIRECTIONAL || self.edge_count + 1 != self.vertex_count() {
            false
        } else {
            let mut dsu = DSU::new(self.vertex_count());
            for i in 0..self.vertex_count() {
                for e in self[i].iter() {
                    dsu.join(i, e.to());
                }
            }
            dsu.count() == 1
        }
    }
}

pub trait FlowGraph<C: AddSub + PartialOrd + Copy + ZeroOne, E: FlowEdgeTrait<C>> {
    fn push_flow(&mut self, push_data: (usize, usize, C));
}

impl<C: AddSub + PartialOrd + Copy + ZeroOne, E: FlowEdgeTrait<C>> FlowGraph<C, E> for Graph<E> {
    fn push_flow(&mut self, (to, reverse_id, flow): (usize, usize, C)) {
        *self.edges[to][reverse_id].capacity_mut() += flow;
        let from = self.edges[to][reverse_id].to();
        let direct_id = self.edges[to][reverse_id].reverse_id();
        let direct = &mut self.edges[from][direct_id];
        assert!(flow >= C::zero() && flow <= direct.capacity());
        *direct.capacity_mut() -= flow;
    }
}

impl<E: EdgeTrait> Index<usize> for Graph<E> {
    type Output = [E];

    fn index(&self, index: usize) -> &Self::Output {
        &self.edges[index]
    }
}

impl<E: EdgeTrait> IndexMut<usize> for Graph<E> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.edges[index]
    }
}
pub trait FromU8 {
    fn from_u8(val: u8) -> Self;
}

macro_rules! from_u8_impl {
    ($t: ident) => {
        impl FromU8 for $t {
            fn from_u8(val: u8) -> Self {
                val as $t
            }
        }
    };
}

from_u8_impl!(i128);
from_u8_impl!(i64);
from_u8_impl!(i32);
from_u8_impl!(i16);
from_u8_impl!(i8);
from_u8_impl!(isize);
from_u8_impl!(u128);
from_u8_impl!(u64);
from_u8_impl!(u32);
from_u8_impl!(u16);
from_u8_impl!(u8);
from_u8_impl!(usize);
from_u8_impl!(f32);
from_u8_impl!(f64);

pub trait Multable: Mul<Output = Self> + MulAssign + Copy {}
impl<T: Mul<Output = Self> + MulAssign + Copy> Multable for T {}

pub trait MulDiv: Multable + Div<Output = Self> + DivAssign {}
impl<T: Multable + Div<Output = Self> + DivAssign> MulDiv for T {}

pub trait MulDivRem: MulDiv + Rem<Output = Self> + RemAssign {}
impl<T: MulDiv + Rem<Output = Self> + RemAssign> MulDivRem for T {}
pub trait IsSigned {
    const SIGNED: bool;
}

pub trait Signed: IsSigned {}

pub trait Unsigned: IsSigned {}

macro_rules! unsigned_impl {
    ($t: ident) => {
        impl Unsigned for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = false;
        }
    };
}

unsigned_impl!(u128);
unsigned_impl!(u64);
unsigned_impl!(u32);
unsigned_impl!(u16);
unsigned_impl!(u8);
unsigned_impl!(usize);

macro_rules! signed_impl {
    ($t: ident) => {
        impl Signed for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = true;
        }
    };
}

signed_impl!(i128);
signed_impl!(i64);
signed_impl!(i32);
signed_impl!(i16);
signed_impl!(i8);
signed_impl!(isize);
signed_impl!(f64);
signed_impl!(f32);

pub struct Input<'s> {
    input: &'s mut dyn Read,
    buf: Vec<u8>,
    at: usize,
    buf_read: usize,
}

impl<'s> Input<'s> {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(input: &'s mut dyn Read) -> Self {
        Self {
            input,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn new_with_size(input: &'s mut dyn Read, buf_size: usize) -> Self {
        Self {
            input,
            buf: vec![0; buf_size],
            at: 0,
            buf_read: 0,
        }
    }

    pub fn get(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            let res = self.buf[self.at];
            self.at += 1;
            Some(res)
        } else {
            None
        }
    }

    pub fn peek(&mut self) -> Option<u8> {
        if self.refill_buffer() {
            Some(self.buf[self.at])
        } else {
            None
        }
    }

    pub fn skip_whitespace(&mut self) {
        while let Some(b) = self.peek() {
            if !char::from(b).is_whitespace() {
                return;
            }
            self.get();
        }
    }

    pub fn next_token(&mut self) -> Option<Vec<u8>> {
        self.skip_whitespace();
        let mut res = Vec::new();
        while let Some(c) = self.get() {
            if char::from(c).is_whitespace() {
                break;
            }
            res.push(c);
        }
        if res.is_empty() {
            None
        } else {
            Some(res)
        }
    }

    //noinspection RsSelfConvention
    pub fn is_exhausted(&mut self) -> bool {
        self.peek().is_none()
    }

    pub fn read<T: Readable>(&mut self) -> T {
        T::read(self)
    }

    pub fn read_vec<T: Readable>(&mut self, size: usize) -> Vec<T> {
        let mut res = Vec::with_capacity(size);
        for _ in 0usize..size {
            res.push(self.read());
        }
        res
    }

    pub fn read_line(&mut self) -> String {
        let mut res = String::new();
        while let Some(c) = self.get() {
            if c == b'\n' {
                break;
            }
            if c == b'\r' {
                if self.peek() == Some(b'\n') {
                    self.get();
                }
                break;
            }
            res.push(c.into());
        }
        res
    }

    #[allow(clippy::should_implement_trait)]
    pub fn into_iter<T: Readable>(self) -> InputIterator<'s, T> {
        InputIterator {
            input: self,
            phantom: Default::default(),
        }
    }

    fn read_integer<T: IsSigned + ZeroOne + FromU8 + AddSub + Multable + Display>(&mut self) -> T {
        self.skip_whitespace();
        let mut c = self.get().unwrap();
        let sgn = if c == b'-' {
            if !T::SIGNED {
                panic!("negative integer")
            }
            c = self.get().unwrap();
            true
        } else if c == b'+' {
            c = self.get().unwrap();
            false
        } else {
            false
        };
        let mut res = T::zero();
        loop {
            if !char::from(c).is_digit(10) {
                panic!(
                    "expected integer, found {}{}{}",
                    if sgn { "" } else { "-" },
                    res,
                    char::from(c)
                );
            }
            res *= T::from_u8(10);
            res += T::from_u8(c - b'0');
            match self.get() {
                None => {
                    break;
                }
                Some(ch) => {
                    if char::from(ch).is_whitespace() {
                        break;
                    } else {
                        c = ch;
                    }
                }
            }
        }
        if sgn {
            debug_assert!(T::SIGNED);
            res = T::zero() - res
        }
        res
    }

    fn read_string(&mut self) -> String {
        match self.next_token() {
            None => {
                panic!("Input exhausted");
            }
            Some(res) => unsafe { String::from_utf8_unchecked(res) },
        }
    }

    fn read_char(&mut self) -> char {
        self.skip_whitespace();
        self.get().unwrap().into()
    }

    fn read_float(&mut self) -> f64 {
        self.read_string().parse().unwrap()
    }

    fn refill_buffer(&mut self) -> bool {
        if self.at == self.buf_read {
            self.at = 0;
            self.buf_read = self.input.read(&mut self.buf).unwrap();
            self.buf_read != 0
        } else {
            true
        }
    }
}

pub trait Readable {
    fn read(input: &mut Input) -> Self;
}

impl Readable for String {
    fn read(input: &mut Input) -> Self {
        input.read_string()
    }
}

impl Readable for char {
    fn read(input: &mut Input) -> Self {
        input.read_char()
    }
}

impl Readable for f64 {
    fn read(input: &mut Input) -> Self {
        input.read_float()
    }
}

impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.read_vec(size)
    }
}

pub struct InputIterator<'s, T: Readable> {
    input: Input<'s>,
    phantom: PhantomData<T>,
}

impl<'s, T: Readable> Iterator for InputIterator<'s, T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.input.skip_whitespace();
        self.input.peek().map(|_| self.input.read())
    }
}

macro_rules! read_integer {
    ($t:ident) => {
        impl Readable for $t {
            fn read(input: &mut Input) -> Self {
                input.read_integer()
            }
        }
    };
}

read_integer!(i8);
read_integer!(i16);
read_integer!(i32);
read_integer!(i64);
read_integer!(i128);
read_integer!(isize);
read_integer!(u8);
read_integer!(u16);
read_integer!(u32);
read_integer!(u64);
read_integer!(u128);
read_integer!(usize);

macro_rules! tuple_readable {
    ( $( $name:ident )+ ) => {
        impl<$($name: Readable), +> Readable for ($($name,)+) {
            fn read(input: &mut Input) -> Self {
                ($($name::read(input),)+)
            }
        }
    }
}

tuple_readable! {T}
tuple_readable! {T U}
tuple_readable! {T U V}
tuple_readable! {T U V X}
tuple_readable! {T U V X Y}
tuple_readable! {T U V X Y Z}
tuple_readable! {T U V X Y Z A}
tuple_readable! {T U V X Y Z A B}
tuple_readable! {T U V X Y Z A B C}
tuple_readable! {T U V X Y Z A B C D}
tuple_readable! {T U V X Y Z A B C D E}
tuple_readable! {T U V X Y Z A B C D E F}

#[derive(Clone)]
pub struct EdgeRaw<Id: EdgeId> {
    to: u32,
    id: Id,
}

impl<Id: EdgeId> EdgeRaw<Id> {
    pub fn new(to: usize) -> Self {
        Self {
            to: to as u32,
            id: Id::new(),
        }
    }
}

impl<Id: EdgeId> EdgeTrait for EdgeRaw<Id> {
    const REVERSABLE: bool = false;
    const BIDIRECTIONAL: bool = false;

    fn to(&self) -> usize {
        self.to as usize
    }

    fn id(&self) -> usize {
        self.id.id()
    }

    fn set_id(&mut self, id: usize) {
        self.id.set_id(id);
    }

    fn reverse_id(&self) -> usize {
        panic!("no reverse")
    }

    fn set_reverse_id(&mut self, _: usize) {
        panic!("no reverse")
    }

    fn reverse_edge(&self, _: usize) -> Self {
        panic!("no reverse")
    }
}

pub type Edge = EdgeRaw<NoId>;
pub type EdgeWithId = EdgeRaw<WithId>;

pub trait ReadEdgeGraph {
    fn read_graph<Id: EdgeId>(&mut self, n: usize, m: usize) -> Graph<EdgeRaw<Id>>;
}

impl ReadEdgeGraph for Input<'_> {
    fn read_graph<Id: EdgeId>(&mut self, n: usize, m: usize) -> Graph<EdgeRaw<Id>> {
        let mut graph = Graph::new(n);
        for _ in 0..m {
            graph.add_edge(self.read(), EdgeRaw::new(self.read()));
        }
        graph
    }
}

impl<Id: EdgeId> Readable for Graph<EdgeRaw<Id>> {
    fn read(input: &mut Input) -> Self {
        let n = input.read();
        let m = input.read();
        <Input as ReadEdgeGraph>::read_graph(input, n, m)
    }
}

pub struct Output {
    output: Box<dyn Write>,
    buf: Vec<u8>,
    at: usize,
    auto_flush: bool,
}

impl Output {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: false,
        }
    }

    pub fn new_with_auto_flush(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: true,
        }
    }

    pub fn flush(&mut self) {
        if self.at != 0 {
            self.output.write_all(&self.buf[..self.at]).unwrap();
            self.at = 0;
        }
    }

    pub fn print<T: Writable>(&mut self, s: &T) {
        s.write(self);
    }

    pub fn put(&mut self, b: u8) {
        self.buf[self.at] = b;
        self.at += 1;
        if self.at == self.buf.len() {
            self.flush();
        }
    }

    pub fn maybe_flush(&mut self) {
        if self.auto_flush {
            self.flush();
        }
    }

    pub fn print_per_line<T: Writable>(&mut self, arg: &[T]) {
        for i in arg {
            i.write(self);
            self.put(b'\n');
        }
    }

    pub fn print_iter<T: Writable, I: Iterator<Item = T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }

    pub fn print_iter_ref<'a, T: 'a + Writable, I: Iterator<Item = &'a T>>(&mut self, iter: I) {
        let mut first = true;
        for e in iter {
            if first {
                first = false;
            } else {
                self.put(b' ');
            }
            e.write(self);
        }
    }
}

impl Write for Output {
    fn write(&mut self, buf: &[u8]) -> std::io::Result<usize> {
        let mut start = 0usize;
        let mut rem = buf.len();
        while rem > 0 {
            let len = (self.buf.len() - self.at).min(rem);
            self.buf[self.at..self.at + len].copy_from_slice(&buf[start..start + len]);
            self.at += len;
            if self.at == self.buf.len() {
                self.flush();
            }
            start += len;
            rem -= len;
        }
        if self.auto_flush {
            self.flush();
        }
        Ok(buf.len())
    }

    fn flush(&mut self) -> std::io::Result<()> {
        self.flush();
        Ok(())
    }
}

pub trait Writable {
    fn write(&self, output: &mut Output);
}

impl Writable for &str {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for String {
    fn write(&self, output: &mut Output) {
        output.write_all(self.as_bytes()).unwrap();
    }
}

impl Writable for char {
    fn write(&self, output: &mut Output) {
        output.put(*self as u8);
    }
}

impl<T: Writable> Writable for [T] {
    fn write(&self, output: &mut Output) {
        output.print_iter_ref(self.iter());
    }
}

impl<T: Writable> Writable for Vec<T> {
    fn write(&self, output: &mut Output) {
        self[..].write(output);
    }
}

macro_rules! write_to_string {
    ($t:ident) => {
        impl Writable for $t {
            fn write(&self, output: &mut Output) {
                self.to_string().write(output);
            }
        }
    };
}

write_to_string!(u8);
write_to_string!(u16);
write_to_string!(u32);
write_to_string!(u64);
write_to_string!(u128);
write_to_string!(usize);
write_to_string!(i8);
write_to_string!(i16);
write_to_string!(i32);
write_to_string!(i64);
write_to_string!(i128);
write_to_string!(isize);
write_to_string!(f32);
write_to_string!(f64);

impl<T: Writable, U: Writable> Writable for (T, U) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
    }
}

impl<T: Writable, U: Writable, V: Writable> Writable for (T, U, V) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
        output.put(b' ');
        self.2.write(output);
    }
}

pub static mut OUTPUT: Option<Output> = None;

pub fn output() -> &'static mut Output {
    unsafe {
        match &mut OUTPUT {
            None => {
                panic!("Panic");
            }
            Some(output) => output,
        }
    }
}

#[macro_export]
macro_rules! out {
    ($first: expr $(,$args:expr )*) => {
        output().print(&$first);
        $(output().put(b' ');
        output().print(&$args);
        )*
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        out!($first $(,$args)*);
        output().put(b'\n');
    };
    () => {
        output().put(b'\n');
    };
}

macro_rules! recursive_function {
    ($name: ident, $trait: ident, ($($type: ident $arg: ident,)*)) => {
        pub trait $trait<$($type, )*Output> {
            fn call(&mut self, $($arg: $type,)*) -> Output;
        }

        pub struct $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            f: F,
            $($arg: PhantomData<$type>,
            )*
            phantom_output: PhantomData<Output>,
        }

        impl<F, $($type, )*Output> $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            pub fn new(f: F) -> Self {
                Self {
                    f,
                    $($arg: Default::default(),
                    )*
                    phantom_output: Default::default(),
                }
            }
        }

        impl<F, $($type, )*Output> $trait<$($type, )*Output> for $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            fn call(&mut self, $($arg: $type,)*) -> Output {
                let const_ptr = &self.f as *const F;
                let mut_ptr = const_ptr as *mut F;
                unsafe { (&mut *mut_ptr)(self, $($arg, )*) }
            }
        }
    }
}

recursive_function!(RecursiveFunction0, Callable0, ());
recursive_function!(RecursiveFunction, Callable, (Arg arg,));
recursive_function!(RecursiveFunction2, Callable2, (Arg1 arg1, Arg2 arg2,));
recursive_function!(RecursiveFunction3, Callable3, (Arg1 arg1, Arg2 arg2, Arg3 arg3,));
recursive_function!(RecursiveFunction4, Callable4, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4,));
recursive_function!(RecursiveFunction5, Callable5, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5,));
recursive_function!(RecursiveFunction6, Callable6, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6,));
recursive_function!(RecursiveFunction7, Callable7, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7,));
recursive_function!(RecursiveFunction8, Callable8, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8,));
recursive_function!(RecursiveFunction9, Callable9, (Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7, Arg8 arg8, Arg9 arg9,));

fn solve(input: &mut Input, _test_case: usize) {
    let t = input.read();
    let mut tests = Vec::new();
    for _ in 0..t {
        let n = input.read();
        let q = input.read();
        let a: Vec<i32> = input.read_vec(n);
        let p = input.read_vec::<usize>(n - 1).dec_by_one();
        let queries: Vec<(usize, usize, usize)> = input.read_vec(q);
        tests.push((n, q, a, p, queries));
    }
    thread::Builder::new()
        .stack_size(400000000)
        .spawn(move || {
            for (n, q, a, p, queries) in tests {
                let mut by_vertex = vec![Vec::new(); n];
                for (i, (v, _, _)) in queries.iter().enumerate() {
                    by_vertex[*v - 1].push(i);
                }
                let mut graph = Graph::new(n);
                for i in 1..n {
                    graph.add_edge(p[i - 1], Edge::new(i));
                }
                let mut ans = vec![0; q];
                let mut set = TreapSet::new();
                let mut qty = vec![0isize; n + 1];
                let mut once = HashSet::new();
                let mut dfs = RecursiveFunction::new(|f, vert: usize| {
                    let was = qty[a[vert] as usize];
                    if was < -1 {
                        set.remove(&(was, a[vert]));
                    } else if was == -1 {
                        once.remove(&a[vert]);
                    }
                    qty[a[vert] as usize] -= 1;
                    if was < 0 {
                        set.insert((was - 1, a[vert]));
                    } else {
                        once.insert(a[vert]);
                    }
                    for i in by_vertex[vert].drain(..) {
                        let (_, l, mut k) = queries[i];
                        if l == 1 {
                            if k <= once.len() {
                                ans[i] = *once.iter().next().unwrap();
                                continue;
                            }
                            k -= once.len();
                        }
                        let qt = set.lower_bound(&(-(l as isize), (n + 1) as i32));
                        if k > qt {
                            ans[i] = -1;
                        } else {
                            let (_, a) = set.get_at(qt - k).unwrap();
                            ans[i] = *a;
                        }
                    }
                    for e in graph[vert].iter() {
                        f.call(e.to());
                    }
                    if was < 0 {
                        set.remove(&(was - 1, a[vert]));
                    } else {
                        once.remove(&a[vert]);
                    }
                    if was < -1 {
                        set.insert((was, a[vert]));
                    } else if was == -1 {
                        once.insert(a[vert]);
                    }
                    qty[a[vert] as usize] += 1;
                });
                dfs.call(0);
                out_line!(ans);
            }
        })
        .unwrap()
        .join()
        .unwrap();
}

pub(crate) fn run(mut input: Input) -> bool {
    solve(&mut input, 1);
    output().flush();
    input.skip_whitespace();
    !input.peek().is_some()
}

fn main() {
    let mut sin = std::io::stdin();
    let input = Input::new(&mut sin);
    unsafe {
        OUTPUT = Some(Output::new(Box::new(std::io::stdout())));
    }
    run(input);
}