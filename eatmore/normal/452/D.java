import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class D {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static void solve() throws Exception {
		int k = nextInt();
		int n1 = nextInt();
		int n2 = nextInt();
		int n3 = nextInt();
		int t1 = nextInt();
		int t2 = nextInt();
		int t3 = nextInt();
		Queue<Integer> q1 = new ArrayDeque<>();
		Queue<Integer> q2 = new ArrayDeque<>();
		Queue<Integer> q3 = new ArrayDeque<>();
		int time = 0;
		while (k > 0) {
			while (q1.size() == n1 || q2.size() == n2 || q3.size() == n3) {
				int v1 = q1.isEmpty() ? Integer.MAX_VALUE : q1.element();
				int v2 = q2.isEmpty() ? Integer.MAX_VALUE : q2.element();
				int v3 = q3.isEmpty() ? Integer.MAX_VALUE : q3.element();
				time = min(min(v1, v2), v3);
				while (!q1.isEmpty() && q1.element() <= time) {
					q1.remove();
				}
				while (!q2.isEmpty() && q2.element() <= time) {
					q2.remove();
				}
				while (!q3.isEmpty() && q3.element() <= time) {
					q3.remove();
				}
			}
			q1.add(time + t1);
			q2.add(time + t2);
			q3.add(time + t3);
//			System.err.println(time);
			--k;
		}
		out.print(time + t1 + t2 + t3);
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}