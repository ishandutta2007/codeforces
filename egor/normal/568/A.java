import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

	static class TaskA {
		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int p = in.readInt();
			int q = in.readInt();
			Rational threshold = new Rational(p, q);
			int prime = 0;
			int palin = 0;
			int limit = 1300000;
			boolean[] isPrime = IntegerUtils.generatePrimalityTable(limit);
			int answer = 0;
			for (int i = 1; i < limit; i++) {
				if (isPrime[i]) {
					prime++;
				}
				if (StringUtils.reverse(Integer.toString(i)).equals(Integer.toString(i))) {
					palin++;
				}
				if (threshold.compareTo(new Rational(prime, palin)) >= 0) {
					answer = i;
				}
			}
			out.printLine(answer);
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private InputReader.SpaceCharFilter filter;

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

	static class Rational implements Comparable<Rational> {
		public final long numerator;
		public final long denominator;

		public Rational(long numerator, long denominator) {
			if (denominator == 0)
				throw new IllegalArgumentException();
			long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
			if (denominator > 0) {
				this.numerator = numerator / gcd;
				this.denominator = denominator / gcd;
			} else {
				this.numerator = -numerator / gcd;
				this.denominator = -denominator / gcd;
			}
		}


		public String toString() {
			return numerator + "/" + denominator;
		}

		public int compareTo(Rational other) {
			return IntegerUtils.longCompare(numerator * other.denominator, denominator * other.numerator);
//		return BigInteger.valueOf(numerator).multiply(BigInteger.valueOf(other.denominator)).compareTo(
//			BigInteger.valueOf(other.numerator).multiply(BigInteger.valueOf(denominator)));
		}


		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Rational rational = (Rational) o;

			if (denominator != rational.denominator) return false;
			if (numerator != rational.numerator) return false;

			return true;
		}


		public int hashCode() {
			int result = (int) (numerator ^ (numerator >>> 32));
			result = 31 * result + (int) (denominator ^ (denominator >>> 32));
			return result;
		}

	}

	static class OutputWriter {
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

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static class StringUtils {
		public static String reverse(String sample) {
			StringBuilder result = new StringBuilder(sample);
			result.reverse();
			return result.toString();
		}

	}

	static class IntegerUtils {
		public static long gcd(long a, long b) {
			a = Math.abs(a);
			b = Math.abs(b);
			while (b != 0) {
				long temp = a % b;
				a = b;
				b = temp;
			}
			return a;
		}

		public static boolean[] generatePrimalityTable(int upTo) {
			boolean[] isPrime = new boolean[upTo];
			if (upTo < 2)
				return isPrime;
			Arrays.fill(isPrime, true);
			isPrime[0] = isPrime[1] = false;
			for (int i = 2; i * i < upTo; i++) {
				if (isPrime[i]) {
					for (int j = i * i; j < upTo; j += i)
						isPrime[j] = false;
				}
			}
			return isPrime;
		}

		public static int longCompare(long a, long b) {
			if (a < b)
				return -1;
			if (a > b)
				return 1;
			return 0;
		}

	}
}