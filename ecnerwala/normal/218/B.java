import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PrB {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br, System.out);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br, PrintStream out) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] planes = new int[m];
		for(int i = 0; i < m; i++) planes[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(planes);
		out.println(max(planes, n, m) + " " + min(planes, n, m));
	}
	
	public static int max(int[] planes, int n, int m) {
		int out = 0;
		int[] seats = new int[1001];
		for(int i = 1; i <= 1000; i++) {
			int numSeats = Arrays.binarySearch(planes, i);
			if(numSeats >= 0) {
				while(numSeats > 0 && planes[numSeats - 1] == planes[numSeats]) numSeats--;
			} else {
				numSeats = -1 - numSeats;
			}
			seats[i] = m - numSeats;
		}
		for(int i = 1000; n > 0; i--) {
			int s = seats[i];
			if(s > n) {
				out += n * i;
				n = 0;
			} else {
				out += s * i;
				n -= s;
			}
		}
		return out;
	}
	
	public static int min(int[] planes, int n, int m) {
		int out = 0;
		for(int i = 0; n > 0; i++) {
			int p = planes[i];
			if(p > n) {
				out += (p + p - n + 1) * (n) / 2;
				n = 0;
			} else {
				out += (p + 1) * (p) / 2;
				n -= p;
			}
		}
		return out;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}