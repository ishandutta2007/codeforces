import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
import java.util.NoSuchElementException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int blockCount = in.readInt();
		int[] from = new int[blockCount];
		int[] to = new int[blockCount];
		int[] appear = new int[blockCount];
		IOUtils.readIntArrays(in, from, to, appear);
		int[] start = IOUtils.readIntArray(in, count);
		List<Event> events = new ArrayList<Event>();
//		for (int i = 0; i < blockCount; i++) {
//			events[2 * i] = new Event(Event.Type.ADD, i, appear[i] - to[i]);
//			events[2 * i + 1] = new Event(Event.Type.FIX, i, appear[i] - from[i]);
//		}
		for (int i = 0; i < count; i++)
			events.add(new Event(Event.Type.TOURIST, i, start[i]));
		int[] order = ArrayUtils.order(appear);
		NavigableSet<Pair<Integer, Integer>> occupied = new TreeSet<Pair<Integer, Integer>>();
		for (int i : order) {
			Pair<Integer, Integer> key = Pair.makePair(from[i], to[i]);
			Pair<Integer, Integer> last = occupied.floor(key);
			int left = from[i];
			int current = from[i];
			if (last != null && last.second >= from[i]) {
				left = last.first;
				current = last.second;
				occupied.remove(last);
			}
			NavigableSet<Pair<Integer, Integer>> subSet = occupied.subSet(key, false, Pair.makePair(to[i], Integer.MAX_VALUE), false);
			Iterator<Pair<Integer, Integer>> iterator = subSet.iterator();
			while (iterator.hasNext()) {
				Pair<Integer, Integer> next = iterator.next();
				if (next.first > current) {
					events.add(new Event(Event.Type.ADD, i, appear[i] - next.first));
					events.add(new Event(Event.Type.FIX, i, appear[i] - current));
				}
				current = Math.max(current, next.second);
				iterator.remove();
			}
			if (current < to[i]) {
				events.add(new Event(Event.Type.ADD, i, appear[i] - to[i]));
				events.add(new Event(Event.Type.FIX, i, appear[i] - current));
				current = to[i];
			}
			occupied.add(Pair.makePair(left, current));
		}
		Collections.sort(events);
		long[] answer = new long[count];
		long current = 0;
		long delta = 0;
		int last = Integer.MIN_VALUE;
		for (Event event : events) {
			current += delta * (event.value - last);
			last = event.value;
			if (event.type == Event.Type.ADD)
				delta++;
			else if (event.type == Event.Type.FIX)
				delta--;
			else
				answer[event.index] = current;
		}
		for (long i : answer)
			out.printLine(i);
	}

	static class Event implements Comparable<Event> {
		public int compareTo(Event o) {
			if (value == o.value)
				return 0;
			else if (value < o.value)
				return -1;
			else
				return 1;
		}

		enum Type {
			ADD, FIX, TOURIST
		}

		final Type type;
		final int index;
		final int value;

		Event(Type type, int index, int value) {
			this.type = type;
			this.index = index;
			this.value = value;
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

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

interface IntComparator {

	public int compare(int first, int second);
}