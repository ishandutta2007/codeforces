pub mod solution {

use crate::collections::arr2d::Arr2dRead;
use crate::collections::dsu::DSU;
use crate::io::input::Input;
use crate::io::output::output;
use crate::numbers::mod_int::ModIntF;
use crate::numbers::num_traits::bit_ops::BitOps;
use crate::numbers::num_traits::primitive::Primitive;
use crate::numbers::num_traits::zero_one::ZeroOne;
use crate::numbers::number_ext::Power;
use crate::out_line;
use std::mem::swap;

fn solve(input: &mut Input, _test_case: usize) {
    let mut r = input.read_usize();
    let mut c = input.read_usize();
    let mut b = input.read_table::<char>(r, c);

    type Mod = ModIntF;

    if r % 2 == 0 && c % 2 == 0 {
        let q_marks = b.iter().filter(|&&it| it == '?').count();
        out_line!(Mod::new(2).power(q_marks));
        return;
    } else if r % 2 == 0 || c % 2 == 0 {
        if c % 2 == 0 {
            b = b.transpose();
            swap(&mut r, &mut c);
        }
        let mut ans = Mod::zero();
        for v in 0..2 {
            let mut q = 0;
            let mut good = true;
            for i in 0..r {
                let ones = b.row(i).filter(|&&it| it == '1').count();
                let qm = b.row(i).filter(|&&it| it == '?').count();
                if qm > 0 {
                    q += qm - 1;
                } else if ones % 2 != v {
                    good = false;
                    break;
                }
            }
            if good {
                ans += Mod::new(2).power(q);
            }
        }
        out_line!(ans);
        return;
    }
    let mut ans = Mod::zero();
    for v in 0..2 {
        let mut free = Vec::new();
        let mut dsu = DSU::new(r + c);
        let mut q = 0;
        for i in 0..r {
            for j in 0..c {
                if b[(i, j)] == '?' {
                    if dsu.join(i, r + j) {
                        free.push((i, j));
                    } else {
                        q += 1;
                    }
                }
            }
        }
        let m = free.len();
        let mut a = vec![vec![0u32; m / 32 + 1]; r + c];
        for (id, (i, j)) in free.into_iter().enumerate() {
            a[i][id >> 5] |= 1 << (id & 31);
            a[j + r][id >> 5] |= 1 << (id & 31);
        }
        for i in 0..r {
            let q = b.row(i).filter(|&&it| it == '1').count() % 2;
            a[i][m >> 5] |= (v ^ q).into_u32() << (m & 31);
        }
        for i in 0..c {
            let q = b.column(i).filter(|&&it| it == '1').count() % 2;
            a[i + r][m >> 5] |= (v ^ q).into_u32() << (m & 31);
        }
        let mut st = 0;
        let mut bad = false;
        for i in 0..=m {
            let mut at = None;
            for j in st..r + c {
                if a[j][i >> 5].is_set(i & 31) {
                    at = Some(j);
                    break;
                }
            }
            if let Some(at) = at {
                if i == m {
                    bad = true;
                    break;
                }
                a.swap(st, at);
                for j in st + 1..r + c {
                    if a[j][i >> 5].is_set(i & 31) {
                        for k in (i >> 5)..=(m >> 5) {
                            a[j][k] ^= a[st][k];
                        }
                    }
                }
                st += 1;
            } else {
                assert_eq!(i, m);
            }
        }
        if !bad {
            ans += Mod::new(2).power(q);
        }
    }
    out_line!(ans);
}

pub(crate) fn run(mut input: Input) -> bool {
    #[allow(dead_code)]
    enum TestType {
        Single,
        MultiNumber,
        MultiEof,
    }
    let test_type = TestType::Single;
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
pub mod arr2d {
use crate::collections::legacy_fill::LegacyFill;
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use std::ops::{Index, IndexMut};
use std::vec::IntoIter;

#[derive(Clone, Eq, PartialEq)]
pub struct Arr2d<T> {
    d1: usize,
    d2: usize,
    data: Vec<T>,
}

impl<T: Clone> Arr2d<T> {
    pub fn new(d1: usize, d2: usize, value: T) -> Self {
        Self {
            d1,
            d2,
            data: vec![value; d1 * d2],
        }
    }
}

impl<T> Arr2d<T> {
    pub fn generate<F>(d1: usize, d2: usize, mut gen: F) -> Self
    where
        F: FnMut(usize, usize) -> T,
    {
        let mut data = Vec::with_capacity(d1 * d2);
        for i in 0usize..d1 {
            for j in 0usize..d2 {
                data.push(gen(i, j));
            }
        }
        Self { d1, d2, data }
    }

    pub fn d1(&self) -> usize {
        self.d1
    }

    pub fn d2(&self) -> usize {
        self.d2
    }

    pub fn iter(&self) -> impl Iterator<Item = &T> {
        self.data.iter()
    }

    pub fn iter_mut(&mut self) -> impl Iterator<Item = &mut T> {
        self.data.iter_mut()
    }

    pub fn row(&self, row: usize) -> impl Iterator<Item = &T> {
        assert!(row < self.d1);
        self.data.iter().skip(row * self.d2).take(self.d2)
    }

    pub fn row_mut(&mut self, row: usize) -> impl Iterator<Item = &mut T> {
        assert!(row < self.d1);
        self.data.iter_mut().skip(row * self.d2).take(self.d2)
    }

    pub fn column(&self, col: usize) -> impl Iterator<Item = &T> {
        assert!(col < self.d2);
        self.data.iter().skip(col).step_by(self.d2)
    }

    pub fn column_mut(&mut self, col: usize) -> impl Iterator<Item = &mut T> {
        assert!(col < self.d2);
        self.data.iter_mut().skip(col).step_by(self.d2)
    }
}

impl<T: Clone> Arr2d<T> {
    pub fn fill(&mut self, elem: T) {
        self.data.legacy_fill(elem);
    }

    pub fn transpose(&self) -> Self {
        Self::generate(self.d2, self.d1, |i, j| self[(j, i)].clone())
    }
}

impl<T> Index<(usize, usize)> for Arr2d<T> {
    type Output = T;

    fn index(&self, (row, col): (usize, usize)) -> &Self::Output {
        assert!(row < self.d1);
        assert!(col < self.d2);
        &self.data[self.d2 * row + col]
    }
}

impl<T> Index<usize> for Arr2d<T> {
    type Output = [T];

    fn index(&self, index: usize) -> &Self::Output {
        &self.data[self.d2 * index..self.d2 * (index + 1)]
    }
}

impl<T> IndexMut<(usize, usize)> for Arr2d<T> {
    fn index_mut(&mut self, (row, col): (usize, usize)) -> &mut T {
        assert!(row < self.d1);
        assert!(col < self.d2);
        &mut self.data[self.d2 * row + col]
    }
}

impl<T> IndexMut<usize> for Arr2d<T> {
    fn index_mut(&mut self, index: usize) -> &mut [T] {
        &mut self.data[self.d2 * index..self.d2 * (index + 1)]
    }
}

impl<T: Writable> Writable for Arr2d<T> {
    fn write(&self, output: &mut Output) {
        let mut at = 0usize;
        for i in 0usize..self.d1 {
            if i != 0 {
                output.put(b'\n');
            }
            for j in 0usize..self.d2 {
                if j != 0 {
                    output.put(b' ');
                }
                self.data[at].write(output);
                at += 1;
            }
        }
    }
}

impl<T> IntoIterator for Arr2d<T> {
    type Item = T;
    type IntoIter = IntoIter<T>;

    fn into_iter(self) -> Self::IntoIter {
        self.data.into_iter()
    }
}

pub trait Arr2dRead {
    fn read_table<T: Readable>(&mut self, d1: usize, d2: usize) -> Arr2d<T>;
}

impl Arr2dRead for Input<'_> {
    fn read_table<T: Readable>(&mut self, d1: usize, d2: usize) -> Arr2d<T> {
        Arr2d::generate(d1, d2, |_, _| self.read())
    }
}

pub trait Arr2dCharWrite {
    fn print_table(&mut self, table: &Arr2d<char>);
}

impl Arr2dCharWrite for Output {
    fn print_table(&mut self, table: &Arr2d<char>) {
        let mut at = 0usize;
        for _ in 0..table.d1 {
            for _ in 0..table.d2 {
                self.print(&table.data[at]);
                at += 1;
            }
            self.put(b'\n');
        }
    }
}

impl<T: Readable> Readable for Arr2d<T> {
    fn read(input: &mut Input) -> Self {
        let d1 = input.read();
        let d2 = input.read();
        input.read_table(d1, d2)
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

impl<A, B, C> Detuple for Vec<(A, B, C)> {
    type Res = (Vec<A>, Vec<B>, Vec<C>);

    fn detuple(self) -> Self::Res {
        let mut a = Vec::with_capacity(self.len());
        let mut b = Vec::with_capacity(self.len());
        let mut c = Vec::with_capacity(self.len());
        for (aa, bb, cc) in self {
            a.push(aa);
            b.push(bb);
            c.push(cc);
        }
        (a, b, c)
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
    ($($t:ident)+) => {$(
        impl Readable for $t {
            fn read(input: &mut Input) -> Self {
                input.read_integer()
            }
        }
    )+};
}

read_integer!(i8 i16 i32 i64 i128 isize u8 u16 u32 u64 u128 usize);

macro_rules! tuple_readable {
    ($($name:ident)+) => {
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

#[derive(Copy, Clone)]
pub enum BoolOutput {
    YesNo,
    YesNoCaps,
    PossibleImpossible,
    Custom(&'static str, &'static str),
}

impl BoolOutput {
    pub fn output(&self, output: &mut Output, val: bool) {
        (if val { self.yes() } else { self.no() }).write(output);
    }

    fn yes(&self) -> &str {
        match self {
            BoolOutput::YesNo => "Yes",
            BoolOutput::YesNoCaps => "YES",
            BoolOutput::PossibleImpossible => "Possible",
            BoolOutput::Custom(yes, _) => yes,
        }
    }

    fn no(&self) -> &str {
        match self {
            BoolOutput::YesNo => "No",
            BoolOutput::YesNoCaps => "NO",
            BoolOutput::PossibleImpossible => "Impossible",
            BoolOutput::Custom(_, no) => no,
        }
    }
}

pub struct Output {
    output: Box<dyn Write>,
    buf: Vec<u8>,
    at: usize,
    auto_flush: bool,
    pub bool_output: BoolOutput,
}

impl Output {
    const DEFAULT_BUF_SIZE: usize = 4096;

    pub fn new(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: false,
            bool_output: BoolOutput::YesNoCaps,
        }
    }

    pub fn new_with_auto_flush(output: Box<dyn Write>) -> Self {
        Self {
            output,
            buf: vec![0; Self::DEFAULT_BUF_SIZE],
            at: 0,
            auto_flush: true,
            bool_output: BoolOutput::YesNoCaps,
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
    ($($t:ident)+) => {$(
        impl Writable for $t {
            fn write(&self, output: &mut Output) {
                self.to_string().write(output);
            }
        }
    )+};
}

write_to_string!(u8 u16 u32 u64 u128 usize i8 i16 i32 i64 i128 isize f32 f64);

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
        let bool_output = output.bool_output;
        bool_output.output(output, *self)
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
    ($name: ident: $t: ty = $val: expr) => {
        #[derive(Copy, Clone, Eq, PartialEq, Hash, Ord, PartialOrd)]
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
    ($name: ident: $t: ty) => {
        static mut VAL: Option<$t> = None;

        #[derive(Copy, Clone, Eq, PartialEq, Hash)]
        struct $name {}

        impl $crate::misc::value::DynamicValue<$t> for $name {
            fn set_val(t: $t) {
                unsafe {
                    VAL = Some(t);
                }
            }
        }

        impl $crate::misc::value::Value<$t> for $name {
            fn val() -> $t {
                unsafe { VAL.unwrap() }
            }
        }
    };
    ($name: ident: $t: ty = $val: expr) => {
        dynamic_value!($name: $t);

        $name::set_val($val);
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

value!(Val7: i32 = 1_000_000_007);
pub type ModInt7 = ModInt<i32, Val7>;

value!(Val9: i32 = 1_000_000_009);
pub type ModInt9 = ModInt<i32, Val9>;

value!(ValF: i32 = 998_244_353);
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
    ($($t: ident)+) => {$(
        impl AsIndex for $t {
            fn from_index(idx: usize) -> Self {
                idx as $t
            }

            fn to_index(&self) -> usize {
                *self as usize
            }
        }
    )+};
}

from_index_impl!(i128 i64 i32 i16 i8 isize u128 u64 u32 u16 u8 usize);
}
pub mod bit_ops {
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::ops::{BitAnd, BitAndAssign, BitOr, BitOrAssign, BitXor, BitXorAssign, Not, Shl};
use std::ops::{ShlAssign, Shr, ShrAssign};

pub trait BitOps:
    Copy
    + BitAnd<Output = Self>
    + BitAndAssign
    + BitOr<Output = Self>
    + BitOrAssign
    + BitXor<Output = Self>
    + BitXorAssign
    + Not<Output = Self>
    + Shl<usize, Output = Self>
    + ShlAssign<usize>
    + Shr<usize, Output = Self>
    + ShrAssign<usize>
    + ZeroOne
    + PartialEq
{
    fn bit(at: usize) -> Self {
        Self::one() << at
    }

    fn is_set(&self, at: usize) -> bool {
        (*self >> at & Self::one()) == Self::one()
    }

    fn set_bit(&mut self, at: usize) {
        *self |= Self::bit(at)
    }

    fn unset_bit(&mut self, at: usize) {
        *self &= !Self::bit(at)
    }

    #[must_use]
    fn with_bit(mut self, at: usize) -> Self {
        self.set_bit(at);
        self
    }

    #[must_use]
    fn without_bit(mut self, at: usize) -> Self {
        self.unset_bit(at);
        self
    }

    fn flip_bit(&mut self, at: usize) {
        *self ^= Self::bit(at)
    }

    fn all_bits(n: usize) -> Self {
        let mut res = Self::zero();
        for i in 0..n {
            res.set_bit(i);
        }
        res
    }
}

impl<
        T: Copy
            + BitAnd<Output = Self>
            + BitAndAssign
            + BitOr<Output = Self>
            + BitOrAssign
            + BitXor<Output = Self>
            + BitXorAssign
            + Not<Output = Self>
            + Shl<usize, Output = Self>
            + ShlAssign<usize>
            + Shr<usize, Output = Self>
            + ShrAssign<usize>
            + ZeroOne
            + PartialEq,
    > BitOps for T
{
}

pub trait Bits: BitOps {
    fn bits() -> u32;
}

macro_rules! bits_integer_impl {
    ($($t: ident $bits: expr),+) => {$(
        impl Bits for $t {
            fn bits() -> u32 {
                $bits
            }
        }
    )+};
}

bits_integer_impl!(i128 128, i64 64, i32 32, i16 16, i8 8, isize 64, u128 128, u64 64, u32 32, u16 16, u8 8, usize 64);
}
pub mod from_u8 {
pub trait FromU8 {
    fn from_u8(val: u8) -> Self;
}

macro_rules! from_u8_impl {
    ($($t: ident)+) => {$(
        impl FromU8 for $t {
            fn from_u8(val: u8) -> Self {
                val as $t
            }
        }
    )+};
}

from_u8_impl!(i128 i64 i32 i16 i8 isize u128 u64 u32 u16 u8 usize f32 f64);
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
pub mod primitive {
pub trait Primitive {
    fn into_u8(self) -> u8;
    fn into_u16(self) -> u16;
    fn into_u32(self) -> u32;
    fn into_u64(self) -> u64;
    fn into_u128(self) -> u128;
    fn into_usize(self) -> usize;
    fn into_i8(self) -> i8;
    fn into_i16(self) -> i16;
    fn into_i32(self) -> i32;
    fn into_i64(self) -> i64;
    fn into_i128(self) -> i128;
    fn into_isize(self) -> isize;
}

macro_rules! primitive {
    ($($t: ident)+) => {$(
        impl Primitive for $t {
            fn into_u8(self) -> u8 {
                self as u8
            }

            fn into_u16(self) -> u16 {
                self as u16
            }

            fn into_u32(self) -> u32 {
                self as u32
            }

            fn into_u64(self) -> u64 {
                self as u64
            }

            fn into_u128(self) -> u128 {
                self as u128
            }

            fn into_usize(self) -> usize {
                self as usize
            }

            fn into_i8(self) -> i8 {
                self as i8
            }

            fn into_i16(self) -> i16 {
                self as i16
            }

            fn into_i32(self) -> i32 {
                self as i32
            }

            fn into_i64(self) -> i64 {
                self as i64
            }

            fn into_i128(self) -> i128 {
                self as i128
            }

            fn into_isize(self) -> isize {
                self as isize
            }
        }
    )+};
}

primitive!(u8 u16 u32 u64 u128 usize i8 i16 i32 i64 i128 isize);
}
pub mod sign {
pub trait IsSigned {
    const SIGNED: bool;
}

pub trait Signed: IsSigned {}

pub trait Unsigned: IsSigned {}

macro_rules! unsigned_impl {
    ($($t: ident)+) => {$(
        impl Unsigned for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = false;
        }
    )+};
}

unsigned_impl!(u128 u64 u32 u16 u8 usize);

macro_rules! signed_impl {
    ($($t: ident)+) => {$(
        impl Signed for $t {}

        impl IsSigned for $t {
            const SIGNED: bool = true;
        }
    )+};
}

signed_impl!(i128 i64 i32 i16 i8 isize f64 f32);
}
pub mod wideable {
use std::convert::From;

pub trait Wideable: Sized {
    type W: From<Self>;

    fn downcast(w: Self::W) -> Self;
}

macro_rules! wideable_impl {
    ($($t: ident $w: ident),+) => {$(
        impl Wideable for $t {
            type W = $w;

            fn downcast(w: Self::W) -> Self {
                w as $t
            }
        }
    )+};
}

wideable_impl!(i128 i128, i64 i128, i32 i64, i16 i32, i8 i16, isize isize, u128 u128, u64 u128, u32 u64, u16 u32, u8 u16, usize usize, f64 f64, f32 f64);
}
pub mod zero_one {
pub trait ZeroOne {
    fn zero() -> Self;
    fn one() -> Self;
}

macro_rules! zero_one_integer_impl {
    ($($t: ident)+) => {$(
        impl ZeroOne for $t {
            fn zero() -> Self {
                0
            }

            fn one() -> Self {
                1
            }
        }
    )+};
}

zero_one_integer_impl!(i128 i64 i32 i16 i8 isize u128 u64 u32 u16 u8 usize);

macro_rules! zero_one_float_impl {
    ($($t: ident)+) => {$(
        impl ZeroOne for $t {
            fn zero() -> Self {
                0.
            }

            fn one() -> Self {
                1.
            }
        }
    )+};
}

zero_one_float_impl!(f32 f64);
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
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}