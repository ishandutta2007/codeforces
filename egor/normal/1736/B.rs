pub mod solution {

use crate::collections::vec_ext::ConsecutiveIter;
use crate::io::input::Input;
use crate::io::output::output;
use crate::numbers::gcd::{gcd, lcm};
use crate::out_line;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read_usize();
    let a = input.read_int_vec(n);

    let mut b = Vec::with_capacity(n + 1);
    b.push(a[0]);
    for (&x, &y) in a.consecutive_iter() {
        b.push(lcm(x, y));
    }
    b.push(a[n - 1]);
    for ((&x, &y), a) in b.consecutive_iter().zip(a.into_iter()) {
        if a != gcd(x, y) {
            out_line!(false);
            return;
        }
    }
    out_line!(true);
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
    fn more(&self, el: &T) -> usize;
    fn more_or_eq(&self, el: &T) -> usize;
    fn less(&self, el: &T) -> usize;
    fn less_or_eq(&self, el: &T) -> usize;
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

    fn more(&self, el: &T) -> usize {
        self.len() - self.upper_bound(el)
    }

    fn more_or_eq(&self, el: &T) -> usize {
        self.len() - self.lower_bound(el)
    }

    fn less(&self, el: &T) -> usize {
        self.lower_bound(el)
    }

    fn less_or_eq(&self, el: &T) -> usize {
        self.upper_bound(el)
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

impl<A, B> Detuple for Vec<(A, B)> {
    type Res = (Vec<A>, Vec<B>);

    fn detuple(self) -> Self::Res {
        let mut a = Vec::with_capacity(self.len());
        let mut b = Vec::with_capacity(self.len());
        for (aa, bb) in self {
            a.push(aa);
            b.push(bb);
        }
        (a, b)
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

pub trait DefaultVec<T> {
    fn default_vec(len: usize) -> Vec<T>;
}

impl<T: Default> DefaultVec<T> for Vec<T> {
    fn default_vec(len: usize) -> Vec<T> {
        let mut v = Vec::with_capacity(len);
        for _ in 0..len {
            v.push(T::default());
        }
        v
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
    bool_output: BoolOutput,
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

pub fn set_bool_output(bool_output: BoolOutput) {
    output().bool_output = bool_output
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

impl<T: Writable, U: Writable, V: Writable, W: Writable> Writable for (T, U, V, W) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
        output.put(b' ');
        self.2.write(output);
        output.put(b' ');
        self.3.write(output);
    }
}

impl<T: Writable, U: Writable, V: Writable, W: Writable, X: Writable> Writable for (T, U, V, W, X) {
    fn write(&self, output: &mut Output) {
        self.0.write(output);
        output.put(b' ');
        self.1.write(output);
        output.put(b' ');
        self.2.write(output);
        output.put(b' ');
        self.3.write(output);
        output.put(b' ');
        self.4.write(output);
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

pub trait Unsigned: IsSigned {
    fn distance(self, other: Self) -> Self;
}

macro_rules! unsigned_impl {
    ($($t: ident)+) => {$(
        impl Unsigned for $t {
            fn distance(self, other: Self) -> Self {
                if self > other {
                    self - other
                } else {
                    other - self
                }
            }
        }

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
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT = Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}