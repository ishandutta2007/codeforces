import java.util.ArrayList;
import java.util.List;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.Comparator;
import java.io.*;
import java.util.Arrays;
import java.util.Collection;

/**
 * Generated by Contest helper plug-in
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskD();
		solver.solve(1, in, out);
		Exit.exit(in, out);
	}
}

abstract class InputReader {
	private boolean finished = false;

	public abstract int read();

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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public void setFinished(boolean finished) {
		this.finished = finished;
	}

	public abstract void close();
}

class StreamInputReader extends InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar, numChars;

	public StreamInputReader(InputStream stream) {
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

	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
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

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}

class TaskD implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int count = in.readInt();
		int[] sequence = IOUtils.readIntArray(in, count);
		for (int i = 0; i < count; i++)
			sequence[i]--;
		int[] cycle = new int[count];
		int[][] twoCycles = new int[count][2];
		int[][] threeCycles = new int[count][3];
		int twoCycleCount = 0;
		int threeCycleCount = 0;
		int answer = 0;
		int[][] initial = new int[count][];
		int[][] after = new int[count][];
		boolean[] processed = new boolean[count];
		for (int i = 0; i < count; i++) {
			if (processed[i] || sequence[i] == i)
				continue;
			int current = i;
			int length = 0;
			do {
				processed[current] = true;
				cycle[length++] = current;
				current = sequence[current];
			} while (current != i);
			while (length > 5) {
				initial[answer] = new int[5];
				after[answer] = new int[5];
				System.arraycopy(cycle, length - 5, initial[answer], 0, 5);
				System.arraycopy(cycle, length - 4, after[answer], 0, 4);
				after[answer][4] = cycle[length - 5];
//				cycle[length - 5] = cycle[length - 1];
				length -= 4;
				answer++;
			}
			if (length >= 4) {
				initial[answer] = new int[length];
				after[answer] = new int[length];
				System.arraycopy(cycle, 0, initial[answer], 0, length);
				System.arraycopy(cycle, 1, after[answer], 0, length - 1);
				after[answer][length - 1] = cycle[0];
				answer++;
			} else if (length == 3) {
				System.arraycopy(cycle, 0, threeCycles[threeCycleCount++], 0, 3);
			} else {
				System.arraycopy(cycle, 0, twoCycles[twoCycleCount++], 0, 2);
			}
		}
		while (threeCycleCount > twoCycleCount && threeCycleCount >= 2) {
			initial[answer] = new int[5];
			after[answer] = new int[5];
			System.arraycopy(threeCycles[threeCycleCount - 1], 0, initial[answer], 0, 3);
			System.arraycopy(threeCycles[threeCycleCount - 1], 1, after[answer], 0, 2);
			after[answer][2] = threeCycles[threeCycleCount - 1][0];
			System.arraycopy(threeCycles[threeCycleCount - 2], 1, initial[answer], 3, 2);
			System.arraycopy(threeCycles[threeCycleCount - 2], 2, after[answer], 3, 1);
			after[answer][4] = threeCycles[threeCycleCount - 2][1];
//			threeCycles[threeCycleCount - 2][1] = threeCycles[threeCycleCount - 2][2];
			System.arraycopy(threeCycles[threeCycleCount - 2], 0, twoCycles[twoCycleCount++], 0, 2);
			threeCycleCount -= 2;
			answer++;
		}
		if (threeCycleCount == 1 && twoCycleCount == 0) {
			initial[answer] = new int[3];
			after[answer] = new int[3];
			System.arraycopy(threeCycles[0], 0, initial[answer], 0, 3);
			System.arraycopy(threeCycles[0], 1, after[answer], 0, 2);
			after[answer][2] = threeCycles[0][0];
			answer++;
			threeCycleCount = 0;
		}
		for (int i = 0; i < threeCycleCount; i++) {
			initial[answer] = new int[5];
			after[answer] = new int[5];
			System.arraycopy(threeCycles[i], 0, initial[answer], 0, 3);
			System.arraycopy(threeCycles[i], 1, after[answer], 0, 2);
			after[answer][2] = threeCycles[i][0];
			System.arraycopy(twoCycles[i], 0, initial[answer], 3, 2);
			System.arraycopy(twoCycles[i], 1, after[answer], 3, 1);
			after[answer][4] = twoCycles[i][0];
			answer++;
		}
		for (int i = threeCycleCount; i + 1 < twoCycleCount; i += 2) {
			initial[answer] = new int[4];
			after[answer] = new int[4];
			System.arraycopy(twoCycles[i], 0, initial[answer], 0, 2);
			System.arraycopy(twoCycles[i], 1, after[answer], 0, 1);
			after[answer][1] = twoCycles[i][0];
			System.arraycopy(twoCycles[i + 1], 0, initial[answer], 2, 2);
			System.arraycopy(twoCycles[i + 1], 1, after[answer], 2, 1);
			after[answer][3] = twoCycles[i + 1][0];
			answer++;
		}
		if ((twoCycleCount - threeCycleCount) % 2 == 1) {
			initial[answer] = new int[2];
			after[answer] = new int[2];
			System.arraycopy(twoCycles[twoCycleCount - 1], 0, initial[answer], 0, 2);
			System.arraycopy(twoCycles[twoCycleCount - 1], 1, after[answer], 0, 1);
			after[answer][1] = twoCycles[twoCycleCount - 1][0];
			answer++;
		}
		out.println(answer);
		for (int i = 0; i < answer; i++) {
			int length = initial[i].length;
			for (int j = 0; j < length; j++) {
				initial[i][j]++;
				after[i][j]++;
			}
			out.println(length);
			IOUtils.printArray(Arrays.copyOf(initial[i], length), out);
			IOUtils.printArray(Arrays.copyOf(after[i], length), out);
		}
	}
}