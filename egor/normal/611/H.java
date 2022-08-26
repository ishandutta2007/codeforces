import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskH solver = new TaskH();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskH {
		int[] bl;
		int[] nonBase;
		int digits;

		public void solve(int testNumber, InputReader in, OutputWriter out) {
			int n = in.readInt();
			digits = Integer.toString(n).length();
			int[][] qty = new int[digits][digits];
			for (int i = 0; i < n - 1; i++) {
				int a = in.readString().length() - 1;
				int b = in.readString().length() - 1;
				qty[Math.min(a, b)][Math.max(a, b)]++;
			}
			nonBase = ArrayUtils.createArray(digits, -1);
			for (int i = 1; i <= n; i++) {
				nonBase[Integer.toString(i).length() - 1]++;
			}
			int[] f = new int[digits * (digits - 1) / 2];
			int[] t = new int[f.length];
			int at = 0;
			for (int i = 0; i < digits; i++) {
				for (int j = 0; j < i; j++) {
					f[at] = j;
					t[at++] = i;
				}
			}
			for (int i = 0; i < (1 << f.length); i++) {
				if (Integer.bitCount(i) != digits - 1) {
					continue;
				}
				IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(digits);
				boolean good = true;
				for (int j = 0; j < f.length; j++) {
					if ((i >> j & 1) == 1) {
						setSystem.join(f[j], t[j]);
						qty[f[j]][t[j]]--;
						if (qty[f[j]][t[j]] < 0) {
							good = false;
						}
					}
				}
				if (setSystem.getSetCount() != 1 || !good) {
					for (int j = 0; j < f.length; j++) {
						if ((i >> j & 1) == 1) {
							qty[f[j]][t[j]]++;
						}
					}
					continue;
				}
				good = true;
				bl = new int[1 << digits];
				for (int j = 1; j < (1 << digits); j++) {
					int balance = 0;
					for (int k = 0; k < digits; k++) {
						if ((j >> k & 1) == 0) {
							continue;
						}
						balance -= nonBase[k];
						for (int l = 0; l < digits; l++) {
							balance += qty[k][l];
							if ((j >> l & 1) == 0) {
								balance += qty[l][k];
							}
						}
					}
					bl[j] = balance;
					if (balance < 0) {
						good = false;
						break;
					}
				}
				if (!good) {
					for (int j = 0; j < f.length; j++) {
						if ((i >> j & 1) == 1) {
							qty[f[j]][t[j]]++;
						}
					}
					continue;
				}
				int[] base = new int[digits];
				int[] next = new int[digits];
				int c = 1;
				for (int j = 0; j < digits; j++) {
					base[j] = c;
					next[j] = c + 1;
					c *= 10;
				}
				int remaining = n - 1;
				for (int j = 0; j < f.length; j++) {
					if ((i >> j & 1) == 1) {
						out.printLine(base[f[j]], base[t[j]]);
						remaining--;
					}
				}
				boolean[] spotted = new boolean[1 << digits];
				while (remaining > 0) {
					boolean found = false;
					for (int j = 1; j < (1 << digits); j++) {
						if (bl[j] == 0 && !spotted[j]) {
							spotted[j] = true;
							for (int k = 0; k < digits; k++) {
								if ((j >> k & 1) == 0) {
									continue;
								}
								for (int l = 0; l < digits; l++) {
									if ((j >> l & 1) == 1) {
										continue;
									}
									for (int m = 0; m < qty[k][l] + qty[l][k]; m++) {
										out.printLine(base[l], next[k]++);
										remaining--;
										addEdge(k, l);
									}
									qty[k][l] = qty[l][k] = 0;
								}
							}
							found = true;
							break;
						}
					}
					if (found) {
						continue;
					}
					for (int j = 0; !found && j < digits; j++) {
						for (int k = 0; k <= j; k++) {
							if (qty[k][j] != 0) {
								found = true;
								out.printLine(base[j], next[k]++);
								addEdge(k, j);
								qty[k][j]--;
								remaining--;
								break;
							}
						}
					}
				}
				return;
			}
			out.printLine(-1);
		}

		private void addEdge(int next, int base) {
			nonBase[next]--;
			for (int i = 0; i < (1 << digits); i++) {
				if ((i >> base & 1) == 1 && (i >> next & 1) == 0) {
					bl[i]--;
				}
			}
		}

	}

	static class OutputWriter {
		private final PrintWriter writer;

		public OutputWriter(OutputStream outputStream) {
			writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
		}

		public OutputWriter(Writer writer) {
			this.writer = new PrintWriter(writer);
		}

		public void print(Object... objects) {
			for (int i = 0; i < objects.length; i++) {
				if (i != 0)
					writer.print(' ');
				writer.print(objects[i]);
			}
		}

		public void printLine(Object... objects) {
			print(objects);
			writer.println();
		}

		public void close() {
			writer.close();
		}

		public void printLine(int i) {
			writer.println(i);
		}

	}

	static interface IndependentSetSystem {
		public boolean join(int first, int second);

		public int getSetCount();

		public static interface Listener {
			public void joined(int joinedRoot, int root);

		}

	}

	static class ArrayUtils {
		public static int[] createArray(int count, int value) {
			int[] array = new int[count];
			Arrays.fill(array, value);
			return array;
		}

	}

	static class RecursiveIndependentSetSystem implements IndependentSetSystem {
		private final int[] color;
		private final int[] rank;
		private int setCount;
		private Listener listener;

		public RecursiveIndependentSetSystem(int size) {
			color = new int[size];
			rank = new int[size];
			for (int i = 0; i < size; i++)
				color[i] = i;
			setCount = size;
		}

		public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
			color = other.color.clone();
			rank = other.rank.clone();
			setCount = other.setCount;
		}

		public boolean join(int first, int second) {
			first = get(first);
			second = get(second);
			if (first == second)
				return false;
			if (rank[first] < rank[second]) {
				int temp = first;
				first = second;
				second = temp;
			} else if (rank[first] == rank[second])
				rank[first]++;
			setCount--;
			color[second] = first;
			if (listener != null)
				listener.joined(second, first);
			return true;
		}

		public int get(int index) {
			if (color[index] == index)
				return index;
			return color[index] = get(color[index]);
		}

		public int getSetCount() {
			return setCount;
		}

	}

	static class InputReader {
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

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				if (Character.isValidCodePoint(c))
					res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);

		}

	}
}