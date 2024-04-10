pub mod solution {

use crate::collections::default_map::DefaultMap;
use crate::collections::min_max::MinimMaxim;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::weighted_edge::WeightedEdge;
use crate::graph::edges::weighted_edge_trait::WeightedEdgeTrait;
use crate::graph::graph::Graph;
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::recursive_function::{Callable2, Callable3, RecursiveFunction2, RecursiveFunction3,};
use crate::numbers::mod_int::ModIntF;
use crate::numbers::num_traits::zero_one::ZeroOne;
use crate::numbers::number_ext::Power;
use crate::numbers::rational::Rational;
use crate::out_line;
use std::mem::swap;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read_usize();
    let edges: Vec<(usize, usize, i32, i32)> = input.read_vec(n - 1);

    let mut graph = Graph::new(n);
    for (i, j, x, y) in edges {
        graph.add_edge(i - 1, WeightedEdge::new(j - 1, Rational::new(x, y)));
        graph.add_edge(j - 1, WeightedEdge::new(i - 1, Rational::new(y, x)));
    }

    type Mod = ModIntF;

    struct Ratio(DefaultMap<i32, usize>);
    impl Ratio {
        pub fn new() -> Self {
            Self(DefaultMap::new())
        }

        fn dec(&mut self, i: i32) {
            if self.0[i] > 0 {
                self.0[i] -= 1;
            }
        }

        fn inc(&mut self, i: i32) {
            self.0[i] += 1;
        }

        pub fn add_edge(&mut self, edge: Rational<i32>) {
            let mut den = edge.den();
            for i in 2.. {
                if i * i > den {
                    break;
                }
                while den % i == 0 {
                    den /= i;
                    self.dec(i);
                }
            }
            if den != 1 {
                self.dec(den);
            }
            let mut num = edge.num();
            for i in 2.. {
                if i * i > num {
                    break;
                }
                while num % i == 0 {
                    num /= i;
                    self.inc(i);
                }
            }
            if num != 1 {
                self.inc(num);
            }
        }

        pub fn join(&mut self, mut other: Self) {
            if other.0.len() > self.0.len() {
                swap(self, &mut other);
            }
            for (i, v) in other.0 {
                self.0[i].maxim(v);
            }
        }

        pub fn value(&self) -> Mod {
            let mut res = Mod::one();
            for (&i, &v) in self.0.iter() {
                res *= Mod::new(i).power(v);
            }
            res
        }
    }

    let mut dfs = RecursiveFunction2::new(|f, vert, prev| -> Ratio {
        let mut res = Ratio::new();
        for e in &graph[vert] {
            if e.to() == prev {
                continue;
            }
            let mut call = f.call(e.to(), vert);
            call.add_edge(e.weight());
            res.join(call);
        }
        res
    });
    let base = dfs.call(0, 0).value();
    let mut ans = Mod::zero();
    let mut dfs2 = RecursiveFunction3::new(|f, vert, prev, value| {
        ans += value;
        for e in &graph[vert] {
            if e.to() == prev {
                continue;
            }
            f.call(
                e.to(),
                vert,
                value * Mod::new(e.weight().den()) / Mod::new(e.weight().num()),
            );
        }
    });
    dfs2.call(0, 0, base);
    out_line!(ans);
}

pub(crate) fn run(mut input: Input) -> bool {
    #[allow(dead_code)]
    enum TestType {
        Single,
        MultiNumber,
        MultiEof,
    }
    let test_type = TestType::MultiNumber;
    match test_type {
        TestType::Single => solve(&mut input, 1),
        TestType::MultiNumber => {
            let t = input.read();
            for i in 0usize..t {
                solve(&mut input, i + 1);
            }
        }
        TestType::MultiEof => {
            let mut i = 1usize;
            while input.peek().is_some() {
                solve(&mut input, i);
                i += 1;
            }
        }
    }
    output().flush();
    input.skip_whitespace();
    !input.peek().is_some()
}

}
pub mod collections {
pub mod default_map {
use std::collections::hash_map::IntoValues;
use std::collections::HashMap;
use std::hash::Hash;
use std::ops::{Deref, DerefMut, Index, IndexMut};

#[derive(Default, Clone, Eq, PartialEq)]
pub struct DefaultMap<K: Hash + Eq, V>(HashMap<K, V>, V);

impl<K: Hash + Eq, V> Deref for DefaultMap<K, V> {
    type Target = HashMap<K, V>;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl<K: Hash + Eq, V> DerefMut for DefaultMap<K, V> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.0
    }
}

impl<K: Hash + Eq, V: Default> DefaultMap<K, V> {
    pub fn new() -> Self {
        Self(HashMap::new(), V::default())
    }

    pub fn get(&self, key: &K) -> &V {
        self.0.get(key).unwrap_or(&self.1)
    }

    pub fn get_mut(&mut self, key: K) -> &mut V {
        self.0.entry(key).or_insert_with(|| V::default())
    }

    pub fn into_values(self) -> IntoValues<K, V> {
        self.0.into_values()
    }
}

impl<K: Hash + Eq, V: Default> Index<K> for DefaultMap<K, V> {
    type Output = V;

    fn index(&self, index: K) -> &Self::Output {
        self.get(&index)
    }
}

impl<K: Hash + Eq, V: Default> IndexMut<K> for DefaultMap<K, V> {
    fn index_mut(&mut self, index: K) -> &mut Self::Output {
        self.get_mut(index)
    }
}

impl<K: Hash + Eq, V> IntoIterator for DefaultMap<K, V> {
    type Item = (K, V);
    type IntoIter = std::collections::hash_map::IntoIter<K, V>;

    fn into_iter(self) -> Self::IntoIter {
        self.0.into_iter()
    }
}
}
pub mod dsu {
use crate::collections::iter_ext::IterExt;
use crate::collections::legacy_fill::LegacyFill;
use crate::collections::vec_ext::Bounds;
use std::cell::Cell;

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

    pub fn parts(&self) -> Vec<Vec<usize>> {
        let roots = self.iter().collect_vec();
        let mut res = vec![Vec::new(); roots.len()];
        for i in 0..self.id.len() {
            res[roots.as_slice().bin_search(&self.get(i)).unwrap()].push(i);
        }
        res
    }
}
}
pub mod iter_ext {
use std::cmp::Ordering;

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

#[macro_export]
macro_rules! zip {
    ( @closure $p:pat => $tup:expr ) => {
        |$p| $tup
    };

    ( @closure $p:pat => ( $($tup:tt)* ) , $_iter:expr $( , $tail:expr )* ) => {
        zip!(@closure ($p, b) => ( $($tup)*, b ) $( , $tail )*)
    };

    ($first:expr $(,)*) => {
        std::iter::IntoIterator::into_iter($first)
    };

    // binary
    ($first:expr, $second:expr $(,)*) => {
        zip!($first).zip($second)
    };

    // n-ary where n > 2
    ( $first:expr $( , $rest:expr )* $(,)* ) => {
        zip!($first)
            $(
                .zip($rest)
            )*
            .map(
                zip!(@closure a => (a) $( , $rest )*)
            )
    };
}

pub fn interleave<T>(
    mut iter1: impl Iterator<Item = T>,
    mut iter2: impl Iterator<Item = T>,
) -> impl Iterator<Item = T> {
    std::iter::from_fn(move || -> Option<T> {
        enum NextFrom {
            First,
            Second,
        }
        static mut NEXT_FROM: NextFrom = NextFrom::First;
        unsafe {
            match NEXT_FROM {
                NextFrom::First => {
                    NEXT_FROM = NextFrom::Second;
                    iter1.next()
                }
                NextFrom::Second => {
                    NEXT_FROM = NextFrom::First;
                    iter2.next()
                }
            }
        }
    })
}
}
pub mod legacy_fill {
// 1.50
pub trait LegacyFill<T> {
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
}
pub mod min_max {
pub trait MinimMaxim<Rhs = Self>: PartialOrd + Sized {
    fn minim(&mut self, other: Rhs) -> bool;

    fn maxim(&mut self, other: Rhs) -> bool;
}

impl<T: PartialOrd + Sized> MinimMaxim for T {
    fn minim(&mut self, other: Self) -> bool {
        if other < *self {
            *self = other;
            true
        } else {
            false
        }
    }

    fn maxim(&mut self, other: Self) -> bool {
        if other > *self {
            *self = other;
            true
        } else {
            false
        }
    }
}

impl<T: PartialOrd + Sized> MinimMaxim<T> for Option<T> {
    fn minim(&mut self, other: T) -> bool {
        match self {
            None => {
                *self = Some(other);
                true
            }
            Some(v) => v.minim(other),
        }
    }

    fn maxim(&mut self, other: T) -> bool {
        match self {
            None => {
                *self = Some(other);
                true
            }
            Some(v) => v.maxim(other),
        }
    }
}
}
pub mod vec_ext {
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::iter::{Skip, Zip};
use std::slice::Iter;

pub trait Qty {
    fn qty_bound(&self, bound: usize) -> Vec<usize>;
    fn qty(&self) -> Vec<usize>;
}

impl Qty for [usize] {
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

pub trait Bounds<T: PartialOrd> {
    fn lower_bound(&self, el: &T) -> usize;
    fn upper_bound(&self, el: &T) -> usize;
    fn bin_search(&self, el: &T) -> Option<usize>;
}

impl<T: PartialOrd> Bounds<T> for [T] {
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
use $crate::collections::vec_ext::Bounds;
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

pub trait Detuple {
    type Res;

    fn detuple(self) -> Self::Res;
}

impl<A, B, C, D> Detuple for Vec<(A, B, C, D)> {
    type Res = (Vec<A>, Vec<B>, Vec<C>, Vec<D>);

    fn detuple(self) -> Self::Res {
        let mut a = Vec::with_capacity(self.len());
        let mut b = Vec::with_capacity(self.len());
        let mut c = Vec::with_capacity(self.len());
        let mut d = Vec::with_capacity(self.len());
        for (aa, bb, cc, dd) in self {
            a.push(aa);
            b.push(bb);
            c.push(cc);
            d.push(dd);
        }
        (a, b, c, d)
    }
}

pub trait IncDec {
    #[must_use]
    fn inc_by_one(self) -> Self;
    #[must_use]
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

impl<T: AddSub + ZeroOne, U: AddSub + ZeroOne, V: AddSub + ZeroOne> IncDec for Vec<(T, U, V)> {
    fn inc_by_one(mut self) -> Self {
        self.iter_mut().for_each(|(i, j, k)| {
            *i += T::one();
            *j += U::one();
            *k += V::one();
        });
        self
    }

    fn dec_by_one(mut self) -> Self {
        self.iter_mut().for_each(|(i, j, k)| {
            *i -= T::one();
            *j -= U::one();
            *k -= V::one();
        });
        self
    }
}

pub trait ConsecutiveIter<T> {
    fn consecutive_iter(&self) -> Zip<Iter<T>, Skip<Iter<T>>>;
}

impl<T> ConsecutiveIter<T> for [T] {
    fn consecutive_iter(&self) -> Zip<Iter<T>, Skip<Iter<T>>> {
        self.iter().zip(self.iter().skip(1))
    }
}
}
}
pub mod graph {
pub mod edges {
pub mod edge_id {
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
}
pub mod edge_trait {
pub trait EdgeTrait: Clone {
    const REVERSABLE: bool;
    const BIDIRECTIONAL: bool;

    fn to(&self) -> usize;
    fn id(&self) -> usize;
    fn set_id(&mut self, id: usize);
    fn reverse_id(&self) -> usize;
    fn set_reverse_id(&mut self, reverse_id: usize);
    #[must_use]
    fn reverse_edge(&self, from: usize) -> Self;
}
}
pub mod flow_edge_trait {
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::graph::Graph;
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::zero_one::ZeroOne;

pub trait FlowEdgeTrait<C: AddSub + PartialOrd + Copy + ZeroOne>: EdgeTrait {
    fn capacity(&self) -> C;
    fn capacity_mut(&mut self) -> &mut C;
    fn flow(&self, graph: &Graph<Self>) -> C;
    fn push_flow(&self, flow: C) -> (usize, usize, C) {
        (self.to(), self.reverse_id(), flow)
    }
}
}
pub mod weighted_edge {
use crate::graph::edges::edge_id::{EdgeId, NoId, WithId};
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::weighted_edge_trait::WeightedEdgeTrait;
use crate::graph::graph::Graph;
use crate::io::input::{Input, Readable};
use crate::numbers::num_traits::add_sub::Addable;
use crate::numbers::num_traits::zero_one::ZeroOne;

#[derive(Clone)]
pub struct WeightedEdgeRaw<W: Addable + PartialOrd + Copy + ZeroOne, Id: EdgeId> {
    to: u32,
    weight: W,
    id: Id,
}

impl<W: Addable + PartialOrd + Copy + ZeroOne, Id: EdgeId> WeightedEdgeRaw<W, Id> {
    pub fn new(to: usize, w: W) -> Self {
        Self {
            to: to as u32,
            weight: w,
            id: Id::new(),
        }
    }
}

impl<W: Addable + PartialOrd + Copy + ZeroOne, Id: EdgeId> EdgeTrait for WeightedEdgeRaw<W, Id> {
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

impl<W: Addable + PartialOrd + Copy + ZeroOne, Id: EdgeId> WeightedEdgeTrait<W>
    for WeightedEdgeRaw<W, Id>
{
    fn weight(&self) -> W {
        self.weight
    }

    fn weight_mut(&mut self) -> &mut W {
        &mut self.weight
    }
}

pub type WeightedEdge<W> = WeightedEdgeRaw<W, NoId>;
pub type WeightedEdgeWithId<W> = WeightedEdgeRaw<W, WithId>;

pub trait ReadWeightedEdgeGraph {
    fn read_graph<W: Addable + PartialOrd + Copy + ZeroOne + Readable, Id: EdgeId>(
        &mut self,
        n: usize,
        m: usize,
    ) -> Graph<WeightedEdgeRaw<W, Id>>;
}

impl ReadWeightedEdgeGraph for Input<'_> {
    fn read_graph<W: Addable + PartialOrd + Copy + ZeroOne + Readable, Id: EdgeId>(
        &mut self,
        n: usize,
        m: usize,
    ) -> Graph<WeightedEdgeRaw<W, Id>> {
        let mut graph = Graph::new(n);
        for _ in 0..m {
            graph.add_edge(self.read(), WeightedEdgeRaw::new(self.read(), self.read()));
        }
        graph
    }
}

impl<W: Addable + PartialOrd + Copy + ZeroOne + Readable, Id: EdgeId> Readable
    for Graph<WeightedEdgeRaw<W, Id>>
{
    fn read(input: &mut Input) -> Self {
        let n = input.read();
        let m = input.read();
        <Input as ReadWeightedEdgeGraph>::read_graph(input, n, m)
    }
}
}
pub mod weighted_edge_trait {
use crate::graph::edges::edge_trait::EdgeTrait;

pub trait WeightedEdgeTrait<W: PartialOrd + Copy>: EdgeTrait {
    fn weight(&self) -> W;
    fn weight_mut(&mut self) -> &mut W;
}
}
}
pub mod graph {
use crate::collections::dsu::DSU;
use crate::graph::edges::edge_trait::EdgeTrait;
use crate::graph::edges::flow_edge_trait::FlowEdgeTrait;
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::ops::{Index, IndexMut};

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
}
}
pub mod io {
pub mod input {
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::from_u8::FromU8;
use crate::numbers::num_traits::mul_div_rem::Multable;
use crate::numbers::num_traits::sign::IsSigned;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::fmt::Display;
use std::io::Read;
use std::marker::PhantomData;

macro_rules! read_impl {
    ($t: ty, $read_name: ident, $read_vec_name: ident) => {
        pub fn $read_name(&mut self) -> $t {
            self.read()
        }

        pub fn $read_vec_name(&mut self, len: usize) -> Vec<$t> {
            self.read_vec(len)
        }
    };

    ($t: ty, $read_name: ident, $read_vec_name: ident, $read_pair_vec_name: ident) => {
        read_impl!($t, $read_name, $read_vec_name);

        pub fn $read_pair_vec_name(&mut self, len: usize) -> Vec<($t, $t)> {
            self.read_vec(len)
        }
    };
}

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

    pub fn iter<'t, T: Readable + 't + 's>(&'t mut self) -> InputIterator<'t, 's, T>
    where
        's: 't,
    {
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
            if !c.is_ascii_digit() {
                panic!(
                    "expected integer, found {}{}{}",
                    if sgn { "-" } else { "" },
                    res,
                    c as char
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

    pub fn read_string(&mut self) -> String {
        match self.next_token() {
            None => {
                panic!("Input exhausted");
            }
            Some(res) => unsafe { String::from_utf8_unchecked(res) },
        }
    }

    pub fn read_char(&mut self) -> char {
        self.skip_whitespace();
        self.get().unwrap().into()
    }

    read_impl!(u8, read_u8, read_u8_vec);
    read_impl!(u16, read_u16, read_u16_vec);
    read_impl!(u32, read_unsigned, read_unsigned_vec);
    read_impl!(u64, read_u64, read_u64_vec);
    read_impl!(u128, read_u128, read_u128_vec);
    read_impl!(usize, read_usize, read_usize_vec, read_usize_pair_vec);
    read_impl!(i8, read_i8, read_i8_vec);
    read_impl!(i16, read_i16, read_i16_vec);
    read_impl!(i32, read_int, read_int_vec, read_int_pair_vec);
    read_impl!(i64, read_long, read_long_vec, read_long_pair_vec);
    read_impl!(i128, read_i128, read_i128_vec);
    read_impl!(isize, read_isize, read_isize_vec);
    read_impl!(f64, read_float, read_float_vec);

    fn read_float_impl(&mut self) -> f64 {
        self.read::<String>().parse().unwrap()
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

pub struct InputIterator<'t, 's: 't, T: Readable + 't + 's> {
    input: &'t mut Input<'s>,
    phantom: PhantomData<T>,
}

impl<'t, 's: 't, T: Readable + 't + 's> Iterator for InputIterator<'t, 's, T> {
    type Item = T;

    fn next(&mut self) -> Option<Self::Item> {
        self.input.skip_whitespace();
        self.input.peek().map(|_| self.input.read())
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
        input.read_float_impl()
    }
}

impl<T: Readable> Readable for Vec<T> {
    fn read(input: &mut Input) -> Self {
        let size = input.read();
        input.read_vec(size)
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
}
pub mod output {
use std::io::Write;

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
            self.output.flush().unwrap();
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

impl<T: Writable> Writable for &[T] {
    fn write(&self, output: &mut Output) {
        output.print_iter_ref(self.iter());
    }
}

impl<T: Writable> Writable for &T {
    fn write(&self, output: &mut Output) {
        T::write(self, output)
    }
}

impl<T: Writable> Writable for Vec<T> {
    fn write(&self, output: &mut Output) {
        (&self[..]).write(output);
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

impl<T: Writable> Writable for Option<T> {
    fn write(&self, output: &mut Output) {
        match self {
            None => (-1).write(output),
            Some(t) => t.write(output),
        }
    }
}

impl Writable for bool {
    fn write(&self, output: &mut Output) {
        if *self {
            output.print(&"YES");
        } else {
            output.print(&"NO");
        }
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
        $crate::io::output::output().print(&$first);
        $($crate::io::output::output().put(b' ');
        $crate::io::output::output().print(&$args);
        )*
        $crate::io::output::output().maybe_flush();
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        $crate::out!($first $(,$args)*);
        $crate::io::output::output().put(b'\n');
        $crate::io::output::output().maybe_flush();
    };
    () => {
        output().put(b'\n');
        output().maybe_flush();
    };
}
}
}
pub mod misc {
pub mod recursive_function {
use std::marker::PhantomData;

macro_rules! recursive_function {
    ($name: ident, $trait: ident, ($($type: ident $arg: ident,)*)) => {
        pub trait $trait<$($type, )*Output> {
            fn call(&mut self, $($arg: $type,)*) -> Output;
        }

        pub struct $name<F, $($type, )*Output>
        where
            F: FnMut(&mut dyn $trait<$($type, )*Output>, $($type, )*) -> Output,
        {
            f: std::cell::UnsafeCell<F>,
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
                    f: std::cell::UnsafeCell::new(f),
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
                unsafe { (&mut *self.f.get())(self, $($arg, )*) }
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
}
pub mod value {
use std::hash::Hash;

pub trait Value<T>: Copy + Eq + Hash {
    fn val() -> T;
}

pub trait ConstValue<T>: Value<T> {
    const VAL: T;
}

impl<T, V: ConstValue<T>> Value<T> for V {
    fn val() -> T {
        Self::VAL
    }
}

#[macro_export]
macro_rules! value {
    ($name: ident, $t: ty, $val: expr) => {
        #[derive(Copy, Clone, Eq, PartialEq, Hash)]
        pub struct $name {}

        impl $crate::misc::value::ConstValue<$t> for $name {
            const VAL: $t = $val;
        }
    };
}

pub trait DynamicValue<T>: Value<T> {
    //noinspection RsSelfConvention
    fn set_val(t: T);
}

#[macro_export]
macro_rules! dynamic_value {
    ($name: ident, $val_name: ident, $t: ty) => {
        static mut $val_name: Option<$t> = None;

        #[derive(Copy, Clone, Eq, PartialEq, Hash)]
        struct $name {}

        impl $crate::misc::value::DynamicValue<$t> for $name {
            fn set_val(t: $t) {
                unsafe {
                    $val_name = Some(t);
                }
            }
        }

        impl $crate::misc::value::Value<$t> for $name {
            fn val() -> $t {
                unsafe { $val_name.unwrap() }
            }
        }
    };
}
}
}
pub mod numbers {
pub mod gcd {
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::mul_div_rem::{MulDivRem, Multable};
use crate::numbers::num_traits::wideable::Wideable;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::mem::swap;

pub fn extended_gcd<T: Copy + ZeroOne + AddSub + MulDivRem + Wideable + PartialEq>(
    a: T,
    b: T,
) -> (T, T::W, T::W)
where
    T::W: Copy + ZeroOne + AddSub + Multable,
{
    if a == T::zero() {
        (b, T::W::zero(), T::W::one())
    } else {
        let (d, y, mut x) = extended_gcd(b % a, a);
        x -= T::W::from(b / a) * y;
        (d, x, y)
    }
}

pub fn gcd<T: Copy + ZeroOne + MulDivRem + PartialEq>(mut a: T, mut b: T) -> T {
    while b != T::zero() {
        a %= b;
        swap(&mut a, &mut b);
    }
    a
}

pub fn lcm<T: Copy + ZeroOne + MulDivRem + PartialEq>(a: T, b: T) -> T {
    (a / gcd(a, b)) * b
}
}
pub mod mod_int {
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use crate::misc::value::Value;
use crate::numbers::gcd::extended_gcd;
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::as_index::AsIndex;
use crate::numbers::num_traits::from_u8::FromU8;
use crate::numbers::num_traits::invertable::Invertable;
use crate::numbers::num_traits::mul_div_rem::{MulDiv, MulDivRem};
use crate::numbers::num_traits::wideable::Wideable;
use crate::numbers::num_traits::zero_one::ZeroOne;
use crate::value;
use std::collections::HashMap;
use std::fmt::{Display, Formatter};
use std::hash::Hash;
use std::marker::PhantomData;
use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Neg, Sub, SubAssign};

pub trait BaseModInt:
    AddSub + MulDiv + Neg<Output = Self> + Copy + ZeroOne + PartialEq + Invertable<Output = Self>
{
    type W: AddSub + MulDivRem + Copy + ZeroOne + From<Self::T>;
    type T: AddSub + MulDivRem + Copy + PartialEq + ZeroOne + Wideable<W = Self::W> + Ord;

    fn from(v: Self::T) -> Self;
    fn module() -> Self::T;
}

#[derive(Copy, Clone, Eq, PartialEq, Hash, Default)]
pub struct ModInt<T, V: Value<T>> {
    n: T,
    phantom: PhantomData<V>,
}

impl<T: Copy, V: Value<T>> ModInt<T, V> {
    pub fn val(&self) -> T {
        self.n
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> ModInt<T, V> {
    unsafe fn unchecked_new(n: T) -> Self {
        debug_assert!(n >= T::zero() && n < V::val());
        Self {
            n,
            phantom: Default::default(),
        }
    }

    unsafe fn maybe_subtract_mod(mut n: T) -> T {
        debug_assert!(n < V::val() + V::val() && n >= T::zero());
        if n >= V::val() {
            n -= V::val();
        }
        n
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord + MulDivRem, V: Value<T>> ModInt<T, V> {
    pub fn new(n: T) -> Self {
        unsafe { Self::unchecked_new(Self::maybe_subtract_mod(n % (V::val()) + V::val())) }
    }
}

impl<T: Copy + ZeroOne + AddSub + MulDivRem + Wideable + PartialEq + Ord + Hash, V: Value<T>>
    ModInt<T, V>
where
    T::W: Copy + ZeroOne + AddSub + MulDivRem,
{
    pub fn log(&self, alpha: Self) -> T {
        let mut base = HashMap::new();
        let mut exp = T::zero();
        let mut pow = Self::one();
        let mut inv = *self;
        let alpha_inv = alpha.inv().unwrap();
        while exp * exp < Self::module() {
            if inv == Self::one() {
                return exp;
            }
            base.insert(inv, exp);
            exp += T::one();
            pow *= alpha;
            inv *= alpha_inv;
        }
        let step = pow;
        let mut i = T::one();
        loop {
            if let Some(b) = base.get(&pow) {
                break exp * i + *b;
            }
            pow *= step;
            i += T::one();
        }
    }
}

impl<T: Wideable + AddSub + Copy + ZeroOne + Ord, V: Value<T>> ModInt<T, V>
where
    T::W: MulDivRem,
{
    pub fn new_from_wide(n: T::W) -> Self {
        unsafe {
            Self::unchecked_new(Self::maybe_subtract_mod(
                T::downcast(n % (V::val()).into()) + V::val(),
            ))
        }
    }
}

impl<T: Copy + ZeroOne + AddSub + MulDivRem + Wideable + PartialEq + Ord, V: Value<T>> Invertable
    for ModInt<T, V>
where
    T::W: Copy + ZeroOne + AddSub + MulDivRem,
{
    type Output = Self;

    fn inv(&self) -> Option<Self> {
        let (g, x, _) = extended_gcd(self.n, V::val());
        if g != T::one() {
            None
        } else {
            Some(Self::new_from_wide(x))
        }
    }
}

impl<T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord, V: Value<T>> BaseModInt
    for ModInt<T, V>
where
    T::W: AddSub + MulDivRem + Copy + ZeroOne,
{
    type W = T::W;
    type T = T;

    fn from(v: Self::T) -> Self {
        Self::new(v)
    }

    fn module() -> T {
        V::val()
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord + MulDivRem, V: Value<T>> From<T> for ModInt<T, V> {
    fn from(n: T) -> Self {
        Self::new(n)
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> AddAssign for ModInt<T, V> {
    fn add_assign(&mut self, rhs: Self) {
        self.n = unsafe { Self::maybe_subtract_mod(self.n + rhs.n) };
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> Add for ModInt<T, V> {
    type Output = Self;

    fn add(mut self, rhs: Self) -> Self::Output {
        self += rhs;
        self
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> SubAssign for ModInt<T, V> {
    fn sub_assign(&mut self, rhs: Self) {
        self.n = unsafe { Self::maybe_subtract_mod(self.n + V::val() - rhs.n) };
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> Sub for ModInt<T, V> {
    type Output = Self;

    fn sub(mut self, rhs: Self) -> Self::Output {
        self -= rhs;
        self
    }
}

impl<T: AddSub + MulDivRem + Copy + Wideable + ZeroOne + Ord, V: Value<T>> MulAssign
    for ModInt<T, V>
where
    T::W: MulDivRem + Copy,
{
    fn mul_assign(&mut self, rhs: Self) {
        self.n = T::downcast(T::W::from(self.n) * T::W::from(rhs.n) % T::W::from(V::val()));
    }
}

impl<T: AddSub + MulDivRem + Copy + Wideable + ZeroOne + Ord, V: Value<T>> Mul for ModInt<T, V>
where
    T::W: MulDivRem + Copy,
{
    type Output = Self;

    fn mul(mut self, rhs: Self) -> Self::Output {
        self *= rhs;
        self
    }
}

impl<T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord, V: Value<T>> DivAssign
    for ModInt<T, V>
where
    T::W: AddSub + MulDivRem + Copy + ZeroOne,
{
    #[allow(clippy::suspicious_op_assign_impl)]
    fn div_assign(&mut self, rhs: Self) {
        *self *= rhs.inv().unwrap();
    }
}

impl<T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord, V: Value<T>> Div
    for ModInt<T, V>
where
    T::W: AddSub + MulDivRem + Copy + ZeroOne,
{
    type Output = Self;

    fn div(mut self, rhs: Self) -> Self::Output {
        self /= rhs;
        self
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord, V: Value<T>> Neg for ModInt<T, V> {
    type Output = Self;

    fn neg(mut self) -> Self::Output {
        self.n = unsafe { Self::maybe_subtract_mod(V::val() - self.n) };
        self
    }
}

impl<T: Display, V: Value<T>> Display for ModInt<T, V> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        <T as Display>::fmt(&self.n, f)
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord + MulDivRem + Readable, V: Value<T>> Readable
    for ModInt<T, V>
{
    fn read(input: &mut Input) -> Self {
        Self::new(T::read(input))
    }
}

impl<T: Writable, V: Value<T>> Writable for ModInt<T, V> {
    fn write(&self, output: &mut Output) {
        self.n.write(output);
    }
}

impl<T: ZeroOne + MulDivRem + AddSub + Copy + Ord, V: Value<T>> ZeroOne for ModInt<T, V> {
    fn zero() -> Self {
        unsafe { Self::unchecked_new(T::zero()) }
    }

    fn one() -> Self {
        Self::new(T::one())
    }
}

impl<T, V: Value<T>> Wideable for ModInt<T, V> {
    type W = Self;

    fn downcast(w: Self::W) -> Self {
        w
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord + MulDivRem + FromU8, V: Value<T>> FromU8 for ModInt<T, V> {
    fn from_u8(n: u8) -> Self {
        Self::new(T::from_u8(n))
    }
}

impl<
        T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord + Display + FromU8,
        V: Value<T>,
    > std::fmt::Debug for ModInt<T, V>
where
    T::W: AddSub + MulDivRem + Copy + ZeroOne,
{
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        let max = T::from_u8(100);
        if self.n <= max {
            write!(f, "{}", self.n)
        } else if self.n >= V::val() - max {
            write!(f, "-{}", V::val() - self.n)
        } else {
            let mut denominator = T::one();
            while denominator < max {
                let mut num = T::one();
                while num < max {
                    if Self::new(num) / Self::new(denominator) == *self {
                        return write!(f, "{}/{}", num, denominator);
                    }
                    if -Self::new(num) / Self::new(denominator) == *self {
                        return write!(f, "-{}/{}", num, denominator);
                    }
                    num += T::one();
                }
                denominator += T::one();
            }
            write!(f, "(?? {} ??)", self.n)
        }
    }
}

impl<T: AddSub + Copy + ZeroOne + Ord + MulDivRem + AsIndex, V: Value<T>> AsIndex for ModInt<T, V> {
    fn from_index(idx: usize) -> Self {
        Self::new(T::from_index(idx))
    }

    fn to_index(&self) -> usize {
        self.n.to_index()
    }
}

value!(Val7, i32, 1_000_000_007);
pub type ModInt7 = ModInt<i32, Val7>;

value!(Val9, i32, 1_000_000_009);
pub type ModInt9 = ModInt<i32, Val9>;

value!(ValF, i32, 998_244_353);
pub type ModIntF = ModInt<i32, ValF>;
}
pub mod num_traits {
pub mod add_sub {
use std::ops::{Add, AddAssign, Sub, SubAssign};

pub trait Addable: Add<Output = Self> + AddAssign + Copy {}
impl<T: Add<Output = Self> + AddAssign + Copy> Addable for T {}

pub trait AddSub: Addable + Sub<Output = Self> + SubAssign {}
impl<T: Addable + Sub<Output = Self> + SubAssign> AddSub for T {}
}
pub mod as_index {
pub trait AsIndex {
    fn from_index(idx: usize) -> Self;
    fn to_index(&self) -> usize;
}

macro_rules! from_index_impl {
    ($t: ident) => {
        impl AsIndex for $t {
            fn from_index(idx: usize) -> Self {
                idx as $t
            }

            fn to_index(&self) -> usize {
                *self as usize
            }
        }
    };
}

from_index_impl!(i128);
from_index_impl!(i64);
from_index_impl!(i32);
from_index_impl!(i16);
from_index_impl!(i8);
from_index_impl!(isize);
from_index_impl!(u128);
from_index_impl!(u64);
from_index_impl!(u32);
from_index_impl!(u16);
from_index_impl!(u8);
from_index_impl!(usize);
}
pub mod from_u8 {
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
}
pub mod invertable {
pub trait Invertable: Sized {
    type Output;

    fn inv(&self) -> Option<Self>;
}
}
pub mod mul_div_rem {
use std::ops::{Div, DivAssign, Mul, MulAssign, Rem, RemAssign};

pub trait Multable: Mul<Output = Self> + MulAssign + Copy {}
impl<T: Mul<Output = Self> + MulAssign + Copy> Multable for T {}

pub trait MulDiv: Multable + Div<Output = Self> + DivAssign {}
impl<T: Multable + Div<Output = Self> + DivAssign> MulDiv for T {}

pub trait MulDivRem: MulDiv + Rem<Output = Self> + RemAssign {}
impl<T: MulDiv + Rem<Output = Self> + RemAssign> MulDivRem for T {}
}
pub mod sign {
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
}
pub mod wideable {
use std::convert::From;

pub trait Wideable: Sized {
    type W: From<Self>;

    fn downcast(w: Self::W) -> Self;
}

macro_rules! wideable_impl {
    ($t: ident, $w: ident) => {
        impl Wideable for $t {
            type W = $w;

            fn downcast(w: Self::W) -> Self {
                w as $t
            }
        }
    };
}

wideable_impl!(i128, i128);
wideable_impl!(i64, i128);
wideable_impl!(i32, i64);
wideable_impl!(i16, i32);
wideable_impl!(i8, i16);
wideable_impl!(isize, isize);
wideable_impl!(u128, u128);
wideable_impl!(u64, u128);
wideable_impl!(u32, u64);
wideable_impl!(u16, u32);
wideable_impl!(u8, u16);
wideable_impl!(usize, usize);
wideable_impl!(f64, f64);
wideable_impl!(f32, f64);
}
pub mod zero_one {
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
}
}
pub mod number_ext {
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::from_u8::FromU8;
use crate::numbers::num_traits::mul_div_rem::{MulDiv, MulDivRem, Multable};
use crate::numbers::num_traits::zero_one::ZeroOne;

pub trait Power {
    #[must_use]
    fn power<T: ZeroOne + PartialEq + MulDivRem + AddSub + Copy>(&self, exp: T) -> Self;
}

impl<S: ZeroOne + Copy + Multable> Power for S {
    fn power<T: ZeroOne + PartialEq + MulDivRem + AddSub + Copy>(&self, exp: T) -> Self {
        if exp == T::zero() {
            S::one()
        } else if exp % (T::one() + T::one()) == T::zero() {
            let res = self.power(exp / (T::one() + T::one()));
            res * res
        } else {
            self.power(exp - T::one()) * (*self)
        }
    }
}

pub trait NumDigs {
    fn num_digs(&self) -> usize;
}

impl<S: ZeroOne + FromU8 + MulDiv + Copy + PartialEq> NumDigs for S {
    fn num_digs(&self) -> usize {
        let mut copy = *self;
        let ten = S::from_u8(10);
        let mut res = 0;
        while copy != S::zero() {
            copy /= ten;
            res += 1;
        }
        res
    }
}
}
pub mod rational {
use crate::io::output::{Output, Writable};
use crate::numbers::gcd::gcd;
use crate::numbers::num_traits::add_sub::AddSub;
use crate::numbers::num_traits::mul_div_rem::MulDivRem;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::cmp::Ordering;
use std::fmt::{Debug, Display, Formatter};
use std::hash::Hash;
use std::ops::{Add, AddAssign, Div, DivAssign, Mul, MulAssign, Sub, SubAssign};

#[derive(Eq, PartialEq, Copy, Clone, Hash)]
pub struct Rational<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> {
    num: T,
    den: T,
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Rational<T> {
    pub fn new(num: T, den: T) -> Self {
        assert!(den != T::zero());
        let mut g = gcd(num, den);

        if g < T::zero() {
            g = T::zero() - g;
        }
        if den < T::zero() {
            g = T::zero() - g;
        }
        Self {
            num: num / g,
            den: den / g,
        }
    }

    pub fn num(&self) -> T {
        self.num
    }

    pub fn den(&self) -> T {
        self.den
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Add for Rational<T> {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self::new(self.num * rhs.den + rhs.num * self.den, self.den * rhs.den)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Sub for Rational<T> {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self::new(self.num * rhs.den - rhs.num * self.den, self.den * rhs.den)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Mul for Rational<T> {
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        Self::new(self.num * rhs.num, self.den * rhs.den)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Div for Rational<T> {
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        Self::new(self.num * rhs.den, self.den * rhs.num)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> AddAssign for Rational<T> {
    fn add_assign(&mut self, rhs: Self) {
        *self = *self + rhs
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> SubAssign for Rational<T> {
    fn sub_assign(&mut self, rhs: Self) {
        *self = *self - rhs
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> MulAssign for Rational<T> {
    fn mul_assign(&mut self, rhs: Self) {
        *self = *self * rhs
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> DivAssign for Rational<T> {
    fn div_assign(&mut self, rhs: Self) {
        *self = *self / rhs
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord + Debug> Debug for Rational<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        self.num.fmt(f)?;
        <char as Debug>::fmt(&'/', f)?;
        self.den.fmt(f)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord + Display> Display for Rational<T> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        self.num.fmt(f)?;
        <char as Display>::fmt(&'/', f)?;
        self.den.fmt(f)
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord + Writable> Writable for Rational<T> {
    fn write(&self, output: &mut Output) {
        self.num.write(output);
        output.put(b'/');
        self.den.write(output);
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> PartialOrd for Rational<T> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some((self.num * other.den).cmp(&(other.num * self.den)))
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> Ord for Rational<T> {
    fn cmp(&self, other: &Self) -> Ordering {
        (self.num * other.den).cmp(&(other.num * self.den))
    }
}

impl<T: Copy + ZeroOne + MulDivRem + AddSub + Ord> ZeroOne for Rational<T> {
    fn zero() -> Self {
        Self::new(T::zero(), T::one())
    }

    fn one() -> Self {
        Self::new(T::one(), T::one())
    }
}
}
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}