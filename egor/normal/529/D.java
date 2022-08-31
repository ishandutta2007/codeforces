import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.util.Arrays;
import java.io.InputStream;
import java.io.OutputStreamWriter;

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
		int max = in.readInt();
		int segment = in.readInt();
		String[] times = IOUtils.readStringArray(in, count);
		int[] queue = new int[count];
		int start = 0;
		int end = 0;
		int[] at = new int[count];
		boolean achieved = false;
		int[] answer = new int[count];
		for (int i = 0; i < count; i++) {
			at[i] = Time.parse(times[i], "hh:mm:ss").totalSeconds();
			while (start < end && at[i] >= at[queue[start]] + segment) {
				start++;
			}
			if (end - start == max) {
				answer[i] = end;
				queue[end - 1] = i;
				continue;
			}
			answer[i] = end + 1;
			queue[end++] = i;
			if (end - start == max) {
				achieved = true;
			}
		}
		if (achieved) {
			out.printLine(end);
			for (int i : answer) {
				out.printLine(i);
			}
		} else {
			out.printLine("No solution");
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

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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

	public void printLine(int i) {
		writer.println(i);
	}
}

class IOUtils {

	public static String[] readStringArray(InputReader in, int size) {
		String[] array = new String[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readString();
		return array;
	}

}

class Time implements Comparable<Time> {
	private final int hours;
	private final int minutes;
	private final int seconds;

	public static Time parse(String time, String pattern) {
		int length = time.length();
		if (length != pattern.length())
			throw new IllegalArgumentException();
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		for (int i = 0; i < length; i++) {
			if (Character.toUpperCase(pattern.charAt(i)) == 'H') {
				hours *= 10;
				hours += time.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'M') {
				minutes *= 10;
				minutes += time.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'S') {
				seconds *= 10;
				seconds += time.charAt(i) - '0';
			}
		}
		return new Time(hours, minutes, seconds);
	}

	public Time(int hours, int minutes, int seconds) {
		this.hours = hours;
		this.minutes = minutes;
		this.seconds = seconds;
	}

	public String toString() {
		return toString("HH:MM:SS");
	}

	public String toString(String pattern) {
		int copyHours = hours;
		int copyMinutes = minutes;
		int copySeconds = seconds;
		StringBuilder result = new StringBuilder();
		for (int i = pattern.length() - 1; i >= 0; i--) {
			char character = pattern.charAt(i);
			switch (character) {
			case 'S': case 's':
				result.append(copySeconds % 10);
				copySeconds /= 10;
				break;
			case 'M': case 'm':
				result.append(copyMinutes % 10);
				copyMinutes /= 10;
				break;
			case 'H': case 'h':
				result.append(copyHours % 10);
				copyHours /= 10;
				break;
			default:
				result.append(character);
			}
		}
		return result.reverse().toString();
	}

	public int totalMinutes() {
		return hours * 60 + minutes;
	}

	public int totalSeconds() {
		return totalMinutes() * 60 + seconds;
	}

	public int compareTo(Time o) {
		return totalSeconds() - o.totalSeconds();
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Time time = (Time) o;

		if (hours != time.hours) return false;
		if (minutes != time.minutes) return false;
		if (seconds != time.seconds) return false;

		return true;
	}

	public int hashCode() {
		int result = hours;
		result = 31 * result + minutes;
		result = 31 * result + seconds;
		return result;
	}
}