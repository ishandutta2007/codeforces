import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static void solve() throws Exception {
		int n = nextInt();
		int sub[][] = new int[5][n];
		int solved[] = new int[5];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				if ((sub[j][i] = nextInt()) >= 0) {
					++solved[j];
				}
			}
		}
		int mulVasya[] = new int[5];
		int mulPetya[] = new int[5];
		for (int i = 0; i < 5; i++) {
			mulVasya[i] = sub[i][0] >= 0 ? 250 - sub[i][0] : 0;
			mulPetya[i] = sub[i][1] >= 0 ? 250 - sub[i][1] : 0;
		}
		for (int bots = 0; bots <= n * 32; bots++) {
			int total = n + bots;
			int scoreVasya = 0, scorePetya = 0;
			for (int i = 0; i < 5; i++) {
				int solv;
				if (mulVasya[i] > mulPetya[i] || sub[i][0] < 0) {
					solv = solved[i];
				} else {
					solv = solved[i] + bots;
				}
				int baseScore;
				if (solv * 2 > total) {
					baseScore = 2;
				} else if (solv * 4 > total) {
					baseScore = 4;
				} else if (solv * 8 > total) {
					baseScore = 6;
				} else if (solv * 16 > total) {
					baseScore = 8;
				} else if (solv * 32 > total) {
					baseScore = 10;
				} else {
					baseScore = 12;
				}
				scoreVasya += mulVasya[i] * baseScore;
				scorePetya += mulPetya[i] * baseScore;
			}
			if (scoreVasya > scorePetya) {
				out.print(bots);
				return;
			}
		}
		out.print(-1);
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