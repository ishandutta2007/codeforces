import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
//	static final int DX[] = {1, 0, -1, 0};
//	static final int DY[] = {0, 1, 0, -1};
//	
//	static boolean solveFirst(boolean glue[][], int x1, int y1, int x2, int y2) {
//		if (x1 == x2 && y1 == y2) {
//			return true;
//		}
//		if (!glue[x1][y1]) {
//			for (int d = 0; d < 4; d++) {
//				int nx1 = x1 + DX[d];
//				int ny1 = y1 + DY[d];
//				if (nx1 < 0 || nx1 >= glue.length || ny1 < 0 || ny1 >= glue[0].length) {
//					continue;
//				}
//				if (solveSecond(glue, nx1, ny1, x2, y2)) {
//					return true;
//				}
//			}
//		}
//		if (!glue[x2][y2]) {
//			for (int d = 0; d < 4; d++) {
//				int nx2 = x2 + DX[d];
//				int ny2 = y2 + DY[d];
//				if (nx2 < 0 || nx2 >= glue.length || ny2 < 0 || ny2 >= glue[0].length) {
//					continue;
//				}
//				if (solveSecond(glue, x1, y1, nx2, ny2)) {
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	
//	static boolean solveSecond(boolean glue[][], int x1, int y1, int x2, int y2) {
//		for (int x = 0; x < glue.length; x++) {
//			for (int y = 0; y < glue[0].length; y++) {
//				if (!(x == x1 && y == y1) && !(x == x2 && y == y2) && !glue[x][y]) {
//					glue[x][y] = true;
//					boolean res = solveFirst(glue, x1, y1, x2, y2);
//					glue[x][y] = false;
//					if (!res) {
//						return false;
//					}
//				}
//			}
//		}
//		return true;
//	}
	
	static void solve() throws Exception {
		/*int n = */nextInt();
		/*int m = */nextInt();
		int x1 = nextInt() - 1;
		int y1 = nextInt() - 1;
		int x2 = nextInt() - 1;
		int y2 = nextInt() - 1;
		// dx > 4 || dy > 4 -> Second
		// dx + dy <= 4 -> First
		// dx == 4 && dy == 1 -> First
		// dx == 4 && dy == 4 -> Second
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		if (dx > 4 || dy > 4) {
			out.println("Second");
			return;
		}
		if (dx == 4 && dy >= 3 || dx >= 3 && dy == 4) {
			out.println("Second");
			return;
		}
		out.println("First");
//		int xMin = min(x1, x2);
//		int xMax = max(x1, x2);
//		int yMin = min(y1, y2);
//		int yMax = max(y1, y2);
//		n = xMax - xMin + 1;
//		x1 -= xMin;
//		x2 -= xMin;
//		m = yMax - yMin + 1;
//		y1 -= yMin;
//		y2 -= yMin;
//		boolean glue[][] = new boolean[n][m];
//		out.println(solveFirst(glue, x1, y1, x2, y2) ? "First" : "Second");
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