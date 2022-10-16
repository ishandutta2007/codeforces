import java.io.*;
import java.util.*;
 
public class B931 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int a = in.nextInt();
    	int b = in.nextInt();
    	if (a > b) {
    		int t = a;
    		a = b;
    		b = t;
    	}
    	int cnt = 1;
    	while (!playing(a, b)) {
    		a = (a + 1) / 2;
    		b = (b + 1) / 2;
    		++cnt;
    	}
    	int rounds = (int) (Math.log(n) / Math.log(2));
    	out.println(cnt == rounds ? "Final!" : cnt);
    }
 
    private boolean playing(int a, int b) {
    	return a + 1 == b && a % 2 == 1;
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
        new B931().run();
    }
}