import java.io.*;
import java.util.*;
 
public class C {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int k = in.nextInt();
    	String s = in.next();
    	char[] buf = new char[k];
    	boolean[] have = new boolean[26];
    	char max = 'a';
    	char min = 'z';
    	for (int i = 0; i < n; ++i) {
    		char c = s.charAt(i);
    		max = max < c ? c : max;
    		min = min > c ? c : min;
    		have[c - 'a'] = true;
    	}
    	if (k > n) {
    		out.print(s);
    		for (int i = 0; i < k - n; ++i) out.print(min);
    	} else {
    		int put = -1;
    		for (int i = k - 1; i >= 0; --i) {
    			if (s.charAt(i) != max) {
    				for (int j = s.charAt(i) - 'a' + 1; j < 26; ++j) {
    					if (have[j]) {
    						buf[i] = (char) ('a' + j);
    						put = i;
    						break;
    					}
    				}
    				break;
    			}
    		}
    		if (put == -1) throw new RuntimeException();
    		for (int i = 0; i < k; ++i) {
    			if (i < put) buf[i] = s.charAt(i);
    			else if (i > put) buf[i] = min;
    		}
    		out.print(new String(buf));
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
 
    public static void main(String[] args) {
        new C().run();
    }
}