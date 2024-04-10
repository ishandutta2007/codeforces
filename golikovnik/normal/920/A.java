import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int t = in.nextInt();
    	while (t-- > 0) {
    		int n = in.nextInt();
    		int k = in.nextInt();
    		int[] a = new int[k];
    		for (int i = 0; i < k; ++i) a[i] = in.nextInt() - 1;
    		boolean[] used = new boolean[n];
    		int left = n;
    		int it = 0;
    		while (left > 0) {
    			for (int i = 0; i < k; ++i) {
    				int L = a[i] - it;
    				int R = a[i] + it;
    				if (L >= 0) {
    					if (!used[L]) {
    						used[L] = true;
    						--left;
    					}
    				}
    				if (R < n) {
    					if (!used[R]) {
    						used[R] = true;
    						--left;
    					}
    				}
    			}
    			++it;
    		}
    		out.println(it);
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
        new A().run();
    }
}