import java.util.*;
import java.io.*;

public class P368B {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] ar = new int[n];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			ar[i] = Integer.parseInt(st.nextToken());
		}
		boolean[] seen = new boolean[100000 + 1];
		int[] dp = new int[n];
		dp[n - 1] = 1;
		seen[ar[n - 1]] = true;
		for (int i = n - 2; i >= 0; i--) {
			dp[i] = dp[i + 1];
			if (!seen[ar[i]]) {
				dp[i]++;
				seen[ar[i]] = true;
			}
		}
		for (int i = 0; i < m; i++) {
			out.println(dp[Integer.parseInt(br.readLine()) - 1]);
		}
		out.flush();
		System.exit(0);
	}
}