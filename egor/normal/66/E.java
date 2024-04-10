import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	private final InputReader in;
	private final PrintWriter out;
	private final boolean testMode;

	private void solve() {
		int stationCount = in.readInt();
		int[] fuel = in.readIntArray(stationCount);
		int[] distances = in.readIntArray(stationCount);
		boolean[] clockwise = solve(fuel, distances);
		int[] counterFuel = new int[stationCount];
		for (int i = 0; i < stationCount; i++)
			counterFuel[i] = fuel[stationCount - i - 1];
		int[] counterDistances = new int[stationCount];
		for (int i = 0; i < stationCount - 1; i++)
			counterDistances[i] = distances[stationCount - i - 2];
		counterDistances[stationCount - 1] = distances[stationCount - 1];
		boolean[] counterClockwise = solve(counterFuel, counterDistances);
		List<Integer> valid = new ArrayList<Integer>();
		for (int i = 0; i < stationCount; i++) {
			if (clockwise[i] || counterClockwise[stationCount - i - 1])
				valid.add(i + 1);
		}
		out.println(valid.size());
		for (int index : valid)
			out.print(index + " ");
		out.println();
	}

	private boolean[] solve(int[] fuel, int[] distances) {
		int stationCount = fuel.length;
		int currentFuel = 0;
		int currentDistance = 0;
		int lastIndex = -1;
		boolean[] result = new boolean[stationCount];
		for (int i = 0; i < stationCount; i++) {
			if (lastIndex < i) {
				currentFuel = 0;
				currentDistance = 0;
				lastIndex = i;
			} else {
				currentFuel -= fuel[i - 1];
				currentDistance -= distances[i - 1];
			}
			while (currentFuel >= currentDistance && lastIndex < i + stationCount) {
				currentFuel += fuel[lastIndex % stationCount];
				currentDistance += distances[lastIndex % stationCount];
				lastIndex++;
			}
			if (lastIndex == i + stationCount)
				result[i] = true;
		}
		return result;
	}

	private static List<Test> createTests() {
		List<Test> tests = new ArrayList<Test>();
		tests.add(new Test("4\n" +
			"1 7 2 3\n" +
			"8 1 1 3", "2\n" +
			"2 4"));
		tests.add(new Test("8\n" +
			"1 2 1 2 1 2 1 2\n" +
			"2 1 2 1 2 1 2 1", "8\n" +
			"1 2 3 4 5 6 7 8"));
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

	private TaskE() {
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
			new TaskE().run();
	}

	private static void test() {
		List<Test> tests = createTests();
		int testCase = 0;
		for (Test test : tests) {
			System.out.print("Test #" + testCase + ": ");
			InputReader in = new StringInputReader(test.getInput());
			StringWriter out = new StringWriter(test.getOutput().length());
			long time = System.currentTimeMillis();
			try {
				new TaskE(in, new PrintWriter(out)).run();
			} catch (TestException e) {
				time = System.currentTimeMillis() - time;
				String checkResult = check(test.getInput(), out.getBuffer().toString(), test.getOutput());
				if (checkResult == null)
					System.out.print("OK");
				else
					System.out.print("WA (" + checkResult + ")");
				System.out.printf(" in %.3f s.\n", time / 1000.);
			} catch (Throwable e) {
				System.out.println("Exception thrown:");
				e.printStackTrace(System.out);
			}
			testCase++;
		}
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
				if (!resultToken.equals(outputToken))
					return "'" + outputToken + "' expected at " + index + " but '" + resultToken + "' received";
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
		return "'" + output + "' expected but '" + result + "' received";
	}

	@SuppressWarnings({"UnusedDeclaration"})
	private static boolean isDoubleEquals(double expected, double result, double certainty) {
		return Math.abs(expected - result) < certainty || Math.abs(expected - result) < certainty * expected;
	}

	private TaskE(InputReader in, PrintWriter out) {
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