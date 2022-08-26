import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.util.Set;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.HashSet;
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
	long[] power;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] treeIndex = new int[count];
		int[] vertex = new int[count];
		char[] label = new char[count];
		for (int i = 0; i < count; i++) {
			treeIndex[i] = in.readInt() - 1;
			vertex[i] = in.readInt() - 1;
			label[i] = in.readCharacter();
		}
		power = new long[count + 1];
		power[0] = 1;
		for (int i = 1; i <= count; i++) {
			power[i] = power[i - 1] * 43;
		}
		int firstCount = 0;
		int secondCount = 0;
		for (int i : treeIndex) {
			if (i == 0)
				firstCount++;
			else
				secondCount++;
		}
		long[] hashFirst = new long[firstCount + 1];
		int[] lengthFirst = new int[firstCount + 1];
		long[] hashSecond = new long[secondCount + 1];
		int[] lengthSecond = new int[secondCount + 1];
		int[] parent = new int[secondCount + 1];
		int firstIndex = 0;
		int secondIndex = 0;
		Set<Long> goodHash = new HashSet<Long>();
		for (int i = 0; i < count; i++) {
			if (treeIndex[i] == 0) {
				firstIndex++;
				lengthFirst[firstIndex] = lengthFirst[vertex[i]] + 1;
				hashFirst[firstIndex] = hashFirst[vertex[i]] + power[lengthFirst[vertex[i]]] * label[i];
				goodHash.add(hashFirst[firstIndex]);
			} else {
				secondIndex++;
				lengthSecond[secondIndex] = lengthSecond[vertex[i]] + 1;
				parent[secondIndex] = vertex[i];
				hashSecond[secondIndex] = hashSecond[vertex[i]] * 43 + label[i];
			}
		}
		Counter<Long> firstCounter = new Counter<Long>();
		Counter<Long> secondCounter = new Counter<Long>();
		firstIndex = 0;
		secondIndex = 0;
		long answer = 1;
		for (int i = 0; i < count; i++) {
			if (treeIndex[i] == 0) {
				firstIndex++;
				answer += secondCounter.get(hashFirst[firstIndex]);
				firstCounter.add(hashFirst[firstIndex]);
			} else {
				secondIndex++;
				answer++;
				int current = secondIndex;
				do {
					current = parent[current];
					long curHash = hashSecond[secondIndex] - hashSecond[current] * power[lengthSecond[secondIndex] - lengthSecond[current]];
					if (goodHash.contains(curHash)) {
						answer += firstCounter.get(curHash);
						secondCounter.add(curHash);
					}
				} while (current != 0);
			}
			out.printLine(answer);
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

class Counter<K> extends HashMap<K, Long> {
	public Counter() {
		super();
	}

	public void add(K key) {
		put(key, get(key) + 1);
	}

	public Long get(Object key) {
		if (containsKey(key))
			return super.get(key);
		return 0L;
	}
}