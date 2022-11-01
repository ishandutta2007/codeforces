import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class CF136E implements Runnable {
	
	private int BIT[], BIT1[];
	private int n;
	
	private void add(int x, int y, int BIT[])
	{
		++x;
		while (x <= n)
		{
			BIT[x] += y;
			x += x & -x;
		}
	}
	
	private int sum(int x, int BIT[])
	{
		++x;
		int ret = 0;
		while (x > 0)
		{
			ret += BIT[x];
			x -= x & -x;
		}
		
		return ret;
	}
	
    private void solve() throws IOException {
    	n = nextInt();
    	long k = nextLong();
    	int a[] = new int[n];
    	for (int i = 0; i < n; ++i)
    		a[i] = nextInt();
    	
    	long cur = 0;
    	BIT = new int[n+1];
    	BIT1 = new int[n+1];
    	
    	HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
    	int ord[] = a.clone();
    	Arrays.sort(ord);
    	
    	int total = 0;
    	for (int i = 0; i < n; ++i)
    		if (i == 0 || ord[i] != ord[i-1])
    			hash.put(ord[i], total++);
    	for (int i = 0; i < n; ++i)
    		a[i] = hash.get(a[i]);

    	Arrays.fill(BIT, 0);
    	for (int i = 0; i < n; ++i)
    	{
    		cur += i - sum(a[i], BIT);
    		add(a[i], 1, BIT);
    	}
    	
    	Arrays.fill(BIT, 0);
    	Arrays.fill(BIT1, 0);
    	
    	for (int i = 0; i < n; ++i)
    		add(a[i], 1, BIT1);
    	
    	int pointer = 0;
    	long ans = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if (pointer > i)
    		{
    			cur += i - sum(a[i], BIT);
    			cur += sum(a[i]-1, BIT1);
    		}
    		else
    		{
    			++pointer;
    			add(a[i], -1, BIT1);
    		}
    		
    		add(a[i], 1, BIT);
    		
    		while (pointer < n && cur > k)
    		{
    			add(a[pointer], -1, BIT1);
    			
    			cur -= i+1 - sum(a[pointer], BIT);
    			cur -= sum(a[pointer]-1, BIT1);
    			
    			++pointer;
    		}
    		
    		ans += n - pointer;
    	}
    	
    	writer.println(ans);
    }

    public static void main(String[] args) {
        new CF136E().run();
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