import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.util.ArrayDeque;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int walkDistance = in.readInt();
		int additionalTime = in.readInt();
		int ax = in.readInt();
		int ay = in.readInt();
		int bx = in.readInt();
		int by = in.readInt();
		int squaredWalkDistance = walkDistance * walkDistance;
		if (squaredDistance(ax, ay, bx, by) <= squaredWalkDistance) {
			out.printLine(Math.hypot(ax - bx, ay - by));
			return;
		}
		int count = in.readInt();
		int[] x1 = new int[count];
		int[] y1 = new int[count];
		int[] x2 = new int[count];
		int[] y2 = new int[count];
		IOUtils.readIntArrays(in, x1, y1, x2, y2);
		for (int i = 0; i < count; i++) {
			if (x1[i] == x2[i] && y1[i] > y2[i]) {
				int temp = y1[i];
				y1[i] = y2[i];
				y2[i] = temp;
			} else if (y1[i] == y2[i] && x1[i] > x2[i]) {
				int temp = x1[i];
				x1[i] = x2[i];
				x2[i] = temp;
			}
		}
		boolean[] accessibleFromStart = new boolean[count];
		boolean[] accessibleFromFinish = new boolean[count];
		boolean[][] canMove = new boolean[count][count];
		for (int i = 0; i < count; i++) {
			accessibleFromStart[i] = squaredDistanceToSegment(ax, ay, x1[i], y1[i], x2[i], y2[i]) <= squaredWalkDistance;
			accessibleFromFinish[i] = squaredDistanceToSegment(bx, by, x1[i], y1[i], x2[i], y2[i]) <= squaredWalkDistance;
			for (int j = i + 1; j < count; j++)
				canMove[j][i] = canMove[i][j] = squaredDistanceBetweenSegments(x1[i], y1[i], x2[i], y2[i], x1[j], y1[j], x2[j], y2[j]) <= squaredWalkDistance;
		}
		Queue<Integer> queue = new ArrayDeque<Integer>();
		int[] answer = new int[count];
		Arrays.fill(answer, Integer.MAX_VALUE);
		for (int i = 0; i < count; i++) {
			if (accessibleFromStart[i]) {
				answer[i] = 1;
				queue.add(i);
			}
		}
		while (!queue.isEmpty()) {
			int current = queue.poll();
			for (int i = 0; i < count; i++) {
				if (answer[i] == Integer.MAX_VALUE && canMove[current][i]) {
					answer[i] = answer[current] + 1;
					queue.add(i);
				}
			}
		}
		double result = Double.POSITIVE_INFINITY;
		for (int i = 0; i < count; i++) {
			if (accessibleFromFinish[i] && answer[i] != Integer.MAX_VALUE)
				result = Math.min(result, answer[i] * (walkDistance + additionalTime) + Math.sqrt(squaredDistanceToSegment(bx, by, x1[i], y1[i], x2[i], y2[i])));
		}
		if (result == Double.POSITIVE_INFINITY)
			out.printLine(-1);
		else
			out.printLine(result);
	}

	private int squaredDistanceBetweenSegments(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2) {
		return Math.min(Math.min(squaredDistanceToSegment(x1, y1, xx1, yy1, xx2, yy2), squaredDistanceToSegment(x2, y2, xx1, yy1, xx2, yy2)),
			Math.min(squaredDistanceToSegment(xx1, yy1, x1, y1, x2, y2), squaredDistanceToSegment(xx2, yy2, x1, y1, x2, y2)));
	}

	private int squaredDistanceToSegment(int x, int y, int x1, int y1, int x2, int y2) {
		int result = Math.min(squaredDistance(x, y, x1, y1), squaredDistance(x, y, x2, y2));
		if (x1 == x2 && y1 <= y && y <= y2)
			result = Math.min(result, Math.abs(x - x1) * Math.abs(x - x1));
		else if (y1 == y2 && x1 <= x && x <= x2)
			result = Math.min(result, Math.abs(y - y1) * Math.abs(y - y1));
		return result;
	}

	private int squaredDistance(int ax, int ay, int bx, int by) {
		return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}