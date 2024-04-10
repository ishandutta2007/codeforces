import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class CF125E implements Runnable {
	
	Point base;
	
	public long dis(Point a, Point b)
	{
		return (a.x - b.x)*(a.x - b.x) +
				(a.y - b.y)*(a.y - b.y);
	}
	
	class Point implements Comparable
	{
		public long x, y;
		public int m, p, r;
		
		public void read() throws IOException
		{
			x = nextInt();
			y = nextInt();
			m = nextInt();
			p = nextInt();
			r = nextInt();
		}

		@Override
		public int compareTo(Object o) {
			// TODO Auto-generated method stub
			Point op = (Point)o;
			if (dis(this, base) < dis(op, base)) return -1;
			return 1;
		}
	}
	
	Point pt[];
	
	class Point2D
	{
		int x, y;
		
		Point2D(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
	
	long distance[];
	int minm[], where[];
	
	private void update(int x)
	{
		int y = x * 2;
		if (minm[y] > minm[y+1])
			++y;
		
		minm[x] = minm[y];
		where[x] = where[y];
	}
	
	private void buildIntervalTree(int left, int right, int x)
	{
		if (left == right)
		{
			minm[x] = pt[left].m;
			where[x] = left;
		}
		else
		{
			int mid = (left + right) >> 1;
			buildIntervalTree(left, mid, x*2);
			buildIntervalTree(mid+1, right, x*2 + 1);
			update(x);
		}
	}
	
	private Point2D intervalMin(int left, int right, int l, int r, int x)
	{
		if (l <= left && r >= right)
			return new Point2D(minm[x], where[x]);
		int mid = (left + right) >> 1;
		Point2D ret = new Point2D(0x7f7f7f7f, 0);
		if (l <= mid) ret = intervalMin(left, mid, l, r, x*2);
		if (r > mid)
		{
			Point2D rret = intervalMin(mid+1, right, l, r, x*2+1);
			if (rret.x < ret.x)
				ret = rret;
		}
		return ret;
	}
	
	private void turnOff(int left, int right, int aim, int x)
	{
		if (left == right)
		{
			minm[x] = 0x7f7f7f7f;
			return;
		}
		int mid = (left + right) >> 1;
		if (aim <= mid)
			turnOff(left, mid, aim, x*2);
		else turnOff(mid+1, right, aim, x*2+1);
		update(x);
	}
	

    private void solve() throws IOException {
    	base = new Point();
    	
    	base.x = nextInt();
    	base.y = nextInt();
    	base.p = nextInt();
    	base.r = nextInt();
    	
    	int n = nextInt();
    	pt = new Point[n];
    	
    	for (int i = 0; i < n; ++i)
    	{
    		pt[i] = new Point();
    		pt[i].read();
    	}
    	
    	Arrays.sort(pt);
    	
    	distance = new long[n];
    	for (int i = 0; i < n; ++i)
    		distance[i] = dis(base, pt[i]);
    	
    	minm = new int[n * 4 + 1];
    	where = new int[n * 4 + 1];
    	
    	buildIntervalTree(0, n-1, 1);
    	
    	Queue<Point> queue = new LinkedList<Point>();
    	queue.offer(base);
    	
    	int ans = 0;
    	while (!queue.isEmpty())
    	{
    		Point front = queue.poll();
    		long key = front.r * (long)front.r;
    		
    		++ans;
    		
    		int left = 0, right = n-1;
    		while (left < right)
    		{
    			int mid = (left + right) >> 1;
    		
    			if (distance[mid] > key)
    				right = mid;
    			else left = mid+1;
    		}
    		
    		if (distance[left] <= key) ++left;
    		
    		int index = left;
    		if (index == 0)
    			continue;
    		
    		while (true)
    		{
    			Point2D result = intervalMin(0, n-1, 0, index-1, 1);
    			if (result.x > front.p) break;
    			queue.offer(pt[result.y]);
    			turnOff(0, n-1, result.y, 1);
    		}
    	}
    	
    	writer.println(ans-1);
    }

    public static void main(String[] args) {
        new CF125E().run();
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