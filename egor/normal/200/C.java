import java.util.Map;
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
		Counter<String> played = new Counter<String>();
		Counter<String> points = new Counter<String>();
		Counter<String> difference = new Counter<String>();
		Counter<String> goals = new Counter<String>();
		for (int i = 0; i < 5; i++) {
			String first = in.readString();
			String second = in.readString();
			String score = in.readString();
			int firstGoals = Integer.parseInt(score.split(":")[0]);
			int secondGoals = Integer.parseInt(score.split(":")[1]);
			played.add(first);
			played.add(second);
			if (firstGoals > secondGoals)
				points.add(first, 3);
			else if (firstGoals < secondGoals)
				points.add(second, 3);
			else {
				points.add(first);
				points.add(second);
			}
			difference.add(first, firstGoals - secondGoals);
			difference.add(second, secondGoals - firstGoals);
			goals.add(first, firstGoals);
			goals.add(second, secondGoals);
		}
		points.add("BERLAND", 3);
		String other = null;
		for (Map.Entry<String, Long> entry : played.entrySet()) {
			if (entry.getValue() == 2 && !"BERLAND".equals(entry.getKey()))
				other = entry.getKey();
		}
		for (int i = 1; i < 100; i++) {
			for (int j = 0; j <= 100; j++) {
				difference.add("BERLAND", i);
				difference.add(other, -i);
				goals.add("BERLAND", i + j);
				goals.add(other, j);
				int place = 0;
				for (String key : played.keySet()) {
					if (points.get(key) > points.get("BERLAND") || points.get(key).equals(points.get("BERLAND")) &&
						(difference.get(key) > difference.get("BERLAND") || difference.get(key).equals(difference.get("BERLAND")) &&
						(goals.get(key) > goals.get("BERLAND") || goals.get(key).equals(goals.get("BERLAND")) && key.compareTo("BERLAND") <= 0)))
					{
						place++;
					}
				}
				if (place <= 2) {
					out.printLine((i + j) + ":" + j);
					return;
				}
				difference.add("BERLAND", -i);
				difference.add(other, i);
				goals.add("BERLAND", -i - j);
				goals.add(other, -j);
			}
		}
		out.printLine("IMPOSSIBLE");
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

	public void add(K key, long delta) {
		put(key, get(key) + delta);
	}

	public Long get(Object key) {
		if (containsKey(key))
			return super.get(key);
		return 0L;
	}
}