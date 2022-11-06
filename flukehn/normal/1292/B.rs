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

    pub struct ParserWrapper<'a, 'b, T> {
        p: &'b mut Parser<'a>,
        _marker: std::marker::PhantomData<T>,
    }

    impl<'a, 'b, T: Parseable> Iterator for ParserWrapper<'a, 'b, T> {
        type Item = T;
        fn next(&mut self) -> Option<T> {
            self.p.read_or_eof()
        }
    }

    impl<'a> Parser<'a> {
        pub fn iter<'b, T>(&'b mut self) -> ParserWrapper<'a, 'b, T> {
            ParserWrapper::<'a, 'b, T> {
                p: self,
                _marker: std::marker::PhantomData {},
            }
        }
    }

    #[macro_export]
    #[deprecated(note = "use $p.iter().take($n) insteadly")]
    macro_rules! take {
        ($p: expr, $n: expr) => {
            $p.by_ref().take($n).map(|x| x.parse().unwrap())
        };
        ($p: expr, $n: expr, $t: ty) => {
            $p.by_ref().take($n).map(|x| x.parse::<$t>().unwrap())
        };
    }

    #[macro_export]
    #[deprecated(note = "use $p.iter() insteadly")]
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
fn work(inp:&mut Parser)->i32{
    let mut x=vec![064;100];
    let mut y=x.clone();
    x[0]=inp.read();
    y[0]=inp.read();
    let (ax,ay,bx,by,xs,ys,t):(i64,i64,i64,i64,i64,i64,i64)=inp.read();
    let n:usize={
        let mut ans=100;
        for i in 1..100{
            x[i]=x[i-1]*ax+bx;
            y[i]=y[i-1]*ay+by;
            if x[i]>3e16 as i64||y[i]>3e16 as i64{
                ans=i;
                break;
            }
        }
        ans
    };
    let mut ans=0i32;
    for i in 0..n{
        let mut now=t-(x[i]-xs).abs()-(y[i]-ys).abs();
        if now<0{
            continue;
        }
        let mut xx=x[i];
        let mut yy=y[i];
        let mut tmp=1i32;
        for j in (0..i).rev(){
            now-=xx-x[j]+yy-y[j];
            if now>=0{
                tmp+=1;
                xx=x[j];
                yy=y[j];
            }else{
                break;
            }
        }
        for j in i+1..n{
            now-=x[j]-xx+y[j]-yy;
            if now>=0{
                tmp+=1;
                xx=x[j];
                yy=y[j];
            }else{
                break;
            }
        }
        if ans<tmp{
            ans=tmp;
        }
    }
    ans
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let t:usize=if cfg!(flukehn){
        inp.read()
    }else{
        1//inp.read();
    };
    for _ in 0..t{
        println!("{}",work(&mut inp));
    }
}