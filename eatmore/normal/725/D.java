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
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static class Team {
		final long t, w;

		public Team(long t, long w) {
			this.t = t;
			this.w = w;
		}
	}

	static void solve() throws Exception {
		int n = nextInt();
		PriorityQueue<Team> higherTeams = new PriorityQueue<>(new Comparator<Team>() {
			public int compare(Team o1, Team o2) {
				return Long.compare(o1.w - o1.t, o2.w - o2.t);
			}
		});
		PriorityQueue<Team> lowerTeams = new PriorityQueue<>(new Comparator<Team>() {
			public int compare(Team o1, Team o2) {
				return Long.compare(o2.t, o1.t);
			}
		});
		long myT = nextLong();
		nextLong();
		for (int i = 0; i < n - 1; i++) {
			Team t = new Team(nextLong(), nextLong());
			(t.t > myT ? higherTeams : lowerTeams).add(t);
		}
		int ans = higherTeams.size();
		while (!higherTeams.isEmpty()) {
			Team t = higherTeams.remove();
			if (t.w + 1 - t.t > myT) {
				break;
			}
			myT -= t.w + 1 - t.t;
			while (!lowerTeams.isEmpty()) {
				t = lowerTeams.remove();
				if (t.t <= myT) {
					lowerTeams.add(t);
					break;
				}
				higherTeams.add(t);
			}
			ans = min(ans, higherTeams.size());
		}
		out.print(ans + 1);
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