import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	private final int THRESHOLD = 120;
	private final int BIG_THRESHOLD = 800;

	int[] p = IntegerUtils.generatePrimes(2000);
	int[][][][] answer = new int[IntegerUtils.generatePrimes(THRESHOLD).length][THRESHOLD][][];
//	boolean[][][][] done = new boolean[answer.length][THRESHOLD][][];
	int[][][] forTwo = new int[IntegerUtils.generatePrimes(BIG_THRESHOLD).length][BIG_THRESHOLD][];
//	boolean[][][] doneForTwo = new boolean[forTwo.length][BIG_THRESHOLD][];
	int[][] forOne = new int[p.length + 1][2001];
	boolean[][] doneForOne = new boolean[p.length + 1][2001];
	int[] table = new int[p.length * 2001];
	int mask = (1 << 30) - 1;

	{
		for (int j = 0; j < answer.length; j++) {
			for (int i = 0; i < THRESHOLD; i++) {
				answer[j][i] = new int[i + 1][];
//				done[j][i] = new boolean[i + 1][];
				for (int k = 0; k <= i; k++) {
					answer[j][i][k] = new int[k + 1];
//					done[j][i][k] = new boolean[k + 1];
				}
			}
		}
		for (int i = 0; i < forTwo.length; i++) {
			for (int j = 0; j < BIG_THRESHOLD; j++) {
				forTwo[i][j] = new int[j + 1];
//				doneForTwo[i][j] = new boolean[j + 1];
			}
		}
		for (int i = 0; i < p.length; i++) {
			for (int j = 0; j <= 2000; j++)
				table[i * 2001 + j] = j / p[i];
		}
	}

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int a = in.readInt();
		int b = in.readInt();
		int c = in.readInt();
		out.printLine(go(0, a, b, c) & ((1 << 30) - 1));
	}

	int go(int step, int a) {
		if (doneForOne[step][a])
			return forOne[step][a];
		doneForOne[step][a] = true;
		if (step == p.length)
			return forOne[step][a] = 1;
		int pp = p[step];
		if (a < pp)
			return forOne[step][a] = 1;
		int aCopy = a;
		int result = 0;
		int stp = step * 2001;
		for (int i = 0; aCopy >= 1; i++, aCopy = table[stp + aCopy])
			result += go(step + 1, aCopy) * (i + 1);
		return forOne[step][a] = result;
	}

	int go(int step, int a, int b) {
		if (step == p.length)
			return 1;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		int pp = p[step];
		if (a < pp)
			return go(step, b);
		if (b < BIG_THRESHOLD && forTwo[step][b][a] != 0)
			return forTwo[step][b][a] - 1;
		int stp = step * 2001;
		int result = 0;
		int aCopy = a;
		for (int i = 0; aCopy >= 1; i++, aCopy = table[stp + aCopy]) {
			int bCopy = b;
			for (int j = 0; bCopy >= 1; j++, bCopy = table[stp + bCopy])
				result += go(step + 1, aCopy, bCopy) * (1 + i + j);
		}
		result &= mask;
		if (b < BIG_THRESHOLD) {
//			doneForTwo[step][b][a] = true;
			forTwo[step][b][a] = result + 1;
		}
		return result;
	}

	private int go(int step, int a, int b, int c) {
		if (step == p.length)
			return 1;
		int temp;
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (b > c) {
			temp = b;
			b = c;
			c = temp;
		}
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		int pp = p[step];
		if (a < pp)
			return go(step, b, c);
		if (c < THRESHOLD) {
			if (answer[step][c][b][a] != 0)
				return answer[step][c][b][a] - 1;
		}
		int stp = step * 2001;
		int result = 0;
		int aCopy = a;
		for (int i = 0; aCopy >= 1; i++, aCopy = aCopy < pp ? 0 : table[stp + aCopy]) {
			int bCopy = b;
			for (int j = 0; bCopy >= 1; j++, bCopy = bCopy < pp ? 0 : table[stp + bCopy]) {
				int cCopy = c;
				for (int k = 0; cCopy >= 1; k++, cCopy = cCopy < pp ? 0 : table[stp + cCopy])
					result += go(step + 1, aCopy, bCopy, cCopy) * (1 + i + j + k);
			}
		}
		result &= mask;
		if (c < THRESHOLD) {
//			done[step][c][b][a] = true;
			answer[step][c][b][a] = result + 1;
		}
		return result;
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

class CollectionUtils {
	public static int[] toArray(Collection<Integer> collection) {
		int[] array = new int[collection.size()];
		int index = 0;
		for (int element : collection)
			array[index++] = element;
		return array;
	}

	}