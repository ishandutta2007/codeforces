import java.io.*;
import java.util.*;
 
public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    class Pair {
    	int to;
    	int c;
    	
    	Pair(int to, int c) {
    		this.to = to;
    		this.c = c;
    	}
    	
    }
    
    ArrayList<Pair> graph[];
    int memo[][][];
   
    int win(int i, int j, int prev) {
    	if (memo[i][j][prev] != -1) return memo[i][j][prev];
    	for (Pair x: graph[i]) {
    		if (x.c >= prev) {
    			int res = win(j, x.to, x.c) ^ 1;
    			if (res == 0) {
    				return memo[i][j][prev] = 0;
    			}
    		}
    	}
    	return memo[i][j][prev] = 1;
    }
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int m = in.nextInt();
    	graph = new ArrayList[n];
    	memo = new int[n][n][27];
    	for (int i = 0; i < n; ++i) {
    		graph[i] = new ArrayList<>();
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			Arrays.fill(memo[i][j], -1);
    		}
    	}
    	for (int i = 0; i < m; ++i) {
    		int a = in.nextInt();
    		int b = in.nextInt();
    		char c = in.next().charAt(0);
    		--a; --b;
    		graph[a].add(new Pair(b, c - 'a' + 1));
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < n; ++j) {
    			out.print(win(i, j, 0) == 0 ? "A" : "B");
    		}
    		out.println();
    	}
    }
 
    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("input.txt"));
                out = new PrintWriter(new File("output.txt"));
            }
            solve();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
 
    class FastScanner {
        BufferedReader br;
        StringTokenizer st;
 
        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
 
        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }
 
        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }
 
        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
 
    }
 
    public static void main(String[] arg) {
        new D().run();
    }
}