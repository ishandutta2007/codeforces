import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrB {

	public static long time;
	
	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		a = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) 
			a[i] = Integer.parseInt(st.nextToken());
		int end = end();
		if(end < 0) System.out.println("-1 -1");
		else System.out.println((start(end) + 1) + " " + (end + 1));
		br.close();
		System.exit(0);
	}
	
	static int n, k;
	static int[] a;

	public static int end() throws Exception {
		boolean[] reached = new boolean[100002];
		int rem = k;
		for(int i = 0; i < n; i++) {
			if(!reached[a[i]]) {
				rem--;
				if(rem == 0) return i;
			}
			reached[a[i]] = true;
		}
		return -1;
	}
	
	public static int start(int end) throws Exception {
		boolean[] reached = new boolean[100002];
		int rem = k;
		for(int i = end; i >= 0; i--) {
			if(!reached[a[i]]) {
				rem--;
				if(rem == 0) return i;
			}
			reached[a[i]] = true;
		}
		return 0;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}