import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskD implements Runnable {
	
	char str[];
	int most, n;
	final int MOD = 1000000003, MUL = 37;
	int hash[], rhash[];
	long power[];
	
	private long key(int l, int r)
	{
		long ret = (hash[r + 1] - hash[l] * power[r - l + 1]) % MOD;
		if (ret < 0) ret += MOD;
		return ret;
	}
	
	private long rkey(int l, int r)
	{
		long ret = (rhash[r + 1] - rhash[l]) % MOD;
		if (ret < 0) ret += MOD;
		return ret;
	}
	
	private boolean par(int l, int r)
	{
		if (l < 0) return false;
		
		int mid = (l + r) >> 1, len = r - l + 1;
		if (len % 2 == 1)
			return key(l, mid) * power[mid] % MOD == rkey(mid, r);
		return key(l, mid) * power[mid+1]  % MOD== rkey(mid+1, r);
	}

    private void solve() throws IOException {
    	most = nextInt();
    	String s = nextToken();
    	str = s.toCharArray();
    	n = s.length();
    	
    	hash = new int[n + 1];
    	rhash = new int[n + 1];
    	power = new long[n + 1];
    	
    	hash[0] = 0;
    	rhash[0] = 0;
    	power[0] = 1;
    	for (int i = 1; i <= n; ++i)
    		power[i] = power[i-1] * MUL % MOD;
    	
    	int where = n-1;
    	for (int i = 0; i < n; ++i)
    	{
    		hash[i+1] = (int)((hash[i] * (long)MUL + (str[i] - 'a')) % MOD);
    		rhash[i+1] = (int)((rhash[i] + power[i] * (str[i] - 'a')) % MOD);

    		if (par(i - most + 1, i) || par(i - most, i))
    		{
    			where = i;
    			break;
    		}
    	}
    	
    	while (where >= 0)
    	{
    		boolean ok = false;
    		for (char i = (char) (str[where] + 1); !ok && i <= 'z'; ++i)
    		{    			
    			hash[where+1] = (int)((hash[where] * (long)MUL + (i - 'a')) % MOD);
        		rhash[where+1] = (int)((rhash[where] + power[where] * (i - 'a')) % MOD);
    			str[where] = i;
    			
    			ok = true;
        		if (par(where - most + 1, where) || par(where - most, where))
        			ok = false;
    		}
    		
    		if (ok) break;
    		--where;
    	}
    	
    	if (where < 0)
    	{
    		writer.println("Impossible");
    		return;
    	}
    	
    	for (int p = where+1; p < n; ++p)
    	{
    		for (char i = 'a'; i <= 'z'; ++i)
    		{
    			hash[p+1] = (int)((hash[p] * (long)MUL + (i - 'a')) % MOD);
        		rhash[p+1] = (int)((rhash[p] + power[p] * (i - 'a')) % MOD);
    			str[p] = i;
    			
        		if (!par(p - most + 1, p) && !par(p - most, p))
        			break;
    		}
    	}
    	
    	writer.println(String.valueOf(str));
    }

    public static void main(String[] args) {
        new TaskD().run();
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