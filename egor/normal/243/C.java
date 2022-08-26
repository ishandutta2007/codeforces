import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] x = new int[count + 1];
		int[] y = new int[count + 1];
		for (int i = 0; i < count; i++) {
			char direction = in.readCharacter();
			int delta = in.readInt();
			x[i + 1] = x[i];
			y[i + 1] = y[i];
			if (direction == 'U')
				y[i + 1] -= delta;
			else if (direction == 'D')
				y[i + 1] += delta;
			else if (direction == 'L')
				x[i + 1] -= delta;
			else
				x[i + 1] += delta;
		}
		int[] ux = new int[3 * x.length];
		for (int i = 0; i < x.length; i++) {
			ux[3 * i] = x[i];
			ux[3 * i + 1] = x[i] - 1;
			ux[3 * i + 2] = x[i] + 1;
		}
		Arrays.sort(ux);
		ux = ArrayUtils.unique(ux);
		int[] uy = new int[3 * y.length];
		for (int i = 0; i < y.length; i++) {
			uy[3 * i] = y[i];
			uy[3 * i + 1] = y[i] - 1;
			uy[3 * i + 2] = y[i] + 1;
		}
		Arrays.sort(uy);
		uy = ArrayUtils.unique(uy);
		boolean[][] map = new boolean[ux.length + 1][uy.length + 1];
		for (int i = 0; i < count; i++) {
			if (x[i] == x[i + 1]) {
				int index = Arrays.binarySearch(ux, x[i]);
				int from = Arrays.binarySearch(uy, y[i]);
				int to = Arrays.binarySearch(uy, y[i + 1]);
				if (from > to) {
					int temp = from;
					from = to;
					to = temp;
				}
				for (int j = from; j <= to; j++)
					map[index][j] = true;
			} else {
				int index = Arrays.binarySearch(uy, y[i]);
				int from = Arrays.binarySearch(ux, x[i]);
				int to = Arrays.binarySearch(ux, x[i + 1]);
				if (from > to) {
					int temp = from;
					from = to;
					to = temp;
				}
				for (int j = from; j <= to; j++)
					map[j][index] = true;
			}
		}
		int[] xQueue = new int[map.length * map[0].length];
		int[] yQueue = new int[map.length * map[0].length];
		int size = 1;
		boolean[][] visited = new boolean[map.length][map[0].length];
		visited[0][0] = true;
		for (int i = 0; i < size; i++) {
			int xx = xQueue[i];
			int yy = yQueue[i];
			for (int j = 0; j < 4; j++) {
				int nxx = xx + MiscUtils.DX4[j];
				int nyy = yy + MiscUtils.DY4[j];
				if (nxx >= 0 && nxx < map.length && nyy >= 0 && nyy < map[0].length && !map[nxx][nyy] && !visited[nxx][nyy]) {
					visited[nxx][nyy] = true;
					xQueue[size] = nxx;
					yQueue[size++] = nyy;
				}
			}
		}
		long answer = 0;
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				if (!visited[i][j]) {
					long dx = ux[i + 1] - ux[i];
					long dy = uy[j + 1] - uy[j];
					answer += dx * dy;
				}
			}
		}
		out.printLine(answer);
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

class ArrayUtils {

	public static int[] unique(int[] array) {
		return unique(array, 0, array.length);
	}

	public static int[] unique(int[] array, int from, int to) {
		if (from == to)
			return new int[0];
		int count = 1;
		for (int i = from + 1; i < to; i++) {
			if (array[i] != array[i - 1])
				count++;
		}
		int[] result = new int[count];
		result[0] = array[from];
		int index = 1;
		for (int i = from + 1; i < to; i++) {
			if (array[i] != array[i - 1])
				result[index++] = array[i];
		}
		return result;
	}

	}

class MiscUtils {
	public static final int[] DX4 = {1, 0, -1, 0};
	public static final int[] DY4 = {0, -1, 0, 1};

	}