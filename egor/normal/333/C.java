import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.AbstractSet;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		Map<Integer, IntSet> map = new CPPMap<Integer, IntSet>(new Factory<IntSet>() {
			public IntSet create() {
				return new SpecialSet();
			}
		});
		map = twice(map, 10, -1);
		map = twice(map, 100, -1);
		int value = in.readInt();
		map = twice(map, 10000, value);
		int count = in.readInt();
		for (int i : map.get(value).toArray()) {
			out.printFormat("%08d\n", i);
			if (--count == 0)
				break;
		}
		if (count != 0)
			throw new RuntimeException();
    }

	private Map<Integer, IntSet> twice(Map<Integer, IntSet> counter, int ten, int exact) {
		for (int i = 0; i < ten; i++)
			counter.get(i).add(i);
		Map<Integer, IntSet> result = new CPPMap<Integer, IntSet>(new Factory<IntSet>() {
			public IntSet create() {
				return new SpecialSet();
			}
		});
		for (Map.Entry<Integer, IntSet> first : counter.entrySet()) {
			if (exact != -1) {
				int key = first.getKey();
				if (counter.containsKey(Math.abs(exact - key)))
					process(ten, exact, result, first.getValue(), counter.get(Math.abs(exact - key)), first.getKey(), Math.abs(exact - key));
				if (counter.containsKey(exact + key))
					process(ten, exact, result, first.getValue(), counter.get(exact + key), first.getKey(), exact + key);
				if (key != 0 && exact % key == 0 && counter.containsKey(exact / key))
					process(ten, exact, result, first.getValue(), counter.get(exact / key), first.getKey(), exact / key);
			} else {
				for (Map.Entry<Integer, IntSet> second : counter.entrySet()) {
					process(ten, exact, result, first.getValue(), second.getValue(), first.getKey(), second.getKey());
				}
			}
		}
		return result;
	}

	private void process(int ten, int exact, Map<Integer, IntSet> result, IntSet first, IntSet second, int firstKey, int secondKey) {
		Integer sum = firstKey + secondKey;
		Integer difference = Math.abs(firstKey - secondKey);
		Integer product = firstKey * secondKey;
		if (exact != -1 && sum != exact && difference != exact && product != exact)
			return;
		for (IntIterator i = first.iterator(); i.isValid(); i.advance()) {
			for (IntIterator j = second.iterator(); j.isValid(); j.advance()) {
				if (exact == -1 || exact == sum)
					result.get(sum).add(i.value() * ten + j.value());
				if (exact == -1 || exact == difference)
					result.get(difference).add(i.value() * ten + j.value());
				if (exact == -1 || exact == product)
					result.get(product).add(i.value() * ten + j.value());
				if (exact != -1 && result.get(exact).size() == 300000)
					return;
			}
		}
	}

	static class SpecialSet extends IntHashSet {
		public void add(int value) {
			if (size() >= 300000)
				return;
			super.add(value);
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

	public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	}

abstract class IntSet extends IntCollection {
	}

class CPPMap<K, V> extends EHashMap<K, V> {
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

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

	public int[] toArray() {
		int size = size();
		int[] array = new int[size];
		int i = 0;
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance())
			array[i++] = iterator.value();
		return array;
	}

	}

interface IntIterator {
	public int value() throws NoSuchElementException;
	/*
	 * @throws NoSuchElementException only if iterator already invalid
	 */
	public void advance() throws NoSuchElementException;
	public boolean isValid();
}

class IntHashSet extends IntSet {
	private static final Random RND = new Random();
	private static final int[] SHIFTS = new int[4];
	private static final byte PRESENT_MASK = 1;

	static {
		for (int i = 0; i < 4; i++)
			SHIFTS[i] = RND.nextInt(31) + 1;
	}

	private int size;
	private int[] values;
	private byte[] present;
	private int step;
	private int ratio;

	public IntHashSet() {
		this(3);
	}


	public IntHashSet(int capacity) {
		capacity = Math.max(capacity, 1);
		values = new int[capacity];
		present = new byte[capacity];
		ratio = capacity;
		initStep(capacity);
	}

	private void initStep(int capacity) {
		step = RND.nextInt(capacity - 2) + 1;
		while (IntegerUtils.gcd(step, capacity) != 1)
			step++;
	}

	public IntIterator iterator() {
		return new IntIterator() {
			private int position = size == 0 ? values.length : -1;

			public int value() throws NoSuchElementException {
				if (position == -1)
					advance();
				if (position >= values.length)
					throw new NoSuchElementException();
				return values[position];
			}

			public void advance() throws NoSuchElementException {
				if (position >= values.length)
					throw new NoSuchElementException();
				position++;
				while (position < values.length && (present[position] & PRESENT_MASK) == 0)
					position++;
			}

			public boolean isValid() {
				return position < values.length;
			}
		};
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity((size + 1) * ratio);
		int current = getHash(value);
		while ((present[current] & PRESENT_MASK) != 0) {
			if (values[current] == value)
				return;
			current += step;
			if (current >= values.length)
				current -= values.length;
		}
		present[current] = PRESENT_MASK;
		values[current] = value;
		size++;
	}

	private int getHash(int value) {
		int result = value;
		for (int i : SHIFTS)
			result ^= value >> i;
		result %= values.length;
		if (result < 0)
			result += values.length;
		return result;
	}

	private void ensureCapacity(int capacity) {
		if (values.length < capacity) {
			capacity = Math.max(capacity, 2 * values.length);
			rebuild(capacity);
		}
	}

	private void rebuild(int capacity) {
		initStep(capacity);
		int[] oldValues = values;
		byte[] oldPresent = present;
		values = new int[capacity];
		present = new byte[capacity];
		size = 0;
		for (int i = 0; i < oldValues.length; i++) {
			if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK)
				add(oldValues[i]);
		}
	}


}

class EHashMap<E, V> extends AbstractMap<E, V> {
	private static final int[] shifts = new int[10];

	private int size;
	private HashEntry<E, V>[] data;
	private int capacity;
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
		capacity = Integer.highestOneBit(4 * size);
        //noinspection unchecked
        data = new HashEntry[capacity];
	}

	public EHashMap(int maxSize) {
		setCapacity(maxSize);
		entrySet = new AbstractSet<Entry<E, V>>() {
			@Override
			public Iterator<Entry<E, V>> iterator() {
				return new Iterator<Entry<E, V>>() {
					private HashEntry<E, V> last = null;
                    private HashEntry<E, V> current = null;
                    private HashEntry<E, V> base = null;
                    private int lastIndex = -1;
					private int index = -1;

					public boolean hasNext() {
                        if (current == null) {
                            for (index++; index < capacity; index++) {
                                if (data[index] != null) {
                                    base = current = data[index];
                                    break;
                                }
                            }
                        }
                        return current != null;
					}

					public Entry<E, V> next() {
						if (!hasNext())
							throw new NoSuchElementException();
                        last = current;
                        lastIndex = index;
                        current = current.next;
                        if (base.next != last)
                            base = base.next;
						return last;
					}

					public void remove() {
						if (last == null)
							throw new IllegalStateException();
                        size--;
                        if (base == last)
                            data[lastIndex] = last.next;
                        else
                            base.next = last.next;
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
		Arrays.fill(data, null);
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
        HashEntry<E, V> current = data[index];
        HashEntry<E, V> last = null;
        while (current != null) {
            if (current.key.equals(o)) {
                if (last == null)
                    data[index] = current.next;
                else
                    last.next = current.next;
                size--;
                return current.value;
            }
            last = current;
            current = current.next;
        }
        return null;
	}

	public V put(E e, V value) {
		if (e == null)
			return null;
		int index = index(e);
        HashEntry<E, V> current = data[index];
        if (current != null) {
            while (true) {
                if (current.key.equals(e)) {
                    V oldValue = current.value;
                    current.value = value;
                    return oldValue;
                }
                if (current.next == null)
                    break;
                current = current.next;
            }
        }
        if (current == null)
            data[index] = new HashEntry<E, V>(e, value);
        else
            current.next = new HashEntry<E, V>(e, value);
        size++;
        if (2 * size > capacity) {
            HashEntry<E, V>[] oldData = data;
            setCapacity(size);
            for (HashEntry<E, V> entry : oldData) {
                while (entry != null) {
                    HashEntry<E, V> next = entry.next;
                    index = index(entry.key);
                    entry.next = data[index];
                    data[index] = entry;
                    entry = next;
                }
            }
        }
		return null;
	}

	public V get(Object o) {
		if (o == null)
			return null;
		int index = index(o);
        HashEntry<E, V> current = data[index];
		while (current != null) {
			if (current.key.equals(o))
                return current.value;
            current = current.next;
        }
		return null;
	}

	public boolean containsKey(Object o) {
        if (o == null)
            return false;
        int index = index(o);
        HashEntry<E, V> current = data[index];
        while (current != null) {
            if (current.key.equals(o))
                return true;
            current = current.next;
        }
        return false;
	}

	public int size() {
		return size;
	}

	private static class HashEntry<E, V> implements Entry<E, V> {
		private final E key;
		private V value;
        private HashEntry<E, V> next;

        private HashEntry(E key, V value) {
            this.key = key;
            this.value = value;
        }


        public E getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public V setValue(V value) {
            V oldValue = this.value;
            this.value = value;
            return oldValue;
        }
    }
}

class IntegerUtils {

    public static int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    }