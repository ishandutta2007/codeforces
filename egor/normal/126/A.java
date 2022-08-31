import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		long t1 = in.readInt();
		long t2 = in.readInt();
		long x1 = in.readInt();
		long x2 = in.readInt();
		long t0 = in.readInt();
		if (t0 == t1) {
			if (t0 == t2) {
				out.printLine(x1, x2);
				return;
			}
			out.printLine(x1, 0);
			return;
		}
		long leftDelta = t0 - t1;
		long rightDelta = t2 - t0;
		long bestY1 = -1;
		long bestY2 = -1;
		Rational minDelta = Rational.MAX_VALUE;
		for (long y2 = 1; y2 <= x2; y2++) {
			long y1 = Math.min((y2 * rightDelta) / leftDelta, x1);
			Rational curDelta = new Rational(t1 * y1 + t2 * y2 - t0 * y1 - t0 * y2, y1 + y2);
			if (curDelta.compareTo(minDelta) <= 0) {
				minDelta = curDelta;
				bestY1 = y1;
				bestY2 = y2;
			}
		}
		out.printLine(bestY1, bestY2);
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

class Rational implements Comparable<Rational> {
	public static final Rational MAX_VALUE = new Rational(Integer.MAX_VALUE, 1);

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

class IntegerUtils {
	public static long gcd(long a, long b) {
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}

	public static int longCompare(long a, long b) {
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	}