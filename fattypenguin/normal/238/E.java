import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class CF148E implements Runnable {
	
	private Edge first[];
	private boolean vis[];
	int ban;
	
	class Edge
	{
		Edge next;
		int u, v;
		
		Edge()
		{
			
		}
		
		Edge(int from, int to)
		{
			u = from;
			v = to;
			next = first[from];
			first[from] = this;
		}
	}
	
	boolean memo[][];
	int dp[][];
	ArrayList<Integer> keyPoint[][];
	
    private void solve() throws IOException {
    	int n, m, a, b;
    	n = nextInt();
    	m = nextInt();
    	a = nextInt();
    	b = nextInt();
    	--a;
    	--b;
    	ban = -1;
    	first = new Edge[n];
    	vis = new boolean[n];
    	
    	final int INF = 0x3f3f3f3f;
    	
    	int dis[][] = new int[n][n];
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < n; ++j)
    			dis[i][j] = i != j ? INF : 0;
    	
    	for (int u, v, i = 0; i < m; ++i)
    	{
    		u = nextInt();
    		v = nextInt();
    		--u;
    		--v;
    		dis[u][v] = 1;
    		new Edge(u, v);
    	}
    	
    	for (int k = 0; k < n; ++k)
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < n; ++j)
    				dis[i][j] = Math.min(dis[i][j], dis[i][k] + dis[k][j]);

		keyPoint = new ArrayList[n][n];
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < n; ++j)
    		{
    			keyPoint[i][j] = new ArrayList<Integer>();
    			if (dis[i][j] >= INF) continue;
    			
    			for (Edge e = first[i]; e != null; e = e.next)
    				if (dis[i][j] == 1 + dis[e.v][j])
    					keyPoint[i][j].add(e.v);
    		}
    	
    	int k = nextInt();
    	
    	@SuppressWarnings("unchecked")
		ArrayList<Integer> stopFrom[] = new ArrayList[n];
    	for (int i = 0; i < n; ++i)
    		stopFrom[i] = new ArrayList<Integer>();
    	
    	for (int s, t, i = 0; i < k; ++i)
    	{
    		s = nextInt();
    		t = nextInt();
    		--s;
    		--t;
    		if (dis[s][t] >= INF) continue;
    		
    		int disCount[] = new int[n];
    		int stand[] = new int[n];
    		
    		for (int j = 0; j < n; ++j)
    			if (dis[s][j] + dis[j][t] == dis[s][t])
    			{
    				++disCount[dis[s][j]];
    				stand[dis[s][j]] = j;
    			}
    		
    		for (int j = 0; j < n; ++j)
    			if (disCount[j] == 1)
    				stopFrom[stand[j]].add(t);
    	}
    	
    	dp = new int[n][n];
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < n; ++j)
    			dp[i][j] = INF;
    	
    	int change[] = new int[n];
    	for (int i = 0; i < n; ++i)
    		change[i] = INF;
    	
    	change[b] = 0;
    	
    	for (int iter = 0; iter <= n; ++iter)
    	{
    		for (int i = 0; i < n; ++i)
    			for (int next : stopFrom[i])
    				change[i] = Math.min(change[i], dp[i][next] + 1);
    		
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < n; ++j)
    				dp[i][j] = Math.min(dp[i][j], change[i]);

    		memo = new boolean[n][n];
    		for (int i = 0; i < n; ++i)
    			for (int j = 0; j < n; ++j)
    				if (!memo[i][j] && dis[i][j] < INF)
    					go(i, j);

    	}
		
    	if (change[a] >= INF)
    		change[a] = -1;
    	
    	writer.println(change[a]);
    }

    private int go(int i, int j) {
		// TODO Auto-generated method stub
		if (i == j) return dp[i][j];
		if (memo[i][j]) return dp[i][j];
		memo[i][j] = true;
		
		int max = 0;
		for (int step : keyPoint[i][j])
			max = Math.max(max, go(step, j));
		dp[i][j] = Math.min(max, dp[i][j]);
		return dp[i][j];			
	}

	public static void main(String[] args) {
        new CF148E().run();
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