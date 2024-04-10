import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collection;
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
		int[] primes = IntegerUtils.generatePrimes(count + 1);
		int[] divisor = IntegerUtils.generateDivisorTable(count + 1);
		int[][] allDivisors = new int[count][];
		for (int i = 0; i < count; i++) {
			int j = i + 1;
			int curCount = 0;
			while (j != 1) {
				int curDivisor = divisor[j];
				while (j % curDivisor == 0)
					j /= curDivisor;
				curCount++;
			}
			allDivisors[i] = new int[curCount];
			j = i + 1;
			int index = 0;
			while (j != 1) {
				int curDivisor = divisor[j];
				while (j % curDivisor == 0)
					j /= curDivisor;
				allDivisors[i][index++] = Arrays.binarySearch(primes, curDivisor);
			}
		}
		int[] curOn = new int[primes.length];
		int queryCount = in.readInt();
		boolean[] isOn = new boolean[count + 1];
		for (int i = 0; i < queryCount; i++) {
			char type = in.readCharacter();
			int index = in.readInt();
			if (type == '+') {
				if (isOn[index])
					out.printLine("Already on");
				else {
					boolean good = true;
					for (int j : allDivisors[index - 1]) {
						if (curOn[j] != 0) {
							out.printLine("Conflict with", curOn[j]);
							good = false;
							break;
						}
					}
					if (good) {
						out.printLine("Success");
						isOn[index] = true;
						for (int j : allDivisors[index - 1]) {
							curOn[j] = index;
						}
					}
				}
			} else {
				if (!isOn[index])
					out.printLine("Already off");
				else {
					out.printLine("Success");
					isOn[index] = false;
					for (int j : allDivisors[index - 1]) {
						curOn[j] = 0;
					}					
				}
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

class IntegerUtils {

	public static int[] generatePrimes(int upTo) {
		boolean[] isPrime = generatePrimalityTable(upTo);
		List<Integer> primes = new ArrayList<Integer>();
		for (int i = 0; i < upTo; i++) {
			if (isPrime[i])
				primes.add(i);
		}
		return CollectionUtils.toArray(primes);
	}

	public static boolean[] generatePrimalityTable(int upTo) {
		boolean[] isPrime = new boolean[upTo];
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

	public static int[] generateDivisorTable(int upTo) {
		int[] divisor = new int[upTo];
		for (int i = 1; i < upTo; i++)
			divisor[i] = i;
		for (int i = 2; i * i < upTo; i++) {
			if (divisor[i] == i) {
				for (int j = i * i; j < upTo; j += i)
					divisor[j] = i;
			}
		}
		return divisor;
	}

	}

class CollectionUtils {
	public static int[] toArray(Collection<Integer> collection) {
		int[] array = new int[collection.size()];
		int index = 0;
		for (int element : collection)
			array[index++] = element;
		return array;
	}

	}