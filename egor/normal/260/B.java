import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.AbstractSet;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.AbstractMap;
import java.util.NoSuchElementException;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String prophecy = in.readString();
        Counter<String> counter = new Counter<String>();
        for (int i = 0; i <= prophecy.length() - 10; i++) {
            String current = prophecy.substring(i, i + 10);
            boolean good = true;
            for (int j = 0; j < 10; j++) {
                if (current.charAt(j) == '-') {
                    if (j != 2 && j != 5) {
                        good = false;
                        break;
                    }
                } else if (j == 2 || j == 5) {
                    good = false;
                    break;
                }
            }
            if (!good)
                continue;
            Date date = Date.parse(current, "DD-MM-YYYY");
            if (date.isValid() && date.year >= 2013 && date.year <= 2015)
                counter.add(current);
        }
        long max = CollectionUtils.maxElement(counter.values());
        for (String s : counter.keySet()) {
            if (counter.get(s) == max) {
                out.printLine(s);
                return;
            }
        }
        throw new RuntimeException();
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

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
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

class Counter<K> extends EHashMap<K, Long> {
	public Counter() {
		super();
	}

	public void add(K key) {
		put(key, get(key) + 1);
	}

	public Long get(Object key) {
		if (containsKey(key))
			return super.get(key);
		return 0L;
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

	public boolean isValid() {
		return !(month > 12 || month < 1) && !(day > DAYS_IN_MONTH[month] &&
			(day != 29 || month != 2 || !isLeapYear(year))) && day >= 1;
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

class CollectionUtils {

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private Object[] keys;
	private Object[] values;
	private int capacity;
	private int shift;
	private int[] indices;
	private Set<Entry<E, V>> entrySet;

	static {
		Random random = new Random(System.currentTimeMillis());
		for (int i = 0; i < 10; i++)
			shifts[i] = 1 + 3 * i + random.nextInt(3);
	}

	public EHashMap() {
		this(4);
	}

	private void setCapacity(int size) {
		capacity = Integer.highestOneBit(10 * size);
		keys = new Object[capacity];
		values = new Object[capacity];
		shift = capacity / 3 - 1;
		shift -= 1 - (shift & 1);
		indices = new int[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			@Override
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry entry = new HashEntry();
					int index = 0;

					public boolean hasNext() {
						while (index < capacity && keys[index] == null)
							index++;
						return index < capacity;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
						entry.key = (E) keys[index];
						entry.value = (V) values[index++];
						return entry;
					}

					public void remove() {
						if (entry.key == null)
							throw new IllegalStateException();
						EHashMap.this.remove(entry.key);
						entry.key = null;
						entry.value = null;
					}
				};
			}

			@Override
			public int size() {
				return size;
			}
		};
	}

	public EHashMap(Map<E, V> map) {
		this(map.size());
		putAll(map);
	}

	public Set<Entry<E, V>> entrySet() {
		return entrySet;
	}

	public void clear() {
		Arrays.fill(keys, null);
		Arrays.fill(values, null);
		size = 0;
	}

	private int index(Object o) {
		return getHash(o.hashCode()) & (capacity - 1);
	}

	private int getHash(int h) {
		int result = h;
		for (int i : shifts)
			result ^= h >>> i;
		return result;
	}

	public V remove(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		int indicesSize = 0;
		while (keys[index] != null && !keys[index].equals(o)) {
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		if (keys[index] == null)
			return null;
		size--;
		int lastIndex = indicesSize;
		indices[indicesSize++] = index;
		keys[index] = null;
		V result = (V) values[index];
		values[index] = null;
		index = (index + shift) & (capacity - 1);
		while (keys[index] != null) {
			int curKey = index(keys[index]);
			for (int i = 0; i <= lastIndex; i++) {
				if (indices[i] == curKey) {
					keys[indices[lastIndex]] = keys[index];
					values[indices[lastIndex]] = values[index];
					keys[index] = null;
					values[index] = null;
					lastIndex = indicesSize;
				}
			}
			indices[indicesSize++] = index;
			index = (index + shift) & (capacity - 1);
		}
		return result;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
		while (keys[index] != null && !keys[index].equals(e))
			index = (index + shift) & (capacity - 1);
		if (keys[index] == null)
			size++;
		keys[index] = e;
		values[index] = value;
		if (size * 2 > capacity) {
			Object[] oldKeys = keys;
			Object[] oldValues = values;
			setCapacity(size);
			size = 0;
			for (int i = 0; i < oldKeys.length; i++) {
				if (oldKeys[i] != null)
					put((E) oldKeys[i], (V) oldValues[i]);
			}
		}
		return value;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return (V) values[index];
	}

	public boolean containsKey(Object o) {
		if (o == null)
			return false;
		int index = index(o);
		while (keys[index] != null && !keys[index].equals(o))
			index = (index + shift) & (capacity - 1);
		return keys[index] != null;
	}

	public int size() {
		return size;
	}

	private class HashEntry implements Entry<E, V> {
		private E key;
		private V value;

		public E getKey() {
			return key;
		}

		public V getValue() {
			return value;
		}

		public V setValue(V value) {
			put(key, value);
			return this.value = value;
		}
	}
}