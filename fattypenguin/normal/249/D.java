import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class TaskD implements Runnable {
	
    private void solve() throws IOException {
    	/*
    	 * 
    	 * (X, Y) * (b, a) > 0
    	 * aX - bY > 0
    	 * a(x - x0) - b(y - y0) > 0
    	 * ax - by > ax0 - by0 (1)
    	 *
    	 * (X, Y) * (c, d) < 0
    	 * cX - dY < 0
    	 * cx - dy < cx0 - dy0
    	 * dy - cx > dy0 - cx0 (2)
    	 * 
    	 */
    	
    	int n = nextInt();
    	Point points[] = new Point[n];
    	String frac = nextToken();
    	String num[] = frac.split("/");
    	int c = Integer.parseInt(num[0]);
    	int d = Integer.parseInt(num[1]);
    	frac = nextToken();
    	num = frac.split("/");
    	int a = Integer.parseInt(num[0]);
    	int b = Integer.parseInt(num[1]);
    	
    	long diffY[] = new long[n];
    	
    	for (int i = 0; i < n; ++i) {
    		long x, y;
    		x = nextInt();
    		y = nextInt();
    		points[i] = new Point(a * x - b * y, d * y - c * x);
    		diffY[i] = points[i].y;
    	}
    	
    	Arrays.sort(points);
    	
    	Order order = new Order(diffY);
    	int diffSize = order.size();
    	BitIndexedTree bit = new BitIndexedTree(diffSize);
    	
    	int dp[] = new int[n];
    	int ans = 0;
    	for (int i = 0; i < n; ) {
    		int j = i;
    		
    		for (; j < n && points[i].x == points[j].x; ++j) {
        		if (points[j].x > 0 && points[j].y > 0) {
        			dp[j] = bit.getMax(order.getIndex(points[j].y) - 1) + 1;
        		}
        		
        		ans = Math.max(ans, dp[j]);
    		}
    		
    		j = i;
    		
    		for (; j < n && points[i].x == points[j].x; ++j) {
        		if (points[j].x > 0 && points[j].y > 0) {
        			bit.update(order.getIndex(points[j].y), dp[j]);
        		}
    		}
    		
    		i = j;
    		
    	}
    	
    	writer.println(ans);
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

class BitIndexedTree {
	private int arr[];
	private int size;
	
	BitIndexedTree(int size) {
		this.size = size;
		arr = new int[size + 1];
	}
	
	private int lowbit(int x) {
		return x & -x;
	}
	
	public void update(int x, int y) {
		++x;
		
		while (x <= size) {
			arr[x] = Math.max(arr[x], y);
			x += lowbit(x);
		}
	}
	
	public int getMax(int x) {
		++x;
		
		int ret = 0;
		while (x > 0) {
			ret = Math.max(ret, arr[x]);
			x -= lowbit(x);
		}
		
		return ret;
	}
}

class Point implements Comparable<Point> {
	public long x, y;
	
	Point(long x, long y) {
		this.x = x;
		this.y = y;
	}
	
	private static int sign(long x) {
		if (x < 0) {
			return -1;
		}
		
		if (x > 0) {
			return 1;
		}
		
		return 0;
	}
	
	@Override
	public int compareTo(Point arg0) {
		// TODO Auto-generated method stub
		if (x != arg0.x) {
			return sign(x - arg0.x);
		}
		
		return sign(y - arg0.y);
	}
}

class Order { 
	
	private long arr[];
	
	Order(long orig[]) {
		long temp[] = orig.clone();
		Arrays.sort(temp);
		
		int total = 1;
		for (int i = 1; i < temp.length; ++i)
			if (temp[i] != temp[i - 1])
				++total;
		
		arr = new long[total];
		arr[0] = temp[0];
		total = 1;
		for (int i = 1; i < temp.length; ++i)
			if (temp[i] != temp[i - 1])
				arr[total++] = temp[i];
	}
	
	public int size() {
		return arr.length;
	}
	
	public long get(int x) {
		return arr[x];
	}
	
	public int getIndex(long x) {
		return Arrays.binarySearch(arr, x);
	}
}