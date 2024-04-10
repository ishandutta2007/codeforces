import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskC {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			char[] s = in.readString().toCharArray();
			CharList stack = new CharArrayList(s.length);
			int answer = 0;
			char[] opening = new char[256];
			opening['>'] = '<';
			opening[']'] = '[';
			opening[')'] = '(';
			opening['}'] = '{';
			for (char c : s) {
				if (opening[c] == 0) {
					stack.add(c);
				} else {
					if (stack.isEmpty()) {
						out.printLine("Impossible");
						return;
					} else if (stack.last() != opening[c]) {
						answer++;
					}
					stack.popLast();
				}
			}
			if (!stack.isEmpty()) {
				out.printLine("Impossible");
				return;
			}
			out.printLine(answer);
		}

	}

	static interface CharStream extends Iterable<Character>, Comparable<CharStream> {
		public CharIterator charIterator();

		default public Iterator<Character> iterator() {
			return new Iterator<Character>() {
				private CharIterator it = charIterator();

				public boolean hasNext() {
					return it.isValid();
				}

				public Character next() {
					char result = it.value();
					it.advance();
					return result;
				}
			};
		}

		default public int compareTo(CharStream c) {
			CharIterator it = charIterator();
			CharIterator jt = c.charIterator();
			while (it.isValid() && jt.isValid()) {
				char i = it.value();
				char j = jt.value();
				if (i < j) {
					return -1;
				} else if (i > j) {
					return 1;
				}
				it.advance();
				jt.advance();
			}
			if (it.isValid()) {
				return 1;
			}
			if (jt.isValid()) {
				return -1;
			}
			return 0;
		}

	}

	static interface CharIterator {
		public char value() throws NoSuchElementException;

		public boolean advance();

		public boolean isValid();

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

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
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

	static class CharArrayList extends CharAbstractStream implements CharList {
		private int size;
		private char[] data;

		public CharArrayList() {
			this(3);
		}

		public CharArrayList(int capacity) {
			data = new char[capacity];
		}

		public CharArrayList(CharCollection c) {
			this(c.size());
			addAll(c);
		}

		public CharArrayList(CharStream c) {
			this();
			if (c instanceof CharCollection) {
				ensureCapacity(((CharCollection) c).size());
			}
			addAll(c);
		}

		public CharArrayList(CharArrayList c) {
			size = c.size();
			data = c.data.clone();
		}

		public CharArrayList(char[] arr) {
			size = arr.length;
			data = arr.clone();
		}

		public int size() {
			return size;
		}

		public char get(int at) {
			if (at >= size) {
				throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
			}
			return data[at];
		}

		private void ensureCapacity(int capacity) {
			if (data.length >= capacity) {
				return;
			}
			capacity = Math.max(2 * data.length, capacity);
			data = Arrays.copyOf(data, capacity);
		}

		public void addAt(int index, char value) {
			ensureCapacity(size + 1);
			if (index > size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size) {
				System.arraycopy(data, index, data, index + 1, size - index);
			}
			data[index] = value;
			size++;
		}

		public void removeAt(int index) {
			if (index >= size || index < 0) {
				throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
			}
			if (index != size - 1) {
				System.arraycopy(data, index + 1, data, index, size - index - 1);
			}
			size--;
		}

	}

	static interface CharList extends CharReversableCollection {
		public abstract char get(int index);

		public abstract void addAt(int index, char value);

		public abstract void removeAt(int index);

		default public char last() {
			return get(size() - 1);
		}

		default public CharIterator charIterator() {
			return new CharIterator() {
				private int at;
				private boolean removed;

				public char value() {
					if (removed) {
						throw new IllegalStateException();
					}
					return get(at);
				}

				public boolean advance() {
					at++;
					removed = false;
					return isValid();
				}

				public boolean isValid() {
					return !removed && at < size();
				}

				public void remove() {
					removeAt(at);
					at--;
					removed = true;
				}
			};
		}


		default public void add(char value) {
			addAt(size(), value);
		}

		default public void popLast() {
			removeAt(size() - 1);
		}

	}

	static interface CharReversableCollection extends CharCollection {
	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
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

	static abstract class CharAbstractStream implements CharStream {

		public String toString() {
			StringBuilder builder = new StringBuilder();
			boolean first = true;
			for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
				if (first) {
					first = false;
				} else {
					builder.append(' ');
				}
				builder.append(it.value());
			}
			return builder.toString();
		}


		public boolean equals(Object o) {
			if (!(o instanceof CharStream)) {
				return false;
			}
			CharStream c = (CharStream) o;
			CharIterator it = charIterator();
			CharIterator jt = c.charIterator();
			while (it.isValid() && jt.isValid()) {
				if (it.value() != jt.value()) {
					return false;
				}
				it.advance();
				jt.advance();
			}
			return !it.isValid() && !jt.isValid();
		}


		public int hashCode() {
			int result = 0;
			for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
				result *= 31;
				result += it.value();
			}
			return result;
		}

	}

	static interface CharCollection extends CharStream {
		public int size();

		default public boolean isEmpty() {
			return size() == 0;
		}

		default public void add(char value) {
			throw new UnsupportedOperationException();
		}

		default public CharCollection addAll(CharStream values) {
			for (CharIterator it = values.charIterator(); it.isValid(); it.advance()) {
				add(it.value());
			}
			return this;
		}

	}
}