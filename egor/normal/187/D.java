import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
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
		long green = in.readInt();
		long red = in.readInt();
		long period = green + red;
		long[] lengths = IOUtils.readLongArray(in, count + 1);
		for (int i = 1; i <= count; i++)
			lengths[i] += lengths[i - 1];
		NavigableSet<Vertex> vertices = new TreeSet<Vertex>();
		vertices.add(new GreenVertex(0));
		for (int i = count - 1; i >= 0; i--) {
			long start = (period - lengths[i] % period) % period;
			if (start + green <= period) {
				Vertex fake = new GreenVertex(start);
				if (vertices.contains(fake))
					remove(vertices.headSet(fake, false));
				else {
					Vertex last = vertices.headSet(fake, false).last();
					remove(vertices.headSet(fake, false));
					last.setStart(start);
					vertices.add(last);
				}
				long additionalWait = vertices.headSet(fake, true).last().totalWait(start);
				remove(vertices.tailSet(new GreenVertex(start + green), true));
				if (start + green < period)
					vertices.add(new RedVertex(start + green, start + period, additionalWait));
				if (start != 0)
					vertices.add(new RedVertex(0, start, additionalWait));
			} else {
				Vertex fake = new GreenVertex(start);
				if (vertices.contains(fake))
					remove(vertices.subSet(new GreenVertex(start - red), true, fake, false));
				else {
					Vertex last = vertices.headSet(fake, false).last();
					remove(vertices.subSet(new GreenVertex(start - red), true, fake, false));
					if (last.start() >= start - red) {
						last.setStart(start);
						vertices.add(last);
					} else {
						last = last.clone();
						last.setStart(start);
						vertices.add(last);
					}
				}
				vertices.add(new RedVertex(start - red, start, vertices.headSet(fake, true).last().totalWait(start)));
			}
		}
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			long time = in.readInt();
			out.printLine(vertices.headSet(new GreenVertex(time % period), true).last().totalWait(time % period) + lengths[count] + time);
		}
	}

	private void remove(NavigableSet<Vertex> vertices) {
		vertices.clear();
	}

	abstract static class Vertex implements Comparable<Vertex> {
		long start;

		protected Vertex(long start) {
			this.start = start;
		}

		abstract long totalWait(long atTime);
		public abstract Vertex clone();

		long start() {
			return start;
		}

		void setStart(long newStart) {
			start = newStart;
		}

		public int compareTo(Vertex o) {
			return IntegerUtils.longCompare(start, o.start());
		}

		public boolean equals(Object o) {
			if (this == o) return true;
			if (!(o instanceof Vertex)) return false;

			Vertex vertex = (Vertex) o;

			if (start != vertex.start) return false;

			return true;
		}

		public int hashCode() {
			return (int) (start ^ (start >>> 32));
		}
	}

	static class RedVertex extends Vertex {
		final long waitTill;
		final long additionalWait;

		RedVertex(long start, long waitTill, long additionalWait) {
			super(start);
			this.waitTill = waitTill;
			this.additionalWait = additionalWait;
		}

		public long totalWait(long atTime) {
			if (waitTill < atTime)
				throw new RuntimeException();
			return waitTill - atTime + additionalWait;
		}

		public Vertex clone() {
			return new RedVertex(start, waitTill, additionalWait);
		}

	}

	static class GreenVertex extends Vertex {
		GreenVertex(long start) {
			super(start);
		}

		public long totalWait(long atTime) {
			return 0;
		}

		public Vertex clone() {
			return new GreenVertex(start);
		}
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	}

class IntegerUtils {

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}