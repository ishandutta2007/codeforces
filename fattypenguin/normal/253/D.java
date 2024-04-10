import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskD implements Runnable {

    private void solve() throws IOException {
    	int n = nextInt();
    	int m = nextInt();
    	int k = nextInt();
    	String a[] = new String[n];
    	for (int i = 0; i < n; ++i) {
    		a[i] = nextToken();
    	}
    	
    	long ans = 0;
    	for (int i = 0; i < n; ++i) {
    		int b[] = new int[m];
    		for (int j = 0; j < m; ++j) {
    			
    			if (a[i].charAt(j) == 'a') {
    				b[j] = 1;
    			}
    		}
    		
    		for (int j = i + 1; j < n; ++j) {
    			int sum[] = new int[m + 1];
    			
        		for (int t = 0; t < m; ++t) {
        			
        			if (a[j].charAt(t) == 'a') {
        				b[t] += 1;
        			}

        			sum[t + 1] = sum[t] + b[t]; 
        		}
        		
        		int sa[] = new int[26];
        		int outsa[] = new int[26];
        		int ptr = 0;
        		for (int t = 1; t <= m; ++t) {
        			
        			while (ptr < t && sum[t] - sum[ptr] > k) {
        				if (a[i].charAt(ptr) == a[j].charAt(ptr)) {
        					++outsa[a[i].charAt(ptr) - 'a'];
        				}
        				
        				++ptr;
        			}
        			
        			if (ptr < t - 1 && a[i].charAt(t - 1) == a[j].charAt(t - 1)) {
        				ans += sa[a[i].charAt(t - 1) - 'a'] - outsa[a[i].charAt(t - 1) - 'a'];
        			}
        			
        			if (a[i].charAt(t - 1) == a[j].charAt(t - 1)) {
        				++sa[a[i].charAt(t - 1) - 'a'];
        			}
        		}
    		}
    	}
    	
    	writer.println(ans);
    }

    public static void main(String[] args) {
        new TaskD().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            tokenizer = null;
            writer = new PrintWriter(new FileWriter("output.txt"));
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}

class BitIndexedTree {
	private int arr[];
	private int size;
	
	BitIndexedTree(int size) {
		this.size = size;
		arr = new int[size + 1];
	}
	
	private int lowbit(int x) {
		return x & -x;
	}
	
	public void update(int x, int y) {
		
		while (x <= size) {
			arr[x] += y;
			x += lowbit(x);
		}
	}
	
	public int getSum(int x) {

		int ret = 0;
		while (x > 0) {
			ret += arr[x];
			x -= lowbit(x);
		}
		
		return ret;
	}
}