import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static void solve() throws Exception {
		int nos = 0;
		for (int i = 0; i < 10; i++) {
			out.println(i);
			out.flush();
			switch (in.readLine()) {
			case "don't think so":
			case "not bad":
			case "cool":
			case "don't touch me!":
			case "great!":
				out.print("normal");
				return;
			case "are you serious?":
			case "go die in a hole":
			case "worse":
			case "terrible":
			case "don't even":
			case "no way":
				out.print("grumpy");
				return;
			case "no":
				if (++nos > 3) {
					out.print("normal");
					return;
				}
			}
		}

	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}