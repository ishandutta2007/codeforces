import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
import java.util.NoSuchElementException;
import java.util.TreeSet;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		in.readInt();
		int[] height = new int[count];
		int[] left = new int[count];
		int[] right = new int[count];
		IOUtils.readIntArrays(in, height, left, right);
		int[] order = ArrayUtils.order(height);
		NavigableSet<Segment> segments = new TreeSet<Segment>();
		segments.add(new Segment((int)(-1e9 - 1), (int)(1e9 + 1), (int) 2e9, (int)(-1e9 - 1), (int)(1e9 + 1)));
		for (int i : order) {
			Segment leftFake = new Segment(left[i], 0, 0, 0, 0);
			Segment rightFake = new Segment(right[i], 0, 0, 0, 0);
			Segment toLeft = segments.floor(leftFake);
			Segment toRight = segments.lower(rightFake);
			if (toLeft == toRight) {
				segments.remove(toLeft);
				if (left[i] > toLeft.left)
					segments.add(new Segment(toLeft.left, left[i], toLeft.value, toLeft.wholeLeft, toLeft.wholeRight));
				if (right[i] < toLeft.right)
					segments.add(new Segment(right[i], toLeft.right, toLeft.value, toLeft.wholeLeft, toLeft.wholeRight));
				segments.add(new Segment(left[i], right[i], Math.min(right[i] - left[i], toLeft.value), left[i], right[i]));
				continue;
			}
			segments.remove(toLeft);
			segments.remove(toRight);
			int currentResult = 0;
			if (toLeft.right == toLeft.wholeRight)
				currentResult = Math.max(currentResult, Math.min(toLeft.right - left[i], toLeft.value));
			if (left[i] > toLeft.left)
				segments.add(new Segment(toLeft.left, left[i], toLeft.value, toLeft.wholeLeft, toLeft.wholeRight));
			if (toRight.left == toRight.wholeLeft)
				currentResult = Math.max(currentResult, Math.min(right[i] - toRight.left, toRight.value));
			if (right[i] < toRight.right)
				segments.add(new Segment(right[i], toRight.right, toRight.value, toRight.wholeLeft, toRight.wholeRight));
			Iterator<Segment> iterator = segments.subSet(leftFake, true, rightFake, false).iterator();
			while (iterator.hasNext()) {
				Segment segment = iterator.next();
				iterator.remove();
				if (segment.left == segment.wholeLeft && segment.right == segment.wholeRight)
					currentResult = Math.max(currentResult, Math.min(segment.right - segment.left, segment.value));
			}
			segments.add(new Segment(left[i], right[i], currentResult, left[i], right[i]));
		}
		int answer = 0;
		for (Segment segment : segments) {
			if (segment.wholeLeft == segment.left && segment.wholeRight == segment.right)
				answer = Math.max(answer, segment.value);
		}
		out.printLine(answer);
	}

	static class Segment implements Comparable<Segment> {
		final int left, right, wholeLeft, wholeRight, value;

		Segment(int left, int right, int value, int wholeLeft, int wholeRight) {
			this.left = left;
			this.right = right;
			this.value = value;
			this.wholeLeft = wholeLeft;
			this.wholeRight = wholeRight;
		}

		public int compareTo(Segment o) {
			if (left < o.left)
				return -1;
			if (left > o.left)
				return 1;
			return 0;
		}
	}

/*	public class IntervalTree {
		protected int size;
		protected int[] value;
		protected int[] delta;

		protected IntervalTree(int size) {
			this.size = size;
			int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
			value = new int[nodeCount];
			delta = new int[nodeCount];
			init();
		}

		public void init() {
			init(0, 0, size - 1);
		}

		private void init(int root, int left, int right) {
			if (left == right) {
				value[root] = 0;
				delta[root] = -2;
			} else {
				int middle = (left + right) >> 1;
				init(2 * root + 1, left, middle);
				init(2 * root + 2, middle + 1, right);
				value[root] = 0;
				delta[root] = -2;
			}
		}

		public void update(int from, int to, int delta) {
			update(0, 0, size - 1, from, to, delta);
		}

		private void update(int root, int left, int right, int from, int to, int delta) {
			if (left > to || right < from)
				return;
			if (left >= from && right <= to) {
				value[root] = delta;
				this.delta[root] = delta;
				return;
			}
			if (this.delta[root] != -2) {
				this.value[2 * root + 1] = this.delta[2 * root + 1] = this.delta[root];
				this.value[2 * root + 2] = this.delta[2 * root + 2] = this.delta[root];
				this.delta[root] = -2;
			}
			int middle = (left + right) >> 1;
			update(2 * root + 1, left, middle, from, to, delta);
			update(2 * root + 2, middle + 1, right, from, to, delta);
			int leftValue = value[2 * root + 1];
			int rightValue = value[2 * root + 2];
		}

		public int query(int from, int to) {
			return query(0, 0, size - 1, from, to);
		}

		private int query(int root, int left, int right, int from, int to) {
			if (left > to || right < from)
				return -2;
			if (left >= from && right <= to)
				return value[root];
			if (delta[root] != -2)
				return delta[root];
			int middle = (left + right) >> 1;
			int leftValue = query(2 * root + 1, left, middle, from, to);
			int rightValue = query(2 * root + 2, middle + 1, right, from, to);
			if (leftValue < 0)
				return rightValue;
			if (rightValue < 0)
				return leftValue;
			if (Math.max(compressedLeft[leftValue], compressedLeft[rightValue]) < Math.min(compressedRight[leftValue], compressedRight[rightValue])) {
				if (height[leftValue] > height[rightValue])
					return leftValue;
				else
					return rightValue;
			}
			int leftResult = Math.min(Math.min(TaskD.this.right[current], TaskD.this.right[leftValue]) - Math.max(TaskD.this.left[current], TaskD.this.left[leftValue]), answer[leftValue]);
			int rightResult = Math.min(Math.min(TaskD.this.right[current], TaskD.this.right[rightValue]) - Math.max(TaskD.this.left[current], TaskD.this.left[rightValue]), answer[rightValue]);
			if (leftResult > rightResult)
				return leftValue;
			else
				return rightValue;
		}
	}*/

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

	}

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class ArrayUtils {
	private static int[] tempInt = new int[0];

	public static int[] createOrder(int size) {
		int[] order = new int[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

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

	public static int[] order(final int[] array) {
		return sort(createOrder(array.length), new IntComparator() {
			public int compare(int first, int second) {
				if (array[first] < array[second])
					return -1;
				if (array[first] > array[second])
					return 1;
				return 0;
			}
		});
	}

	}

interface IntComparator {

	public int compare(int first, int second);
}