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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int hLeft = in.readInt();
		int hRight = in.readInt();
		int count = in.readInt();
		int[] score = new int[count];
		boolean[] side = new boolean[count];
		int[] from = new int[count];
		int[] to = new int[count];
		for (int i = 0; i < count; i++) {
			score[i] = in.readInt();
			side[i] = in.readCharacter() == 'T';
			from[i] = in.readInt() * 2;
			to[i] = in.readInt() * 2;
		}
		int answer = 0;
		for (int a = 0; a < 2; a++) {
			for (int i = 1; i <= count; i++) {
				boolean[] hit = new boolean[count];
				int curHRight = i % 2 == 0 ? hRight + 100 * i : 100 * (i + 1) - hRight;
				boolean good = true;
				int total = 0;
				for (int j = 0; j < i; j++) {
					boolean curSide = j % 2 == 0;
					long h1 = 100 * (j + 1) - hLeft;
					long h2 = curHRight - 100 * (j + 1);
					long position = h1 * 100000 / (h1 + h2);
					if (position * (h1 + h2) == h1 * 100000)
						position *= 2;
					else
						position = position * 2 + 1;
					boolean found = false;
					for (int k = 0; k < count; k++) {
						if (side[k] == curSide && from[k] <= position && to[k] >= position) {
							if (hit[k])
								break;
							hit[k] = true;
							found = true;
							total += score[k];
							break;
						}
					}
					if (!found) {
						good = false;
						break;
					}
				}
				if (good)
					answer = Math.max(answer, total);
			}
			hLeft = 100 - hLeft;
			hRight = 100 - hRight;
			for (int i = 0; i < count; i++)
				side[i] = !side[i];
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
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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