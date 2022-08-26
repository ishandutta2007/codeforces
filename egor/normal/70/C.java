import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskC {
	private static final double CERTAINTY = 0;

	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private final InputReader in;
	private final PrintWriter out;
	private final boolean testMode;

	private static class Rational {
		private final int a;
		private final int b;

		private Rational(int a, int b) {
			int g = gcd(a, b);
			this.a = a / g;
			this.b = b / g;
		}

		private int gcd(int a, int b) {
			while (b != 0) {
				int t = a % b;
				a = b;
				b = t;
			}
			return a;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Rational rational = (Rational) o;

			return a == rational.a && b == rational.b;

		}

		@Override
		public int hashCode() {
			int result = a;
			result = 31 * result + b;
			return result;
		}
	}

	private void solve() {
		int maxx = in.readInt();
		int maxy = in.readInt();
		int w = in.readInt();
		Map<Rational, List<Integer>> map = new HashMap<Rational, List<Integer>>();
		for (int i = 1; i <= maxy; i++) {
			Rational ratio = new Rational(i, reverse(i));
			List<Integer> current = map.get(ratio);
			if (current == null)
				map.put(ratio, current = new ArrayList<Integer>());
			current.add(i);
		}
		long bestResult = Long.MAX_VALUE;
		int bestX = -1;
		int bestY = -1;
		IntervalTree tree = new IntervalTree(maxy + 1);
		for (int x = 1; x <= maxx; x++) {
			List<Integer> ys = map.get(new Rational(reverse(x), x));
			if (ys != null) {
				for (int y : ys)
					tree.putValue(y, 1);
			}
			if (tree.value[0] < w)
				continue;
			long y = tree.lowerBound(w);
			if (x * y < bestResult) {
				bestResult = x * y;
				bestX = x;
				bestY = (int) y;
			}
		}
		if (bestResult == Long.MAX_VALUE) {
			out.println(-1);
			return;
		}
		out.println(bestX + " " + bestY);
	}

	private int reverse(int v) {
		int result = 0;
		while (v != 0) {
			result *= 10;
			result += v % 10;
			v /= 10;
		}
		return result;
	}

	public static class IntervalTree {
		private int[] left;
		private int[] right;
		private int[] value;

		public IntervalTree(int size) {
			left = new int[4 * size];
			right = new int[4 * size];
			value = new int[4 * size];
			init(0, size, 0);
		}

		private void init(int left, int right, int root) {
			this.left[root] = left;
			this.right[root] = right;
			if (right - left > 1) {
				init(left, (left + right) / 2, 2 * root + 1);
				init((left + right) / 2, right, 2 * root + 2);
			}
		}

		public int lowerBound(int value) {
			return lowerBound(value, 0);
		}

		private int lowerBound(int value, int root) {
			if (right[root] - left[root] == 1)
				return left[root];
			if (this.value[2 * root + 1] >= value)
				return lowerBound(value, 2 * root + 1);
			return lowerBound(value - this.value[2 * root + 1], 2 * root + 2);
		}

		public void putValue(int position, int value) {
			putValue(position, value, 0);
		}

		private void putValue(int position, int value, int root) {
			if (left[root] > position || right[root] <= position)
				return;
			this.value[root] += value;
			if (right[root] - left[root] > 1) {
				putValue(position, value, 2 * root + 1);
				putValue(position, value, 2 * root + 2);
			}
		}
	}

	private static List<Test> createTests() {
		List<Test> tests = new ArrayList<Test>();
		tests.add(new Test("2 2 1", "1 1"));
		tests.add(new Test("132 10 35", "7 5"));
		tests.add(new Test("5 18 1000", "-1"));
		tests.add(new Test("48 132 235", "22 111"));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
//		tests.add(new Test("", ""));
		return tests;
	}

	private void run() {
		//noinspection InfiniteLoopStatement
//		while (true)
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
		solve();
		exit();
	}

	private TaskC() {
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
		in = new StreamInputReader(System.in);
		out = new PrintWriter(System.out);
		testMode = false;
	}

	@SuppressWarnings({"UnusedParameters"})
	private static String check(String input, String result, String output) {
//		return strictCheck(result, output);
		return tokenCheck(result, output);
	}

	public static void main(String[] args) {
		if (args.length != 0 && args[0].equals("42"))
			test();
		else
			new TaskC().run();
	}

	private static void test() {
		System.setProperty("line.separator", "\n");
		List<Test> tests = createTests();
		int testCase = 0;
		List<Verdict> verdicts = new ArrayList<Verdict>();
		long maximalTime = 0;
		boolean ok = true;
		for (Test test : tests) {
			System.out.println("Test #" + testCase + ":");
			InputReader in = new StringInputReader(test.getInput());
			StringWriter out = new StringWriter(test.getOutput().length());
			System.out.println("Input:");
			System.out.println(test.getInput());
			System.out.println("Expected output:");
			System.out.println(test.getOutput());
			System.out.println("Execution result:");
			long time = System.currentTimeMillis();
			try {
				new TaskC(in, new PrintWriter(out)).run();
			} catch (TestException e) {
				time = System.currentTimeMillis() - time;
				maximalTime = Math.max(time, maximalTime);
				String result = out.getBuffer().toString();
				System.out.println(result);
				System.out.print("Verdict: ");
				String checkResult = check(test.getInput(), result, test.getOutput());
				if (checkResult == null) {
					System.out.print("OK");
					verdicts.add(Verdict.OK);
				} else {
					System.out.print("WA (" + checkResult + ")");
					verdicts.add(Verdict.WA);
					ok = false;
				}
				System.out.printf(" in %.3f s.\n", time / 1000.);
			} catch (Throwable e) {
				System.out.println("Exception thrown:");
				e.printStackTrace(System.out);
				verdicts.add(Verdict.RTE);
				ok = false;
			}
			testCase++;
			System.out.println("------------------------------------------------------------------");
		}
		System.out.println("==================================================================");
		System.out.println("Test results:");
		if (ok)
			System.out.printf("All test passed in %.3f s.\n", maximalTime / 1000.);
		else {
			for (int i = 0; i < verdicts.size(); i++)
				System.out.println("Test #" + i + ": " + verdicts.get(i));
		}
	}

	private static enum Verdict {
		OK, WA, RTE
	}

	private static String tokenCheck(String result, String output) {
		StringInputReader resultStream = new StringInputReader(result);
		StringInputReader outputStream = new StringInputReader(output);
		int index = 0;
		boolean readingResult = false;
		try {
			while (true) {
				readingResult = true;
				String resultToken = resultStream.readString();
				readingResult = false;
				String outputToken = outputStream.readString();
				if (!resultToken.equals(outputToken)) {
					try {
						//noinspection PointlessBooleanExpression
						if (CERTAINTY != 0 && isDoubleEquals(Double.parseDouble(outputToken.replace(',', '.')),
								Double.parseDouble(resultToken.replace(',', '.')), CERTAINTY))
						{
							index++;
							continue;
						}
					} catch (NumberFormatException ignored) {}
					return "'" + outputToken + "' expected at " + index + " but '" + resultToken + "' received";
				}
				index++;
			}
		} catch (InputMismatchException e) {
			if (readingResult) {
				try {
					outputStream.readString();
					return "only " + index + " tokens received";
				} catch (InputMismatchException e1) {
					return null;
				}
			} else
				return "only " + index + " tokens expected";
		}
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static String strictCheck(String result, String output) {
		if (result.equals(output))
			return null;
		return "Result and expected output do not match";
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static boolean isDoubleEquals(double expected, double result, double certainty) {
		return Math.abs(expected - result) < certainty || Math.abs(expected - result) < certainty * expected;
	}

	private TaskC(InputReader in, PrintWriter out) {
		this.in = in;
		this.out = out;
		testMode = true;
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private void exit() {
		out.close();
		if (testMode)
			throw new TestException();
		System.exit(0);
	}

	private static class Test {
		private final String input;
		private final String output;

		private Test(String input, String output) {
			this.input = input;
			this.output = output;
		}

		public String getInput() {
			return input;
		}

		public String getOutput() {
			return output;
		}
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private abstract static class InputReader {
		public abstract int read();

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
				if (c != '\r')
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

		public int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		public long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		public double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		public String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		public char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		public void readIntArrays(int[]... arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}

	private static class StreamInputReader extends InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar, numChars;

		public StreamInputReader(InputStream stream) {
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
	}

	private static class StringInputReader extends InputReader {
		private Reader stream;
		private char[] buf = new char[1024];
		private int curChar, numChars;

		public StringInputReader(String stream) {
			this.stream = new StringReader(stream);
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
	}

	private static class TestException extends RuntimeException {}
}