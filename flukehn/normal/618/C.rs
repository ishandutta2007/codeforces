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
    fn cha((x,y,_1):(i64,i64,usize),(u,v,_2):(i64,i64,usize),(a,b,_3):(i64,i64,usize))->i64{
        ((v-y)*a-(u-x)*b+u*y-v*x).abs()
        /*
        if x==u{
            (a-x).abs();
        }else if y==v{
            (b-y).abs();
        }else{
            //(v-y)X-(u-x)Y+uy-vx=0
            
        }*/
    }
     
    fn main() {
        let content = stdin_to_string();
        let mut inp = Parser::new(&content);
        let n:usize=inp.read();
        let mut p=vec![(0i64,0i64,0usize);n];
        for i in 0..n{
            p[i].0=inp.read();
            p[i].1=inp.read();
            p[i].2=i;
        }
        p.sort();
        let mut q:usize=0;
        let mut ans:i64=1i64<<62;
        for i in 2..n{
            let tmp=cha(p[0],p[1],p[i]);
            if tmp>0&&tmp<ans{
                ans=tmp;
                q=i;
            }
        }
        println!("{} {} {}",p[0].2+1,p[1].2+1,p[q].2+1);
    }