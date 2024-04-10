import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Set;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	Set<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>> processed;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int left1 = in.readInt();
		int right1 = in.readInt();
		int left2 = in.readInt();
		int right2 = in.readInt();
		processed = new HashSet<Pair<Pair<Integer, Integer>, Pair<Integer, Integer>>>();
		out.printLine(go(left1, right1, left2, right2));
	}

	private int go(int left1, int right1, int left2, int right2) {
		if (left1 > right1 || left2 > right2)
			return 0;
		while (Integer.highestOneBit(left1) == Integer.highestOneBit(right1) && left1 != Integer.highestOneBit(left1)) {
			left1 -= Integer.highestOneBit(left1);
			right1 -= Integer.highestOneBit(right1);
		}
		while (Integer.highestOneBit(left2) == Integer.highestOneBit(right2) && left2 != Integer.highestOneBit(left2)) {
			left2 -= Integer.highestOneBit(left2);
			right2 -= Integer.highestOneBit(right2);
		}
		Pair<Pair<Integer, Integer>, Pair<Integer, Integer>> key = Pair.makePair(Pair.makePair(left1, right1),
			Pair.makePair(left2, right2));
		if (processed.contains(key))
			return 0;
		processed.add(key);
		int answer = Math.max(0, Math.min(right1, right2) - Math.max(left1, left2) + 1);
		int first = Integer.highestOneBit(right1);
		int second = Integer.highestOneBit(right2);
		if (first == 1 && second == 1)
			return answer;
		if (first > second) {
			answer = Math.max(answer, go(left1, first - 1, left2, right2));
			answer = Math.max(answer, go(1, right1 - first, left2, right2));
		} else if (first < second) {
			answer = Math.max(answer, go(left1, right1, left2, second - 1));
			answer = Math.max(answer, go(left1, right1, 1, right2 - second));
		} else {
			answer = Math.max(answer, go(left1, first - 1, left2, first - 1));
			answer = Math.max(answer, go(left1, first - 1, 1, right2 - first));
			answer = Math.max(answer, go(1, right1 - first, left2, first - 1));
			answer = Math.max(answer, go(1, right1 - first, 1, right2 - first));
		}
		return answer;
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

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}