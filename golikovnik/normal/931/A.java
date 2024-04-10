import java.io.*;
import java.util.*;
 
public class A931 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int l = in.nextInt();
    	int r = in.nextInt();
    	if (l > r) {
    		int t = l;
    		l = r;
    		r = t;
    	}
    	int tired_a = 0;
    	int tired_b = 0;
    	int ans = 0;
    	boolean who = false;
    	while (l < r) {
    		if (who) {
    			++l;
    			ans += (++tired_a);
    		} else {
    			--r;
    			ans += (++tired_b);
    		}
    		who ^= true;
    	}
    	out.println(ans);
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
        new A931().run();
    }
}