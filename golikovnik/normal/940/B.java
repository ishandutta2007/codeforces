import java.io.*;
import java.util.*;
 
public class B {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	long n = in.nextInt();
    	long k = in.nextInt();
    	long a = in.nextInt();
    	long b = in.nextInt();
    	if (k == 1) {
    		out.println(a * (n - 1));
    		return;
    	}
    	long paid = 0;
    	long have = n;
    	while (have > 1) {
    		paid += a * (have % k);
    		have = have - have % k;
    		if (have == 0) {
    			paid -= a;
    			break;
    		}
    		paid += Math.min(b, a * (have - have / k));
    		have /= k;
    	}
    	out.println(paid);
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
        new B().run();
    }
}