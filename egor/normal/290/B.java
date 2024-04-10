import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	String code = "111111101010101111100101001111111\n" +
		"100000100000000001010110001000001\n" +
		"101110100110110000011010001011101\n" +
		"101110101011001001111101001011101\n" +
		"101110101100011000111100101011101\n" +
		"100000101010101011010000101000001\n" +
		"111111101010101010101010101111111\n" +
		"000000001111101111100111100000000\n" +
		"100010111100100001011110111111001\n" +
		"110111001111111100100001000101100\n" +
		"011100111010000101000111010001010\n" +
		"011110000110001111110101100000011\n" +
		"111111111111111000111001001011000\n" +
		"111000010111010011010011010100100\n" +
		"101010100010110010110101010000010\n" +
		"101100000101010001111101000000000\n" +
		"000010100011001101000111101011010\n" +
		"101001001111101111000101010001110\n" +
		"101101111111000100100001110001000\n" +
		"000010011000100110000011010000010\n" +
		"001101101001101110010010011011000\n" +
		"011101011010001000111101010100110\n" +
		"111010100110011101001101000001110\n" +
		"110001010010101111000101111111000\n" +
		"001000111011100001010110111110000\n" +
		"000000001110010110100010100010110\n" +
		"111111101000101111000110101011010\n" +
		"100000100111010101111100100011011\n" +
		"101110101001010000101000111111000\n" +
		"101110100011010010010111111011010\n" +
		"101110100100011011110110101110000\n" +
		"100000100110011001111100111100000\n" +
		"111111101101000101001101110010001";
	
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		String[] rows = code.split("\n");
		int row = in.readInt();
		int column = in.readInt();
		out.printLine(rows[row].charAt(column));
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