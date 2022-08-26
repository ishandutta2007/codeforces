import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

/**
 * @author Egor Kulikov (egor@egork.net)
 */
public class TaskE {
	@SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
	InputReader in;
	PrintWriter out;

	void solve() {
		int dominoCount = in.readInt();
		final int[] x = new int[dominoCount];
		int[] height = new int[dominoCount];
		in.readIntArrays(x, height);
		Integer[] order = new Integer[dominoCount];
		for (int i = 0; i < dominoCount; i++)
			order[i] = i;
		Arrays.sort(order, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return x[o1] - x[o2];
			}
		});
		int[] sortedX = new int[dominoCount];
		System.arraycopy(x, 0, sortedX, 0, dominoCount);
		Arrays.sort(sortedX);
		int[] felt = new int[dominoCount];
		MaximumIntervalTree tree = new MaximumIntervalTree(dominoCount);
		for (int i = dominoCount - 1; i >= 0; i--) {
			int currentHeight = height[order[i]];
			int directIndex = Arrays.binarySearch(sortedX, sortedX[i] + currentHeight - 1);
			if (directIndex < 0)
				directIndex = -directIndex - 2;
			if (directIndex != i)
				directIndex = tree.getValue(i, directIndex + 1);
			tree.putValue(i, directIndex);
			felt[order[i]] = directIndex - i + 1;
		}
		out.print(felt[0]);
		for (int i = 1; i < dominoCount; i++)
			out.print(" " + felt[i]);
		out.println();
	}

	static class MaximumIntervalTree {
		int[] left;
		int[] right;
		int[] value;

		MaximumIntervalTree(int size) {
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

		public int getValue(int left, int right) {
			return getValue(left, right, 0);
		}

		private int getValue(int left, int right, int root) {
			if (left >= this.right[root] || right <= this.left[root])
				return 0;
			if (left <= this.left[root] && right >= this.right[root])
				return value[root];
			return Math.max(getValue(left, right, 2 * root + 1), getValue(left, right, 2 * root + 2));
		}

		public void putValue(int position, int value) {
			putValue(position, value, 0);
		}

		private void putValue(int position, int value, int root) {
			if (left[root] > position || right[root] <= position)
				return;
			this.value[root] = Math.max(this.value[root], value);
			if (right[root] - left[root] > 1) {
				putValue(position, value, 2 * root + 1);
				putValue(position, value, 2 * root + 2);
			}
		}
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
//		int testCount = in.readInt();
//		for (int i = 0; i < testCount; i++)
//		while (true)
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

		int[] readIntArray(int size) {
			int[] array = new int[size];
			for (int i = 0; i < size; i++)
				array[i] = readInt();
			return array;
		}

		long[] readLongArray(int size) {
			long[] array = new long[size];
			for (int i = 0; i < size; i++)
				array[i] = readLong();
			return array;
		}

		double[] readDoubleArray(int size) {
			double[] array = new double[size];
			for (int i = 0; i < size; i++)
				array[i] = readDouble();
			return array;
		}

		String[] readStringArray(int size) {
			String[] array = new String[size];
			for (int i = 0; i < size; i++)
				array[i] = readString();
			return array;
		}

		char[][] readTable(int rowCount, int columnCount) {
			char[][] table = new char[rowCount][columnCount];
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < columnCount; j++)
					table[i][j] = readCharacter();
			}
			return table;
		}

		void readIntArrays(int[]...arrays) {
			for (int i = 0; i < arrays[0].length; i++) {
				for (int j = 0; j < arrays.length; j++)
					arrays[j][i] = readInt();
			}
		}
	}
}