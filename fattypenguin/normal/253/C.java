import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskC implements Runnable {

    private void solve() throws IOException {
    	int n = nextInt();
    	int a[] = new int[n];
    	for (int i = 0; i < n; ++i) {
    		a[i] = nextInt();
    	}
    	
    	int r1 = nextInt() - 1;
    	int c1 = nextInt() - 1;
    	int r2 = nextInt() - 1;
    	int c2 = nextInt() - 1;

    	int min[][] = new int[n][n];
    	for (int i = 0; i < n; ++i) {
    		Arrays.fill(min[i], Integer.MAX_VALUE);
    		min[i][i] = a[i];
    		for (int j = i + 1; j < n; ++j) {
    			min[i][j] = Math.min(min[i][j - 1], a[j]);
    		}
    	}
    	
    	int ans = Integer.MAX_VALUE;
    	if (r1 <= r2) {
        	if (r1 + 1 < n) {
        		c1 = Math.min(c1, min[r1 + 1][r2]);
        	}
        	ans = Math.min(ans, r2 - r1 + Math.abs(c1 - c2));
    		for (int i = 0; i < r1; ++i) {
    			int step = r2 - r1 + 2 * (r1 - i);
    			int y = Math.min(min[i][r1 - 1], c1);
    			ans = Math.min(ans, step + Math.abs(y - c2));
    		}
    		
    		for (int i = r2 + 1; i < n; ++i) {
    			int step = r2 - r1 + 2 * (i - r2);
    			int y = Math.min(min[r2 + 1][i], c1);
    			ans = Math.min(ans, step + Math.abs(y - c2));
    		}
    	} else {
        	c1 = Math.min(c1, min[r2][r1 - 1]);
        	ans = Math.min(ans, r1 - r2 + Math.abs(c1 - c2));
    		for (int i = 0; i < r2; ++i) {
    			int step = r1 - r2 + 2 * (r2 - i);
    			int y = Math.min(min[i][r2 - 1], c1);
    			ans = Math.min(ans, step + Math.abs(y - c2));
    		}
    		
    		for (int i = r1 + 1; i < n; ++i) {
    			int step = r1 - r2 + 2 * (i - r1);
    			int y = Math.min(min[r1 + 1][i], c1);
    			ans = Math.min(ans, step + Math.abs(y - c2));
    		}
    	}
    	
    	writer.println(ans);
    }

    public static void main(String[] args) {
        new TaskC().run();
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