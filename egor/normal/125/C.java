import java.io.IOException;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int count = in.readInt();
		int day = 0;
		while (day * (day + 1) / 2 <= count)
			day++;
		out.println(day);
		int[][] answer = new int[day][day - 1];
		int index = 1;
		int[] position = new int[day];
		for (int i = 0; i < day; i++) {
			for (int j = i + 1; j < day; j++) {
				answer[i][position[i]++] = index;
				answer[j][position[j]++] = index++;
			}
		}
		for (int[] row : answer)
			IOUtils.printArray(row, out);
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

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class IOUtils {
	public static void printArray(int[] array, PrintWriter out) {
		if (array.length == 0) {
			out.println();
			return;
		}
		out.print(array[0]);
		for (int i = 1; i < array.length; i++)
			out.print(" " + array[i]);
		out.println();
	}

	}