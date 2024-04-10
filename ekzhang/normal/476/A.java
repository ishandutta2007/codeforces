import java.io.*;
import java.util.*;

public class P476A {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		final int n = Integer.parseInt(st.nextToken());
		final int m = Integer.parseInt(st.nextToken());
		int min = (int) Math.ceil(1.0 * n / 2);
		int max = n;
		for (int i = min; i <= max; i++) {
			if (i % m == 0) {
				out.println(i);
				break;
			}
			if (i == max) {
				out.println(-1);
			}
		}
		out.flush();
		System.exit(0);
	}

}