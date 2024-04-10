import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int countTruth = in.readInt();
		boolean[] killed = new boolean[count];
		int[] who = new int[count];
		for (int i = 0; i < count; i++) {
			killed[i] = in.readCharacter() == '+';
			who[i] = in.readInt() - 1;
		}
		int base = 0;
		int[] deltaIfKilled = new int[count];
		for (int i = 0; i < count; i++) {
			if (killed[i])
				deltaIfKilled[who[i]]++;
			else {
				deltaIfKilled[who[i]]--;
				base++;
			}
		}
		boolean[] canKill = new boolean[count];
		for (int i = 0; i < count; i++)
			canKill[i] = base + deltaIfKilled[i] == countTruth;
		int countCanKill = CollectionUtils.count(Array.wrap(canKill), true);
		for (int i = 0; i < count; i++) {
			if (killed[i]) {
				if (canKill[who[i]] && countCanKill == 1)
					out.printLine("Truth");
				else if (canKill[who[i]])
					out.printLine("Not defined");
				else
					out.printLine("Lie");
			} else {
				if (canKill[who[i]] && countCanKill == 1)
					out.printLine("Lie");
				else if (canKill[who[i]])
					out.printLine("Not defined");
				else
					out.printLine("Truth");
			}
		}
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

	public char readCharacter() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		return (char) c;
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

class CollectionUtils {

	public static<T> int count(Iterable<T> array, T sample) {
		int result = 0;
		for (T element : array) {
			if (element.equals(sample))
				result++;
		}
		return result;
	}

	}

abstract class Array<T> extends AbstractList<T> {

	public static List<Boolean> wrap(boolean...array) {
		return new BooleanArray(array);
	}

	protected static class BooleanArray extends Array<Boolean> {
		protected final boolean[] array;

		protected BooleanArray(boolean[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Boolean get(int index) {
			return array[index];
		}

		public Boolean set(int index, Boolean value) {
			boolean result = array[index];
			array[index] = value;
			return result;
		}
	}

	}