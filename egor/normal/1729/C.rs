pub mod solution {

use crate::io::input::Input;
use crate::io::output::output;
use crate::numbers::num_traits::primitive::Primitive;
use crate::numbers::num_traits::sign::Unsigned;
use crate::out_line;
use crate::string::string::Str;

fn solve(input: &mut Input, _test_case: usize) {
    let s: Str = input.read();

    let mut pos = vec![Vec::new(); 26];
    for (i, c) in s.iter().enumerate() {
        pos[c as usize - 'a' as usize].push(i + 1);
    }
    let a = (s[0] - b'a').into_usize();
    let b = (s[s.len() - 1] - b'a').into_usize();
    let mut ans = Vec::new();
    if a <= b {
        for i in a..=b {
            ans.extend(pos[i].iter().copied());
        }
    } else {
        for i in (b..=a).rev() {
            ans.extend(pos[i].iter().copied());
        }
    }
    out_line!(a.distance(b), ans.len());
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
pub mod iter_ext {
use std::cmp::Ordering;

pub trait IterPartialEqExt<T: PartialEq>: Iterator<Item = T> + Sized {
    fn find(mut self, item: T) -> Option<usize> {
        self.position(|r| r == item)
    }
    fn count_eq(self, item: &T) -> usize {
        Iterator::count(self.filter(|r| r == item))
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
pub mod string {
pub mod string {
use crate::collections::iter_ext::IterExt;
use crate::io::input::{Input, Readable};
use crate::io::output::{Output, Writable};
use std::cmp::Ordering;
use std::fmt::{Display, Formatter};
use std::hash::{Hash, Hasher};
use std::iter::{Cloned, FromIterator};
use std::marker::PhantomData;
use std::ops::{Add, AddAssign, Deref, DerefMut, Index, IndexMut};
use std::slice::{Iter, SliceIndex};
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

    pub fn as_slice_mut(&mut self) -> &mut [u8] {
        self.to_vec();
        self.as_vec().as_mut_slice()
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

    pub fn iter(&self) -> Cloned<Iter<u8>> {
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

    pub fn into_owned(mut self) -> Str<'static> {
        self.to_vec();
        Str::Vec(
            match self {
                Str::Vec(v, _) => v,
                _ => unreachable!(),
            },
            Default::default(),
        )
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

impl From<u8> for Str<'static> {
    fn from(c: u8) -> Self {
        Str::Vec(vec![c], PhantomData::default())
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

impl Display for Str<'_> {
    fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
        <String as Display>::fmt(&String::from_utf8(self.as_slice().to_vec()).unwrap(), f)
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

impl Deref for Str<'_> {
    type Target = [u8];

    fn deref(&self) -> &Self::Target {
        self.as_slice()
    }
}

impl DerefMut for Str<'_> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        self.as_slice_mut()
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