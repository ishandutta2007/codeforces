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
macro_rules! swap{
    ($x:expr, $y:expr) => {
        {
            let temp=$x;
            $x=$y;
            $y=temp;
        }
    };
}
fn chk(a:(usize,usize),b:(usize,usize))->bool{
    (b.0>a.0&&b.0<a.1)!=(b.1>a.0&&b.1<a.1)
}
fn work(inp:&mut Parser){
    let n:usize=inp.read();
    let k:usize=inp.read();
    let mut p:Vec<(usize,usize)>=inp.iter().take(k).collect();
    let mut vis=vec![false;2*n];
    for i in 0..k{
        p[i].0-=1;
        p[i].1-=1;
        if p[i].0>p[i].1{swap!(p[i].0,p[i].1);}
        vis[p[i].0]=true;
        vis[p[i].1]=true;
    }
    let mut a=Vec::<usize>::new();
    for i in 0..2*n{
        if !vis[i]{
            a.push(i);
        }
    }
    let m=(n-k)*2;
    let mut ans=0i32;
    for i in 0..m{
        let mut q=Vec::<(usize,usize)>::new();
        for j in 0..m/2{
            let mut u=a[(i+j)%m];
            let mut v=a[(i+j+m/2)%m];
            if u>v{swap!(u,v);}
            q.push((u,v));
        }
        let mut tmp=0i32;
        for i in 0..m/2{
            for j in i+1..m/2{
                tmp+=chk(q[i],q[j])as i32;
            }
        }
        for i in &p{
            for j in &q{
               tmp+=chk(*i,*j) as i32;
            }
        }

        if ans<tmp{ans=tmp;}
    }
    for i in 0..k{
        for j in i+1..k{
            ans+=chk(p[i],p[j])as i32;
        }
    }
    println!("{}",ans);
}
fn main() {
    let content = stdin_to_string();
    let mut inp = Parser::new(&content);
	let t:usize=if cfg!(flukehn){
        inp.read()
    }else{
        inp.read()
    };
    for _ in 0..t{
        work(&mut inp);
    }
}