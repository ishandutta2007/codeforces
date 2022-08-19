import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrC {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}
	
	static Point[] p;
	static boolean[] reached;
	static int numReached;

	public static int go(BufferedReader br) throws Exception {
		int n = Integer.parseInt(br.readLine());
		p = new Point[n];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			p[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		int out = -1;
		reached = new boolean[n];
		numReached = 0;
		for(int i = 0; numReached < n; i++) {
			if(!reached[i]) {
				out ++;
				recurse(i);
			}
		}
		return out;
	}
	
	public static void recurse(int cur) {
		if(reached[cur]) return;
		reached[cur] = true;
		numReached++;
		for(int i = 0; i < p.length; i++) {
			if(!reached[i] && ((p[i].x == p[cur].x) ^ (p[i].y == p[cur].y))) {
				recurse(i);
			}
		}
	}
	
	static class Point {
		public int x, y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}