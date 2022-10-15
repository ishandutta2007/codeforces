import java.util.*;
import java.io.*;

public class P400A {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		final int[] divisors = {1, 2, 3, 4, 6, 12};
		int n = Integer.parseInt(br.readLine());
		for (int t = 0; t < n; t++) {
			String s = br.readLine();
			boolean[] working = new boolean[6];
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < divisors[i]; j ++) {
					boolean colWorks = true;
					for (int k = j; k < 12; k += divisors[i]) {
						if (s.charAt(k) == 'O') {
							colWorks = false;
							break;
						}
					}
					if (colWorks) {
						working[i] = true;
						break;
					}
				}
			}
			int num = 0;
			for (boolean b : working) {
				if (b) num++;
			}
			out.print(num);
			for (int i = 5; i >= 0; i--) {
				if (working[i]) {
					out.printf(" %dx%d", 12 / divisors[i], divisors[i]);
				}
			}
			out.println();
		}
		out.flush();
		System.exit(0);
	}
	
}