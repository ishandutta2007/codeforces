import java.io.*;
import java.util.*;
 
public class A294 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int[] a = new int[n];
    	for (int i = 0; i < n; ++i) {
    		a[i] = in.nextInt();
    	}
    	int m = in.nextInt();
    	for (int i = 0; i < m; ++i) {
    		int x = in.nextInt() - 1;
    		int y = in.nextInt();
    		int left = y - 1;
    		int right = a[x] - y;
    		a[x] = 0;
    		if (x > 0) {
    			a[x - 1] += left;
    		}
    		if (x + 1 < n) {
    			a[x + 1] += right;
    		}
    	}
    	Arrays.stream(a).forEach(out::println);
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
        new A294().run();
    }
}