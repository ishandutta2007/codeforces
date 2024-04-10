import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractCollection;
import java.io.Writer;
import java.util.Collection;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int count = in.readInt();
		Rational[] x = new Rational[count];
		Rational[] y = new Rational[count];
		Rational[] dx = new Rational[count];
		Rational[] dy = new Rational[count];
		for (int i = 0; i < count; i++) {
			int t0 = in.readInt();
			int x0 = in.readInt();
			int y0 = in.readInt();
			int t1 = in.readInt();
			int x1 = in.readInt();
			int y1 = in.readInt();
			dx[i] = new Rational(x1 - x0, t1 - t0);
			dy[i] = new Rational(y1 - y0, t1 - t0);
			x[i] = new Rational(x0, 1).subtract(new Rational(t0, 1).multiply(dx[i]));
			y[i] = new Rational(y0, 1).subtract(new Rational(t0, 1).multiply(dy[i]));
		}
		Rational[] cx = new Rational[count];
		Rational[] cy = new Rational[count];
		Rational[] cdx = new Rational[count];
		Rational[] cdy = new Rational[count];
		long answer = 1;
		for (int i = 0; i < count; i++) {
			IntList goodList = new IntArrayList();
			for (int j = i + 1; j < count; j++) {
				if (dx[j].equals(dx[i]) && dy[j].equals(dy[i]))
					continue;
				cx[j] = x[j].subtract(x[i]);
				cy[j] = y[j].subtract(y[i]);
				cdx[j] = dx[j].subtract(dx[i]);
				cdy[j] = dy[j].subtract(dy[i]);
				if (cx[j].numerator.multiply(cdy[j].numerator).multiply(cy[j].denominator).multiply(cdx[j].denominator).equals(
					cy[j].numerator.multiply(cdx[j].numerator).multiply(cx[j].denominator).multiply(cdy[j].denominator)))
				{
					goodList.add(j);
				}
			}
			int[] good = goodList.toArray();
			Counter<Rational> times = new Counter<Rational>();
			Map<Rational, Set<Rational>> lines = new CPPMap<Rational, Set<Rational>>(new Factory<Set<Rational>>() {
				public Set<Rational> create() {
					return new EHashSet<Rational>();
				}
			});
			Set<Rational> special = new EHashSet<Rational>();
			for (int j : good) {
				if (cdy[j].equals(Rational.ZERO)) {
					times.add(cx[j].divide(cdx[j]));
					special.add(cdx[j]);
				} else {
					times.add(cy[j].divide(cdy[j]));
					lines.get(cdx[j].divide(cdy[j])).add(cdy[j]);
				}
			}
			for (long value : times.values())
				answer = Math.max(answer, value + 1);
			for (Set<Rational> set : lines.values())
				answer = Math.max(answer, set.size() + 1);
			answer = Math.max(answer, special.size() + 1);
		}
		out.printLine(answer);
    }

	public static class Rational implements Comparable<Rational> {
		public static final Rational ZERO = new Rational(0, 1);

		public final BigInteger numerator;
		public final BigInteger denominator;

		public Rational(long numerator, long denominator) {
			if (denominator == 0)
				throw new IllegalArgumentException();
			long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
			if (denominator > 0) {
				this.numerator = BigInteger.valueOf(numerator / gcd);
				this.denominator = BigInteger.valueOf(denominator / gcd);
			} else {
				this.numerator = BigInteger.valueOf(-numerator / gcd);
				this.denominator = BigInteger.valueOf(-denominator / gcd);
			}
		}

		public Rational(BigInteger numerator, BigInteger denominator) {
			if (denominator.equals(BigInteger.ZERO))
				throw new IllegalArgumentException();
			BigInteger gcd = numerator.abs().gcd(denominator.abs());
			if (denominator.compareTo(BigInteger.ZERO) > 0) {
				this.numerator = numerator.divide(gcd);
				this.denominator = denominator.divide(gcd);
			} else {
				this.numerator = numerator.negate().divide(gcd);
				this.denominator = denominator.negate().divide(gcd);
			}
		}

		public String toString() {
			return numerator + "/" + denominator;
		}

		public int compareTo(Rational other) {
			return numerator.multiply(other.denominator).compareTo(denominator.multiply(other.numerator));
		}

		public Rational subtract(Rational other) {
			return new Rational(numerator.multiply(other.denominator).subtract(denominator.multiply(other.numerator)),
				denominator.multiply(other.denominator));
		}

		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Rational rational = (Rational) o;

			if (!denominator.equals(rational.denominator)) return false;
			if (!numerator.equals(rational.numerator)) return false;

			return true;
		}

		public int hashCode() {
			int result = numerator.hashCode();
			result = 31 * result + denominator.hashCode();
			return result;
		}

		public Rational divide(Rational other) {
			return new Rational(numerator.multiply(other.denominator), other.numerator.multiply(denominator));
		}

		public Rational multiply(Rational other) {
			return new Rational(numerator.multiply(other.numerator), other.denominator.multiply(denominator));
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	}

abstract class IntList extends IntCollection implements Comparable<IntList> {

	public abstract int get(int index);

	public IntIterator iterator() {
		return new IntIterator() {
			private int size = size();
			private int index = 0;

			public int value() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				return get(index);
			}

			public void advance() throws NoSuchElementException {
				if (!isValid())
					throw new NoSuchElementException();
				index++;
			}

			public boolean isValid() {
				return index < size;
			}
		};
	}

	public int hashCode() {
		int hashCode = 1;
		for (IntIterator i = iterator(); i.isValid(); i.advance())
			hashCode = 31 * hashCode + i.value();
		return hashCode;
	}

	public boolean equals(Object obj) {
		if (!(obj instanceof IntList))
			return false;
		IntList list = (IntList)obj;
		if (list.size() != size())
			return false;
		IntIterator i = iterator();
		IntIterator j = list.iterator();
		while (i.isValid()) {
			if (i.value() != j.value())
				return false;
			i.advance();
			j.advance();
		}
		return true;
	}

	public int compareTo(IntList o) {
		IntIterator i = iterator();
		IntIterator j = o.iterator();
		while (true) {
			if (i.isValid()) {
				if (j.isValid()) {
					if (i.value() != j.value()) {
						if (i.value() < j.value())
							return -1;
						else
							return 1;
					}
				} else
					return 1;
			} else {
				if (j.isValid())
					return -1;
				else
					return 0;
			}
			i.advance();
			j.advance();
		}
	}

	}

class IntArrayList extends IntList {
	private int[] array;
	private int size;

	public IntArrayList() {
		this(10);
	}

	public IntArrayList(int capacity) {
		array = new int[capacity];
	}

	public IntArrayList(IntList list) {
		this(list.size());
		addAll(list);
	}

	public int get(int index) {
		if (index >= size)
			throw new IndexOutOfBoundsException();
		return array[index];
	}

	public int size() {
		return size;
	}

	public void add(int value) {
		ensureCapacity(size + 1);
		array[size++] = value;
	}

	public void ensureCapacity(int newCapacity) {
		if (newCapacity > array.length) {
			int[] newArray = new int[Math.max(newCapacity, array.length << 1)];
			System.arraycopy(array, 0, newArray, 0, size);
			array = newArray;
		}
	}

	public int[] toArray() {
		int[] array = new int[size];
		System.arraycopy(this.array, 0, array, 0, size);
		return array;
	}

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

	public void addAll(IntCollection values) {
		for (IntIterator it = values.iterator(); it.isValid(); it.advance()) {
			add(it.value());
		}
	}

	}

class Counter<K> extends EHashMap<K, Long> {
	public Counter() {
		super();
	}

	public Counter(int capacity) {
		super(capacity);
	}

	public long add(K key) {
		long result = get(key);
		put(key, result + 1);
		return result + 1;
	}

	public Long get(Object key) {
		if (containsKey(key))
			return super.get(key);
		return 0L;
	}
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

class EHashSet<E> extends AbstractSet<E> {
    private static final Object VALUE = new Object();
    private final Map<E, Object> map;

	public EHashSet() {
		this(4);
	}

	public EHashSet(int maxSize) {
		map = new EHashMap<E, Object>(maxSize);
	}

	public EHashSet(Collection<E> collection) {
		this(collection.size());
		addAll(collection);
	}

	public boolean contains(Object o) {
        return map.containsKey(o);
	}

	public boolean add(E e) {
		if (e == null)
			return false;
		return map.put(e, VALUE) == null;
	}

	public boolean remove(Object o) {
		if (o == null)
			return false;
		return map.remove(o) != null;
	}

	public void clear() {
        map.clear();
	}

	public Iterator<E> iterator() {
        return map.keySet().iterator();
	}

	public int size() {
		return map.size();
	}
}

class IntegerUtils {
	public static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
		while (b != 0) {
			long temp = a % b;
			a = b;
			b = temp;
		}
		return a;
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