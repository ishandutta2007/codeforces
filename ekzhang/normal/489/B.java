import java.io.*;
import java.util.*;

public class P489B {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[] boys = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			boys[i] = Integer.parseInt(st.nextToken());
		}
		int m = Integer.parseInt(br.readLine());
		int[] girls = new int[m];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			girls[i] = Integer.parseInt(st.nextToken());
		}
		
		// greedy approach
		Arrays.sort(boys);
		Arrays.sort(girls);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (Math.abs(boys[i] - girls[j]) <= 1) {
					ans++;
					girls[j] = 1000;
					break;
				}
			}
		}
		out.println(ans);
		out.flush();
		System.exit(0);
	}

}