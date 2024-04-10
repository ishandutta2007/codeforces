import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		final int[] current = new int[count + 1];
		int[] taskCount = new int[count];
		long[] x = new long[count];
		long[] y = new long[count];
		long[] m = new long[count];
		int totalTasks = 0;
		for (int i = 0; i < count; i++) {
			taskCount[i] = in.readInt();
			current[i] = in.readInt();
			x[i] = in.readInt();
			y[i] = in.readInt();
			m[i] = in.readInt();
			totalTasks += taskCount[i];
		}
		int[] pointer = new int[count];
		Heap cur = new Heap(current);
		Heap next = new Heap(current);
		for (int i = 0; i < count; i++)
			cur.add(i);
		int[] resourceNeed = new int[0];
		int[] scientistIndex = new int[0];
		if (totalTasks <= 200000) {
			resourceNeed = new int[totalTasks];
			scientistIndex = new int[totalTasks];
		}
		int bad = 0;
		for (int i = 0; i < count; i++) {
			long c = current[i];
			int curBad = 0;
			for (int j = 1; j < taskCount[i]; j++) {
				long cc = (c * x[i] + y[i]) % m[i];
				if (cc < c)
					curBad++;
				c = cc;
			}
			bad = Math.max(bad, curBad);
		}
		if (totalTasks > 200000) {
			out.printLine(bad);
			return;
		}
		for (int i = 0; i < totalTasks; i++) {
			if (cur.size == 0) {
//				bad++;
				Heap temp = cur;
				cur = next;
				next = temp;
			}
			int index = cur.poll();
			if (totalTasks <= 200000) {
				scientistIndex[i] = index + 1;
				resourceNeed[i] = current[index];
			}
			current[count] = current[index];
			if (++pointer[index] != taskCount[index]) {
				current[index] = (int) ((current[index] * x[index] + y[index]) % m[index]);
				if (current[index] < current[count])
					next.add(index);
				else
					cur.add(index);
			}
		}
		out.printLine(bad);
		if (totalTasks <= 200000) {
			for (int i = 0; i < totalTasks; i++)
				out.printLine(resourceNeed[i], scientistIndex[i]);
		}
	}
}

class Heap {
	int[] values;
	private final int[] array;
	int size = 0;

	Heap(int[] array) {
		this.array = array;
		values = new int[array.length];
	}

	void add(int value) {
		size++;
		siftUp(size - 1, value);
	}

	private void siftUp(int k, int value) {
		while (k > 0) {
			int parent = (k - 1) >> 1;
			if (array[values[parent]] <= array[value])
				break;
			values[k] = values[parent];
			k = parent;
		}
		values[k] = value;
	}

	int poll() {
		size--;
		int result = values[0];
		if (size != 0)
			siftDown(0, values[size]);
		return result;
	}

	private void siftDown(int k, int value) {
		int half = size >> 1;
		while (k < half) {
			int child = (k << 1) + 1;
			int right = child + 1;
			if (right < size && array[values[child]] > array[values[right]])
				child = right;
			if (array[value] <= array[child])
				break;
			values[k] = values[child];
			k = child;
		}
		values[k] = value;
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