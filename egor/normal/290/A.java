import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	String list = "1. George Washington \n" +
		"2. John Adams \n" +
		"3. Thomas Jefferson \n" +
		"4. James Madison \n" +
		"5. James Monroe \n" +
		"6. John Adams \n" +
		"7. Andrew Jackson \n" +
		"8. Martin Van_Buren \n" +
		"9. William Harrison \n" +
		"10. John Tyler \n" +
		"11. James Polk \n" +
		"12. Zachary Taylor \n" +
		"13. Millard Fillmore \n" +
		"14. Franklin Pierce \n" +
		"15. James Buchanan \n" +
		"16. Abraham Lincoln \n" +
		"17. Andrew Johnson \n" +
		"18. Ulysses S. Grant \n" +
		"19. Rutherford B. Hayes \n" +
		"20. James Garfield \n" +
		"21. Chester Arthur \n" +
		"22. Grover Cleveland \n" +
		"23. Benjamin Harrison \n" +
		"24. Grover Cleveland \n" +
		"25. William McKinley \n" +
		"26. Theodore Roosevelt \n" +
		"27. William Taft \n" +
		"28. Woodrow Wilson \n" +
		"29. Warren Harding \n" +
		"30. Calvin Coolidge \n" +
		"31. Herbert Hoover \n" +
		"32. Franklin D. Roosevelt \n" +
		"33. Harry Truman \n" +
		"34. Dwight D. Eisenhower \n" +
		"35. John F. Kennedy \n" +
		"36. Lyndon Johnson \n" +
		"37. Richard Nixon \n" +
		"38. Gerald Ford \n" +
		"39. James Carter \n" +
		"40. Ronald Reagan ";

    public void solve(int testNumber, InputReader in, OutputWriter out) {
		String[] tokens = list.split(" ");
		int index = in.readInt();
		int i = 0;
		while (true) {
			i += 2;
			if (tokens[i].length() == 2)
				i++;
			index--;
			if (index == 0) {
				out.printLine(tokens[i].replace('_', ' '));
				return;
			}
			i++;
		}
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
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
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