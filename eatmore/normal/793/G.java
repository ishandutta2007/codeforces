import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GFast {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;

	static int n, len;
	static long edges[][];
	static int matchingL[], matchingR[];
	static int hkQueue[];
	static long hkSet[], hkSet2[][];

	static final int BIT_INDEX[] = {
		0, 1, 2, 7, 3, 13, 8, 19, 4, 25, 14, 28, 9, 34, 20, 40,
		5, 17, 26, 38, 15, 46, 29, 48, 10, 31, 35, 54, 21, 50, 41, 57,
		63, 6, 12, 18, 24, 27, 33, 39, 16, 37, 45, 47, 30, 53, 49, 56,
		62, 11, 23, 32, 36, 44, 52, 55, 61, 22, 43, 51, 60, 42, 59, 58};

	static int bitIndex(long x) {
		return BIT_INDEX[(int) ((x * 0x218a392cd3d5dbfL) >>> 58)];
	}

	static int hopcroftKarp() {
		fill(matchingL, -1);
		fill(matchingR, -1);
		int size = 0;
		while (true) {
			fill(hkSet, -1L);
			int queueHead = 0, queueTail = 0;
			for (int i = 0; i < n; i++) {
				if (matchingL[i] < 0) {
					hkQueue[queueTail++] = i;
					hkQueue[queueTail++] = 0;
				}
			}
			int resDist = -1;
			while (queueHead < queueTail) {
				int cur = hkQueue[queueHead++];
				int cdist = hkQueue[queueHead++];
				if ((cdist + Integer.MIN_VALUE) > (resDist + Integer.MIN_VALUE)) {
					break;
				}
				long ecur[] = edges[cur], curSet2[] = hkSet2[cdist];
				for (int nextBlock = 0; nextBlock < len; nextBlock++) {
					long v = hkSet[nextBlock], w = ecur[nextBlock] & v;
					if (w == 0) {
						continue;
					}
					hkSet[nextBlock] = v ^ w;
					curSet2[nextBlock] |= w;
					do {
						long x = w & -w;
						w ^= x;
						int next = (nextBlock << 6) + bitIndex(x);
						int next2 = matchingR[next];
						if (next2 < 0) {
							resDist = cdist;
						} else {
							hkQueue[queueTail++] = next2;
							hkQueue[queueTail++] = cdist + 1;
						}
					} while (w != 0);
				}
			}
			if (resDist == -1) {
				return size;
			}
			for (int i = 0; i < n; i++) {
				if (matchingL[i] < 0 && hopcroftKarpDfs(i, 0)) {
					++size;
				}
			}
			for (int i = 0; i <= resDist; i++) {
				fill(hkSet2[i], 0);
			}
		}
	}

	static boolean hopcroftKarpDfs(int cur, int cdist) {
		long ecur[] = edges[cur], curSet2[] = hkSet2[cdist];
		for (int nextBlock = 0; nextBlock < len; nextBlock++) {
			long v = curSet2[nextBlock], w = ecur[nextBlock] & v;
			if (w == 0) {
				continue;
			}
			v ^= w;
			do {
				long x = w & -w;
				w ^= x;
				int next = (nextBlock << 6) + bitIndex(x);
				int next2 = matchingR[next];
				if (next2 < 0 || hopcroftKarpDfs(next2, cdist + 1)) {
					matchingR[next] = cur;
					matchingL[cur] = next;
					curSet2[nextBlock] = v ^ w;
					return true;
				}
			} while (w != 0);
			curSet2[nextBlock] = v;
		}
		return false;
	}

	static void solve() throws Exception {
		n = nextInt();
		int q = nextInt();
		len = (n + 63) >> 6;
		edges = new long[n][len];
		matchingL = new int[n];
		matchingR = new int[n];
		hkQueue = new int[2 * n];
		hkSet = new long[len];
		hkSet2 = new long[n][len];
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n >> 6; y++) {
				edges[x][y] = -1L;
			}
			if ((n & 63) != 0) {
				edges[x][n >> 6] = (1L << n) - 1;
			}
		}
		for (int i = 0; i < q; i++) {
			int x1 = nextInt() - 1;
			int y1 = nextInt() - 1;
			int x2 = nextInt();
			int y2 = nextInt();
			if (y1 >> 6 == y2 >> 6) {
				long mask = ~((1L << y2) - (1L << y1));
				for (int x = x1; x < x2; x++) {
					edges[x][y1 >> 6] &= mask;
				}
			} else {
				for (int x = x1; x < x2; x++) {
					edges[x][y1 >> 6] &= ~(-1L << y1);
					for (int y = (y1 >> 6) + 1; y < y2 >> 6; y++) {
						edges[x][y] = 0;
					}
					if ((y2 & 63) != 0) {
						edges[x][y2 >> 6] &= -1L << y2;
					}
				}
			}
		}
		out.print(hopcroftKarp());
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