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

}

use cp::*;
use std::cmp::*;

fn gcd(mut a:i64,mut b:i64)->i64{
    while b!=0{
        let c=a%b;
        a=b;
        b=c;
    }
    a
}
fn calc(a:(i64,i64),b:(i64,i64))->i64{
    if a.0==b.0{
        return a.0;
    }
    let mut u=b.0-a.0;
    let mut v=b.1-a.1;
    let g=gcd(u,v).abs();
    u/=g;
    v/=g;
    if a.1%v!=0{
        return -1;
    }
    return a.0-(a.1/v)*u;
}
fn work(inp:&mut Parser){
    let n:usize=inp.read();
    let m:usize=inp.read();
    let p:Vec<(i64,i64)>=inp.iter().take(m).collect();
    let mut f=vec![1i32;n+1];
    for i in 0..m{
        for j in i+1..m{
            if p[i].1==p[j].1{
                continue;
            }
            let x=calc(p[i],p[j]);
            //println!("{} {} : {}",i,j,x);
            if x<1||x>n as i64{
                continue;
            }
            
            let mut tmp=2i32;
            for k in j+1..m{
                tmp+=((p[k].0-p[i].0)*(p[j].1-p[i].1)==(p[k].1-p[i].1)*(p[j].0-p[i].0))as i32;
            }
            let x=x as usize;
            f[x]=max(f[x],tmp);
        }
    }
    let mut ans:i64=0;
    for i in 1..=n{
        ans+=f[i]as i64;
        //print!("{}{}",f[i],[" ","\n"][(i==n) as usize]);
    }
    println!("{}",ans);
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
	let t:usize=if cfg!(flukehn){
        inp.read()
    }else{
        1
    };
    for _ in 0..t{
        work(&mut inp);
    }
}