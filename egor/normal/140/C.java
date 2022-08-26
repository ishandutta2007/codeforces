import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Queue;
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
		int[] radius = IOUtils.readIntArray(in, count);
		Map<Integer, Integer> index = new HashMap<Integer, Integer>();
		final int[] perRadius = new int[count];
		int sizeCount = 0;
		for (int i : radius) {
			if (!index.containsKey(i)) {
				radius[sizeCount] = i;
				index.put(i, sizeCount++);
			}
			perRadius[index.get(i)]++;
		}
		Queue<Integer> queue = new PriorityQueue<Integer>(sizeCount, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				return perRadius[o2] - perRadius[o1];
			}
		});
		for (int i = 0; i < sizeCount; i++)
			queue.add(i);
		int answer = 0;
		int[][] result = new int[count / 3][3];
		while (queue.size() > 2) {
			for (int i = 0; i < 3; i++)
				result[answer][i] = queue.poll();
			for (int i : result[answer]) {
				if (--perRadius[i] != 0)
					queue.add(i);
			}
			for (int i = 0; i < 3; i++)
				result[answer][i] = radius[result[answer][i]];
			Arrays.sort(result[answer]);
			int temp = result[answer][0];
			result[answer][0] = result[answer][2];
			result[answer][2] = temp;
			answer++;
		}
		out.printLine(answer);
		for (int i = 0; i < answer; i++)
			out.printLine(result[i][0], result[i][1], result[i][2]);
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