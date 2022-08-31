import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		String t = in.readString();
		StringHash hash = new SimpleStringHash(t);
		IntervalTree tree = new SumIntervalTree(t.length());
		IntSet candidates = new IntHashSet();
		for (int i = 0; i < t.length(); i++)
			candidates.add(i);
		long base = t.length();
		int shift = 2;
		long[][] answer = new long[t.length()][26];
		while (candidates.size() > 0) {
			int[] array = candidates.toArray();
			IntSet next = new IntHashSet();
			long baseScore = (long) (2 * shift - 1) * (2 * shift - 1);
			for (int i : array) {
				int used = 0;
				for (int j = i, add = 1; j < i + shift - 1; ) {
					used |= 1 << (t.charAt(j) - 'a');
					j += add;
					add *= 2;
				}
				if (candidates.contains(i + shift) && hash.hash(i, i + shift - 1) == hash.hash(i + shift, i + 2 * shift - 1)) {
					if ((used >> (t.charAt(i + shift - 1) - 'a') & 1) == 0) {
						next.add(i);
						base += baseScore;
						tree.update(i, i + shift - 2, -baseScore);
						tree.update(i + shift, i + 2 * shift - 2, -baseScore);
						for (int j = 0; j < 26; j++) {
							if ((used >> j & 1) == 1)
								answer[i + shift - 1][j] -= baseScore;
						}
					} else {
						for (int j = 0; j < 26; j++) {
							if ((used >> j & 1) == 0)
								answer[i + shift - 1][j] += baseScore;
						}
					}
				} else if (i + 2 * shift - 1 <= t.length() && ((used >> (t.charAt(i + shift - 1) - 'a') & 1) == 0)) {
					int left = 0;
					int right = shift - 1;
					int at = i + shift;
					while (left < right) {
						int middle = (left + right + 1) >> 1;
						if (hash.hash(i, i + middle) == hash.hash(at, at + middle))
							left = middle;
						else
							right = middle - 1;
					}
					if (left == shift - 2 || hash.hash(i + left + 1, i + shift - 1) == hash.hash(at + left + 1, at + shift - 1))
						answer[at + left][t.charAt(i + left) - 'a'] += baseScore;
				}
				if (i >= shift && ((used >> (t.charAt(i - 1) - 'a') & 1) == 0)) {
					int left = 0;
					int right = shift - 1;
					int at = i - shift;
					while (left < right) {
						int middle = (left + right + 1) >> 1;
						if (hash.hash(i, i + middle) == hash.hash(at, at + middle))
							left = middle;
						else
							right = middle - 1;
					}
					if (left != shift - 1 && (left == shift - 2 || hash.hash(i + left + 1, i + shift - 1) == hash.hash(at + left + 1, at + shift - 1)))
						answer[at + left][t.charAt(i + left) - 'a'] += baseScore;
				}
			}
			shift *= 2;
			candidates = next;
		}
		long result = base;
		for (int i = 0; i < t.length(); i++) {
			long delta = tree.query(i, i);
			for (int j = 0; j < 26; j++)
				result = Math.max(result, base + delta + answer[i][j]);
		}
		out.printLine(result);
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

	public void close() {
		writer.close();
	}

	public void printLine(long i) {
		writer.println(i);
	}

	}

interface StringHash {
    long hash(int from, int to);

	}

class SimpleStringHash extends AbstractStringHash {
    private static long[] firstReversePower = new long[0];
    private static long[] secondReversePower = new long[0];

    private final long[] firstHash;
    private final long[] secondHash;

    public SimpleStringHash(CharSequence string) {
        int length = string.length();
        ensureCapacity(length);
		firstHash = new long[length + 1];
        secondHash = new long[length + 1];
        long firstPower = 1;
        long secondPower = 1;
		for (int i = 0; i < length; i++) {
			firstHash[i + 1] = (firstHash[i] + string.charAt(i) * firstPower) % FIRST_MOD;
            secondHash[i + 1] = (secondHash[i] + string.charAt(i) * secondPower) % SECOND_MOD;
			firstPower *= MULTIPLIER;
            firstPower %= FIRST_MOD;
            secondPower *= MULTIPLIER;
            secondPower %= SECOND_MOD;
		}
	}

    private void ensureCapacity(int length) {
        if (firstReversePower.length >= length)
            return;
        length = Math.max(length + 1, firstReversePower.length << 1);
        long[] oldFirst = firstReversePower;
        long[] oldSecond = secondReversePower;
        firstReversePower = new long[length];
        secondReversePower = new long[length];
        System.arraycopy(oldFirst, 0, firstReversePower, 0, oldFirst.length);
        System.arraycopy(oldSecond, 0, secondReversePower, 0, oldSecond.length);
        firstReversePower[0] = secondReversePower[0] = 1;
        for (int i = Math.max(oldFirst.length, 1); i < length; i++) {
            firstReversePower[i] = firstReversePower[i - 1] * FIRST_REVERSE_MULTIPLIER % FIRST_MOD;
            secondReversePower[i]= secondReversePower[i - 1] * SECOND_REVERSE_MULTIPLIER % SECOND_MOD;
        }
    }

    public long hash(int from, int to) {
		return (((firstHash[to] - firstHash[from] + FIRST_MOD) * firstReversePower[from] % FIRST_MOD) << 32) +
            ((secondHash[to] - secondHash[from] + SECOND_MOD) * secondReversePower[from] % SECOND_MOD);
	}

	}

abstract class IntervalTree {
	protected int size;

	protected IntervalTree(int size) {
		this(size, true);
	}

	public IntervalTree(int size, boolean shouldInit) {
		this.size = size;
		int nodeCount = Math.max(1, Integer.highestOneBit(size) << 2);
		initData(size, nodeCount);
		if (shouldInit)
			init();
	}

	protected abstract void initData(int size, int nodeCount);
	protected abstract void initAfter(int root, int left, int right, int middle);
	protected abstract void initBefore(int root, int left, int right, int middle);
	protected abstract void initLeaf(int root, int index);
	protected abstract void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle);
	protected abstract void updateFull(int root, int left, int right, int from, int to, long delta);
	protected abstract long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult);
	protected abstract void queryPreProcess(int root, int left, int right, int from, int to, int middle);
	protected abstract long queryFull(int root, int left, int right, int from, int to);
	protected abstract long emptySegmentResult();

	public void init() {
		init(0, 0, size - 1);
	}

	private void init(int root, int left, int right) {
		if (left == right) {
			initLeaf(root, left);
		} else {
			int middle = (left + right) >> 1;
			initBefore(root, left, right, middle);
			init(2 * root + 1, left, middle);
			init(2 * root + 2, middle + 1, right);
			initAfter(root, left, right, middle);
		}
	}

	public void update(int from, int to, long delta) {
		update(0, 0, size - 1, from, to, delta);
	}

	protected void update(int root, int left, int right, int from, int to, long delta) {
		if (left > to || right < from)
			return;
		if (left >= from && right <= to) {
			updateFull(root, left, right, from, to, delta);
			return;
		}
		int middle = (left + right) >> 1;
		updatePreProcess(root, left, right, from, to, delta, middle);
		update(2 * root + 1, left, middle, from, to, delta);
		update(2 * root + 2, middle + 1, right, from, to, delta);
		updatePostProcess(root, left, right, from, to, delta, middle);
	}

	public long query(int from, int to) {
		return query(0, 0, size - 1, from, to);
	}

	protected long query(int root, int left, int right, int from, int to) {
		if (left > to || right < from)
			return emptySegmentResult();
		if (left >= from && right <= to)
			return queryFull(root, left, right, from, to);
		int middle = (left + right) >> 1;
		queryPreProcess(root, left, right, from, to, middle);
		long leftResult = query(2 * root + 1, left, middle, from, to);
		long rightResult = query(2 * root + 2, middle + 1, right, from, to);
		return queryPostProcess(root, left, right, from, to, middle, leftResult, rightResult);
	}
}

class SumIntervalTree extends LongIntervalTree {
    public SumIntervalTree(int size) {
        super(size);
    }

    protected long joinValue(long left, long right) {
        return left + right;
    }

    protected long joinDelta(long was, long delta) {
        return was + delta;
    }

    protected long accumulate(long value, long delta, int length) {
        return value + delta * length;
    }

    protected long neutralValue() {
        return 0;
    }

    protected long neutralDelta() {
        return 0;
    }
}

abstract class IntSet extends IntCollection {
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

	public boolean contains(int value) {
		int current = getHash(value);
		while (present[current] != 0) {
			if (values[current] == value && (present[current] & PRESENT_MASK) != 0)
				return true;
			current += step;
			if (current >= values.length)
				current -= values.length;
		}
		return false;
	}


}

abstract class IntCollection {
	public abstract IntIterator iterator();
	public abstract int size();
	public abstract void add(int value);

	public boolean contains(int value) {
		for (IntIterator iterator = iterator(); iterator.isValid(); iterator.advance()) {
			if (iterator.value() == value)
				return true;
		}
		return false;
	}

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

abstract class AbstractStringHash implements StringHash {
    public static final long MULTIPLIER;
    protected static final long FIRST_REVERSE_MULTIPLIER;
    protected static final long SECOND_REVERSE_MULTIPLIER;
    public static final long FIRST_MOD;
    public static final long SECOND_MOD;

    static {
        Random random = new Random(System.currentTimeMillis());
        FIRST_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
        SECOND_MOD = IntegerUtils.nextPrime((long) (1e9 + random.nextInt((int) 1e9)));
		MULTIPLIER = random.nextInt((int) 1e9 - 257) + 257;
        FIRST_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, FIRST_MOD);
        SECOND_REVERSE_MULTIPLIER = IntegerUtils.reverse(MULTIPLIER, SECOND_MOD);
    }

    }

abstract class LongIntervalTree extends IntervalTree {
    protected long[] value;
    protected long[] delta;

    protected LongIntervalTree(int size) {
        this(size, true);
    }

	public LongIntervalTree(int size, boolean shouldInit) {
		super(size, shouldInit);
	}

	protected void initData(int size, int nodeCount) {
		value = new long[nodeCount];
		delta = new long[nodeCount];
	}

	protected abstract long joinValue(long left, long right);
    protected abstract long joinDelta(long was, long delta);
    protected abstract long accumulate(long value, long delta, int length);
    protected abstract long neutralValue();
    protected abstract long neutralDelta();

    protected long initValue(int index) {
        return neutralValue();
    }

	protected void initAfter(int root, int left, int right, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
		delta[root] = neutralDelta();
	}

	protected void initBefore(int root, int left, int right, int middle) {
	}

	protected void initLeaf(int root, int index) {
		value[root] = initValue(index);
		delta[root] = neutralDelta();
	}

	protected void updatePostProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		value[root] = joinValue(value[2 * root + 1], value[2 * root + 2]);
	}

	protected void updatePreProcess(int root, int left, int right, int from, int to, long delta, int middle) {
		pushDown(root, left, middle, right);
	}

	protected void pushDown(int root, int left, int middle, int right) {
		value[2 * root + 1] = accumulate(value[2 * root + 1], delta[root], middle - left + 1);
		value[2 * root + 2] = accumulate(value[2 * root + 2], delta[root], right - middle);
		delta[2 * root + 1] = joinDelta(delta[2 * root + 1], delta[root]);
		delta[2 * root + 2] = joinDelta(delta[2 * root + 2], delta[root]);
		delta[root] = neutralDelta();
	}

	protected void updateFull(int root, int left, int right, int from, int to, long delta) {
		value[root] = accumulate(value[root], delta, right - left + 1);
		this.delta[root] = joinDelta(this.delta[root], delta);
	}

	protected long queryPostProcess(int root, int left, int right, int from, int to, int middle, long leftResult, long rightResult) {
		return joinValue(leftResult, rightResult);
	}

	protected void queryPreProcess(int root, int left, int right, int from, int to, int middle) {
		pushDown(root, left, middle, right);
	}

	protected long queryFull(int root, int left, int right, int from, int to) {
		return value[root];
	}

	protected long emptySegmentResult() {
		return neutralValue();
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

    public static long power(long base, long exponent, long mod) {
		if (base >= mod)
			base %= mod;
		if (exponent == 0)
			return 1 % mod;
		long result = power(base, exponent >> 1, mod);
		result = result * result % mod;
		if ((exponent & 1) != 0)
			result = result * base % mod;
		return result;
	}

	public static long reverse(long number, long module) {
		return power(number, module - 2, module);
	}

	public static boolean isPrime(long number) {
		if (number < 2)
			return false;
		for (long i = 2; i * i <= number; i++) {
			if (number % i == 0)
				return false;
		}
		return true;
	}

	public static long nextPrime(long from) {
        if (from <= 2)
            return 2;
        from += 1 - (from & 1);
        while (!isPrime(from))
            from += 2;
        return from;
    }

	}