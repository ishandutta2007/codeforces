import java.io.*;
import java.util.*;

public class P460C {
	
	static int n, m, w;
	static int[] flowers;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		flowers = new int[n];
		for (int i = 0; i < n; i++) {
			flowers[i] = Integer.parseInt(st.nextToken());
		}
		// binary search
		int hi = 1000100000;
		int lo = 0;
		int mid;
		while (hi != lo) {
			mid = (int) Math.ceil((hi + lo) / 2.0);
			if (checkWorking(mid)) {
				lo = mid;
			}
			else {
				hi = mid - 1;
			}
		}
		out.println(hi);
		out.flush();
		System.exit(0);
	}
	
	static boolean checkWorking(int ans) {
		int[] water = new int[n];
		int days = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i >= w) {
				res -= water[i - w];
			}
			int diff = ans - (flowers[i] + res);
			if (diff > 0) {
				days += diff;
				res += diff;
				water[i] = diff;
			}
			if (days > m) {
				return false;
			}
		}
		return true;
	}
	
	static int check(int mid, int[] a, int n, int m, int w) {
		int i;
		long res = 0, sum = 0;
		long[] b = new long[n];
		for (i = 0; i < n; i++) {
			if (i >= w) {
				res -= b[i - w];
			}
			if (a[i] + res < mid) {
				b[i] = mid - res - a[i];
				res += b[i];
				sum += b[i];
			}
		}

		if (sum < m)
			return 1;
		else if (sum == m)
			return 0;
		else
			return -1;
	}
}