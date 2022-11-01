import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
        
    private void solve() throws IOException {
    	int n = nextInt();
    	int a[] = new int[n];
    	for (int i = 0;i < n;++i)
    		a[i] = nextInt();
    	Arrays.sort(a);
    	int ans = 0;
    	for (int i = 0;i < n;++i)
    	{
    		boolean aa = false;
    		for (int j = 0;j < n;++j)
    			if (a[j]==i+1) aa=true;
    		if (!aa) ++ans;
    	}
    	writer.println(ans);
    	
    }

    public static void main(String[] args) {
        new Main().run();
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