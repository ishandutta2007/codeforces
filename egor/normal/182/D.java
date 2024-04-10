import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String first = in.readString();
		String second = in.readString();
		if (first.length() > second.length()) {
			String temp = first;
			first = second;
			second = temp;
		}
		int[] z1 = StringUtils.zAlgorithm(first);
		int[] z2 = StringUtils.zAlgorithm(second);
		int[] z = StringUtils.zAlgorithm(first + "$" + second);
		int answer = 0;
		for (int i = 1; i < z1.length; i++) {
			if (z1.length % i == 0 && z2.length % i == 0 && z1[i] == z1.length - i && z2[i] == z2.length - i && z[z1.length + 1] >= i)
				answer++;
		}
		if (z[z1.length + 1] >= z1.length && (z1.length == z2.length || z2.length % z1.length == 0 && z2[z1.length] == z2.length - z1.length))
			answer++;
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

class StringUtils {

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