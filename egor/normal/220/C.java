import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.util.TreeSet;
import java.math.BigInteger;
import java.util.Collections;
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
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] a = IOUtils.readIntArray(in, count);
		int[] b = IOUtils.readIntArray(in, count);
		MiscUtils.decreaseByOne(a, b);
		int[] pA = position(a);
		int[] pB = position(b);
		final int[] diff = new int[count + 1];
		for (int i = 0; i < count; i++)
			diff[i] = pA[i] - pB[i];
		NavigableSet<Integer> set = new TreeSet<Integer>(new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				int value = diff[o1] - diff[o2];
				if (value != 0)
					return value;
				return o1 - o2;
			}
		});
		for (int i = 0; i < count; i++)
			set.add(i);
		for (int i = 0; i < count; i++) {
			int answer = Integer.MAX_VALUE;
			NavigableSet<Integer> head = set.headSet(count, true);
			if (!head.isEmpty())
				answer = Math.min(answer, diff[count] - diff[head.last()]);
			NavigableSet<Integer> tail = set.tailSet(count, true);
			if (!tail.isEmpty())
				answer = Math.min(answer, diff[tail.first()] - diff[count]);
			out.printLine(answer);
			diff[count]--;
			set.remove(b[i]);
			diff[b[i]] -= count;
			set.add(b[i]);
		}
	}

	private int[] position(int[] array) {
		int[] result = new int[array.length];
		for (int i = 0; i < array.length; i++)
			result[array[i]] = i;
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

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}