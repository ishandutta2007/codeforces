import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;

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
	int sx, sy;
	int[][] start;
	List<IntPair> answer;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int rowCount = in.readInt();
		int columnCount = in.readInt();
		start = IOUtils.readIntTable(in, rowCount, columnCount);
		int[][] target = IOUtils.readIntTable(in, rowCount, columnCount);
		if (rowCount == 1) {
			int from = 0;
			int to = columnCount - 1;
			while (start[0][from] == target[0][from]) {
				from++;
			}
			while (start[0][to] == target[0][to]) {
				to--;
			}
			if (start[0][from] == target[0][to]) {
				boolean good = true;
				for (int j = from; j < to; j++) {
					if (start[0][j + 1] != target[0][j]) {
						good = false;
						break;
					}
				}
				if (good) {
					out.printLine(to - from);
					for (int j = from; j <= to; j++) {
						out.printLine(1, j + 1);
					}
					return;
				}
			}
			if (start[0][to] == target[0][from]) {
				boolean good = true;
				for (int j = from; j < to; j++) {
					if (start[0][j] != target[0][j + 1]) {
						good = false;
						break;
					}
				}
				if (good) {
					out.printLine(to - from);
					for (int j = to; j >= from; j--) {
						out.printLine(1, j + 1);
					}
					return;
				}
			}
			out.printLine(-1);
			return;
		}
		if (columnCount == 1) {
			int from = 0;
			int to = rowCount - 1;
			while (start[from][0] == target[from][0]) {
				from++;
			}
			while (start[to][0] == target[to][0]) {
				to--;
			}
			if (start[from][0] == target[to][0]) {
				boolean good = true;
				for (int j = from; j < to; j++) {
					if (start[j + 1][0] != target[j][0]) {
						good = false;
						break;
					}
				}
				if (good) {
					out.printLine(to - from);
					for (int j = from; j <= to; j++) {
						out.printLine(j + 1, 1);
					}
					return;
				}
			}
			if (start[to][0] == target[from][0]) {
				boolean good = true;
				for (int j = from; j < to; j++) {
					if (start[j][0] != target[j + 1][0]) {
						good = false;
						break;
					}
				}
				if (good) {
					out.printLine(to - from);
					for (int j = to; j >= from; j--) {
						out.printLine(j + 1, 1);
					}
					return;
				}
			}
			out.printLine(-1);
			return;
		}
		sx = -1;
		sy = -1;
		answer = new ArrayList<>();
		for (int i = 0; i < rowCount && sx == -1; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (start[i][j] == target[0][0]) {
					sx = i;
					sy = j;
					break;
				}
			}
		}
		if (sx == -1) {
			out.printLine(-1);
			return;
		}
		answer.add(new IntPair(sx, sy));
		for (int i = rowCount - 1; i >= 2; i--) {
			for (int j = columnCount - 1; j >= 0; j--) {
				int cx = -1;
				int cy = -1;
				for (int k = 0; k < i && cx == -1; k++) {
					for (int l = 0; l < columnCount; l++) {
						if (start[k][l] == target[i][j] && (k != sx || l != sy)) {
							cx = k;
							cy = l;
							break;
						}
					}
				}
				if (cx == -1) {
					for (int k = 0; k <= j; k++) {
						if (start[i][k] == target[i][j] && (i != sx || k != sy)) {
							cx = i;
							cy = k;
							break;
						}
					}
					if (cx == -1) {
						out.printLine(-1);
						return;
					}
				}
				if (cx == i && cy == j) {
					continue;
				}
				if (cy != 0) {
					if (cx == sx) {
						if (sx == 0) {
							go(sx + 1, sy);
						} else {
							go(sx - 1, sy);
						}
					}
					for (int k = sy - 1; k >= 0; k--) {
						go(sx, k);
					}
					for (int k = sx + 1; k <= cx; k++) {
						go(k, sy);
					}
					for (int k = sx - 1; k >= cx; k--) {
						go(k, sy);
					}
					for (int k = 1; k <= cy; k++) {
						go(sx, k);
					}
					cy--;
					while (cy > 0) {
						if (sx == 0) {
							go(sx + 1, sy - 1);
							go(sx - 1, sy - 1);
							go(sx, sy + 1);
						} else {
							go(sx - 1, sy - 1);
							go(sx + 1, sy - 1);
							go(sx, sy + 1);
						}
						cy--;
					}
				} else {
					while (sy > 1) {
						go(sx, sy - 1);
					}
					if (cx != sx && sy != 0) {
						go(sx, sy - 1);
					}
					while (sx + 1 < cx) {
						go(sx + 1, sy);
					}
					while (sx - 1 > cx) {
						go(sx - 1, sy);
					}
					if (sy == 0) {
						go(cx, 1);
					}
				}
				if (cx < i) {
					go(sx + 1, sy - 1);
					go(sx - 1, sy);
					cx++;
					while (cx < i) {
						go(sx + 1, sy + 1);
						go(sx + 1, sy - 1);
						go(sx - 1, sy);
						cx++;
					}
				} else {
					go(sx - 1, sy - 1);
				}
				if (cy < j) {
					go(sx + 1, sy + 1);
					go(sx, sy - 1);
					cy++;
					while (cy < j) {
						go(sx - 1, sy + 1);
						go(sx + 1, sy + 1);
						go(sx, sy - 1);
						cy++;
					}
				}
			}
		}
		for (int i = columnCount - 1; i >= 2; i--) {
			for (int j = 1; j >= 0; j--) {
				int cx = -1;
				int cy = -1;
				for (int k = 0; k < i && cx == -1; k++) {
					for (int l = 0; l < 2; l++) {
						if (start[l][k] == target[j][i] && (l != sx || k != sy)) {
							cx = l;
							cy = k;
						}
					}
				}
				if (cx == -1) {
					for (int k = 0; k <= j; k++) {
						if (start[k][i] == target[j][i] && (k != sx || i != sy)) {
							cx = k;
							cy = i;
						}
					}
					if (cx == -1) {
						out.printLine(-1);
						return;
					}
				}
				if (cx == j && cy == i) {
					continue;
				}
				while (cy - sy > 1) {
					go(sx, sy + 1);
				}
				while (sy - cy > 1) {
					go(sx, sy - 1);
				}
				if (sx != (cx ^ 1) || cy != sy) {
					go(cx ^ 1, cy);
				}
				if (cx != j) {
					go(cx, cy);
					cx ^= 1;
				}
				if (cy < i) {
					go(cx, cy + 1);
					go(cx, cy);
					cy++;
					while (cy < i) {
						go(sx ^ 1, sy + 1);
						go(sx ^ 1, sy + 1);
						go(sx, sy - 1);
						cy++;
					}
				}
			}
		}
		if (sx != 0 || sy != 0) {
			go(0, 0);
		}
		if (start[1][1] != target[1][1]) {
			if (start[0][1] == target[1][1]) {
				go(0, 1);
				go(1, 1);
				go(0, 0);
			} else if (start[1][0] == target[1][1]) {
				go(1, 0);
				go(1, 1);
				go(0, 0);
			} else {
				out.printLine(-1);
				return;
			}
		}
		if (start[0][1] != target[0][1]) {
			if (start[1][0] == target[0][1]) {
				go(1, 0);
				go(0, 1);
				go(0, 0);
			} else {
				out.printLine(-1);
				return;
			}
		}
		if (start[1][0] != target[1][0]) {
			out.printLine(-1);
			return;
		}
		out.printLine(answer.size() - 1);
		for (IntPair pair : answer) {
			out.printLine(pair.first + 1, pair.second + 1);
		}
    }

	private void go(int nx, int ny) {
		int temp = start[sx][sy];
		start[sx][sy] = start[nx][ny];
		start[nx][ny] = temp;
		sx = nx;
		sy = ny;
		answer.add(new IntPair(nx, ny));
	}
}

class IntPair implements Comparable<IntPair> {
	public final int first, second;

	public IntPair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		IntPair intPair = (IntPair) o;

		return first == intPair.first && second == intPair.second;

	}

	public int hashCode() {
		int result = first;
		result = 31 * result + second;
		return result;
	}

	public int compareTo(IntPair o) {
		if (first < o.first)
			return -1;
		if (first > o.first)
			return 1;
		if (second < o.second)
			return -1;
		if (second > o.second)
			return 1;
		return 0;
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

	public static int[][] readIntTable(InputReader in, int rowCount, int columnCount) {
		int[][] table = new int[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readIntArray(in, columnCount);
		return table;
	}

}