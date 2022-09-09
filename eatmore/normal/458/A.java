import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.arraycopy;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Number {
		int digits[], dot;
		
		Number(String s) {
			digits = new int[s.length()];
			for (int i = 0; i < s.length(); i++) {
				digits[i] = s.charAt(s.length() - i - 1) - '0';
			}
			dot = 0;
			optimize();
		}
		
		void alloc(int pos) {
			if (dot + pos >= digits.length) {
				int l = digits.length;
				while (dot + pos >= l) {
					l <<= 1;
				}
				digits = Arrays.copyOf(digits, l);
			}
			if (dot + pos < 0) {
				int l = digits.length;
				while (dot + pos + l - digits.length < 0) {
					l <<= 1;
				}
				int newDigits[] = new int[l];
				arraycopy(digits, 0, newDigits, l - digits.length, digits.length);
				dot += l - digits.length;
				digits = newDigits;
			}
		}
		
		int get(int pos) {
			if (dot + pos < 0 || dot + pos >= digits.length) {
				return 0;
			}
			return digits[dot + pos];
		}
		
		void add(int pos, int val) {
			alloc(pos);
			digits[dot + pos] += val;
		}
		
		void checkBad(int from, int to, List<Integer> badpos) {
			for (int pos = from; pos <= to; pos++) {
				if (get(pos) >= 2 || (get(pos) >= 1 && get(pos + 1) >= 1)) {
					badpos.add(pos);
				}
			}
		}
		
		void optimize() {
			List<Integer> badpos = new ArrayList<>();
			checkBad(-dot, digits.length - dot - 1, badpos);
			while (!badpos.isEmpty()) {
				int i = badpos.remove(badpos.size() - 1);
				if (get(i) >= 2) {
					add(i, -2);
					add(i + 1, 1);
					add(i - 2, 1);
					checkBad(i - 3, i + 1, badpos);
				} else if (get(i) >= 1 && get(i + 1) >= 1) {
					add(i, -1);
					add(i + 1, -1);
					add(i + 2, 1);
					checkBad(i - 1, i + 2, badpos);
				}
			}
		}
	}
	
	static void solve() throws Exception {
		Number a = new Number(next());
		Number b = new Number(next());
		for (int i = max(a.digits.length - a.dot - 1, b.digits.length - b.dot - 1); i >= min(-a.dot, -b.dot); i--) {
			if (a.get(i) != b.get(i)) {
				out.print(a.get(i) > b.get(i) ? '>' : '<');
				return;
			}
		}
		out.print('=');
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