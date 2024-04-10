import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collection;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long n = in.readLong();
		List<Long> divisors = IntegerUtils.getDivisors(n);
		Collections.sort(divisors);
		boolean[] winner = new boolean[divisors.size()];
		winner[0] = true;
		long move = 0;
		for (int i = 1; i < winner.length; i++) {
			boolean found = false;
			for (int j = 1; j < i; j++) {
				if (divisors.get(i) % divisors.get(j) == 0) {
					found = true;
					if (!winner[j]) {
						winner[i] = true;
						move = divisors.get(j);
					}
				}
			}
			if (!found)
				winner[i] = true;
		}
		if (winner[winner.length - 1]) {
			out.printLine(1);
			out.printLine(move);
		} else
			out.printLine(2);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

class IntegerUtils {

	public static List<Pair<Long, Integer>> factorize(long number) {
		List<Pair<Long, Integer>> result = new ArrayList<Pair<Long, Integer>>();
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0) {
				int power = 0;
				do {
					power++;
					number /= i;
				} while (number % i == 0);
				result.add(Pair.makePair(i, power));
			}
		}
		if (number != 1)
			result.add(Pair.makePair(number, 1));
		return result;
	}

	public static List<Long> getDivisors(long number) {
		List<Pair<Long, Integer>> primeDivisors = factorize(number);
		return getDivisorsImpl(primeDivisors, 0, 1, new ArrayList<Long>());
	}

	private static List<Long> getDivisorsImpl(List<Pair<Long, Integer>> primeDivisors, int index, long current,
		List<Long> result)
	{
		if (index == primeDivisors.size()) {
			result.add(current);
			return result;
		}
		long p = primeDivisors.get(index).first;
		int power = primeDivisors.get(index).second;
		for (int i = 0; i <= power; i++) {
			getDivisorsImpl(primeDivisors, index + 1, current, result);
			current *= p;
		}
		return result;
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