import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.concurrent.atomic.AtomicInteger;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

	static class TaskD {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			int m = in.readInt();
			IntList[] dormitories = new IntList[n];
			IntList[] armies = new IntList[n];
			for (int i = 0; i < n; i++) {
				dormitories[i] = new IntArrayList(1);
				dormitories[i].add(i);
				armies[i] = new IntArrayList(1);
				armies[i].add(i);
			}
			int[] ignoreArmyBefore = new int[n];
			int[] lastExplicitArmy = new int[n];
			Arrays.fill(ignoreArmyBefore, -1);
			Arrays.fill(lastExplicitArmy, -1);
			long[] baseQty = new long[n];
			int[] baseQtyTime = new int[n];
			Arrays.fill(baseQtyTime, -1);
			IntList[] updateTimes = new IntList[n];
			IntList[] updateCumulQtys = new IntList[n];
			long[] allCumulUpds = new long[m + 1];
			int cumulUpdsAt = 1;
			AtomicInteger[] lastArmyVisits = new AtomicInteger[n];
			for (int i = 0; i < n; i++) {
				updateTimes[i] = new IntArrayList(1);
				updateCumulQtys[i] = new IntArrayList(1);
				updateCumulQtys[i].add(0);
				lastArmyVisits[i] = new AtomicInteger(-1);
			}
			for (int i = 0; i < m; i++) {
				char type = in.readCharacter();
				if (type == 'U') {
					int first = in.readInt() - 1;
					int second = in.readInt() - 1;
					if (dormitories[first].size() > dormitories[second].size()) {
						int temp = first;
						first = second;
						second = temp;
					}
					IntList toAdd = dormitories[first];
					dormitories[second].addAll(toAdd);
					for (int current : toAdd.toArray()) {
						int lastArmyVisit = lastArmyVisits[current].get();
						if (lastArmyVisit < ignoreArmyBefore[current]) {
							lastArmyVisit = lastExplicitArmy[current];
						}
						if (baseQtyTime[current] > lastArmyVisit) {
							lastArmyVisit = baseQtyTime[current];
						} else {
							baseQty[current] = 0;
						}
						int lastNotNeededUpdate = get(updateTimes[current], lastArmyVisit);
						baseQty[current] += allCumulUpds[updateCumulQtys[current].get(updateTimes[current].size())] - allCumulUpds[updateCumulQtys[current].get(lastNotNeededUpdate)];
						baseQtyTime[current] = i;
						dormitories[current] = dormitories[second];
						updateTimes[current] = updateTimes[second];
						updateCumulQtys[current] = updateCumulQtys[second];
					}
				} else if (type == 'M') {
					int first = in.readInt() - 1;
					int second = in.readInt() - 1;
					if (armies[first].size() > armies[second].size()) {
						int temp = first;
						first = second;
						second = temp;
					}
					IntList toAdd = armies[first];
					armies[second].addAll(toAdd);
					for (int current : toAdd.toArray()) {
						int lastArmyVisit = lastArmyVisits[current].get();
						if (lastArmyVisit > ignoreArmyBefore[current]) {
							lastExplicitArmy[current] = lastArmyVisit;
						}
						ignoreArmyBefore[current] = i;
						lastArmyVisits[current] = lastArmyVisits[second];
						armies[current] = armies[second];
					}
				} else if (type == 'A') {
					int id = in.readInt() - 1;
					updateTimes[id].add(i);
					allCumulUpds[cumulUpdsAt] = dormitories[id].size() + allCumulUpds[updateCumulQtys[id].back()];
					updateCumulQtys[id].add(cumulUpdsAt++);
				} else if (type == 'Z') {
					int id = in.readInt() - 1;
					lastArmyVisits[id].set(i);
				} else {
					int current = in.readInt() - 1;
					int lastArmyVisit = lastArmyVisits[current].get();
					if (lastArmyVisit < ignoreArmyBefore[current]) {
						lastArmyVisit = lastExplicitArmy[current];
					}
					if (baseQtyTime[current] > lastArmyVisit) {
						lastArmyVisit = baseQtyTime[current];
					} else {
						baseQty[current] = 0;
					}
					int lastNotNeededUpdate = get(updateTimes[current], lastArmyVisit);
					baseQty[current] += allCumulUpds[updateCumulQtys[current].get(updateTimes[current].size())] - allCumulUpds[updateCumulQtys[current].get(lastNotNeededUpdate)];
					baseQtyTime[current] = i;
					out.printLine(baseQty[current]);
				}
			}
		}

		private int get(IntList time, int visit) {
			int left = 0;
			int right = time.size();
			while (left < right) {
				int middle = (left + right) >> 1;
				if (time.get(middle) > visit) {
					right = middle;
				} else {
					left = middle + 1;
				}
			}
			return left;
		}

	}

	static class IntArrayList extends IntList {
		private int[] array;
		private int size;

		public IntArrayList() {
			this(10);
		}

		public IntArrayList(int capacity) {
			array = new int[capacity];
		}

		public IntArrayList(IntList list) {
			this(list.size());
			addAll(list);
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

	static interface IntIterator {
		public int value();

		public void advance();

		public boolean isValid();

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void close() {
			writer.close();
		}

		public void printLine(long i) {
			writer.println(i);
		}

	}

	static abstract class IntCollection {
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

		public void addAll(IntCollection values) {
			for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
		}

	}

	static class InputReader {
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

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}

	static abstract class IntList extends IntCollection implements Comparable<IntList> {
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

		public int back() {
			return get(size() - 1);
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
			IntList list = (IntList) obj;
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
}