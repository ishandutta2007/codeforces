import java.io.*;
import java.util.*;
 
public class A304 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    final int MAXN = 11111;
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	HashSet<Integer> squares = new HashSet<Integer>();
    	for (int i = 1; i <= MAXN; ++i) squares.add(i * i);
    	long ans = 0;
    	for (int c = 1; c <= n; ++c) {
    		for (int a = 1; a * a < c * c; ++a) {
    			int b_sq = c * c - a * a;
    			if (squares.contains(b_sq)) ++ans;
    		}
    	}
    	out.println(ans / 2);
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
        new A304().run();
    }
}