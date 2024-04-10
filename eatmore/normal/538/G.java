import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.abs;
import static java.lang.Math.floorDiv;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class G {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
//	static final Random rng = new Random(42);
//	static boolean rngOk;
	
	static void solve() throws Exception {
		int n = nextInt();
		int l = nextInt();
//		int n = rng.nextInt(40) + 1;
//		int l = rng.nextInt(15) + 1;
//		long rngX[] = new long[l + 1];
//		long rngY[] = new long[l + 1];
//		for (int i = 0; i < l; i++) {
//			long dx, dy;
//			switch (rng.nextInt(4)) {
//			case 0:
//				dx = 1;
//				dy = 0;
//				break;
//			case 1:
//				dx = -1;
//				dy = 0;
//				break;
//			case 2:
//				dx = 0;
//				dy = 1;
//				break;
//			case 3:
//				dx = 0;
//				dy = -1;
//				break;
//			default:
//				throw new AssertionError();
//			}
//			rngX[i + 1] = rngX[i] + dx;
//			rngY[i + 1] = rngY[i] + dy;
//		}
		long t[] = new long[n];
		long x[] = new long[n];
		long y[] = new long[n];
		{
			long pt = 0;
			long px = 0;
			long py = 0;
			for (int i = 0; i < n; i++) {
				long ct = nextLong();
				long cx = nextLong();
				long cy = nextLong();
//				long ct = pt + rng.nextInt(40) + 1;
//				long cx = (ct / l) * rngX[l] + rngX[(int) (ct % l)];
//				long cy = (ct / l) * rngY[l] + rngY[(int) (ct % l)];
//				if (rng.nextInt(10) == 0) {
//					cx += rng.nextInt(5) - 2;
//				}
//				if (rng.nextInt(10) == 0) {
//					cy += rng.nextInt(5) - 2;
//				}
				if (ct - pt < abs(cx - px) + abs(cy - py) || ((ct ^ cx ^ cy) & 1) != 0) {
					out.print("NO");
					return;
				}
				t[i] = ct;
				x[i] = cx + cy;
				y[i] = cx - cy;
				pt = ct;
				px = cx;
				py = cy;
			}
		}
		long lt[] = new long[l + 1];
		long lx[] = new long[l + 1];
		long ly[] = new long[l + 1];
		fill(lt, -1);
		lt[0] = 0;
		lx[0] = 0;
		ly[0] = 0;
		long shiftXmin = -l;
		long shiftXmax = l;
		long shiftYmin = -l;
		long shiftYmax = l;
		for (int i = 0; i < n; i++) {
			int j = (int) (t[i] % l);
			if (lt[j] >= 0) {
				long its = (t[i] - lt[j]) / l;
				if ((x[i] - lx[j]) % its != 0 || ((y[i] - ly[j]) % its != 0)) {
					out.print("NO");
					return;
				}
				shiftXmin = max(shiftXmin, (x[i] - lx[j]) / its);
				shiftXmax = min(shiftXmax, (x[i] - lx[j]) / its);
				shiftYmin = max(shiftYmin, (y[i] - ly[j]) / its);
				shiftYmax = min(shiftYmax, (y[i] - ly[j]) / its);
			} else {
				lt[j] = t[i];
				lx[j] = x[i];
				ly[j] = y[i];
			}
		}
		lt[l] = 0;
		lx[l] = 0;
		ly[l] = 0;
//		System.err.println(Arrays.toString(lt));
//		System.err.println(Arrays.toString(lx));
//		System.err.println(Arrays.toString(ly));
		{
			int pi = 0;
			for (int i = 1; i <= l; i++) {
				if (lt[i] < 0) {
					continue;
				}
				long its = (lt[i] - lt[pi] - (i - pi)) / l;
				if (its == 0) {
					if (i - pi < abs(lx[i] - lx[pi]) || i - pi < abs(ly[i] - ly[pi])) {
						out.print("NO");
						return;
					}
				} else {
					long dx = lx[i] - lx[pi];
					long dy = ly[i] - ly[pi];
					// dx - (i - pi) <= shiftX * its
					// dx + (i - pi) >= shiftX * its
					if (its > 0) {
						shiftXmin = max(shiftXmin, floorDiv(dx - (i - pi) + its - 1,  its));
						shiftXmax = min(shiftXmax, floorDiv(dx + (i - pi), its));
						shiftYmin = max(shiftYmin, floorDiv(dy - (i - pi) + its - 1, its));
						shiftYmax = min(shiftYmax, floorDiv(dy + (i - pi), its));
					} else {
						shiftXmin = max(shiftXmin, floorDiv(dx + (i - pi) + its + 1, its));
						shiftXmax = min(shiftXmax, floorDiv(dx - (i - pi), its));
						shiftYmin = max(shiftYmin, floorDiv(dy + (i - pi) + its + 1, its));
						shiftYmax = min(shiftYmax, floorDiv(dy - (i - pi), its));
					}
				}
				pi = i;
			}
			if (((shiftXmin ^ l) & 1) != 0) {
				++shiftXmin;
			}
			if (((shiftXmax ^ l) & 1) != 0) {
				--shiftXmax;
			}
			if (((shiftYmin ^ l) & 1) != 0) {
				++shiftYmin;
			}
			if (((shiftYmax ^ l) & 1) != 0) {
				--shiftYmax;
			}
			if (shiftXmin > shiftXmax || shiftYmin > shiftYmax) {
				out.print("NO");
				return;
			}
		}
		{
			long shiftX = shiftXmin;
			long shiftY = shiftYmin;
			long cx = 0;
			long cy = 0;
			int pi = 0;
			for (int i = 1; i <= l; i++) {
				if (lt[i] < 0) {
					continue;
				}
				long its = (lt[i] - i) / l;
				long nx = lx[i] - shiftX * its;
				long ny = ly[i] - shiftY * its;
				while (pi < i) {
					boolean xUp = nx > cx;
					boolean yUp = ny > cy;
					out.print(xUp ? (yUp ? 'R' : 'U') : (yUp ? 'D' : 'L'));
					if (xUp) {
						++cx;
					} else {
						--cx;
					}
					if (yUp) {
						++cy;
					} else {
						--cy;
					}
					++pi;
				}
				if (cx != nx || cy != ny) {
//					System.err.println(n + " " + l);
//					System.err.println(Arrays.toString(rngX));
//					System.err.println(Arrays.toString(rngY));
//					System.err.println(Arrays.toString(t));
//					System.err.println(Arrays.toString(x));
//					System.err.println(Arrays.toString(y));
//					System.err.println(Arrays.toString(lt));
//					System.err.println(Arrays.toString(lx));
//					System.err.println(Arrays.toString(ly));
//					System.err.println(shiftX + " " + shiftY);
//					System.err.println(i + " " + cx + " " + cy + " " + nx + " " + ny);
					throw new AssertionError();
				}
			}
		}
//		rngOk = true;
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
//			if (true) while (true) {
//				rngOk = false;
//				solve();
////				if (!rngOk) {
////					throw new AssertionError();
////				}
//				System.err.println("PASS");
//			}
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}