import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	static final int MOD = (int) (1e9 + 9);

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int height = in.readInt();
		int[][][][] result = new int[height + 1][height + 1][height + 1][height + 1];
		result[0][0][0][0] = 1;
		int[][][][] next = new int[height + 1][height + 1][height + 1][height + 1];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j <= height; j++) {
				for (int k = j; k <= height; k++)
					Arrays.fill(next[0][j][k], k, height + 1, 0);
			}
			next[height][height][height][height] = 0;
			for (int j = 1; j < height; j++) {
				next[j][height][height][height] = 0;
				for (int k = j; k < height; k++) {
					next[j][k][height][height] = 0;
					for (int l = k; l < height; l++)
						next[j][k][l][height] = 0;
				}
			}
			for (int j = 0; j <= height; j++) {
				int nj = Math.min(j + 1, height);
				for (int k = j; k <= height; k++) {
					int nk = Math.min(k + 1, height);
					for (int l = k; l <= height; l++) {
						int nl = Math.min(l + 1, height);
						int shift = 1;
						if (j != 0 && l != height)
							shift = height;
						int start = l;
						if (l != 0 && shift == height)
							start = height;
						for (int m = start; m <= height; m += shift) {
							if (result[j][k][l][m] == 0)
								continue;
							int nm = Math.min(m + 1, height);
							if (j == height) {
								next[j][nk][nl][nm] += result[j][k][l][m];
								if (next[j][nk][nl][nm] >= MOD)
									next[j][nk][nl][nm] -= MOD;
							} else {
//								int delta;
//								if (0 == nm)
//									delta = 1;
//								else if (nk == nm)
//									delta = 4;
//								else if (nl == nm)
//									delta = 12;
//								else
//									delta = 24;
								next[0][nk][nl][nm] += result[j][k][l][m];
								if (next[0][nk][nl][nm] >= MOD)
									next[0][nk][nl][nm] -= MOD;
							}
//							if (k != j)
							if (k == height) {
//								int delta;
//								if (nj == height)
//									delta = 1;
//								else
//									delta = 4;
								next[nj][k][nl][nm] += result[j][k][l][m];
								if (next[nj][k][nl][nm] >= MOD)
									next[nj][k][nl][nm] -= MOD;
							} else {
//								int delta;
//								if (0 == nm)
//									delta = 1;
//								else if (nj == nm)
//									delta = 4;
//								else if (nl == nm)
//									delta = 12;
//								else
//									delta = 24;
								next[0][nj][nl][nm] += result[j][k][l][m];
								if (next[0][nj][nl][nm] >= MOD)
									next[0][nj][nl][nm] -= MOD;
							}
//							if (l != k)
							if (l == height) {
//								int delta;
//								if (nj == height)
//									delta = 1;
//								else if (nk == height)
//									delta = 4;
//								else
//									delta = 12;
								next[nj][nk][l][nm] += result[j][k][l][m];
								if (next[nj][nk][l][nm] >= MOD)
									next[nj][nk][l][nm] -= MOD;
							} else {
//								int delta;
//								if (0 == nm)
//									delta = 1;
//								else if (nj == nm)
//									delta = 4;
//								else if (nk == nm)
//									delta = 12;
//								else
//									delta = 24;
								next[0][nj][nk][nm] += result[j][k][l][m];
								if (next[0][nj][nk][nm] >= MOD)
									next[0][nj][nk][nm] -= MOD;
							}
//							if (m != l)
							if (m == height) {
//								int delta;
//								if (nj == height)
//									delta = 1;
//								else if (nk == height)
//									delta = 4;
//								else if (nl == height)
//									delta = 12;
//								else
//									delta = 24;
								next[nj][nk][nl][m] += result[j][k][l][m];
								if (next[nj][nk][nl][m] >= MOD)
									next[nj][nk][nl][m] -= MOD;
							} else {
//								int delta;
//								if (0 == nl)
//									delta = 1;
//								else if (nj == nl)
//									delta = 4;
//								else if (nk == nl)
//									delta = 12;
//								else
//									delta = 24;
								next[0][nj][nk][nl] += result[j][k][l][m];
								if (next[0][nj][nk][nl] >= MOD)
									next[0][nj][nk][nl] -= MOD;
							}
						}
					}
				}
			}
			int[][][][] temp = result;
			result = next;
			next = temp;
		}
		long total = 0;
		for (int i = 0; i <= height; i++) {
			for (int j = i; j <= height; j++) {
				for (int k = j; k <= height; k++) {
					for (int l = k; l <= height; l++) {
						int delta;
						if (i == l)
							delta = 1;
						else if (j == l)
							delta = 4;
						else if (k == l)
							delta = 12;
						else
							delta = 24;
						total += result[i][j][k][l];
					}
				}
			}
		}
		total -= result[height][height][height][height];
		out.printLine(total % MOD);
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}