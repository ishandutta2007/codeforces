import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class TaskE implements Runnable {
	Edge first[];
	
	class Point implements Comparable<Point>
	{
		int u, v;
		long w;
		
		Point(int u, int v, long w)
		{
			this.u = u;
			this.v = v;
			this.w = w;
		}
		
		@Override
		public int compareTo(Point o) {
			// TODO Auto-generated method stub
			if (w < o.w) return -1;
			return 1;
		}
	}

	class Edge
	{
		int to, w;
		Edge next;
		
		public Edge(int from, int to, int w) {
			this.to = to;
			this.w = w;
			this.next = first[from];
		}
	}
	
	class UnionFindSet
	{
		int father[];
		int n;
		
		UnionFindSet(int n)
		{
			this.n = n;
			father = new int[n];
			for (int i = 0; i < n; ++i)
				father[i] = i;
		}
		
		int get(int u)
		{
			if (father[u] == u)
				return u;
			
			return father[u] = get(father[u]);
		}
		
		boolean same(int u, int v)
		{
			return get(u) == get(v);
		}
		
		void union(int u, int v)
		{
			father[get(u)] = get(v);
		}
	}

    private void solve() throws IOException 
    {
    	int n, m;
    	n = nextInt();
    	m = nextInt();
    	
    	boolean key[] = new boolean[n];
    	first = new Edge[n];
    	Point kru[] = new Point[m]; 
    	for (int u, v, w, i = 0; i < m; ++i)
    	{
    		u = nextInt();
    		v = nextInt();
    		w = nextInt();
    		
    		--u; --v;
    		first[u] = new Edge(u, v, w);
    		first[v] = new Edge(v, u, w);
    		
    		kru[i] = new Point(u, v, w);
    	}
    	
    	int[] index = new int[n];
    	int totalkey = nextInt();
    	for (int u, i = 0; i < totalkey; ++i)
    	{
    		u = nextInt();
    		key[u - 1] = true;
    		index[u - 1] = i;
    	}
    	
    	long distance[] = new long[n];
    	int from[] = new int[n];
    	boolean inqueue[] = new boolean[n];
    	
    	Queue<Integer> queue = new LinkedList<Integer>();
    	
    	for (int i = 0; i < n; ++i)
    	{
    		from[i] = -1;
    		
    		if (!key[i])
    			distance[i] = 1l << 60l;
    		else 
    		{
    			queue.offer(i);
    			inqueue[i] = true;
    			distance[i] = 0;
    			from[i] = i;
    		}
    		
    	}
    	
    	while (!queue.isEmpty())
    	{
    		int front = queue.poll();
    		inqueue[front] = false;
    		
    		for (Edge e = first[front]; e != null; e = e.next)
    			if (distance[e.to] > distance[front] + e.w)
    			{
    				distance[e.to] = distance[front] + e.w;
    				from[e.to] = from[front];
    				if (!inqueue[e.to])
    				{
    					queue.offer(e.to);
    					inqueue[e.to] = true;
    				}
    			}
    	}
    	
    	for (Point pt : kru)
    	{
    		pt.w += distance[pt.u] + distance[pt.v];
    		pt.u = index[from[pt.u]];
    		pt.v = index[from[pt.v]];
    	}
    	
    	Arrays.sort(kru);
    	
    	long answer = distance[0];
    	UnionFindSet set = new UnionFindSet(totalkey);
    	
    	for (Point pt : kru)
    	{
    		if (set.same(pt.u, pt.v))
    			continue;
    		
    		answer += pt.w;
    		set.union(pt.u, pt.v);
    	}
    	
    	writer.println(answer);
    }

    public static void main(String[] args) {
        new TaskE().run();
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