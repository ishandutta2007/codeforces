import java.io.*;
import java.util.*;
 
public class A293 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	String s = in.next();
    	String t = in.next();
    	int zero_one = 0;
    	int zero_zero = 0;
    	int one_zero = 0;
    	int one_one = 0;
    	for (int i = 0; i < 2 * n; ++i) {
    		boolean a = s.charAt(i) == '1';
    		boolean b = t.charAt(i) == '1';
    		if (a && b) ++one_one;
    		if (a && !b) ++one_zero;
    		if (!a && b) ++zero_one;
    		if (!a && !b) ++zero_zero;
    	}
    	int ones_s = 0;
    	int ones_t = 0;
    	for (int i = 0; i < 2 * n; ++i) {
    		if (i % 2 == 0) {
    			if (one_one > 0) {
    				++ones_s;
    				--one_one;
    			} else if (one_zero > 0) {
    				++ones_s;
    				--one_zero;
    			} else if (zero_one > 0) {
    				--zero_one;
    			} else {
    				--zero_zero;
    			}
    		} else {
    			if (one_one > 0) {
    				++ones_t;
    				--one_one;
    			} else if (zero_one > 0) {
    				++ones_t;
    				--zero_one;
    			} else if (one_zero > 0) {
    				--one_zero;
    			} else {
    				--zero_zero;
    			}
     		}
    	}
    	if (ones_s > ones_t) {
    		out.println("First");
    	} else if (ones_s == ones_t) {
    		out.println("Draw");
    	} else out.println("Second");
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
        new A293().run();
    }
}