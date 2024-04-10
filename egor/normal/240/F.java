import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
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
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		int queryCount = in.readInt();
		char[] s = in.readString().toCharArray();
		IntervalTree tree = new IntervalTree(s);
		for (int i = 0; i < queryCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			int[] result = tree.query(from, to);
			int middleSymbol = -1;
			for (int j = 0; j < 26; j++) {
				if ((result[j] & 1) == 1) {
					if (middleSymbol == -1)
						middleSymbol = j;
					else
						middleSymbol = -2;
				}
			}
			if (middleSymbol == -2)
				continue;
			int middle = (from + to) >> 1;
			tree.update(from, middleSymbol == -1 ? middle : middle - 1, 1);
			tree.update(middle + 1, to, -1);
			if (middleSymbol != -1)
				tree.setSingle(middle, middleSymbol);
		}
		for (int i = 0; i < length; i++) {
			int[] result = tree.query(i, i);
			for (int j = 0; j < 26; j++) {
				if (result[j] == 1) {
					out.print((char)('a' + j));
					break;
				}
			}
		}
		out.printLine();
	}
}

class IntervalTree {
	protected int size;
    protected int[][] value;
    protected int[] delta;
	int[] result = new int[26];

	protected IntervalTree(char[] s) {
		this.size = s.length;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		value = new int[nodeCount][26];
        delta = new int[nodeCount];
		init(s);
	}

	public void init(char[] s) {
		init(0, 0, size - 1, s);
	}

	private void init(int root, int left, int right, char[] s) {
		if (left == right) {
			value[root][s[left] - 'a'] = 1;
        } else {
			int middle = (left + right) >> 1;
			init(2 * root + 1, left, middle, s);
			init(2 * root + 2, middle + 1, right, s);
			for (int i = 0; i < 26; i++)
				value[root][i] = value[2 * root + 1][i] + value[2 * root + 2][i];
		}
	}

	public void setSingle(int index, int value) {
		setSingle(0, index, value, 0, size - 1);
	}

	private void setSingle(int root, int index, int value, int left, int right) {
		if (index < left || index > right)
			return;
		if (left == right) {
			Arrays.fill(this.value[root], 0);
			this.value[root][value] = 1;
			return;
		}
		delta[root] = 0;
		int middle = (left + right) >> 1;
		setSingle(2 * root + 1, index, value, left, middle);
		setSingle(2 * root + 2, index, value, middle + 1, right);
		for (int i = 0; i < 26; i++)
			this.value[root][i] = this.value[2 * root + 1][i] + this.value[2 * root + 2][i];
	}

	public void update(int from, int to, int delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	private void update(int root, int left, int right, int from, int to, int delta) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
            this.delta[root] = delta;
			int skip = left - from;
			Arrays.fill(value[root], 0);
			int total = right - left + 1;
			if (delta == 1) {
				for (int i = 0; i < 26; i++) {
					int curSkip = Math.min(skip, result[i] >> 1);
					skip -= curSkip;
					int curAdd = Math.min(total, (result[i] >> 1) - curSkip);
					value[root][i] = curAdd;
					total -= curAdd;
				}
			} else if (delta == -1) {
				for (int i = 25; i >= 0; i--) {
					int curSkip = Math.min(skip, result[i] >> 1);
					skip -= curSkip;
					int curAdd = Math.min(total, (result[i] >> 1) - curSkip);
					value[root][i] = curAdd;
					total -= curAdd;
				}
			}
            return;
        }
		this.delta[root] = 0;
        int middle = (left + right) >> 1;
        update(2 * root + 1, left, middle, from, to, delta);
        update(2 * root + 2, middle + 1, right, from, to, delta);
		for (int i = 0; i < 26; i++)
			value[root][i] = value[2 * root + 1][i] + value[2 * root + 2][i];
    }

	public int[] query(int from, int to) {
		Arrays.fill(result, 0);
		query(0, 0, size - 1, from, to);
		return result;
	}

	private void query(int root, int left, int right, int from, int to) {
        if (left > to || right < from)
            return;
        if (left >= from && right <= to) {
			for (int i = 0; i < 26; i++)
				result[i] += value[root][i];
            return;
		}
		int middle = (left + right) >> 1;
		if (delta[root] != 0) {
			delta[2 * root + 1] = delta[root];
			delta[2 * root + 2] = delta[root];
			int length = middle - left + 1;
			if (delta[root] == 1) {
				for (int i = 0; i < 26; i++) {
					int cur = Math.min(length, value[root][i]);
					length -= cur;
					value[2 * root + 1][i] = cur;
					value[2 * root + 2][i] = value[root][i] - cur;
				}
			} else {
				for (int i = 25; i >= 0; i--) {
					int cur = Math.min(length, value[root][i]);
					length -= cur;
					value[2 * root + 1][i] = cur;
					value[2 * root + 2][i] = value[root][i] - cur;
				}
			}
			delta[root] = 0;
		}
        query(2 * root + 1, left, middle, from, to);
		query(2 * root + 2, middle + 1, right, from, to);
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

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
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