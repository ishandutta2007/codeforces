import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] array = IOUtils.readIntArray(in, count);
		int[] sorted = array.clone();
		ArrayUtils.sort(sorted, IntComparator.DEFAULT);
		int differs = 0;
		for (int i = 0; i < count; i++) {
			if (array[i] != sorted[i])
				differs++;
		}
		if (differs <= 2)
			out.printLine("YES");
		else
			out.printLine("NO");
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

class ArrayUtils {
    private static int[] tempInt = new int[0];

	public static int[] sort(int[] array, IntComparator comparator) {
        return sort(array, 0, array.length, comparator);
    }

    public static int[] sort(int[] array, int from, int to, IntComparator comparator) {
        ensureCapacityInt(to - from);
        System.arraycopy(array, from, tempInt, 0, to - from);
        sortImpl(array, from, to, tempInt, 0, to - from, comparator);
        return array;
    }

    private static void ensureCapacityInt(int size) {
        if (tempInt.length >= size)
            return;
        size = Math.max(size, tempInt.length << 1);
        tempInt = new int[size];
    }

    private static void sortImpl(int[] array, int from, int to, int[] temp, int fromTemp, int toTemp, IntComparator comparator) {
        if (to - from <= 1)
            return;
        int middle = (to - from) >> 1;
        int tempMiddle = fromTemp + middle;
        sortImpl(temp, fromTemp, tempMiddle, array, from, from + middle, comparator);
        sortImpl(temp, tempMiddle, toTemp, array, from + middle, to, comparator);
        int index = from;
        int index1 = fromTemp;
        int index2 = tempMiddle;
        while (index1 < tempMiddle && index2 < toTemp) {
            if (comparator.compare(temp[index1], temp[index2]) <= 0)
                array[index++] = temp[index1++];
            else
                array[index++] = temp[index2++];
        }
        if (index1 != tempMiddle)
            System.arraycopy(temp, index1, array, index, tempMiddle - index1);
        if (index2 != toTemp)
            System.arraycopy(temp, index2, array, index, toTemp - index2);
    }

    }

interface IntComparator {
    public static final IntComparator DEFAULT = new IntComparator() {
        public int compare(int first, int second) {
            if (first < second)
                return -1;
            if (first > second)
                return 1;
            return 0;
        }
    };

    public int compare(int first, int second);
}