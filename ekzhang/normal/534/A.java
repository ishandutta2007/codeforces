import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		if (n >= 5) {
			out.println(n);
			for (int i = 1; i <= n; i += 2) {
				out.print(i);
				out.print(' ');
			}
			for (int i = 2; i <= n; i += 2) {
				out.print(i);
				if (n - i > 1) {
					out.print(' ');
				}
				else {
					out.println();
				}
			}
		}
		else if (n <= 2) {
			out.println("1\n1");
		}
		else if (n == 3) {
			out.println("2\n1 3");
		}
		else { // n == 4
			out.println("4\n2 4 1 3");
		}
		out.flush();
		System.exit(0);
	}

}