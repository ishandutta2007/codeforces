mod solve {
    use std::vec::Vec;

    pub struct Graph {
        edges: Vec<Vec<usize>>,
    }

    impl Graph {
        pub fn new(size: usize) -> Graph {
            Graph { edges: vec![Vec::new(); size] }
        }

        pub fn len(&self) -> usize {
            self.edges.len()
        }

        pub fn add_edge(&mut self, x: usize, y: usize) {
            self.edges[x].push(y);
            self.edges[y].push(x);
        }

        pub fn euler(&self) -> Vec<usize> {
            let mut euler = Vec::new();
            let mut used = vec![false; self.len()];
            self.dfs(0, &mut used, &mut euler);
            euler
        }

        fn dfs(&self, node: usize, used: &mut Vec<bool>, euler: &mut Vec<usize>) {
            euler.push(node);
            used[node] = true;

            for &neighbour in self.edges[node].iter() {
                if used[neighbour] {
                    continue;
                }
                self.dfs(neighbour, used, euler);
                euler.push(node);
            }
        }
    }
}

fn main() {
    use std;
    use std::thread::Builder;
    use std::io::{Write, BufWriter};

    Builder::new()
        .stack_size(8 * 1024 * 1024)
        .spawn(|| {
            let stdin = std::io::stdin();
            let stdout = std::io::stdout();

            let mut stream = io::InputStream::new(stdin.lock());
            let mut writer = BufWriter::new(stdout.lock());

            let vertices = stream.scan();
            let edges = stream.scan();
            let clones = stream.scan();

            let mut graph = solve::Graph::new(vertices);

            for _ in 0..edges {
                let x: usize = stream.scan();
                let y: usize = stream.scan();
                graph.add_edge(x - 1, y - 1);
            }

            let mut euler = graph.euler().into_iter();
            let can_take = if 2 * vertices % clones != 0 {
                2 * vertices / clones + 1
            } else {
                2 * vertices / clones
            };

            for _ in 0..clones {
                let mut current: Vec<_> = euler.by_ref().take(can_take).collect();
                if current.is_empty() {
                    current.push(0)
                }

                write!(writer, "{} ", current.len()).unwrap();
                for elem in current {
                    write!(writer, "{} ", elem + 1).unwrap();
                }
                write!(writer, "\n").unwrap();
            }
        })
        .unwrap()
        .join()
        .unwrap();
}

mod io {
    use std::io::{self, BufRead};
    use std::str::FromStr;
    use std::str;
    use std::fmt::Debug;

    pub struct InputStream<T: BufRead> {
        reader: T,
        byte_buffer: Vec<u8>,
    }

    fn is_whitespace(c: u8) -> bool {
        match c {
            b' ' |
            b'\x09'...b'\x0d' => true,
            _ => false,
        }
    }

    fn act_while<T, F, G>(reader: &mut T, mut condition: F, mut act: G)
        where T: BufRead,
              F: FnMut(u8) -> bool,
              G: FnMut(&[u8])
    {
        loop {
            let (skipped, done) = match reader.fill_buf() {
                Ok(buf) => {
                    let skipped = buf.iter().take_while(|&&x| condition(x)).count();
                    act(&buf[..skipped]);
                    (skipped, skipped < buf.len() || buf.len() == 0)
                }
                Err(ref e) if e.kind() == io::ErrorKind::Interrupted => continue,
                Err(_) => panic!("Noooo"),
            };

            reader.consume(skipped);
            if done {
                break;
            }
        }
    }

    impl<T: BufRead> InputStream<T> {
        pub fn new(reader: T) -> InputStream<T> {
            InputStream {
                reader: reader,
                byte_buffer: Vec::new(),
            }
        }

        pub fn scan<F: FromStr>(&mut self) -> F
            where <F as FromStr>::Err: Debug
        {
            let &mut InputStream { ref mut reader, ref mut byte_buffer } = self;

            act_while(reader,
                      |c| is_whitespace(c),
                      |slice| byte_buffer.extend_from_slice(slice));
            byte_buffer.clear();
            act_while(reader,
                      |c| !is_whitespace(c),
                      |slice| byte_buffer.extend_from_slice(slice));

            let slice = match byte_buffer.split_last() {
                Some((&b' ', slice)) => slice,
                _ => byte_buffer.as_slice(),
            };

            str::from_utf8(slice)
                .expect("Utf8 String")
                .parse::<F>()
                .expect("A parsable string")
        }
    }
}