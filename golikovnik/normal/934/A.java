import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int m = in.nextInt();
    	int a[] = new int[n];
    	int b[] = new int[m];
    	for (int i = 0; i < n; ++i) {
    		a[i] = in.nextInt();
    	}
    	for (int i = 0; i < m; ++i) {
    		b[i] = in.nextInt();
    	}
    	int L = 0;
    	long min = Long.MAX_VALUE;
    	for (int i = 0; i < n; ++i) {
    		//delete i
    		long max = Long.MIN_VALUE;
    		for (int j = 0; j < n; ++j) {
    			if (j == i) continue;
    			for (int k = 0; k < m; ++k) {
    				max = Math.max(max, 1L * b[k] * a[j]);
    			}
    		}
    		if (max < min) {
    			L = i;
    			min = max;
    		}
    	}
    	long res = Long.MIN_VALUE;
    	for (int i = 0; i < n; ++i) {
    		if (i == L) continue;
    		for (int j = 0; j < m; ++j) {
    			res = Math.max(res, 1L * a[i] * b[j]);
    		}
    	}
    	out.println(res);
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
        new A().run();
    }
}