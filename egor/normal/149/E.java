import java.io.IOException;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String s = in.readString();
		int count = in.readInt();
		String[] good = IOUtils.readStringArray(in, count);
		String sReverse = StringUtils.reverse(s);
		int answer = 0;
		for (String t : good) {
			if (t.length() == 1)
				continue;
			String direct = t + "$" + s;
			String reverse = StringUtils.reverse(t) + "$" + sReverse;
			int[] zDirect = StringUtils.zAlgorithm(direct);
			int[] zReverse = StringUtils.zAlgorithm(reverse);
			boolean found = false;
			int maxPrefix = 0;
			int last = s.length() - t.length();
			for (int i = 0; i <= last; i++) {
				maxPrefix = Math.max(maxPrefix, zDirect[i + t.length() + 1]);
				if (maxPrefix + zReverse[s.length() - i + 1] >= t.length())
					found = true;
			}
			if (found)
				answer++;
		}
		out.printLine(answer);
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

class IOUtils {

	public static String[] readStringArray(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

	}

class StringUtils {
	public static String reverse(String sample) {
		StringBuilder result = new StringBuilder(sample);
		result.reverse();
		return result.toString();
	}

	public static int[] zAlgorithm(CharSequence s) {
		int length = s.length();
		int[] z = new int[length];
		z[0] = 0;

		int left = 0, right = 0;
		for (int i = 1; i < length; i++) {
			if (i > right) {
				int j;
				//noinspection StatementWithEmptyBody
				for (j = 0; i + j < length && s.charAt(i + j) == s.charAt(j); j++) ;
				z[i] = j;
				left = i;
				right = i + j - 1;
			} else if (z[i - left] < right - i + 1)
				z[i] = z[i - left];
			else {
				int j;
				//noinspection StatementWithEmptyBody
				for (j = 1; right + j < length && s.charAt(right + j) == s.charAt(right - i + j); j++) ;
				z[i] = right - i + j;
				left = i;
				right = right + j - 1;
			}
		}
		return z;
	}

	}