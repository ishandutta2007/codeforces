import java.io.*;
import java.util.*;
 
public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    int graph[][];
    int label[];
    int n;
    int color[];
    int memo[][];
    
    public void solve() throws IOException {
    	n = in.nextInt();
    	int m = in.nextInt();
    	int cnt[] = new int[n];
    	label = new int[n];
    	color = new int[n];
    	memo = new int[n][26];
    	graph = new int[n][];
    	int x[] = new int[m];
    	int y[] = new int[m];
    	String s = in.next();
    	for (int i = 0; i < n; ++i) {
    		label[i] = s.charAt(i) - 'a';
    	}
    	for (int i = 0; i < n; ++i) {
    		Arrays.fill(memo[i], -1);
    	}
    	for (int i = 0; i < m; ++i) {
    		int a = in.nextInt();
    		int b = in.nextInt();
    		x[i] = a - 1;
    		y[i] = b - 1;
    		++cnt[a - 1];
    	}
    	for (int i = 0; i < n; ++i) {
    		graph[i] = new int[cnt[i]];
    	}
    	int cnt1[] = new int[n];
    	for (int i = 0; i < m; ++i) {
    		graph[x[i]][cnt1[x[i]]++] = y[i];
    	}
    	if (hasCycles()) {
    		out.println(-1);
    		return;
    	}
    	int max = 0;
    	for (int let = 0; let < 26; ++let) {
    		for (int i = 0; i < n; ++i) {
    			max = Math.max(max, get(i, let));
    		}
    	}
    	out.println(max);
    }
    
    private int get(int i, int let) {
    	if (memo[i][let] != -1) return memo[i][let];
    	int ans = 0;
    	for (int x: graph[i]) {
    		ans = Math.max(ans, get(x, let));
		}
    	if (label[i] == let) ++ans;
    	return memo[i][let] = ans;
	}

	private boolean hasCycles() {
		for (int i = 0; i < n; ++i) {
			if (dfsCycles(i)) {
				return true;
			}
		}
		return false;
	}

	private boolean dfsCycles(int v) {
		color[v] = 1;
		for (int u: graph[v]) {
			if (color[u] == 0) {
				if (dfsCycles(u)) return true;
			}
			if (color[u] == 1) return true;
		}
		color[v] = 2;
		return false;
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