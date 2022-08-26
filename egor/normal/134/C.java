import java.io.IOException;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Queue;
import java.math.BigInteger;
import java.util.Collection;
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
		int edgeCount = in.readInt() / 2;
		final int[] degrees = IOUtils.readIntArray(in, count);
		Queue<Integer> queue = new PriorityQueue<Integer>(count, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return degrees[o2] - degrees[o1];
			}
		});
		for (int i = 0; i < count; i++) {
			if (degrees[i] != 0)
				queue.add(i);
		}
		int[] from = new int[edgeCount];
		int[] to = new int[edgeCount];
		int index = 0;
		int[] back = new int[count];
		while (queue.size() != 0) {
			int current = queue.poll();
			if (degrees[current] > queue.size()) {
				out.printLine("No");
				return;
			}
			for (int i = 0; i < degrees[current]; i++) {
				back[i] = queue.poll();
				degrees[back[i]]--;
				from[index] = current + 1;
				to[index++] = back[i] + 1;
			}
			for (int i = 0; i < degrees[current]; i++) {
				if (degrees[back[i]] != 0)
					queue.add(back[i]);
			}
		}
		out.printLine("Yes");
		out.printLine(edgeCount);
		for (int i = 0; i < edgeCount; i++) {
			out.printLine(from[i], to[i]);
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