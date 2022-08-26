import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.util.Collections;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;
import java.util.Collection;
import java.io.OutputStreamWriter;

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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] x = IOUtils.readIntArray(in, count);
		int[] y = IOUtils.readIntArray(in, count);
		List<IntPair> direct = simplify(x);
		List<IntPair> reverse = simplify(y);
		int at = 0;
		for (int i = 0; i < count; i++) {
			if (Integer.highestOneBit(x[i]) > Integer.highestOneBit(y[at])) {
				direct.add(new IntPair(i, i));
				x[i] = 0;
			} else {
				for (int j = 29; j >= 0; j--) {
					if ((x[i] >> j & 1) != (y[at] >> j & 1)) {
						for (int k = i + 1; k < count && x[k] != 0; k++) {
							if (Integer.highestOneBit(x[k]) == (1 << j)) {
								direct.add(new IntPair(i, k));
								x[i] ^= x[k];
								break;
							}
						}
						if ((x[i] >> j & 1) != (y[at] >> j & 1)) {
							out.printLine(-1);
							return;
						}
					}
				}
				if (i != at) {
					direct.add(new IntPair(at, at));
					direct.add(new IntPair(at, i));
					x[at] = x[i];
				}
				at++;
			}
		}
		for (int i = at; i < count; i++) {
			if (y[i] != 0) {
				out.printLine(-1);
				return;
			}
			direct.add(new IntPair(i, i));
			x[i] = 0;
		}
		Collections.reverse(reverse);
		direct.addAll(reverse);
		out.printLine(direct.size());
		for (IntPair pair : direct) {
			out.printLine(pair.first + 1, pair.second + 1);
		}
    }

	private List<IntPair> simplify(int[] x) {
		int id = 0;
		List<IntPair> result = new ArrayList<>();
		for (int i = 29; i >= 0 && id < x.length; i--) {
			if ((x[id] >> i & 1) == 0) {
				for (int j = id + 1; j < x.length; j++) {
					if ((x[j] >> i & 1) != 0) {
						result.add(new IntPair(id, j));
						x[id] ^= x[j];
						break;
					}
				}
			}
			if ((x[id] >> i & 1) != 0) {
				for (int j = 0; j < id; j++) {
					if ((x[j] >> i & 1) == 0) {
						result.add(new IntPair(j, id));
						x[j] ^= x[id];
					}
				}
				for (int j = id + 1; j < x.length; j++) {
					if ((x[j] >> i & 1) != 0) {
						result.add(new IntPair(j, id));
						x[j] ^= x[id];
					}
				}
				id++;
			}
		}
		return result;
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

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

}

class IntPair implements Comparable<IntPair> {
	public final int first, second;

	public IntPair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		IntPair intPair = (IntPair) o;

		return first == intPair.first && second == intPair.second;

	}

	public int hashCode() {
		int result = first;
		result = 31 * result + second;
		return result;
	}

	public int compareTo(IntPair o) {
		if (first < o.first)
			return -1;
		if (first > o.first)
			return 1;
		if (second < o.second)
			return -1;
		if (second > o.second)
			return 1;
		return 0;
	}
}