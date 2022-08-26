import java.util.Map;
import java.util.Collections;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.util.Collection;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;
import java.util.Comparator;
import java.io.*;
import java.util.Iterator;
import java.util.Arrays;

/**
 * @author Egor Kulikov (egor@egork.net)
 * Actual solution is at the bottom
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new StreamInputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		run(in, out);
	}

	public static void run(InputReader in, PrintWriter out) {
		Solver solver = new TaskB();
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

class Exit {
	private Exit() {
	}

	public static void exit(InputReader in, PrintWriter out) {
		in.setFinished(true);
		in.close();
		out.close();
	}
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

	@Override
	public void close() {
		try {
			stream.close();
		} catch (IOException ignored) {
		}
	}
}

interface Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out);
}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}

	}

class TaskB implements Solver {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int racerCount = in.readInt();
		final String[] name = new String[racerCount];
		final int[] points = new int[racerCount];
		for (int i = 0; i < racerCount; i++) {
			name[i] = in.readString();
			points[i] = in.readInt();
		}
		int prizePositions = in.readInt();
		int[] prizes = new int[racerCount];
		for (int i = 0; i < prizePositions; i++)
			prizes[i] = in.readInt();
		String pilotName = in.readString();
		Arrays.sort(prizes);
		Integer[] table = ArrayUtils.order(racerCount, new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				if (points[o1] != points[o2])
					return points[o2] - points[o1];
				return name[o1].compareTo(name[o2]);
			}
		});
		int currentPlace = 1;
		int index = -1;
		for (int i : table) {
			if (name[i].equals(pilotName)) {
				index = i;
				break;
			}
			currentPlace++;
		}
		int maxPoints = points[index] + prizes[racerCount - 1];
		int prizeIndex = 0;
		int result = currentPlace;
		for (int i : table) {
			if (i == index)
				break;
			if (prizes[prizeIndex] + points[i] < maxPoints || prizes[prizeIndex] + points[i] == maxPoints && pilotName.compareTo(name[i]) < 0) {
				prizeIndex++;
				result--;
			}
		}
		int minPlace = result;
		int minPoints = points[index] + prizes[0];
		prizeIndex = racerCount - 1;
		result = currentPlace;
		for (int ii = racerCount - 1; ii >= 0; ii--) {
			int i = table[ii];
			if (i == index)
				break;
			if (prizes[prizeIndex] + points[i] > minPoints || prizes[prizeIndex] + points[i] == minPoints && pilotName.compareTo(name[i]) > 0) {
				prizeIndex--;
				result++;
			}
		}
		out.println(minPlace + " " + result);
	}
}