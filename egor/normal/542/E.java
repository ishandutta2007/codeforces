import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.Comparator;

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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
int count = in.readInt();
        int edgeCount = in.readInt();
        int[][] distance = new int[count][count];
        ArrayUtils.fill(distance, Integer.MAX_VALUE / 2);
        for (int i = 0; i < count; i++) {
            distance[i][i] = 0;
        }
for (int i = 0; i < edgeCount; i++) {
int from = in.readInt() - 1;
            int to = in.readInt() - 1;
            distance[from][to] = distance[to][from] = 1;
        }
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < i; j++) {
                for (int k = j + 1; k < i; k++) {
                    distance[j][k] = Math.min(distance[j][k], distance[j][i] + distance[k][i]);
                }
            }
            for (int j = i + 1; j < count; j++) {
                for (int k = j + 1; k < count; k++) {
                    distance[j][k] = Math.min(distance[j][k], distance[i][j] + distance[i][k]);
                }
            }
            for (int j = 0; j < i; j++) {
                for (int k = i + 1; k < count; k++) {
                    distance[j][k] = Math.min(distance[j][k], distance[j][i] + distance[i][k]);
                }
            }
}
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < i; j++) {
                distance[i][j] = distance[j][i];
            }
        }
        int answer = 0;
        boolean[] processed = new boolean[count];
        for (int i = 0; i < count; i++) {
            if (processed[i]) {
                continue;
            }
            IntList curList = new IntArrayList();
            for (int j = 0; j < count; j++) {
                if (distance[i][j] != Integer.MAX_VALUE / 2) {
                    curList.add(j);
                    processed[j] = true;
                }
            }
            int[] current = curList.toArray();
            int max = 0;
            for (int j : current) {
                for (int k : current) {
                    if ((distance[i][j] + distance[i][k] + distance[j][k]) % 2 == 1) {
                        out.printLine(-1);
                        return;
                    }
                    max = Math.max(max, distance[j][k]);
                }
            }
            answer += max;
        }
        out.printLine(answer);
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

	public void close() {
		writer.close();
	}

	public void printLine(int i) {
		writer.println(i);
	}
}

class ArrayUtils {

	public static void fill(int[][] array, int value) {
		for (int[] row : array)
			Arrays.fill(row, value);
	}

}

abstract class IntList extends IntCollection implements Comparable<IntList> {

	public abstract int get(int index);

	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

}

class IntArrayList extends IntList {
	private int[] array;
	private int size;

	public IntArrayList() {
		this(10);
	}

	public IntArrayList(int capacity) {
		array = new int[capacity];
	}

	public int get(int index) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		return array[index];
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity(size + 1);
		array[size++] = value;
	}

	public void ensureCapacity(int newCapacity) {
		if (newCapacity > array.length) {
			int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
			System.arraycopy(array, 0, newArray, 0, size);
			array = newArray;
		}
	}

	public int[] toArray() {
		int[] array = new int[size];
		System.arraycopy(this.array, 0, array, 0, size);
		return array;
	}

}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

	public int[] toArray() {
		int size = size();
		int[] array = new int[size];
		int i = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		return array;
	}

}

interface IntIterator {
	public int value() throws NoSuchElementException;
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}