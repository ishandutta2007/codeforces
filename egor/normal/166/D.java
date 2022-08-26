import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int[] cost = new int[count];
		int[] size = new int[count];
		IOUtils.readIntArrays(in, cost, size);
		int buyerCount = in.readInt();
		int[] money = new int[buyerCount];
		int[] required = new int[buyerCount];
		IOUtils.readIntArrays(in, money, required);
		for (int i = 0; i < buyerCount; i++)
			required[i]++;
		Map<Integer, State> states = new HashMap<Integer, State>();
		for (int i = 0; i < count; i++)
			states.put(size[i], new State(size[i], cost[i], i + 1));
		for (int i = 0; i < buyerCount; i++) {
			if (states.containsKey(required[i])) {
				State state = states.get(required[i]);
				if (money[i] > state.best) {
					state.secondBest = state.best;
					state.secondBestIndex = state.bestIndex;
					state.best = money[i];
					state.bestIndex = i + 1;
				} else if (money[i] > state.secondBest) {
					state.secondBest = money[i];
					state.secondBestIndex = i + 1;
				}
			} else if (states.containsKey(required[i] - 1) && states.get(required[i] - 1).cost != Integer.MAX_VALUE) {
				State state = new State(required[i], Integer.MAX_VALUE, -1);
				state.best = money[i];
				state.bestIndex = i + 1;
				states.put(required[i], state);
			}
		}
		State[] array = states.values().toArray(new State[states.values().size()]);
		Arrays.sort(array, new Comparator<State>() {
			public int compare(State o1, State o2) {
				return o1.size - o2.size;
			}
		});
		long taken = 0;
		long notTaken = 0;
		int[] lastTaken = new int[array.length];
		boolean[] lastNotTaken = new boolean[array.length];
		for (int i = 0; i < array.length; i++) {
			if (i == 0 || array[i - 1].size != array[i].size - 1) {
				notTaken = taken;
				lastNotTaken[i] = true;
				lastTaken[i] = 0;
				if (array[i].best >= array[i].cost) {
					taken += array[i].cost;
					lastTaken[i] = 1;
				}
			} else {
				long nextNotTaken = taken;
				lastNotTaken[i] = true;
				if (array[i].best >= array[i - 1].cost && nextNotTaken < notTaken + array[i - 1].cost) {
					lastNotTaken[i] = false;
					nextNotTaken = notTaken + array[i - 1].cost;
				}
				long nextTaken = taken;
				lastTaken[i] = 0;
				if (array[i].best >= array[i].cost) {
					nextTaken = taken + array[i].cost;
					lastTaken[i] = 1;
				}
				if (nextNotTaken > nextTaken) {
					nextTaken = nextNotTaken;
					lastTaken[i] = 2;
				}
				if (array[i].best >= Math.max(array[i].cost, array[i - 1].cost) && array[i].secondBest >= Math.min(array[i].cost, array[i - 1].cost) &&
					nextTaken < notTaken + array[i].cost + array[i - 1].cost)
				{
					nextTaken = notTaken + array[i].cost + array[i - 1].cost;
					lastTaken[i] = 3;
				}
				notTaken = nextNotTaken;
				taken = nextTaken;
			}
		}
		out.printLine(taken);
		boolean curTaken = true;
		List<Pair<Integer, Integer>> answer = new ArrayList<Pair<Integer, Integer>>();
		for (int i = array.length - 1; i >= 0; i--) {
			if (curTaken) {
				if (lastTaken[i] == 0)
					continue;
				if (lastTaken[i] == 1) {
					answer.add(Pair.makePair(array[i].bestIndex, array[i].shoeIndex));
					continue;
				}
				if (lastTaken[i] == 3) {
					if (array[i].secondBest >= array[i].cost) {
						answer.add(Pair.makePair(array[i].secondBestIndex, array[i].shoeIndex));
						answer.add(Pair.makePair(array[i].bestIndex, array[i - 1].shoeIndex));
					} else {
						answer.add(Pair.makePair(array[i].secondBestIndex, array[i - 1].shoeIndex));
						answer.add(Pair.makePair(array[i].bestIndex, array[i].shoeIndex));
					}
					curTaken = false;
					continue;
				}
			}
			if (!lastNotTaken[i])
				answer.add(Pair.makePair(array[i].bestIndex, array[i - 1].shoeIndex));
			curTaken = lastNotTaken[i];
		}
		out.printLine(answer.size());
		for (Pair<Integer, Integer> pair : answer) {
			out.printLine(pair.first, pair.second);
		}
	}

	static class State {
		int size;
		int cost;
		int shoeIndex;
		int best;
		int bestIndex;
		int secondBest;
		int secondBestIndex;

		State(int size, int cost, int shoeIndex) {
			this.size = size;
			this.cost = cost;
			this.shoeIndex = shoeIndex;
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}