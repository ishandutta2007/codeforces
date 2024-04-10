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
        int count = in.readInt();
        double side = Math.sin(3 * Math.PI / 10) * 20;
        out.printLine(4 * count + 1);
        out.printLine(0, 0);
        for (int i = 1; i <= count; i++)
            out.printLine(side * i, 0);
        double height = Math.cos(3 * Math.PI / 10) * 10;
        for (int i = 0; i < count; i++)
            out.printLine(side * i + side / 2, height);
        double otherHeight = -Math.sin(2 * Math.PI / 5) * 10;
        double shift = Math.cos(2 * Math.PI / 5) * 10;
        for (int i = 0; i < count; i++)
            out.printLine(side * i + shift, otherHeight);
        for (int i = 0; i < count; i++)
            out.printLine(side * (i + 1) - shift, otherHeight);
        for (int i = 0; i < count; i++)
            out.printLine(i + 1, 2 * count + 2 + i, 3 * count + 2 + i, 2 + i, count + 2 + i);
        for (int i = 0; i <= count; i++)
            out.print(count - i + 1, "");
        for (int i = 0; i < count; i++)
            out.print(3 * count + 2 + i, count + 2 + i, 2 * count + 2 + i, 2 + i, "");
        out.printLine();
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