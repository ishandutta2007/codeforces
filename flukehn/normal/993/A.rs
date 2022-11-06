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

fn dist(a:(i32,i32),b:(i32,i32))->i32{
    (a.0-b.0).abs()+(a.1-b.1).abs()
}
fn dist2(a:(i32,i32),b:(i32,i32),c:(i32,i32))->i32{
    if b.0==c.0{
        (a.0-b.0).abs()
    }else{
        (a.1-b.1).abs()
    }
}
fn dist3(a:(i32,i32),b:(i32,i32),c:(i32,i32))->i32{
    if (b.0>c.0) == (b.1>c.1){
        (a.1-a.0-(b.1-b.0)).abs()
    }else{
        (a.1+a.0-(b.1+b.0)).abs()
    }
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
    let p1:Vec<(i32,i32)>=inp.iter().take(4).collect();
    let p2:Vec<(i32,i32)>=inp.iter().take(4).collect();
    let mut sum=0i32;
    for i in 0..4{
        sum+=dist(p1[i],p1[(i+1)%4]);
    }
    let mut ans=false;
    let mut tmp=0i32;
    let mut p=(0i32,0i32);
    for i in 0..4{
        p.0+=p2[i].0;
        p.1+=p2[i].1;
        tmp=0;
        for j in 0..4{
            tmp+=dist2(p2[i],p1[j],p1[(j+1)%4]);
        }
        ans|=2*tmp==sum;
    }
    p.0/=4;
    p.1/=4;
    tmp=0;
    for j in 0..4{
        tmp+=dist2(p,p1[j],p1[(j+1)%4]);
    }
    ans|=2*tmp==sum;

    sum=0;
    p=(0,0);
    for i in 0..4{
        sum+=dist(p2[i],p2[(i+1)%4]);
    }
    for i in 0..4{
        p.0+=p1[i].0;
        p.1+=p1[i].1;
        tmp=0;
        for j in 0..4{
            tmp+=dist3(p1[i],p2[j],p2[(j+1)%4]);
        }
        ans|=2*tmp==sum;
        //println!("{} {}",tmp,sum)
    }
    p.0/=4;
    p.1/=4;
    tmp=0;
    for j in 0..4{
        tmp+=dist3(p,p2[j],p2[(j+1)%4]);
    }
    ans|=2*tmp==sum;
    println!("{}",["NO","YES"][ans as usize]);
}