import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {

	static void solve() throws Exception {
		int n = scanInt(), p[] = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = scanInt() - 1;
		}
		int cycle[] = new int[n];
		int cyclePos[] = new int[n + 1];
		int cycleCnt = 0;
		boolean have[] = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (have[i]) {
				continue;
			}
			int pos = cyclePos[cycleCnt];
			for (int j = i; !have[j]; j = p[j]) {
				have[j] = true;
				cycle[pos++] = j;
			}
			cyclePos[++cycleCnt] = pos;
		}
		if (cycleCnt == 1) {
			out.println(n + 1);
			out.println((cycle[0] + 1) + " " + (cycle[1] + 1));
			out.println((cycle[1] + 1) + " " + (cycle[2] + 1));
			out.println((cycle[0] + 1) + " " + (cycle[2] + 1));
			for (int i = 3; i < n; i++) {
				out.println((cycle[1] + 1) + " " + (cycle[i] + 1));
			}
			out.println((cycle[0] + 1) + " " + (cycle[1] + 1));
		} else {
			out.println(n + cycleCnt % 2);
			if (cycleCnt % 2 != 0) {
				out.println((cycle[cyclePos[1]] + 1) + " " + (cycle[cyclePos[2]] + 1));
				out.println((cycle[cyclePos[0]] + 1) + " " + (cycle[cyclePos[1]] + 1));
				for (int j = cyclePos[0] + 1; j < cyclePos[1]; j++) {
					out.println((cycle[cyclePos[1]] + 1) + " " + (cycle[j] + 1));
				}
				out.println((cycle[cyclePos[0]] + 1) + " " + (cycle[cyclePos[1]] + 1));
			}
			for (int i = cycleCnt % 2; i < cycleCnt; i += 2) {
				if (i != 1) {
					out.println((cycle[cyclePos[i]] + 1) + " " + (cycle[cyclePos[i + 1]] + 1));
				}
				for (int j = cyclePos[i + 1] + 1; j < cyclePos[i + 2]; j++) {
					out.println((cycle[cyclePos[i]] + 1) + " " + (cycle[j] + 1));
				}
				for (int j = cyclePos[i] + 1; j < cyclePos[i + 1]; j++) {
					out.println((cycle[cyclePos[i + 1]] + 1) + " " + (cycle[j] + 1));
				}
				out.println((cycle[cyclePos[i]] + 1) + " " + (cycle[cyclePos[i + 1]] + 1));
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