import java.io.*;
import java.util.*;
 
public class C {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int m = in.nextInt();
    	int k = in.nextInt();
    	boolean table[][] = new boolean[n][m];
    	for (int i = 0; i < n; ++i) {
    		String row = in.next();
    		for (int j = 0; j < m; ++j) {
    			table[i][j] = row.charAt(j) == '.';
    		}
    	}
    	if (k == 1) {
    		int ans = 0;
    		for (int i = 0; i < n; ++i) {
    			for (int j = 0; j < m; ++j) {
    				if (table[i][j]) ++ans;
    			}
    		}
    		out.println(ans);
    		return;
    	}
    	List<Integer> seq = new ArrayList<>();
    	for (int i = 0; i < n; ++i) {
    		int cur = 0;
    		for (int j = 0; j < m; ++j) {
    			if (table[i][j]) ++cur;
    			else if (cur > 0) {
    				seq.add(cur);
    				cur = 0;
    			}
    		}
    		if (cur > 0) seq.add(cur);
    	}
    	for (int i = 0; i < m; ++i) {
    		int cur = 0;
    		for (int j = 0; j < n; ++j) {
    			if (table[j][i]) ++cur;
    			else if (cur > 0) {
    				seq.add(cur);
    				cur = 0;
    			}
    		}
    		if (cur > 0) seq.add(cur);
    	}
    	long ans = 0;
    	for (int x: seq) {
    		ans += Math.max(0, x - k + 1);
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
 
    public static void main(String[] arg) {
        new C().run();
    }
}