import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class TaskB implements Runnable {
	
	class Point implements Comparable
	{
		int x, y;
		Point()
		{
			
		}
		
		Point(int x, int y)
		{
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Object arg0) {
			// TODO Auto-generated method stub
			Point o = (Point)arg0;
			return x - o.x;
		}
		
		
	}
	
    private void solve() throws IOException {
    	int n = nextInt(), h = nextInt();
    	int a[] = new int[n];
    	for (int i = 0; i < n; ++i)
    		a[i] = nextInt();
    	int ans[] = new int[n];
    	int ans1 = Integer.MAX_VALUE;
    	if (n <= 4)
    	{
    		for (int i = 0; i < (1 << n); ++i)
    		{
    			int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    			for (int j = 0; j < n; ++j)
    				for (int k = 0; k < j; ++k)
    				{
    					int v = 0;
    					if (((i >> k) & 1) != ((i >> j) & 1))
    						v = a[j] + a[k] + h;
    					else v = a[j] + a[k];
    					max = Math.max(max, v);
    					min = Math.min(min, v);
    				}
    			
        		if (max - min < ans1)
        		{
        			ans1 = max - min;
        			for (int j = 0; j < n; ++j)
        				ans[j] = (i >> j) & 1;
        		}
    		}
    	}
    	else
    	{
    		Point pt[] = new Point[n];
    		for (int i = 0; i < n; ++i)
    			pt[i] = new Point(a[i], i);
    		Arrays.sort(pt);
    		int vans = pt[n - 1].x + pt[n - 2].x - pt[0].x - pt[1].x;
    		ans1 = vans;
    		int where = -1;
    		for (int dont = 0; dont < n; ++dont)
    		{
    			int mini = Integer.MAX_VALUE, maxi = Integer.MIN_VALUE;
    			int cur = 0;
    			if (dont == 0)
    				cur = pt[1].x + pt[2].x;
    			else if (dont == 1)
    				cur = pt[0].x + pt[2].x;
    			else cur = pt[0].x + pt[1].x;
    			
    			mini = Math.min(mini, cur);
    			cur = 0;
    			if (dont == n-1)
    				cur = pt[n-2].x + pt[n-3].x;
    			else if (dont == n-2)
    				cur = pt[n-1].x + pt[n-3].x;
    			else cur = pt[n-2].x + pt[n-1].x;
    			
    			maxi = Math.max(maxi, cur);
    			
    			if (dont == 0 || dont == 1)
    				cur = pt[0].x + pt[1].x + h;
    			else cur = pt[0].x + pt[dont].x + h;
    			
    			mini = Math.min(mini, cur);
    			maxi = Math.max(maxi, cur);
    			
    			if (dont == n-1 || dont == n-2)
    				cur = pt[n-1].x + pt[n-2].x + h;
    			else cur = pt[n-1].x + pt[dont].x + h;
    			
				mini = Math.min(mini, cur);
				maxi = Math.max(maxi, cur);
				
				if (maxi - mini < ans1)
				{
					ans1 = maxi - mini;
					where = pt[dont].y;
				}
    		}
    		
    		for (int i = 0; i < n; ++i)
    			if (i == where)
    				ans[i] = 1;
    			else ans[i] = 0;
    	}
    	
    	writer.println(ans1);
    	for (int i = 0; i < n; ++i)
    	{
    		if (i != 0) writer.print(" ");
    		writer.print(ans[i] + 1);
    	}
    	
    	writer.println();
    }

    public static void main(String[] args) {
        new TaskB().run();
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