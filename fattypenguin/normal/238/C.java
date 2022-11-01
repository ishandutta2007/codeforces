import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class TaskC implements Runnable {
	
	private Edge first[];
	private boolean vis[];
	
	class Edge
	{
		Edge next;
		int u, v;
		boolean rev;
		
		Edge()
		{
			
		}
		
		Edge(int from, int to, boolean dir)
		{
			u = from;
			v = to;
			rev = dir;
			next = first[from];
			first[from] = this;
		}
	}
	
	private int left[], right[];
	private int f[], g[];
	
	private void dp1(int u)
	{
		vis[u] = true;
		f[u] = g[u] = 0;
		for (Edge e = first[u]; e != null; e = e.next)
			if (!vis[e.v])
			{
				dp1(e.v);
				f[u] += f[e.v];
				if (e.rev) ++f[u];
			}
	}
	
	private void dp2(int u)
	{
		vis[u] = true;
		int t = g[u];
		g[u] += f[u];
		
		for (Edge e = first[u]; e != null; e = e.next)
			if (!vis[e.v])
			{
				t += f[e.v];
				if (e.rev) ++t;
			}
		
		for (Edge e = first[u]; e != null; e = e.next)
			if (!vis[e.v])
			{
				int cur = f[e.v];
				if (e.rev) ++cur; 
				g[e.v] = t - cur;
				if (!e.rev)
					++g[e.v];
			}
		
		for (Edge e = first[u]; e != null; e = e.next)
			if (!vis[e.v])
			{
				dp2(e.v);
			}
	}
	
	private int gao(int u)
	{
		boolean bak[] = vis.clone();
		dp1(u);
		vis = bak.clone();
		dp2(u);
		
		int ret = g[u];
	//	for (int i = 0; i < g.length; ++i)
	//		System.out.println(vis[i] + " " + f[i] + " " + g[i]);
	//	System.out.println("--------------------");
		for (int i = 0; i < g.length; ++i)
			if (i == u || vis[i] && !bak[i])
				ret = Math.min(ret,  g[i]);
		return ret;
	}
	
    private void solve() throws IOException {
    	int n = nextInt();
    	first = new Edge[n];
    	left = new int[n];
    	right = new int[n];
    	f = new int[n];
    	g = new int[n];
    	vis = new boolean[n];
    	for (int i = 0; i < n - 1; ++i)
    	{
    		int u, v;
    		u = nextInt();
    		v = nextInt();
    		--u;
    		--v;
    		left[i] = u;
    		right[i] = v;
    		new Edge(u, v, false);
    		new Edge(v, u, true);
    	}
    	
    	int ans = -1;
    	if (n == 1) ans = 0;
    	for (int i = 0; i < n - 1; ++i)
    	{
    		Arrays.fill(vis, false);
    		vis[left[i]] = vis[right[i]] = true;
    		int v = gao(left[i]) + gao(right[i]);
    //		System.out.println("i = " + i + " ans = " + v);
    		if (ans == -1 || v < ans) 
    			ans = v;
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