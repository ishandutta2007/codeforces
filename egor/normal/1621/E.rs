pub mod solution {

use crate::collections::bit_set::BitSet;
use crate::collections::iter_ext::IterExt;
use crate::collections::vec_ext::Bounds;
use crate::io::input::Input;
use crate::io::output::output;
use crate::numbers::num_traits::primitive::Primitive;
use crate::numbers::rational::Rational;
use crate::out_line;
use crate::string::string::Str;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read_usize();
    let m = input.read_usize();
    let mut a: Vec<u64> = input.read_vec(n);

    a.sort_unstable();
    a.reverse();
    a.resize_with(m, || unreachable!());
    a.reverse();

    let mut groups = Vec::with_capacity(m);
    for _ in 0..m {
        let k = input.read_usize();
        let b: Vec<u64> = input.read_vec(k);
        let s = b.iter().sum::<u64>();
        groups.push((Rational::new(s, k.into_u64()), s, k, b));
    }
    let mut ratio = groups.iter().map(|(r, _, _, _)| *r).collect_vec();
    ratio.sort();
    let mut same = BitSet::new(m);
    let mut up = BitSet::new(m);
    let mut down = BitSet::new(m);
    for i in 0..m {
        if ratio[i] <= Rational::new(a[i], 1) {
            same.set(i, true);
        }
        if i > 0 && ratio[i] <= Rational::new(a[i - 1], 1) {
            up.set(i, true);
        }
        if i < m - 1 && ratio[i] <= Rational::new(a[i + 1], 1) {
            down.set(i, true);
        }
    }
    fn count(b: &BitSet) -> Vec<usize> {
        let mut res = Vec::with_capacity(b.len() + 1);
        res.push(0);
        for i in 0..b.len() {
            res.push(*res.last().unwrap() + if b[i] { 1 } else { 0 });
        }
        res
    }
    let c_same = count(&same);
    let c_up = count(&up);
    let c_down = count(&down);
    let mut ans = Str::new();
    for (r, s, k, b) in groups {
        let pos = ratio.as_slice().lower_bound(&r);
        for v in b {
            let cr = Rational::new(s - v, (k - 1).into_u64());
            let mut n_pos = ratio.as_slice().lower_bound(&cr);
            if n_pos > pos {
                n_pos -= 1;
            }
            let l = pos.min(n_pos);
            let r = pos.max(n_pos) + 1;
            if c_same[l] != l || c_same[m] - c_same[r] != m - r || cr > Rational::new(a[n_pos], 1) {
                ans += b'0';
                continue;
            }
            if n_pos < pos && c_down[pos] - c_down[n_pos] != pos - n_pos {
                ans += b'0';
                continue;
            }
            if n_pos > pos && c_up[n_pos + 1] - c_up[pos + 1] != n_pos - pos {
                ans += b'0';
                continue;
            }
            ans += b'1';
        }
    }
    out_line!(ans);
}

pub(crate) fn run(mut input: Input) -> bool {
    let t = input.read();
    for i in 0usize..t {
        solve(&mut input, i + 1);
    }
    output().flush();
    input.skip_whitespace();
    !input.peek().is_some()
}

}
pub mod collections {
pub mod bit_set {
use crate::collections::legacy_fill::LegacyFill;
use crate::numbers::num_traits::bit_ops::BitOps;
use std::ops::Index;

const TRUE: bool = true;
const FALSE: bool = false;

#[derive(Clone)]
pub struct BitSet {
    data: Vec<u64>,
    len: usize,
}

impl BitSet {
    pub fn new(len: usize) -> Self {
        let data_len = if len == 0 {
            0
        } else {
            Self::index(len - 1) + 1
        };
        Self {
            data: vec![0; data_len],
            len,
        }
    }

    pub fn set(&mut self, at: usize, value: bool) {
        assert!(at < self.len);
        if value {
            self.data[Self::index(at)].set_bit(at & 63);
        } else {
            self.data[Self::index(at)].unset_bit(at & 63);
        }
    }

    pub fn flip(&mut self, at: usize) {
        self.set(at, !self[at]);
    }

    #[allow(clippy::len_without_is_empty)]
    pub fn len(&self) -> usize {
        self.len
    }

    pub fn fill(&mut self, value: bool) {
        // 1.43
        self.data.legacy_fill(if value { std::u64::MAX } else { 0 })
    }

    pub fn iter(&self) -> impl Iterator<Item = usize> + '_ {
        struct Iter<'s> {
            at: usize,
            inside: usize,
            set: &'s BitSet,
        }

        impl<'s> Iterator for Iter<'s> {
            type Item = usize;

            fn next(&mut self) -> Option<Self::Item> {
                while self.at < self.set.data.len()
                    && (self.inside == 64 || (self.set.data[self.at] >> self.inside) == 0)
                {
                    self.at += 1;
                    self.inside = 0;
                }
                if self.at == self.set.data.len() {
                    None
                } else {
                    while !self.set.data[self.at].is_set(self.inside) {
                        self.inside += 1;
                    }
                    let res = self.at * 64 + self.inside;
                    if res < self.set.len {
                        self.inside += 1;
                        Some(res)
                    } else {
                        None
                    }
                }
            }
        }

        Iter {
            at: 0,
            inside: 0,
            set: self,
        }
    }

    fn index(at: usize) -> usize {
        at >> 6
    }
}

impl Index<usize> for BitSet {
    type Output = bool;

    fn index(&self, at: usize) -> &Self::Output {
        assert!(at < self.len);
        if self.data[Self::index(at)].is_set(at & 63) {
            &TRUE
        } else {
            &FALSE
        }
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

pub trait Bounds<T: PartialOrd> {
    fn lower_bound(&self, el: &T) -> usize;
    fn upper_bound(&self, el: &T) -> usize;
    fn bin_search(&self, el: &T) -> Option<usize>;
}

impl<T: PartialOrd> Bounds<T> for &[T] {
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

    #[allow(clippy::should_implement_trait)]
    pub fn into_iter<T: Readable + 's>(self) -> impl Iterator<Item = T> + 's {
        struct InputIterator<'s, T: Readable> {
            input: Input<'s>,
            phantom: PhantomData<T>,
        }

        impl<'s, T: Readable + 's> Iterator for InputIterator<'s, T> {
            type Item = T;

            fn next(&mut self) -> Option<Self::Item> {
                self.input.skip_whitespace();
                self.input.peek().map(|_| self.input.read())
            }
        }

        InputIterator {
            input: self,
            phantom: Default::default(),
        }
    }

    /*pub fn iter<'t, T: Readable + 's>(&'t mut self) -> impl Iterator<Item = T> + 't
    where
        's: 't,
    {
        struct InputIterator<'t, 's: 't, T: Readable + 's> {
            input: &'t mut Input<'s>,
            phantom: PhantomData<T>,
        }

        impl<'t, 's: 't, T: Readable + 's> Iterator for InputIterator<'s, 't, T> {
            type Item = T;

            fn next(&mut self) -> Option<Self::Item> {
                self.input.skip_whitespace();
                self.input.peek().map(|_| self.input.read())
            }
        }

        InputIterator::<'t, 's> {
            input: self,
            phantom: Default::default(),
        }
    }*/

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
    read_impl!(usize, read_usize, read_usize_vec);
    read_impl!(i8, read_i8, read_i8_vec);
    read_impl!(i16, read_i16, read_i16_vec);
    read_impl!(i32, read_int, read_int_vec);
    read_impl!(i64, read_long, read_long_vec);
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
pub mod num_traits {
pub mod add_sub {
use std::ops::{Add, AddAssign, Sub, SubAssign};

pub trait Addable: Add<Output = Self> + AddAssign + Copy {}
impl<T: Add<Output = Self> + AddAssign + Copy> Addable for T {}

pub trait AddSub: Addable + Sub<Output = Self> + SubAssign {}
impl<T: Addable + Sub<Output = Self> + SubAssign> AddSub for T {}
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
    ($t: ident, $bits: expr) => {
        impl Bits for $t {
            fn bits() -> u32 {
                $bits
            }
        }
    };
}

bits_integer_impl!(i128, 128);
bits_integer_impl!(i64, 64);
bits_integer_impl!(i32, 32);
bits_integer_impl!(i16, 16);
bits_integer_impl!(i8, 8);
bits_integer_impl!(isize, 64);
bits_integer_impl!(u128, 128);
bits_integer_impl!(u64, 64);
bits_integer_impl!(u32, 32);
bits_integer_impl!(u16, 16);
bits_integer_impl!(u8, 8);
bits_integer_impl!(usize, 64);
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
    ($t: ident) => {
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
    };
}

primitive!(u8);
primitive!(u16);
primitive!(u32);
primitive!(u64);
primitive!(u128);
primitive!(usize);
primitive!(i8);
primitive!(i16);
primitive!(i32);
primitive!(i64);
primitive!(i128);
primitive!(isize);
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
}
}
pub mod string {
pub mod string {
use crate::collections::iter_ext::IterExt;
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use std::cmp::Ordering;
use std::hash::{Hash, Hasher};
use std::iter::FromIterator;
use std::marker::PhantomData;
use std::ops::{Add, AddAssign, Deref, Index, IndexMut};
use std::slice::SliceIndex;
use std::vec::IntoIter;

pub enum Str<'s> {
    String(String, PhantomData<&'s str>),
    StringRef(&'s String),
    Str(&'s str),
    Vec(Vec<u8>, PhantomData<&'s str>),
    VecRef(&'s Vec<u8>),
    U8(&'s [u8]),
}

impl Default for Str<'static> {
    fn default() -> Self {
        Self::new()
    }
}

impl Str<'static> {
    pub fn new() -> Self {
        Str::Vec(Vec::new(), PhantomData::default())
    }

    pub fn with_capacity(cap: usize) -> Self {
        Str::Vec(Vec::with_capacity(cap), PhantomData::default())
    }
}

impl<'s> Str<'s> {
    pub fn push(&mut self, c: u8) {
        self.to_vec();
        self.as_vec().push(c)
    }

    pub fn as_slice(&self) -> &[u8] {
        match self {
            Str::String(s, _) => s.as_bytes(),
            Str::StringRef(s) => s.as_bytes(),
            Str::Str(s) => s.as_bytes(),
            Str::Vec(s, _) => s,
            Str::VecRef(s) => s,
            Str::U8(s) => s,
        }
    }

    pub fn len(&self) -> usize {
        match self {
            Str::String(s, _) => s.len(),
            Str::StringRef(s) => s.len(),
            Str::Str(s) => s.len(),
            Str::Vec(s, _) => s.len(),
            Str::VecRef(s) => s.len(),
            Str::U8(s) => s.len(),
        }
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn iter(&self) -> impl ExactSizeIterator<Item = u8> + DoubleEndedIterator<Item = u8> + '_ {
        match self {
            Str::String(s, _) => s.as_bytes().iter(),
            Str::StringRef(s) => s.as_bytes().iter(),
            Str::Str(s) => s.as_bytes().iter(),
            Str::Vec(s, _) => s.iter(),
            Str::VecRef(s) => s.iter(),
            Str::U8(s) => s.iter(),
        }
        .cloned()
    }

    pub fn iter_mut(
        &mut self,
    ) -> impl ExactSizeIterator<Item = &mut u8> + DoubleEndedIterator<Item = &mut u8> {
        self.to_vec();
        self.as_vec().iter_mut()
    }

    pub fn sort(&mut self) {
        self.to_vec();
        self.as_vec().sort_unstable();
    }

    //noinspection RsSelfConvention
    #[allow(clippy::wrong_self_convention)]
    fn to_vec(&mut self) {
        match self {
            Str::Vec(_, _) => {}
            _ => *self = self.clone(),
        }
    }

    fn as_vec(&mut self) -> &mut Vec<u8> {
        match self {
            Str::Vec(s, _) => s,
            _ => panic!("unreachable"),
        }
    }

    pub fn into_string(self) -> String {
        match self {
            Str::String(s, _) => s,
            Str::StringRef(s) => s.clone(),
            Str::Str(s) => s.to_string(),
            Str::Vec(v, _) => String::from_utf8(v).unwrap(),
            Str::VecRef(v) => String::from_utf8(v.clone()).unwrap(),
            Str::U8(v) => String::from_utf8_lossy(v).into_owned(),
        }
    }

    pub fn reverse(&mut self) {
        self.as_vec().reverse();
    }
}

impl IntoIterator for Str<'_> {
    type Item = u8;
    type IntoIter = IntoIter<u8>;

    fn into_iter(mut self) -> Self::IntoIter {
        self.to_vec();
        match self {
            Str::Vec(v, _) => v.into_iter(),
            _ => panic!("unreachable"),
        }
    }
}

impl From<String> for Str<'static> {
    fn from(s: String) -> Self {
        Str::String(s, PhantomData::default())
    }
}

impl<'s> From<&'s str> for Str<'s> {
    fn from(s: &'s str) -> Self {
        Str::Str(s)
    }
}

impl From<Vec<u8>> for Str<'static> {
    fn from(s: Vec<u8>) -> Self {
        Str::Vec(s, PhantomData::default())
    }
}

impl<'s> From<&'s [u8]> for Str<'s> {
    fn from(s: &'s [u8]) -> Self {
        Str::U8(s)
    }
}

impl<'s> From<&'s String> for Str<'s> {
    fn from(s: &'s String) -> Self {
        Str::StringRef(s)
    }
}

impl<'s> From<&'s Vec<u8>> for Str<'s> {
    fn from(s: &'s Vec<u8>) -> Self {
        Str::VecRef(s)
    }
}

impl<R: SliceIndex<[u8]>> Index<R> for Str<'_> {
    type Output = R::Output;

    fn index(&self, index: R) -> &Self::Output {
        match self {
            Str::String(s, _) => &s.as_bytes()[index],
            Str::Str(s) => &s.as_bytes()[index],
            Str::Vec(s, _) => &s[index],
            Str::U8(s) => &s[index],
            Str::StringRef(s) => &s.as_bytes()[index],
            Str::VecRef(s) => &s[index],
        }
    }
}

impl<R: SliceIndex<[u8]>> IndexMut<R> for Str<'_> {
    fn index_mut(&mut self, index: R) -> &mut Self::Output {
        self.to_vec();
        self.as_vec().index_mut(index)
    }
}

impl Clone for Str<'_> {
    fn clone(&self) -> Self {
        match self {
            Str::String(s, _) => Str::Vec(Vec::from(s.as_bytes()), PhantomData::default()),
            Str::Str(s) => Str::Vec(Vec::from(s.as_bytes()), PhantomData::default()),
            Str::Vec(s, _) => Str::Vec(s.clone(), PhantomData::default()),
            Str::U8(s) => Str::Vec(Vec::from(*s), PhantomData::default()),
            Str::StringRef(s) => Str::Vec(Vec::from(s.as_bytes()), PhantomData::default()),
            Str::VecRef(s) => Str::Vec(s.deref().clone(), PhantomData::default()),
        }
    }
}

impl<'r, 's, S: Into<Str<'r>>> AddAssign<S> for Str<'s> {
    fn add_assign(&mut self, rhs: S) {
        self.to_vec();
        self.as_vec().extend_from_slice(rhs.into().as_slice());
    }
}

impl<'s> AddAssign<u8> for Str<'s> {
    fn add_assign(&mut self, rhs: u8) {
        self.to_vec();
        self.as_vec().push(rhs);
    }
}

impl<'r, 's, S: Into<Str<'r>>> Add<S> for Str<'s> {
    type Output = Str<'s>;

    fn add(mut self, rhs: S) -> Self::Output {
        self += rhs;
        self
    }
}

impl Readable for Str<'static> {
    fn read(input: &mut Input) -> Self {
        input.next_token().unwrap().into()
    }
}

impl Writable for Str<'_> {
    fn write(&self, output: &mut Output) {
        for c in self.as_slice() {
            output.put(*c);
        }
        output.maybe_flush();
    }
}

impl Hash for Str<'_> {
    fn hash<H: Hasher>(&self, state: &mut H) {
        self.as_slice().hash(state);
    }
}

impl<'r> PartialEq<Str<'r>> for Str<'_> {
    fn eq(&self, other: &Str<'r>) -> bool {
        self.as_slice().eq(other.as_slice())
    }
}

impl Eq for Str<'_> {}

impl<'r> PartialOrd<Str<'r>> for Str<'_> {
    fn partial_cmp(&self, other: &Str<'r>) -> Option<Ordering> {
        self.as_slice().partial_cmp(other.as_slice())
    }
}

impl Ord for Str<'_> {
    fn cmp(&self, other: &Self) -> Ordering {
        self.as_slice().cmp(other.as_slice())
    }
}

impl FromIterator<u8> for Str<'static> {
    fn from_iter<T: IntoIterator<Item = u8>>(iter: T) -> Self {
        Self::Vec(iter.into_iter().collect_vec(), Default::default())
    }
}

impl<'r> FromIterator<&'r u8> for Str<'static> {
    fn from_iter<T: IntoIterator<Item = &'r u8>>(iter: T) -> Self {
        Self::Vec(iter.into_iter().cloned().collect_vec(), Default::default())
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