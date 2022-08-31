import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.HashMap;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		Map<String, List<int[]>> functions = new CPPMap<String, List<int[]>>(new Factory<List<int[]>>() {
			public List<int[]> create() {
				return new ArrayList<int[]>();
			}
		});
		Indexer<String> indexer = new Indexer<String>();
		indexer.put("T", -1);
		for (int i = 0; i < count; i++) {
			String function = in.readLine().replace('(', ' ').replace(')', ' ').replace(',', ' ').trim();
			String[] tokens = function.split(" +");
			int[] signature = new int[tokens.length - 2];
			for (int j = 0; j < signature.length; j++)
				signature[j] = indexer.get(tokens[j + 2]);
			functions.get(tokens[1]).add(signature);
		}
		int variableCount = in.readInt();
		Map<String, String> variables = new HashMap<String, String>();
		for (int i = 0; i < variableCount; i++) {
			String type = in.readString();
			String name = in.readString();
			variables.put(name, type);
		}
		int callCount = in.readInt();
		for (int i = 0; i < callCount; i++) {
			String call = in.readLine().replace('(', ' ').replace(')', ' ').replace(',', ' ').trim();
			String[] tokens = call.split(" +");
			int[] signature = new int[tokens.length - 1];
			for (int j = 0; j < signature.length; j++)
				signature[j] = indexer.get(variables.get(tokens[j + 1]));
			int answer = 0;
			for (int[] function : functions.get(tokens[0])) {
				if (function.length != signature.length)
					continue;
				boolean good = true;
				for (int j = 0; j < function.length; j++) {
					if (function[j] != -1 && function[j] != signature[j]) {
						good = false;
						break;
					}
				}
				if (good)
					answer++;
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

	private String readLine0() {
		StringBuffer buf = new StringBuffer();
		int c = read();
		while (c != '\n' && c != -1) {
			if (c != '\r')
				buf.appendCodePoint(c);
			c = read();
		}
		return buf.toString();
	}

	public String readLine() {
		String s = readLine0();
		while (s.trim().length() == 0)
			s = readLine0();
		return s;
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

class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

interface Factory<V> {
	public V create();
}

class Indexer<K> extends HashMap<K, Integer> {
	private int index = 0;

	public Integer get(Object key) {
		if (!containsKey(key))
			put((K) key, index++);
		return super.get(key);
	}
}