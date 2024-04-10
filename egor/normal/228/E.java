import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		boolean[][] roads = new boolean[edgeCount][count + 1];
		for (int i = 0; i < edgeCount; i++) {
			int from = in.readInt() - 1;
			int to = in.readInt() - 1;
			roads[i][from] = true;
			roads[i][to] = true;
			roads[i][count] = in.readInt() == 0;
		}
		boolean[] taken = new boolean[edgeCount];
		for (int i = 0; i < count; i++) {
			int index = -1;
			for (int j = 0; j < edgeCount; j++) {
				if (!taken[j] && roads[j][i]) {
					index = j;
					break;
				}
			}
			if (index == -1)
				continue;
			taken[index] = true;
			for (int j = count; j >= i; j--) {
				if (roads[index][j]) {
					for (int k = 0; k < edgeCount; k++) {
						if (k != index && roads[k][i])
							roads[k][j] = !roads[k][j];
					}
				}
			}
		}
		List<Integer> answer = new ArrayList<Integer>();
		for (int i = 0; i < edgeCount; i++) {
			if (roads[i][count]) {
				boolean found = false;
				for (int j = 0; j < count; j++) {
					if (roads[i][j]) {
						answer.add(j + 1);
						found = true;
						break;
					}
				}
				if (!found) {
					out.printLine("Impossible");
					return;
				}
			}
		}
		out.printLine(answer.size());
		out.printLine(answer.toArray());
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