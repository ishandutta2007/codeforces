import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int baseCount = in.readInt();
		int exponentCount = in.readInt();
		int prime = in.readInt();
		int[] bases = IOUtils.readIntArray(in, baseCount);
		int[] exponents = IOUtils.readIntArray(in, exponentCount);
		int exponent = prime - 1;
		for (int i : exponents)
			exponent = IntegerUtils.gcd(exponent, i);
		List<Long> divisors = IntegerUtils.getDivisors(prime - 1);
		Collections.sort(divisors);
		long[] reverse = new long[divisors.size()];
		for (int i = 0; i < reverse.length; i++)
			reverse[i] = (prime - 1) / divisors.get(i);
		boolean[] include = new boolean[divisors.size()];
		for (int i : bases) {
			long base = IntegerUtils.power(i, exponent, prime);
			for (int i1 = divisors.size() - 1; i1 >= 0; i1--) {
				if (IntegerUtils.power(base, reverse[i1], prime) == 1) {
					include[i1] = true;
					break;
				}
			}
		}
		for (int i = 0; i < include.length; i++) {
			if (!include[i])
				continue;
			for (int j = i + 1; j < include.length; j++) {
				if (divisors.get(j) % divisors.get(i) == 0)
					include[j] = true;
			}
		}
		long answer = 0;
		long[] count = new long[divisors.size()];
		for (int i = count.length - 1; i >= 0; i--) {
			count[i] = (prime - 1) / divisors.get(i);
			for (int j = i + 1; j < count.length; j++) {
				if (divisors.get(j) % divisors.get(i) == 0)
					count[i] -= count[j];
			}
			if (include[i])
				answer += count[i];
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
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

	}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

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

	public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
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