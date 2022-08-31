// problem-url: https://codeforces.com/contest/1616/problem/H
pub mod solution {

    use crate::collections::default_map::DefaultMap;
    use crate::io::input::Input;
    use crate::io::output::output;
    use crate::numbers::mod_int::ModIntF;
    use crate::numbers::num_traits::bit_ops::BitOps;
    use crate::numbers::num_traits::zero_one::ZeroOne;
    use crate::out_line;

    fn solve(input: &mut Input, _test_case: usize) {
        let n = input.read_usize();
        let x = input.read_unsigned();
        let a = input.read_unsigned_vec(n);

        let mut prefixes = Vec::with_capacity(30);
        for i in 0..=30 {
            let mut cur: DefaultMap<_, usize> = DefaultMap::new();
            for j in a.iter().cloned() {
                cur[j >> i] += 1;
            }
            prefixes.push(cur);
        }

        type Mod = ModIntF;
        let mut p = Vec::with_capacity(n + 1);
        let mut cur = Mod::one();
        for _ in 0..=n {
            p.push(cur);
            cur *= Mod::new(2);
        }
        fn double_prefix(
            mut step: usize,
            prefix1: u32,
            prefix2: u32,
            x: u32,
            p: &Vec<Mod>,
            prefixes: &Vec<DefaultMap<u32, usize>>,
        ) -> Mod {
            if prefixes[step][prefix1] == 0 || prefixes[step][prefix2] == 0 {
                return Mod::zero();
            }
            if step == 0 {
                return (p[prefixes[0][prefix1]] - Mod::one())
                    * (p[prefixes[0][prefix2]] - Mod::one());
            }
            step -= 1;
            if x.is_set(step) {
                let dp1 = double_prefix(step, prefix1 * 2, prefix2 * 2 + 1, x, p, prefixes);
                let dp2 = double_prefix(step, prefix1 * 2 + 1, prefix2 * 2, x, p, prefixes);
                (p[prefixes[step][prefix1 * 2]] - Mod::one())
                    * (p[prefixes[step][prefix2 * 2]] - Mod::one())
                    + (p[prefixes[step][prefix1 * 2 + 1]] - Mod::one())
                        * (p[prefixes[step][prefix2 * 2 + 1]] - Mod::one())
                    + dp1 * dp2
                    + dp1
                        * (p[prefixes[step][prefix1 * 2 + 1]] + p[prefixes[step][prefix2 * 2]]
                            - Mod::one())
                    + dp2
                        * (p[prefixes[step][prefix1 * 2]] + p[prefixes[step][prefix2 * 2 + 1]]
                            - Mod::one())
            } else {
                double_prefix(step, prefix1 * 2, prefix2 * 2, x, p, prefixes)
                    + double_prefix(step, prefix1 * 2 + 1, prefix2 * 2 + 1, x, p, prefixes)
            }
        }
        fn single_prefix(
            mut step: usize,
            prefix: u32,
            x: u32,
            p: &Vec<Mod>,
            prefixes: &Vec<DefaultMap<u32, usize>>,
        ) -> Mod {
            if prefixes[step][prefix] == 0 {
                return Mod::zero();
            }
            if step == 0 {
                return p[prefixes[0][prefix]] - Mod::one();
            }
            step -= 1;
            if x.is_set(step) {
                p[prefixes[step][prefix * 2]] + p[prefixes[step][prefix * 2 + 1]] - Mod::new(2)
                    + double_prefix(step, prefix * 2, prefix * 2 + 1, x, p, prefixes)
            } else {
                single_prefix(step, prefix * 2, x, p, prefixes)
                    + single_prefix(step, prefix * 2 + 1, x, p, prefixes)
            }
        }
        out_line!(single_prefix(30, 0, x, &p, &prefixes));
    }

    pub(crate) fn run(mut input: Input) -> bool {
        solve(&mut input, 1);
        output().flush();
        input.skip_whitespace();
        !input.peek().is_some()
    }
}
pub mod collections {
    pub mod default_map {
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

            fn read_integer<T: IsSigned + ZeroOne + FromU8 + AddSub + Multable + Display>(
                &mut self,
            ) -> T {
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

            pub fn print_iter_ref<'a, T: 'a + Writable, I: Iterator<Item = &'a T>>(
                &mut self,
                iter: I,
            ) {
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
            ($name: ident, $val_name: ident, $t: ty, $base: expr, $val: expr) => {
                static mut $val_name: $t = $base;

                #[derive(Copy, Clone, Eq, PartialEq, Hash)]
                pub struct $name {}

                impl $crate::misc::value::DynamicValue<$t> for $name {
                    fn set_val(t: $t) {
                        unsafe {
                            $val_name = t;
                        }
                    }
                }

                impl $crate::misc::value::Value<$t> for $name {
                    fn val() -> $t {
                        unsafe { $val_name }
                    }
                }

                $name.set_val($val);
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
            AddSub
            + MulDiv
            + Neg<Output = Self>
            + Copy
            + ZeroOne
            + PartialEq
            + From<Self::T>
            + Invertable<Output = Self>
        {
            type W: AddSub + MulDivRem + Copy + ZeroOne + From<Self::T>;
            type T: AddSub + MulDivRem + Copy + PartialEq + ZeroOne + Wideable<W = Self::W> + Ord;

            fn module() -> Self::T;
        }

        #[derive(Copy, Clone, Eq, PartialEq, Hash)]
        pub struct ModInt<T, V: Value<T>> {
            n: T,
            phantom: PhantomData<V>,
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

        impl<
                T: Copy + ZeroOne + AddSub + MulDivRem + Wideable + PartialEq + Ord + Hash,
                V: Value<T>,
            > ModInt<T, V>
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

        impl<T: Copy + ZeroOne + AddSub + MulDivRem + Wideable + PartialEq + Ord, V: Value<T>>
            Invertable for ModInt<T, V>
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

        impl<T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord, V: Value<T>>
            BaseModInt for ModInt<T, V>
        where
            T::W: AddSub + MulDivRem + Copy + ZeroOne,
        {
            type W = T::W;
            type T = T;

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

        impl<T: AddSub + MulDivRem + Copy + PartialEq + Wideable + ZeroOne + Ord, V: Value<T>>
            DivAssign for ModInt<T, V>
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
        pub mod bit_ops {
            use crate::numbers::num_traits::zero_one::ZeroOne;
            use std::ops::{
                BitAnd, BitAndAssign, BitOr, BitOrAssign, BitXor, BitXorAssign, Not, Shl,
            };
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
}
fn main() {
    let mut sin = std::io::stdin();
    let input = crate::io::input::Input::new(&mut sin);
    unsafe {
        crate::io::output::OUTPUT =
            Some(crate::io::output::Output::new(Box::new(std::io::stdout())));
    }
    crate::solution::run(input);
}