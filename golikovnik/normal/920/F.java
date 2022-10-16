import java.io.*;
import java.util.*;
 
public class F {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    int[] divisors;
    int INF = (int) 1e6;
    int[] ones;
    
    public void solve() throws IOException {
    	precalc();
    	int n = in.nextInt();
    	int m = in.nextInt();
    	long tree[] = new long[4 * n];
    	int a[] = new int[n];
    	ones = new int[n];
    	for (int i = 0; i < n; ++i) {
    		a[i] = in.nextInt();
    		if (i == 0) {
    			ones[i] = (a[i] == 1 ? 1 : 0);
    			continue;
    		}
    		ones[i] = ones[i - 1] + (a[i] == 1 ? 1 : 0);
    	}
    	build(tree, 0, 0, n - 1, a);
    	for (int i = 0; i < m; ++i) {
    		int t = in.nextInt();
    		if (t == 1) {
    			int l = in.nextInt();
    			int r = in.nextInt();
    			modify(tree, 0, 0, n - 1, l - 1, r - 1);
    		} else {
    			int l = in.nextInt();
    			int r = in.nextInt();
    			out.println(query(tree, 0, 0, n - 1, l - 1, r - 1));
    		}
    	}
    }
 
    private void precalc() {
    	divisors = new int[INF + 1];
		for (int i = 1; i <= INF; ++i) {
			for (int j = i; j <= INF; j += i) {
				++divisors[j];
			}
		}
	}

	private void build(long[] tree, int v, int vl, int vr, int[] a) {
    	if (vl == vr) {
    		tree[v] = a[vl];
    		return;
    	}
		int vm = (vl + vr) / 2;
		build(tree, 2 * v + 1, vl, vm, a);
		build(tree, 2 * v + 2, vm + 1, vr, a);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}
	
    private long query(long[] tree, int v, int vl, int vr, int ql, int qr) {
    	if (ql > vr || vl > qr) return 0;
    	if (ql <= vl && vr <= qr) return tree[v];
    	int vm = (vl + vr) / 2;
    	return query(tree, 2 * v + 1, vl, vm, ql, qr) +
    			query(tree, 2 * v + 2, vm + 1, vr, ql, qr);
    }
    
    private void modify(long[] tree, int v, int vl, int vr, int ql, int qr) {
    	if (ql > vr || vl > qr) return;
    	if (ql <= vl && vr <= qr) {
    		int cntOnes = getOnes(vl, vr);
    		if ((tree[v] - cntOnes) == 2L * (vr - vl + 1 - cntOnes)) return;
    		if (vl == vr) {
    			tree[v] = divisors[(int) tree[v]];
    			return;
    		}
    	}
    	int vm = (vl + vr) / 2;
    	modify(tree, 2 * v + 1, vl, vm, ql, qr);
    	modify(tree, 2 * v + 2, vm + 1, vr, ql, qr);
    	tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }
    
	private int getOnes(int vl, int vr) {
		return ones[vr] - (vl > 0 ? ones[vl - 1] : 0);
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
        new F().run();
    }
}