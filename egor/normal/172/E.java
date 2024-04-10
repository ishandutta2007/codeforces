import java.util.List;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
	int start;
	String document;

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		document = in.readString();
		List<Node> roots = new ArrayList<Node>();
		while (start != document.length())
			roots.add(build());
		int queryCount = in.readInt();
		for (int i = 0; i < queryCount; i++) {
			String[] tags = in.readLine().split(" ");
			int result = 0;
			for (Node root : roots)
				result += root.count(tags, 0);
			out.printLine(result);
		}
	}

	private Node build() {
		String tag = null;
		for (int i = start + 1; ; i++) {
			if (document.charAt(i) == '>') {
				tag = document.substring(start + 1, i);
				start = i + 1;
				break;
			}
		}
		if (tag.charAt(tag.length() - 1) == '/')
			return new Node(tag.substring(0, tag.length() - 1));
		Node result = new Node(tag);
		while (document.charAt(start + 1) != '/')
			result.addChild(build());
		start += tag.length() + 3;
		return result;
	}

	static class Node {
		final String tag;
		List<Node> children;

		Node(String tag) {
			this.tag = tag;
		}

		Node addChild(Node node) {
			if (children == null)
				children = new ArrayList<Node>();
			children.add(node);
			return node;
		}

		public int count(String[] tags, int position) {
			int result = 0;
			if (tags[position].equals(tag)) {
				if (position == tags.length - 1)
					result++;
				else
					position++;
			}
			if (children != null) {
				for (Node node : children)
					result += node.count(tags, position);
			}
			return result;
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