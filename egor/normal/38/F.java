import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class TaskF implements Runnable {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private InputReader in;
	private PrintWriter out;
	private Map<String, Integer> num;
	private Map<String, Boolean> w;
	private Map<String, Integer> sc1;
	private Map<String, Integer> sc2;

	public static void main(String[] args) throws InterruptedException {
		new TaskF().run();
	}

	public TaskF() {
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

	public void run() {
		solve();
		out.close();
	}

	public boolean solve() {
		int n = in.readInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++)
			s[i] = in.readString();
		num = new HashMap<String, Integer>();
		for (String t : s) {
			Set<String> sub = new HashSet<String>();
			for (int i = 0; i < t.length(); i++) {
				for (int j = i + 1; j <= t.length(); j++)
					sub.add(t.substring(i, j));
			}
			for (String u : sub) {
				Integer v = num.get(u);
				if (v == null)
					v = 0;
				num.put(u, v + 1);
			}
		}
		w = new HashMap<String, Boolean>();
		sc1 = new HashMap<String, Integer>();
		sc2 = new HashMap<String, Integer>();
		go("", 0, 0);
		out.println(w.get("") ? "Second" : "First");
		out.println(sc1.get("") + " " + sc2.get(""));
		return true;
	}

	private void go(String c, int s, int m) {
		if (w.containsKey(c))
			return;
		boolean ww = true;
		int ssc1 = 0;
		int ssc2 = 0;
		for (char cc = 'a'; cc <= 'z'; cc++) {
			String c1 = cc + c;
			if (num.containsKey(c1)) {
				int ns = s + cc - 'a' + 1;
				int nm = Math.max(m, cc - 'a' + 1);
				go(c1, ns, nm);
				boolean nw = !w.get(c1);
				int nssc1 = sc2.get(c1) + num.get(c1) + ns * nm;
				int nssc2 = sc1.get(c1);
				if (ww && !nw || ww == nw && (nssc1 > ssc1 || nssc1 == ssc1 && nssc2 < ssc2)) {
					ww = nw;
					ssc1 = nssc1;
					ssc2 = nssc2;
				}
			}
			c1 = c + cc;
			if (num.containsKey(c1)) {
				int ns = s + cc - 'a' + 1;
				int nm = Math.max(m, cc - 'a' + 1);
				go(c1, ns, nm);
				boolean nw = !w.get(c1);
				int nssc1 = sc2.get(c1) + num.get(c1) + ns * nm;
				int nssc2 = sc1.get(c1);
				if (ww && !nw || ww == nw && (nssc1 > ssc1 || nssc1 == ssc1 && nssc2 < ssc2)) {
					ww = nw;
					ssc1 = nssc1;
					ssc2 = nssc2;
				}
			}
		}
		w.put(c, ww);
		sc1.put(c, ssc1);
		sc2.put(c, ssc2);
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
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

		public long readLong() {
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

		public String readString() {
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

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
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