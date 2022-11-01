import java.util.*;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main implements Runnable {
	
	class Point
	{
		public int x, y;
		Point (int x, int y)
		{
			this.x = x;
			this.y = y;
		}
	}
	
	static ConcurrentLinkedQueue<Point> queue;
	String map[];
	int n, m;

    public static void main(String[] args) {
        new Main().run();
    }
    
    public void solve() throws Exception
    {
    	n = nextInt();
    	m = nextInt();
    	map = new String[n];  
    	
    	for (int i = 0; i < n; ++i)
    		map[i] = nextToken();
    	
    	boolean v[][] = new boolean[n][m];
    	int x[][] = new int[n][m], y[][] = new int[n][m];
    	
    	int sx = -1, sy = -1;
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < m; ++j)
    			if (map[i].charAt(j) == 'S')
    			{
    				sx = i;
    				sy = j;
    			}
    	
    	if (sx == -1 || sy == -1) throw new Exception();
    	
    	queue = new ConcurrentLinkedQueue<Point>();
    	v[sx][sy] = true;
    	x[sx][sy] = sx;
    	y[sx][sy] = sy;
    			
    	queue.offer(new Point(sx, sy));
    	
    	int dx[] = {-1, 1, 0, 0},
    		dy[] = {0, 0, -1, 1};
    	
    	while (!queue.isEmpty())
    	{
    		Point now = queue.poll();
    		
    		for (int k = 0; k < 4; ++k)
    		{
    			int nx = now.x + dx[k],
    				ny = now.y + dy[k];
    			
    			nx = (nx % n + n) % n;
    			ny = (ny % m + m) % m;
    			
    			if (map[nx].charAt(ny) == '#')
    				continue;
    			
    			if (!v[nx][ny])
    			{
    				v[nx][ny] = true;
    				x[nx][ny] = now.x + dx[k];
    				y[nx][ny] = now.y + dy[k];
    				queue.offer(new Point(now.x + dx[k], now.y + dy[k]));
    			}
    			else
    			{
    				if (!(now.x+dx[k] == x[nx][ny] && now.y+dy[k] == y[nx][ny]))
    				{
    					writer.println("Yes");
    					return;
    				}
    			}
    		}
    	}
    	
    	writer.println("No");
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