import java.io.*;
import java.util.*;

public class C {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long sum = Long.parseLong(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] dice = new int[n];
		long max = 0;
		for (int i = 0; i < n; i++) {
			dice[i] = Integer.parseInt(st.nextToken());
			max += dice[i];
		}
		for (int i = 0; i < n; i++) {
			long thisMax = sum - (n - 1);
			long thisMin = sum - (max - dice[i]);
			if (thisMax > dice[i]) thisMax = dice[i];
			if (thisMin < 1) thisMin = 1;
			out.print(dice[i] - (thisMax - thisMin + 1));
			if (i != n - 1) {
				out.print(' ');
			}
		}
		out.println();
		out.flush();
		System.exit(0);
	}

}