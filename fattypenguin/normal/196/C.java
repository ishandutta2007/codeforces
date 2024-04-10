import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.math.*;

public class TaskC implements Runnable {
	
	class Point
	{
		public int x, y;
		Point (int x, int y)
		{
			this.x = x;
			this.y = y;
		}
		
		public Point sub(Point pt)
		{
			return new Point(x - pt.x, y - pt.y);
		}
		
		public long det(Point pt)
		{
			return x * (long)pt.y - y * (long)pt.x;
		}
	}
	
	int n;
	static Point pt[], orig;

	Edge first[];

	class Edge
	{
		int to;
		Edge next;
		
		public Edge(int from, int to) {
			// TODO Auto-generated constructor stub
			this.to = to;
			this.next = first[from];
			//first[from] = this;
		}
	}
	
	private static class CompareClass implements Comparator<Integer>
	{
		@Override
		public int compare(Integer x, Integer y) {
			Point ox = pt[x].sub(orig),
				  oy = pt[y].sub(orig);
			if (ox.det(oy) < 0) return -1;
			return 1;
		}
		
	}
	
	static Comparator<Integer> comp;
	static int put[], size[];
	
	private void go(int x, int father, int left, int right, Integer[] rest)
	{
		int highest = left;
		for (int i = left; i <= right; ++i)
			if (pt[rest[i]].y > pt[rest[highest]].y)
				highest = i;
		
		int temp = rest[left];
		rest[left] = rest[highest];
		rest[highest] = temp;
		
		put[rest[left]] = x;
		
		orig = pt[rest[left]];
		if (left != right)
			Arrays.sort(rest, left+1, right+1, comp);
		
		int cnt = 1;
		
		for (Edge e = first[x]; e != null; e = e.next)
		{
			if (e.to == father) continue;
			go(e.to, x, left+cnt, left + cnt - 1 + size[e.to], rest);
			cnt += size[e.to];
		}
	}
	
	private void predfs(int x, int father)
	{
		size[x] = 1;
		for (Edge e = first[x]; e != null; e = e.next)
		{
			if (e.to == father) continue;
			predfs(e.to, x);
			size[x] += size[e.to];
		}
	}

    private void solve() throws IOException {
    	n = nextInt();
    	first = new Edge[n];
    	pt = new Point[n];
    	
    	for (int x, y, i = 0; i < n-1; ++i)
    	{
    		x = nextInt();
    		y = nextInt();
    		--x; --y;
    		first[x] = new Edge(x, y);
    		first[y] = new Edge(y, x);
    	}
    	
    	for (int x, y, i = 0; i < n; ++i)
    	{
    		x = nextInt();
    		y = nextInt();
    		pt[i] = new Point(x, y);
    	}
    	
    	Integer rest[] = new Integer[n];
    	for (int i = 0; i < n; ++i)
    		rest[i] = i;
    	
    	comp = new CompareClass();
    	
    	put = new int[n];
    	size = new int[n];
    	
    	predfs(0, -1);
    	go(0, -1, 0, n-1, rest);
    	
    	for (int i = 0; i < n; ++i)
    	{
    		if (i > 0) writer.print(" ");
    		writer.print(put[i]+1);
    	}
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