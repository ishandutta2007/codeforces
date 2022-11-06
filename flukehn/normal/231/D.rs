mod cp {
    use std::io::prelude::*;

    pub trait Parseable: Sized {
        fn parse(p: &mut Parser) -> Option<Self>;
    }

    pub trait ParseableScalar: std::str::FromStr + Sized {}

    impl<T: ParseableScalar> Parseable for T {
        fn parse(p: &mut Parser) -> Option<Self> {
            return p.parse_scalar();
        }
    }

    // The following may look stupid, but we don't have a better solution.
    // https://github.com/rust-lang/rust/issues/42721
    macro_rules! declare_parseable_scalar {
        ( $( $x: ty),* ) => {
            $(
                impl ParseableScalar for $x {}
            )*
        }
    }

    declare_parseable_scalar!(
        i8, u8, i16, u16, i32, u32, i64, u64, i128, u128, isize, usize, f32, f64, String
    );

    macro_rules! impl_parseable_tuple {
        ( $( $name:ident )+ ) => {
            impl<$($name: Parseable),+> Parseable for ($($name,)+)
            {
                fn parse(p: &mut Parser) -> Option<Self> {
                    Some(($($name::parse(p)?,)+))
                }
            }
        };
    }

    // The following may look stupid, but we don't have a better solution.
    impl_parseable_tuple! { A }
    impl_parseable_tuple! { A B }
    impl_parseable_tuple! { A B C }
    impl_parseable_tuple! { A B C D }
    impl_parseable_tuple! { A B C D E }
    impl_parseable_tuple! { A B C D E F }
    impl_parseable_tuple! { A B C D E F G }
    impl_parseable_tuple! { A B C D E F G H }
    impl_parseable_tuple! { A B C D E F G H I }
    impl_parseable_tuple! { A B C D E F G H I J }
    impl_parseable_tuple! { A B C D E F G H I J K }
    impl_parseable_tuple! { A B C D E F G H I J K L }

    pub fn stdin_to_string() -> String {
        let mut content = String::new();
        let stdin = std::io::stdin();
        let mut rd = stdin.lock();
        rd.read_to_string(&mut content).unwrap();
        return content;
    }

    pub struct Parser<'a> {
        tokens: std::str::SplitWhitespace<'a>,
    }

    impl<'a> Parser<'a> {
        pub fn new(text: &'a str) -> Self {
            Self {
                tokens: text.split_whitespace(),
            }
        }

        pub fn parse_scalar<T: std::str::FromStr>(&mut self) -> Option<T> {
            self.next().map(|s| match s.parse() {
                Ok(x) => x,
                Err(_) => panic!("cannot parse {:?}", s),
            })
        }

        pub fn read_or_eof<T: Parseable>(&mut self) -> Option<T> {
            T::parse(self)
        }

        pub fn read<T: Parseable>(&mut self) -> T {
            self.read_or_eof::<T>().expect("unexpected end-of-file")
        }
    }

    impl<'a> Iterator for Parser<'a> {
        type Item = &'a str;
        fn next(&mut self) -> Option<&'a str> {
            self.tokens.next()
        }
    }

    #[macro_export]
    macro_rules! take {
        ($p: expr, $n: expr) => {
            $p.by_ref().take($n).map(|x| x.parse().unwrap())
        };
        ($p: expr, $n: expr, $t: ty) => {
            $p.by_ref().take($n).map(|x| x.parse::<$t>().unwrap())
        };
    }

    #[macro_export]
    macro_rules! take_all {
        ($p: expr) => {
            $p.by_ref().map(|x| x.parse().unwrap())
        };
        ($p: expr, $t: ty) => {
            $p.by_ref().map(|x| x.parse::<$t>().unwrap())
        };
    }
}

use cp::*;
//use std::cmp::*;
//use std::mem::swap;
//use std::f64::consts::*;
//const N: usize = 100011;
//const EPS: f64 = 1e-9;
//const INF:i32=1073741824;

fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    
    let (x,y,z):(i32,i32,i32)=inp.read();
    let (a,b,c):(i32,i32,i32)=inp.read();
    let p:Vec<i32>=take!(inp,6).collect();
    let mut sum:i32=0;
    sum+=p[6-1]*(x>a)as i32;
    sum+=p[5-1]*(x<0)as i32;
    sum+=p[2-1]*(y>b)as i32;
    sum+=p[1-1]*(y<0)as i32;
    sum+=p[4-1]*(z>c)as i32;
    sum+=p[3-1]*(z<0)as i32;
    println!("{}",sum);
}