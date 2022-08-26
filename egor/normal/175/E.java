import java.util.NavigableSet;
import java.util.SortedSet;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
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
	int n = 12;

	private int radiusFire;
	private int radiusElectric;
	private int radiusSlow;
	private int damageFire;
	private int damageElectric;
	int[] slowAt;
	private int countFire;
	private int countElectric;
	double[][][] result;
	double[] slowPoints;
	int[] slowOrder = new int[2 * n];
	double[] scoreFire = new double[n];
	double[] scoreElectric = new double[n];
	int[] countSlow = new int[2 * n + 1];
	private double[][] intersectFire;
	private double[][] intersectElectric;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		countFire = in.readInt();
		countElectric = in.readInt();
		int countSlow = in.readInt();
		radiusFire = in.readInt();
		radiusElectric = in.readInt();
		radiusSlow = in.readInt();
		if (radiusSlow == 1)
			countSlow = 0;
		damageFire = in.readInt();
		damageElectric = in.readInt();
		slowAt = new int[n];
		result = new double[n + 1][countFire + 1][countElectric + 1];
		slowPoints = new double[2 * n];
		for (int i = 0; i < n; i++) {
			slowPoints[2 * i] = i - Math.sqrt(radiusSlow * radiusSlow - 1);
			slowPoints[2 * i + 1] = i + Math.sqrt(radiusSlow * radiusSlow - 1);
		}
		Integer[] reverseSlowOrder = ListUtils.order(Array.wrap(slowPoints));
		for (int i = 0; i < 2 * n; i++)
			slowOrder[reverseSlowOrder[i]] = i;
		Arrays.sort(slowPoints);
		intersectFire = new double[n][2 * n + 1];
		intersectElectric = new double[n][2 * n + 1];
		for (int i = 0; i < n; i++) {
			double start = i - Math.sqrt(radiusFire * radiusFire - 1);
			double end = i + Math.sqrt(radiusFire * radiusFire - 1);
			for (int j = 0; j < 2 * n + 1; j++) {
				double curStart = j == 0 ? Double.NEGATIVE_INFINITY : slowPoints[j - 1];
				double curFinish = j == 2 * n ? Double.POSITIVE_INFINITY : slowPoints[j];
				intersectFire[i][j] = Math.max(0, Math.min(end, curFinish) - Math.max(start, curStart));
			}
			start = i - Math.sqrt(radiusElectric * radiusElectric - 1);
			end = i + Math.sqrt(radiusElectric * radiusElectric - 1);
			for (int j = 0; j < 2 * n + 1; j++) {
				double curStart = j == 0 ? Double.NEGATIVE_INFINITY : slowPoints[j - 1];
				double curFinish = j == 2 * n ? Double.POSITIVE_INFINITY : slowPoints[j];
				intersectElectric[i][j] = Math.max(0, Math.min(end, curFinish) - Math.max(start, curStart));
			}
		}
		out.printLine(go(0, countSlow));
	}

	private double go(int step, int remaining) {
		if (step == slowAt.length) {
			if (remaining == 0)
				return count();
			return 0;
		}
		double result = 0;
		for (int i = 0; i <= 2 && i <= remaining; i++) {
			slowAt[step] = i;
			result = Math.max(result, go(step + 1, remaining - i));
		}
		return result;
	}

	private double count() {
		Arrays.fill(countSlow, 1);
		for (int i = 0; i < n; i++) {
			if (slowAt[i] != 0) {
				for (int j = slowOrder[2 * i]; j < slowOrder[2 * i + 1]; j++)
					countSlow[j + 1] += slowAt[i];
			}
		}
		for (int i = 0; i < n; i++) {
			scoreFire[i] = 0;
			scoreElectric[i] = 0;
			for (int j = 0; j < 2 * n + 1; j++) {
				scoreFire[i] += intersectFire[i][j] * countSlow[j] * damageFire;
				scoreElectric[i] += intersectElectric[i][j] * countSlow[j] * damageElectric;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= countFire; j++) {
				for (int k = 0; k <= countElectric; k++) {
					result[i + 1][j][k] = result[i][j][k];
					if (slowAt[i] == 2)
						continue;
					if (j != countFire) {
						result[i + 1][j][k] = Math.max(result[i + 1][j][k], result[i][j + 1][k] + scoreFire[i]);
						if (slowAt[i] == 0) {
							if (j + 2 <= countFire)
								result[i + 1][j][k] = Math.max(result[i + 1][j][k], result[i][j + 2][k] + scoreFire[i] * 2);
							if (k < countElectric)
								result[i + 1][j][k] = Math.max(result[i + 1][j][k], result[i][j + 1][k + 1] + scoreFire[i] + scoreElectric[i]);
						}
					}
					if (k != countElectric) {
						result[i + 1][j][k] = Math.max(result[i + 1][j][k], result[i][j][k + 1] + scoreElectric[i]);
						if (slowAt[i] == 0 && k + 2 <= countElectric)
							result[i + 1][j][k] = Math.max(result[i + 1][j][k], result[i][j][k + 2] + 2 * scoreElectric[i]);
					}
				}
			}
		}
		return result[n][0][0];
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

class ListUtils {

	public static Integer[] order(final List<? extends Comparable<?>>...sequences) {
		return ArrayUtils.order(sequences[0].size(), new Comparator<Integer>() {
			public int compare(Integer o1, Integer o2) {
				for (List<? extends Comparable> sequence : sequences) {
					//noinspection unchecked
					int value = sequence.get(o1).compareTo(sequence.get(o2));
					if (value != 0)
						return value;
				}
				return 0;
			}
		});
	}

	}

abstract class Array<T> extends AbstractList<T> {

	public static List<Double> wrap(double...array) {
		return new DoubleArray(array);
	}

	protected static class DoubleArray extends Array<Double> {
		protected final double[] array;

		protected DoubleArray(double[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Double get(int index) {
			return array[index];
		}

		public Double set(int index, Double value) {
			double result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class ArrayUtils {
	public static Integer[] generateOrder(int size) {
		Integer[] order = new Integer[size];
		for (int i = 0; i < size; i++)
			order[i] = i;
		return order;
	}

	public static Integer[] order(int size, Comparator<Integer> comparator) {
		Integer[] order = generateOrder(size);
		Arrays.sort(order, comparator);
		return order;
	}

	}