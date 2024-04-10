import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		String time = in.readString();
		String hours = time.split(":")[0];
		String minutes = time.split(":")[1];
		List<Integer> answer = new ArrayList<Integer>();
		for (int i = 2; i <= 59; i++) {
			int hour = parse(hours, i);
			int minute = parse(minutes, i);
			if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60)
				answer.add(i);
		}
		int hour = parse(hours, 60);
		int minute = parse(minutes, 60);
		if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
			out.printLine(-1);
			return;
		}
		if (answer.isEmpty())
			out.printLine(0);
		else
			out.printLine(answer.toArray());
	}

	private int parse(String number, int base) {
		int result = 0;
		for (char c : number.toCharArray()) {
			int digit = Character.isDigit(c) ? c - '0' : c - 'A' + 10;
			if (digit >= base)
				return -1;
			result *= base;
			result += digit;
		}
		return result;
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