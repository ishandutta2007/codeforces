import static java.lang.Double.parseDouble;
import static java.lang.Integer.bitCount;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static final int strings[] = new int[256];
	static final int stringsReversed[] = new int[256];
	static final int stringLengths[] = new int[256];
	static final int masks[] = new int[256];
	static {
		for (int i = 0; i < 256; i++) {
			int string = 0;
			int stringReversed = 0;
			int stringLength = 0;
			int mask = 0;
			int cur = i;
			do {
				int digit = cur % 10;
				cur /= 10;
				string |= digit << (4 * stringLength);
				stringReversed = (stringReversed << 4) | digit;
				++stringLength;
				mask |= 1 << digit;
			} while (cur > 0);
			strings[i] = string;
			stringsReversed[i] = stringReversed;
			stringLengths[i] = stringLength;
			masks[i] = mask;
		}
	}
	
	static final int pop[] = new int[1024];
	static {
		for (int i = 0; i < 1024; i++) {
			pop[i] = bitCount(i);
		}
	}
	
	static void solve() throws Exception {
		int n = nextInt();
		int mask = 0;
		for (int i = 0; i < n; i++) {
			mask |= 1 << nextInt();
		}
		List<Integer> ans = new ArrayList<Integer>();
//		int cnt = 0;
		for (int o1 = 0; o1 < 256; o1++) {
			int m1 = masks[o1];
			if ((m1 & ~mask) != 0) {
				continue;
			}
			long s1 = strings[o1];
			long s1r = stringsReversed[o1];
			int s1l = stringLengths[o1];
			for (int o2 = 0; o2 < 256; o2++) {
				int m2 = m1 | masks[o2];
				if ((m2 & ~mask) != 0 || pop[mask & ~m2] > 6) {
					continue;
				}
				long s2 = (s1 << (4 * stringLengths[o2])) | strings[o2];
				long s2r = s1r | ((long) stringsReversed[o2] << (4 * s1l));
				int s2l = s1l + stringLengths[o2];
				for (int o3 = 0; o3 < 256; o3++) {
					int m3 = m2 | masks[o3];
					if ((m3 & ~mask) != 0 || pop[mask & ~m3] > 3) {
						continue;
					}
					long s3 = (s2 << (4 * stringLengths[o3])) | strings[o3];
					long s3r = s2r | ((long) stringsReversed[o3] << (4 * s2l));
					int s3l = s2l + stringLengths[o3];
					check: {
						for (int l4 = 1; l4 <= 3; l4++) {
							if ((s3 & ((1L << (4 * (s3l - l4))) - 1)) == s3r >> (4 * l4)) {
								break check;
							}
						}
						continue;
					}
					for (int o4 = 0; o4 < 256; o4++) {
						int m4 = m3 | masks[o4];
						if (m4 != mask) {
							continue;
						}
						long s4 = (s3 << (4 * stringLengths[o4])) | strings[o4];
						long s4r = s3r | ((long) stringsReversed[o4] << (4 * s3l));
//						int s4l = s3l + stringLengths[o4];
//						++cnt;
						if (s4 != s4r) {
							continue;
						}
						ans.add((o1 << 24) | (o2 << 16) | (o3 << 8) | o4);
					}
				}
			}
		}
//		System.err.println(cnt);
		out.println(ans.size());
		for (int i: ans) {
			out.print(i >>> 24);
			out.print('.');
			out.print((i >> 16) & 0xFF);
			out.print('.');
			out.print((i >> 8) & 0xFF);
			out.print('.');
			out.print(i & 0xFF);
			out.println();
		}
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