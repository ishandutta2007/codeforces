import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.util.Random;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int limit = in.readInt();
		int[] value = IOUtils.readIntArray(in, count);
		IntHashMap map = new IntHashMap();
		for (int i : value) {
			for (int j = 0; j <= limit; j++) {
				if (map.contains(i * j)) {
					map.put(i * j, Math.min(j, map.get(i * j)));
				} else {
					map.put(i * j, j);
				}
			}
		}
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			int request = in.readInt();
			int answer = limit + 1;
			for (int j : value) {
				for (int k = 0; k <= limit; k++) {
					if (map.contains(request - j * k)) {
						answer = Math.min(answer, k + map.get(request - j * k));
					}
				}
			}
			if (answer > limit) {
				answer = -1;
			}
			out.printLine(answer);
		}
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

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

}

class IntHashMap extends IntSet {
	private static final Random RND = new Random();
	private static final int[] SHIFTS = new int[4];
	private static final byte PRESENT_MASK = 1;

	static {
		for (int i = 0; i < 4; i++)
			SHIFTS[i] = RND.nextInt(31) + 1;
	}

	private int size;
	private int realSize;
	private int[] keys;
	private int[] values;
	private byte[] present;
	private int step;
	private int ratio;

	public IntHashMap() {
		this(3);
	}


	public IntHashMap(int capacity) {
		capacity = Math.max(capacity, 1);
		keys = new int[capacity];
		present = new byte[capacity];
		values = new int[capacity];
		ratio = 2;
		initStep(capacity);
	}

	private void initStep(int capacity) {
		step = RND.nextInt(capacity - 2) + 1;
		while (IntegerUtils.gcd(step, capacity) != 1)
			step++;
	}

	public void put(int key, int value) {
		ensureCapacity((realSize + 1) * ratio + 2);
		int current = getHash(key);
		while (present[current] != 0) {
			if ((present[current] & PRESENT_MASK) != 0 && keys[current] == key) {
				values[current] = value;
				return;
			}
			current += step;
			if (current >= values.length)
				current -= values.length;
		}
		while ((present[current] & PRESENT_MASK) != 0) {
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		if (present[current] == 0) {
			realSize++;
		}
		present[current] = PRESENT_MASK;
		keys[current] = key;
		values[current] = value;
		size++;
	}

	private int getHash(int key) {
		int result = key;
		for (int i : SHIFTS)
			result ^= key >> i;
		result %= keys.length;
		if (result < 0)
			result += keys.length;
		return result;
	}

	private void ensureCapacity(int capacity) {
		if (keys.length < capacity) {
			capacity = Math.max(capacity * 2, keys.length);
			rebuild(capacity);
		}
	}

	private void rebuild(int capacity) {
		initStep(capacity);
		int[] oldKeys = keys;
		byte[] oldPresent = present;
		int[] oldValues = values;
		keys = new int[capacity];
		present = new byte[capacity];
		values = new int[capacity];
		size = 0;
		realSize = 0;
		for (int i = 0; i < oldKeys.length; i++) {
			if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
				put(oldKeys[i], oldValues[i]);
		}
	}

	public boolean contains(int key) {
		int current = getHash(key);
		while (present[current] != 0) {
			if (keys[current] == key && (present[current] & PRESENT_MASK) != 0)
				return true;
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		return false;
	}

	public int get(int key) {
		int current = getHash(key);
		while (present[current] != 0) {
			if (keys[current] == key && (present[current] & PRESENT_MASK) != 0)
				return values[current];
			current += step;
			if (current >= keys.length)
				current -= keys.length;
		}
		throw new NoSuchElementException();
	}
}

abstract class IntCollection {

}

abstract class IntSet extends IntCollection {
}

class IntegerUtils {

	public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

}