import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
	
	int n;

	Edge node[];
	int amount[],total[],x[],y[],father[];
	
	class Edge
	{
		int to;
		Edge next;
		Edge(int from, int to)
		{
			this.to = to;
			this.next = node[from];
			node[from] = this;
		}
	}
	
	private void gao(int u,int Fa)
	{
		amount[u] = 1;
		total[u] = x[u];
		father[u] = Fa; 
		for (Edge e = node[u];e != null; e = e.next)
			if (e.to != Fa) 
			{
				gao(e.to, u);
				amount[u] += amount[e.to];
				total[u] += total[e.to]; 
			}
	}
	
    private void solve() throws IOException {
    	n = nextInt();
    	node = new Edge[n];
    	amount = new int[n];
    	total = new int[n];
    	x = new int[n];
    	y = new int[n];
    	father = new int[n];
    	for (int a,b,i = 0;i < n-1;++i)
    	{
    		a = nextInt();
    		b = nextInt();
    		new Edge(a-1, b-1);
    		new Edge(b-1, a-1);
    	}
    	long X = 0, Y = 0;
    	for (int i = 0;i < n;++i)
    	{
    		x[i] = nextInt();
    		X += x[i];
    		y[i] = nextInt();
    		Y += y[i];
    	}
    	
    	gao(0, -1);
    	double answer = 0;
    	for (int i = 0;i < n;++i)
    	{
    		for (Edge e = node[i]; e != null; e = e.next)
    		{
    			if (e.to == father[i]) continue;
    			answer += y[i] * 1.0 / Y * (amount[e.to]) * (total[e.to]) / X;
    		}
    		if (father[i] != -1)
    		{
    			answer += y[i] * 1.0 / Y * (n - amount[i]) * (X - total[i]) / X; 
    		}
    	}
    	System.out.printf("%.10f\n", answer);
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