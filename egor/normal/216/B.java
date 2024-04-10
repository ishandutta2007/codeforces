import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		int edgeCount = in.readInt();
		int[] first = new int[edgeCount];
		int[] second = new int[edgeCount];
		IOUtils.readIntArrays(in, first, second);
		MiscUtils.decreaseByOne(first, second);
		IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(count);
		for (int i = 0; i < edgeCount; i++)
			setSystem.join(first[i], second[i]);
		int[] vertices = new int[count];
		int[] edges = new int[count];
		for (int i = 0; i < count; i++)
			vertices[setSystem.get(i)]++;
		for (int i : first)
			edges[setSystem.get(i)]++;
		int answer = 0;
		int odd = 0;
		for (int i = 0; i < count; i++) {
			if (vertices[i] == edges[i])
				answer += vertices[i] & 1;
			else
				odd += vertices[i] & 1;
		}
		answer += odd & 1;
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

class IOUtils {

	public static void readIntArrays(InputReader in, int[]... arrays) {
		for (int i = 0; i < arrays[0].length; i++) {
			for (int j = 0; j < arrays.length; j++)
				arrays[j][i] = in.readInt();
		}
	}

	}

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}

interface IndependentSetSystem {
	public boolean join(int first, int second);

	public int get(int index);

	public static interface Listener {
		public void joined(int joinedRoot, int root);
	}
}

class RecursiveIndependentSetSystem implements IndependentSetSystem {
	private final int[] color;
	private int setCount;
	private Listener listener;

	public RecursiveIndependentSetSystem(int size) {
		color = new int[size];
		for (int i = 0; i < size; i++)
			color[i] = i;
		setCount = size;
	}

	public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
		color = other.color.clone();
		setCount = other.setCount;
	}

	public boolean join(int first, int second) {
		first = get(first);
		second = get(second);
		if (first == second)
			return false;
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

	}