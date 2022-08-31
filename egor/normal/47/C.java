import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskC {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		char[][] ans = null;
		String[] words = new String[6];
		for (int i = 0; i < 6; i++)
			words[i] = in.readString();
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (i == j || words[i].charAt(0) != words[j].charAt(0))
					continue;
				for (int k = 0; k < 6; k++) {
					if (i == k || j == k || words[k].charAt(0) != lastCharacter(words[i]) || words[k].length() < words[j].length())
						continue;
					for (int l = 0; l < 6; l++) {
						if (i == l || j == l || k == l || words[l].charAt(0) != lastCharacter(words[j]) || words[l].length() < words[i].length() || words[l].charAt(words[i].length() - 1) != words[k].charAt(words[j].length() - 1))
							continue;
						for (int m = 0; m < 6; m++) {
							if (i == m || j == m || k == m || l == m || words[m].charAt(0) != lastCharacter(words[l]) || words[m].length() + words[j].length() != words[k].length() + 1)
								continue;
							for (int n = 0; n < 6; n++) {
								if (i == n || j == n || k == n || l == n || m == n || words[n].charAt(0) != lastCharacter(words[k]) || lastCharacter(words[n]) != lastCharacter(words[m]) || words[n].length() + words[i].length() != words[l].length() + 1)
									continue;
								char[][] candidate = new char[words[k].length()][words[l].length()];
								for (int a = 0; a < candidate.length; a++) {
									for (int b = 0; b < candidate[0].length; b++)
										candidate[a][b] = '.';
								}
								for (int a = 0; a < words[i].length(); a++)
									candidate[0][a] = words[i].charAt(a);
								for (int a = 0; a < words[j].length(); a++)
									candidate[a][0] = words[j].charAt(a);
								for (int a = 0; a < words[k].length(); a++)
									candidate[a][words[i].length() - 1] = words[k].charAt(a);
								for (int a = 0; a < words[l].length(); a++)
									candidate[words[j].length() - 1][a] = words[l].charAt(a);
								for (int a = 0; a < words[m].length(); a++)
									candidate[words[j].length() + a - 1][candidate[0].length - 1] = words[m].charAt(a);
								for (int a = 0; a < words[n].length(); a++)
									candidate[candidate.length - 1][words[i].length() + a - 1] = words[n].charAt(a);
								if (better(candidate, ans))
									ans = candidate;
							}
						}
					}
				}
			}
		}
		if (ans == null)
			out.println("Impossible");
		else {
			for (char[] row : ans) {
				for (char l : row)
					out.print(l);
				out.println();
			}
		}
	}

	private boolean better(char[][] candidate, char[][] ans) {
		if (ans == null)
			return true;
		for (int i = 0; i < candidate.length; i++) {
			if (ans.length == i)
				return false;
			int cmp = new String(candidate[i]).compareTo(new String(ans[i]));
			if (cmp != 0)
				return cmp < 0;
		}
		return true;
	}

	private char lastCharacter(String word) {
		return word.charAt(word.length() - 1);
	}

	public static void main(String[] args) {
		new TaskC().run();
	}

	TaskC() {
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