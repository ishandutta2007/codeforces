pub mod solution {

extern crate core;

use crate::collections::bit_set::BitSet;
use crate::collections::min_max::MinimMaxim;
use crate::io::input::Input;
use crate::io::output::output;
use crate::misc::recursive_function::{Callable3, RecursiveFunction3};
use crate::numbers::num_utils::PartialSums;
use crate::out_line;
use std::collections::VecDeque;

fn solve(input: &mut Input, _test_case: usize) {
    let n = input.read_usize();
    let m = input.read_usize();
    let a = input.read_long_vec(n);
    let b = input.read_long_vec(n);
    let segs = input.read_usize_pair_vec(m);

    let mut all_good = BitSet::new(4 * (n + 1));
    let mut good = BitSet::new(n + 1);
    let sa = a.as_slice().partial_sums();
    let sb = b.as_slice().partial_sums();
    let mut order = VecDeque::new();
    for i in 0..=n {
        if sa[i] == sb[i] {
            order.push_back(i);
            let at = i;
            let mut point_op =
                RecursiveFunction3::new(|f, root: usize, left: usize, right: usize| {
                    if left + 1 == right {
                        good.set(left, true);
                        all_good.set(root, true);
                        return;
                    }
                    let mid = (left + right) >> 1;
                    if at < mid {
                        f.call(2 * root + 1, left, mid);
                    } else {
                        f.call(2 * root + 2, mid, right);
                    }
                    if all_good[2 * root + 1] && all_good[2 * root + 2] {
                        all_good.set(root, true);
                    }
                });
            point_op.call(0, 0, n + 1);
        }
    }
    if sa[n] != sb[n] {
        out_line!(false);
        return;
    }
    let mut ends = vec![Vec::new(); n + 1];
    for &(i, j) in &segs {
        ends[i - 1].push(j);
        ends[j].push(i - 1);
    }
    while let Some(i) = order.pop_front() {
        for &j in &ends[i] {
            if good[j] {
                let from = j.min(i);
                let to = i.max(j);
                let mut segment_op =
                    RecursiveFunction3::new(|f, root: usize, left: usize, right: usize| {
                        if to <= left || right <= from {
                            return;
                        }
                        if all_good[root] {
                            return;
                        }
                        if left + 1 == right {
                            order.push_back(left);
                            good.set(left, true);
                            all_good.set(root, true);
                            return;
                        }
                        let mid = (left + right) >> 1;
                        // push down
                        f.call(2 * root + 1, left, mid);
                        f.call(2 * root + 2, mid, right);
                        // unite
                        if all_good[2 * root + 1] && all_good[2 * root + 2] {
                            all_good.set(root, true);
                        }
                    });
                segment_op.call(0, 0, n + 1);
            }
        }
    }
    out_line!(all_good[0]);
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
pub mod num_utils {
use crate::numbers::num_traits::as_index::AsIndex;
use crate::numbers::num_traits::mul_div_rem::Multable;
use crate::numbers::num_traits::zero_one::ZeroOne;
use std::ops::Add;

pub fn factorials<T: ZeroOne + Multable + AsIndex>(len: usize) -> Vec<T> {
    let mut res = Vec::new();
    if len > 0 {
        res.push(T::one());
    }
    while res.len() < len {
        res.push((*res.last().unwrap()) * T::from_index(res.len()));
    }
    res
}

pub fn factorial<T: ZeroOne + Multable + AsIndex>(n: usize) -> T {
    let mut res = T::one();
    for i in 1..=n {
        res *= T::from_index(i);
    }
    res
}

pub trait PartialSums<T> {
    fn partial_sums(&self) -> Vec<T>;
}

impl<T: ZeroOne + Add<Output = T> + Copy> PartialSums<T> for &[T] {
    fn partial_sums(&self) -> Vec<T> {
        let mut res = Vec::with_capacity(self.len() + 1);
        res.push(T::zero());
        for i in self.iter() {
            res.push(*res.last().unwrap() + *i);
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