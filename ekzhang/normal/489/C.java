import java.util.*;
import java.io.*;

public class P489C {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		if ((m != 1 && s == 0) || (s > 9 * m)) {
			out.println("-1 -1");
		}
		else if (m == 1) {
			out.println(s + " " + s);
		}
		else {
			int sumLeft = s;
			// minimum
			sumLeft--;
			int nines = sumLeft / 9;
			int remainder = sumLeft % 9 + 1;
			if (m - 1 - nines > 0) {
				out.print(1);
				remainder--;
			}
			for (int i = 0; i < m - 2 - nines; i++) {
				out.print(0);
			}
			out.print(remainder);
			for (int i = 0; i < nines; i++) {
				out.print(9);
			}
			out.print(' ');
			// maximum
			sumLeft = s;
			nines = sumLeft / 9;
			remainder = sumLeft % 9;
			for (int i = 0; i < nines; i++) {
				out.print(9);
			}
			if (remainder != 0 || m - 1 - nines >= 0) {
				out.print(remainder);
			}
			for (int i = 0; i < m - 1 - nines; i++) {
				out.print(0);
			}
			out.println();
		}
		out.flush();
		System.exit(0);
	}
}