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
import java.util.ArrayDeque;
import java.math.BigInteger;
import java.util.Queue;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int timeLimit = in.readInt();
		int count = in.readInt();
		Queue<Long> queue = new ArrayDeque<Long>();
		while (!in.isExhausted()) {
			String line = in.readLine();
			String date = line.substring(0, 10);
			String time = line.substring(11, 19);
			Date curDate = Date.parse(date, "YYYY-MM-DD");
			Time curTime = Time.parse(time, "HH:MM:SS");
			long total = (long)curDate.asInt() * 24 * 60 * 60 + curTime.totalSeconds();
			while (!queue.isEmpty() && total - queue.peek() >= timeLimit)
				queue.poll();
			if (queue.size() == count - 1) {
				out.printLine(line.substring(0, 19));
				return;
			}
			queue.add(total);
		}
		out.printLine(-1);
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

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
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

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
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

class Date implements Comparable<Date> {
	private static final int[] DAYS_IN_MONTH = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	public final int year;
	public final int month;
	public final int day;
	private int weekday;

	public Date(int year, int month, int day) {
		this.year = year;
		this.month = month;
		this.day = day;
		weekday = -1;
	}

	public int asInt() {
		int day = (year - 1) * 365;
		day += (year - 1) / 4;
		day -= (year - 1) / 100;
		day += (year - 1) / 400;
		for (int i = 1; i < month; i++)
			day += DAYS_IN_MONTH[i];
		day += this.day;
		if (isLeapYear(year) && month > 2)
			day++;
		return day;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Date date = (Date) o;

		return day == date.day && month == date.month && year == date.year;
	}

	public int hashCode() {
		int result = year;
		result = 31 * result + month;
		result = 31 * result + day;
		return result;
	}

	public static Date parse(String date, String pattern) {
		int length = date.length();
		if (length != pattern.length())
			throw new IllegalArgumentException();
		int year = 0;
		int month = 0;
		int day = 0;
		for (int i = 0; i < length; i++) {
			if (Character.toUpperCase(pattern.charAt(i)) == 'Y') {
				year *= 10;
				year += date.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'M') {
				month *= 10;
				month += date.charAt(i) - '0';
			} else if (Character.toUpperCase(pattern.charAt(i)) == 'D') {
				day *= 10;
				day += date.charAt(i) - '0';
			}
		}
		return new Date(year, month, day);
	}

	public static boolean isLeapYear(int year) {
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}

	public int compareTo(Date o) {
		return asInt() - o.asInt();
	}

	public String toString() {
		return toString("DD.MM.YYYY");
	}

	public String toString(String pattern) {
		int copyYear = year;
		int copyMonth = month;
		int copyDay = day;
		StringBuilder result = new StringBuilder();
		for (int i = pattern.length() - 1; i >= 0; i--) {
			char character = pattern.charAt(i);
			switch (character) {
			case 'D': case 'd':
				result.append(copyDay % 10);
				copyDay /= 10;
				break;
			case 'M': case 'm':
				result.append(copyMonth % 10);
				copyMonth /= 10;
				break;
			case 'Y': case 'y':
				result.append(copyYear % 10);
				copyYear /= 10;
				break;
			default:
				result.append(character);
			}
		}
		return result.reverse().toString();
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