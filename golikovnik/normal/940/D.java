import java.io.*;
import java.util.*;
 
public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int[] a = new int[n];
    	boolean[] b = new boolean[n];
    	for (int i = 0; i < n; ++i) a[i] = in.nextInt();
    	String s = in.next();
    	for (int i = 0; i < n; ++i) b[i] = s.charAt(i) == '1';
    	int L = (int) -1e9;
    	int R = (int) 1e9;
    	for (int i = 4; i < n; ++i) {
    		if (b[i - 1] && b[i - 2] && b[i - 3] && b[i - 4]) {
    			if (!b[i]) {
    				int mn = Math.min(Math.min(a[i - 1], a[i - 2]),
    						Math.min(a[i - 3], a[i - 4]));
    				mn = Math.min(mn, a[i]);
    				R = Math.min(R, mn - 1);
    			}
    		} else if (!b[i - 1] && !b[i - 2] && !b[i - 3] && !b[i - 4]) {
    			if (b[i]) {
    				int mx = Math.max(Math.max(a[i - 1], a[i - 2]),
    						Math.max(a[i - 3], a[i - 4]));
    				mx = Math.max(mx, a[i]);
    				L = Math.max(L, mx + 1);
    			}
    		}
    	}
    	out.printf("%d %d\n", L, R);
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
 
    public static void main(String[] args) {
        new D().run();
    }
}