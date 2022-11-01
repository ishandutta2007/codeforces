import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskB implements Runnable {
	
	private boolean go(int start, int n, int t, String s) {
		int last = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) == 'H') {
				last = i;
			}
		}
		
		if (last == -1) {
			return true;
		}
		
		int least[] = new int[n];
		
		Arrays.fill(least, Integer.MAX_VALUE / 2);
		
		int need = 0;
		int right = -1, current = start, prev = 0;
		for (int i = 0; i < s.length(); ++i) {
			++need;
			
			if (s.charAt(i) == 'S') {
				++current;
			}
			
			if (s.charAt(i) == 'H') {
				--current;
			}
			
			if (current == -1 && s.charAt(i) == 'H') {
				prev = i;
			}
			
			if (current == 0 && s.charAt(i) == 'S') {
				right = i;
				
				need += (i - prev) * 2;
			}
			
			if (i >= last && current >= 0) {
				if (need <= t) {
					return true;
				}
			}
			
			if (current == 0) {
				least[i] = need;
			}
		}
		
		if (current < 0) {
			return false;
		}
		
		right = Math.max(right, last);
		need = Math.min(need, right * 2 + 1);
		
		for (int i = 0; i < right; ++i) {
			need = Math.min(need, least[i] + (right - i) * 2 - 1);
		}
		
		return need <= t;
	}

    private void solve() throws IOException {
    	int n = nextInt(),
    		t = nextInt();
    	
    	String s = nextToken();
    	
    	int low = 0, high = n;
    	
    	while (low < high) {
    		int mid = (low + high) >> 1;
    		
    		if (go(mid, n, t, s)) {
    			high = mid;
    		} else {
    			low = mid + 1;
    		}
    	}
    	
    	if (!go(low, n, t, s)) {
    		low = -1;
    	}
    	
    	writer.println(low);
    }

    public static void main(String[] args) {
        new TaskB().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
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