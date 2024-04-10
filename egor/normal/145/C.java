import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.HashSet;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	private static final long MOD = 1000000007;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int length = in.readInt();
		int count = in.readInt();
		int[] array = IOUtils.readIntArray(in, length);
		Set<Long> happy = new HashSet<Long>(Array.wrap(IntegerUtils.generateHappy(9)));
		int[] sameHappy = new int[length + 1];
		Map<Long, Integer> happyCount = new CPPMap<Long, Integer>(new Factory<Integer>() {
			public Integer create() {
				return 0;
			}
		});
		for (int i : array) {
			if (happy.contains((long)i))
				happyCount.put((long)i, happyCount.get((long)i) + 1);
			else
				sameHappy[1]++;
		}
		long[] factorial = new long[length + 1];
		long[] reverseFactorial = new long[length + 1];
		factorial[0] = 1;
		reverseFactorial[0] = 1;
		BigInteger bigMod = BigInteger.valueOf(MOD);
		for (int i = 1; i <= length; i++) {
			factorial[i] = (factorial[i - 1] * i) % MOD;
			reverseFactorial[i] = (reverseFactorial[i - 1] * BigInteger.valueOf(i).modInverse(bigMod).longValue()) % MOD;
		}
		long[] result = new long[count + 1];
		for (int i = 0; i <= count; i++) {
			if (sameHappy[1] >= i) {
				result[i] = factorial[sameHappy[1]] * reverseFactorial[i] % MOD * reverseFactorial[sameHappy[1] - i] % MOD;
			}
		}
		long cur = 1;
		for (int l : happyCount.values()) {
			if (cur * (l + 1) > MOD) {
				for (int i = 0; i <= count; i++)
					result[i] %= MOD;
				cur = 1;
			}
			cur *= l + 1;
			for (int i = count; i > 0; i--)
				result[i] += l * result[i - 1];
		}
		out.printLine(result[count] % MOD);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(outputStream);
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

abstract class Array<T> extends AbstractList<T> {

	public static List<Long> wrap(long...array) {
		return new LongArray(array);
	}

	protected static class LongArray extends Array<Long> {
		protected final long[] array;

		protected LongArray(long[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Long get(int index) {
			return array[index];
		}

		public Long set(int index, Long value) {
			long result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class IntegerUtils {

	public static long[] generateHappy(int digits) {
		long[] happy = new long[(1 << (digits + 1)) - 2];
		happy[0] = 4;
		happy[1] = 7;
		int first = 0;
		int last = 2;
		for (int i = 2; i <= digits; i++) {
			for (int j = 0; j < last - first; j++) {
				happy[last + 2 * j] = 10 * happy[first + j] + 4;
				happy[last + 2 * j + 1] = 10 * happy[first + j] + 7;
			}
			int next = last + 2 * (last - first);
			first = last;
			last = next;
		}
		return happy;
	}

	}

class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

interface Factory<V> {
	public V create();
}