import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		int relaxCount = in.readInt();
		int[] relaxBy = IOUtils.readIntArray(in, relaxCount);
		MiscUtils.decreaseByOne(relaxBy);
		boolean[] isRelaxed = new boolean[count];
		for (int i : relaxBy)
			isRelaxed[i] = true;
		if (count == relaxCount || edgeCount > count * (count - 1) / 2 - (relaxCount - 1)) {
			out.printLine(-1);
			return;
		}
		int noRelaxSample = -1;
		int firstRelaxSample = -1;
		int secondRelaxSample = -1;
		for (int i = 0; i < count; i++) {
			if (isRelaxed[i]) {
				if (firstRelaxSample == -1)
					firstRelaxSample = i;
				else
					secondRelaxSample = i;
			} else
				noRelaxSample = i;
		}
		boolean[][] edges = new boolean[count][count];
		edges[firstRelaxSample][secondRelaxSample] = edges[secondRelaxSample][firstRelaxSample] = true;
		addEdge(firstRelaxSample, noRelaxSample, out, edges);
		edgeCount--;
		addEdge(secondRelaxSample, noRelaxSample, out, edges);
		edgeCount--;
		for (int i = 0; i < count; i++) {
			if (i != firstRelaxSample && i != secondRelaxSample && i != noRelaxSample) {
				addEdge(secondRelaxSample, i, out, edges);
				edgeCount--;
			}
		}
		for (int i = 0; i < count && edgeCount > 0; i++) {
			for (int j = i + 1; j < count && edgeCount > 0; j++) {
				if ((i != firstRelaxSample || !isRelaxed[j]) && (j != firstRelaxSample || !isRelaxed[i])) {
					if (addEdge(i, j, out, edges))
						edgeCount--;
				}
			}
		}
    }

	private boolean addEdge(int i, int j, OutputWriter out, boolean[][] edges) {
		if (edges[i][j])
			return false;
		edges[i][j] = edges[j][i] = true;
		out.printLine(i + 1, j + 1);
		return true;
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

	public void printLine(int i) {
		writer.println(i);
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