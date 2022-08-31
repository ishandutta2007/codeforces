import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		char[] s1 = convert(in.readString().toCharArray());
		char[] s2 = convert(in.readString().toCharArray());
		int n = in.readInt();
		char[][] replacements = new char[n][3];
		for (int i = 0; i < n; i++) {
			replacements[i][2] = (char) (in.readCharacter() - 'a');
			in.readCharacter();
			in.readCharacter();
			replacements[i][0] = (char) (in.readCharacter() - 'a');
			replacements[i][1] = (char) (in.readCharacter() - 'a');
		}
		int[][] singleSource1 = createSingleSourceTable(s1, replacements);
		int[][] singleSource2 = createSingleSourceTable(s2, replacements);
		int[][] result = new int[s1.length + 1][s2.length + 1];
		for (int[] row : result)
			Arrays.fill(row, Integer.MAX_VALUE);
		result[0][0] = 0;
		for (int i = 0; i < s1.length; i++) {
			for (int j = 0; j < s2.length; j++) {
				if (result[i][j] == Integer.MAX_VALUE)
					continue;
				for (int k = i + 1; k <= s1.length; k++) {
					for (int l = j + 1; l <= s2.length; l++) {
						if ((singleSource1[i][k] & singleSource2[j][l]) != 0)
							result[k][l] = Math.min(result[k][l], result[i][j] + 1);
					}
				}
			}
		}
		int ans = result[s1.length][s2.length];
		if (ans == Integer.MAX_VALUE)
			ans = -1;
		out.println(ans);
	}

	private char[] convert(char[] s) {
		for (int i = 0; i < s.length; i++)
			s[i] -= 'a';
		return s;
	}

	private int[][] createSingleSourceTable(char[] s, char[][] replacements) {
		int n = s.length;
		int[][] result = new int[n][n + 1];
		for (int i = 0; i < n; i++)
			result[i][i + 1] = 1 << s[i];
		for (int length = 2; length <= n; length++) {
			for (int i = 0; i <= n - length; i++) {
				for (int j = i + 1; j < i + length; j++) {
					for (char[] replacement : replacements) {
						if (((result[i][j] >> replacement[0]) & 1) != 0 && ((result[j][i + length] >> replacement[1]) & 1) != 0)
							result[i][i + length] |= 1 << replacement[2];
					}
				}
			}
		}
		return result;
	}

	public static void main(String[] args) {
		new TaskE().run();
	}

	TaskE() {
		@SuppressWarnings({"UnusedDeclaration"})
		String id = getClass().getName().toLowerCase();
		//noinspection EmptyTryBlock
		try {
//			System.setIn(new FileInputStream(id + ".in"));
//			System.setOut(new PrintStream(new FileOutputStream(id + ".out")));
//			System.setIn(new FileInputStream("input.txt"));
//			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	void run() {
		//noinspection InfiniteLoopStatement
		solve();
		exit();
	}

	@SuppressWarnings({"UnusedDeclaration"})
	void exit() {
		out.close();
		System.exit(0);
	}

	@SuppressWarnings({"UnusedDeclaration"})
	static class InputReader {
		InputStream stream;
		byte[] buf = new byte[1024];
		int curChar, numChars;

		InputReader(InputStream stream) {
			this.stream = stream;
		}

		int read() {
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

		int readInt() {
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

		long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				if (c != '\r')
					buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}