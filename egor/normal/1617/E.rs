use std::collections::HashMap;
use std::ops::SubAssign;
use std::ops::Rem;
use std::ops::IndexMut;
use std::io::Read;
use std::ops::Index;
use std::ops::RemAssign;
use std::ops::AddAssign;
use std::ops::Mul;
use std::fmt::Display;
use std::ops::MulAssign;
use std::io::Write;
use std::cmp::Ordering;
use std::hash::Hash;
use std::ops::DivAssign;
use std::ops::Add;
use std::marker::PhantomData;
use std::ops::Div;
use std::mem::MaybeUninit;
use std::ops::Sub;
use std::cell::Cell;


#[derive(Default)]
pub struct Id<T: Hash + Eq> {
    map: HashMap<T, usize>,
    next: usize,
}

impl<T: Hash + Eq> Id<T> {
    pub fn new() -> Self {
        Self {
            map: HashMap::new(),
            next: 0,
        }
    }

    pub fn len(&self) -> usize {
        self.next
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn get(&mut self, el: T) -> usize {
        match self.map.get(&el) {
            None => {
                let res = self.next;
                self.map.insert(el, res);
                self.next += 1;
                res
            }
            Some(res) => *res,
        }
    }

    pub fn iter(&self) -> impl Iterator<Item = (&T, &usize)> {
        self.map.iter()
    }
}

impl<T: Hash + Eq + Clone> Id<T> {
    pub fn by_id(&self) -> Vec<T> {
        unsafe {
            let mut res = MaybeUninit::new(Vec::with_capacity(self.len()));
            (*res.as_mut_ptr()).set_len(self.len());
            for (val, i) in self.map.iter() {
                let ptr: *mut T = (*res.as_mut_ptr()).as_mut_ptr();
                ptr.add(*i).write(val.clone());
            }
            res.assume_init()
        }
    }
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
pub trait MinimMaxim: PartialOrd + Sized {
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

impl<T: PartialOrd + Sized> MinimMaxim for T {}
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

pub trait BiEdgeTrait: EdgeTrait {}
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

#[macro_export]
macro_rules! transparent_wrapper {
    ($name: ident, $t: ty) => {
        pub struct $name($t);

        impl Deref for $name {
            type Target = $t;

            fn deref(&self) -> &Self::Target {
                &self.0
            }
        }

        impl DerefMut for $name {
            fn deref_mut(&mut self) -> &mut Self::Target {
                &mut self.0
            }
        }
    };
}

#[derive(Clone)]
pub struct BiEdgeRaw<Id: EdgeId> {
    to: u32,
    id: Id,
}

impl<Id: EdgeId> BiEdgeRaw<Id> {
    pub fn new(to: usize) -> Self {
        Self {
            to: to as u32,
            id: Id::new(),
        }
    }
}

impl<Id: EdgeId> EdgeTrait for BiEdgeRaw<Id> {
    const REVERSABLE: bool = true;
    const BIDIRECTIONAL: bool = true;

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
        panic!("no reverse id")
    }

    fn set_reverse_id(&mut self, _: usize) {}

    fn reverse_edge(&self, from: usize) -> Self {
        Self::new(from)
    }
}

impl<Id: EdgeId> BiEdgeTrait for BiEdgeRaw<Id> {}

pub type BiEdge = BiEdgeRaw<NoId>;
pub type BiEdgeWithId = BiEdgeRaw<WithId>;

pub trait ReadBiEdgeGraph {
    fn read_graph<Id: EdgeId>(&mut self, n: usize, m: usize) -> Graph<BiEdgeRaw<Id>>;

    fn read_tree<Id: EdgeId>(&mut self, n: usize) -> Graph<BiEdgeRaw<Id>> {
        self.read_graph(n, n - 1)
    }
}

impl ReadBiEdgeGraph for Input<'_> {
    fn read_graph<Id: EdgeId>(&mut self, n: usize, m: usize) -> Graph<BiEdgeRaw<Id>> {
        let mut graph = Graph::new(n);
        for _ in 0..m {
            graph.add_edge(self.read(), BiEdgeRaw::new(self.read()));
        }
        graph
    }
}

impl<Id: EdgeId> Readable for Graph<BiEdgeRaw<Id>> {
    fn read(input: &mut Input) -> Self {
        let n = input.read();
        let m = input.read();
        <Input as ReadBiEdgeGraph>::read_graph(input, n, m)
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
        output().maybe_flush();
    }
}

#[macro_export]
macro_rules! out_line {
    ($first: expr $(, $args:expr )* ) => {
        out!($first $(,$args)*);
        output().put(b'\n');
        output().maybe_flush();
    };
    () => {
        output().put(b'\n');
        output().maybe_flush();
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
    let n = input.read();
    let a: Vec<u32> = input.read_vec(n);

    let mut id = Id::new();
    id.get(0);
    for mut i in a.iter().cloned() {
        while i != 0 {
            id.get(i);
            i = i.next_power_of_two() - i;
        }
    }
    let mut graph = Graph::new(id.len());
    for i in id.by_id() {
        if i != 0 {
            graph.add_edge(id.get(i), BiEdge::new(id.get(i.next_power_of_two() - i)));
        }
    }
    let mut depth = vec![(0, 0); graph.vertex_count()];
    let mut dfs = RecursiveFunction2::new(|f, vert: usize, prev: usize| -> (i32, usize) {
        let mut res = (0, vert);
        for e in graph[vert].iter() {
            if e.to() != prev {
                let mut call = f.call(e.to(), vert);
                call.0 += 1;
                res.maxim(call);
            }
        }
        depth[vert] = res;
        res
    });
    dfs.call(id.get(0), id.get(0));
    let mut ans = 0;
    let (mut from, mut to) = (a[0], a[0]);
    let by_id = id.by_id();
    let mut dfs = RecursiveFunction2::new(|f, vert: usize, prev: usize| {
        let mut down = 0;
        let mut down_vert = vert;
        for e in graph[vert].iter() {
            if e.to() != prev {
                let cand = down + depth[e.to()].0 + 1;
                if cand > ans {
                    ans = cand;
                    from = by_id[down_vert];
                    to = by_id[depth[e.to()].1];
                }
                let cand = depth[e.to()].0 + 1;
                if cand > down {
                    down = cand;
                    down_vert = depth[e.to()].1;
                }
                f.call(e.to(), vert);
            }
        }
    });
    dfs.call(id.get(0), id.get(0));
    let x = a.iter().find(&from).unwrap() + 1;
    let y = a.iter().find(&to).unwrap() + 1;
    out_line!(x, y, ans);
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