import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int cnt4 = in.readInt();
		int cnt7 = in.readInt();
		int cnt47 = in.readInt();
		int cnt74 = in.readInt();
		if (cnt4 == cnt47 && cnt4 == cnt74 && cnt7 > cnt4) {
			for (int i = 0; i < cnt74; i++)
				out.print(74);
			for (int i = cnt74; i < cnt7; i++)
				out.print(7);
			out.printLine();
			return;
		}
		if (Math.abs(cnt47 - cnt74) > 1 || Math.max(cnt47, cnt74) > Math.min(cnt4, cnt7) ||
			cnt4 == cnt7 && cnt4 == cnt47 && cnt4 == cnt74)
		{
			out.printLine(-1);
			return;
		}
		if (cnt74 > cnt47) {
			out.print(7);
			cnt7--;
			cnt74--;
		}
		int front4 = cnt4 - cnt47;
		if (cnt47 == cnt74)
			front4--;
		for (int i = 0; i < front4; i++) {
			out.print(4);
			cnt4--;
		}
		for (int i = 0; i < cnt47; i++) {
			out.print(47);
			cnt4--;
			cnt7--;
			if (i != 0)
				cnt74--;
		}
		for (int i = 0; i < cnt7; i++)
			out.print(7);
		if (cnt74 != 0)
			out.print(4);
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