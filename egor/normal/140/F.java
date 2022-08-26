import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.awt.Point;
import java.util.Set;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.HashSet;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int lost = in.readInt();
		if (count <= lost) {
			out.printLine(-1);
			return;
		}
		Point[] points = new Point[count];
		for (int i = 0; i < count; i++) {
			int x = in.readInt();
			int y = in.readInt();
			points[i] = new Point(x, y);
		}
		Set<Point> answer = new HashSet<Point>();
		Set<Point> checked = new HashSet<Point>();
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				if (o1.y != o2.y)
					return o1.y - o2.y;
				return o1.x - o2.x;
			}
		});
		for (int i = 0; i <= lost; i++) {
			for (int j = 0; i + j <= lost; j++) {
				int x = points[i].x + points[count - j - 1].x;
				int y = points[i].y + points[count - j - 1].y;
				Point center = new Point(x, y);
				if (checked.contains(center))
					continue;
				checked.add(center);
				int remaining = lost - i - j;
				int index1 = i + 1;
				int index2 = count - j - 2;
				while (index1 <= index2 && remaining >= 0) {
					int value1 = y - points[index1].y - points[index2].y;
					int value2 = x - points[index1].x - points[index2].x;
					if (value1 == 0) {
						if (value2 == 0) {
							index1++;
							index2--;
						} else if (value2 > 0) {
							index1++;
							remaining--;
						} else {
							index2--;
							remaining--;
						}
					} else if (value1 > 0) {
						index1++;
						remaining--;
					} else {
						index2--;
						remaining--;
					}
				}
				if (remaining >= 0)
					answer.add(center);
			}
		}
		out.printLine(answer.size());
		for (Point point : answer)
			out.printFormat("%.1f %.1f\n", point.x / 2., point.y / 2.);
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

	public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	}