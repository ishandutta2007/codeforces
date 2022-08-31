import java.util.NavigableSet;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.List;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.Collections;
import java.io.IOException;
import java.io.InputStream;
import java.util.Random;
import java.util.Collection;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.SortedSet;
import java.util.Set;

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
		int count = in.readInt();
		int[] p = IOUtils.readIntArray(in, count);
		int[] q = IOUtils.readIntArray(in, count);
		SumIntervalTree pTree = new SumIntervalTree(count);
		pTree.update(0, count - 1, 1);
		for (int i = 0; i < count; i++) {
			pTree.update(p[i], p[i], -1);
			p[i] = (int) pTree.query(0, p[i]);
		}
		SumIntervalTree qTree = new SumIntervalTree(count);
		qTree.update(0, count - 1, 1);
		for (int i = 0; i < count; i++) {
			qTree.update(q[i], q[i], -1);
			q[i] = (int) qTree.query(0, q[i]);
		}
		int[] result = new int[count];
		for (int i = count - 1; i >= 0; i--) {
			result[i] += p[i] + q[i];
			if (result[i] >= count - i) {
				result[i] -= count - i;
				if (i > 0) result[i - 1]++;
			}
		}
		TreapSet<Integer> treapSet = new TreapSet<>();
		for (int i = 0; i < count; i++) {
			treapSet.add(i);
		}
		for (int i = 0; i < count; i++) {
			result[i] = treapSet.get(result[i]);
			treapSet.remove(result[i]);
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

	public void print(int[] array) {
        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(array[i]);
        }
    }

	public void printLine(int[] array) {
        print(array);
        writer.println();
    }

	public void close() {
		writer.close();
	}

}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
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

abstract class IntervalTree {
	protected int size;

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
		if (size == 0)
			return;
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

class TreapSet<K> implements NavigableSet<K> {
	protected static final Random rnd = new Random(239);

	protected final Node nullNode;
	protected final Comparator<? super K> comparator;
	protected Node root;
	private final K from;
	private final K to;
	private final boolean fromInclusive;
	private final boolean toInclusive;

	public TreapSet() {
		this((Comparator<? super K>)null);
	}

	public TreapSet(Comparator<? super K> comparator) {
		this(null, null, false, false, comparator, null, null);
	}

	protected TreapSet(K from, K to, boolean fromInclusive, boolean toInclusive, Comparator<? super K> comparator, Node root, Node nullNode) {
		this.comparator = comparator;
		this.from = from;
		this.to = to;
		this.fromInclusive = fromInclusive;
		this.toInclusive = toInclusive;
		if (nullNode == null)
			nullNode = new NullNode();
		if (root == null)
			root = nullNode;
		this.root = root;
		this.nullNode = nullNode;
	}

	public boolean addAll(Iterable<? extends K> collection) {
		boolean result = false;
		for (K element : collection)
			result |= add(element);
		return result;
	}

	public K lower(K k) {
		Node target = root.lower(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	private boolean belongs(K key) {
		int valueFrom = compare(from, key);
		int valueTo = compare(key, to);
		return (valueFrom < 0 || valueFrom == 0 && fromInclusive) && (valueTo < 0 || valueTo == 0 && toInclusive);
	}

	public K floor(K k) {
		Node target = root.floor(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K ceiling(K k) {
		Node target = root.ceil(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K higher(K k) {
		Node target = root.higher(k);
		if (target == nullNode)
			return null;
		if (belongs(target.key))
			return target.key;
		return null;
	}

	public K pollFirst() {
		K first = first();
		if (first == null)
			throw new NoSuchElementException();
		root.erase(first);
		return first;
	}

	public K pollLast() {
		K last = last();
		if (last == null)
			throw new NoSuchElementException();
		root.erase(last);
		return last;
	}

	public int size() {
		if (from == null && to == null)
			return root.size;
		if (from == null) {
			Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
			if (to == nullNode)
				return 0;
			return root.indexOf(to) + 1;
		}
		if (to == null) {
			Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
			if (from == nullNode)
				return 0;
			return root.size - root.indexOf(from);
		}
		Node from = fromInclusive ? root.ceil(this.from) : root.higher(this.from);
		if (from == nullNode || !belongs(from.key))
			return 0;
		Node to = toInclusive ? root.floor(this.to) : root.lower(this.to);
		return root.indexOf(to) - root.indexOf(from) + 1;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public boolean contains(Object o) {
		return belongs((K) o) && root.search((K) o) != nullNode;
	}

	public Iterator<K> iterator() {
		return new Iterator<K>() {
			private K current = first();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = higher(current);
				return result;
			}

			public void remove() {
				TreapSet.this.remove(current);
			}
		};
	}

	public Object[] toArray() {
		Object[] array = new Object[size()];
		int index = 0;
		for (K key : this)
			array[index++] = key;
		return array;
	}

	public <T> T[] toArray(T[] a) {
		if (a.length < size())
			throw new IllegalArgumentException();
		int index = 0;
		for (K key : this)
			a[index++] = (T) key;
		return a;
	}

	public boolean add(K k) {
		if (k == null)
			throw new NullPointerException();
		if (contains(k))
			return false;
		root = root.insert(createNode(k));
		return true;
	}

	protected Node createNode(K k) {
		return new Node(k, rnd.nextLong());
	}

	public boolean remove(Object o) {
		if (!contains(o))
			return false;
		//noinspection unchecked
		root = root.erase((K) o);
		return true;
	}

	public boolean containsAll(Collection<?> c) {
		for (Object o : c) {
			if (!contains(o))
				return false;
		}
		return true;
	}

	public boolean addAll(Collection<? extends K> c) {
		return addAll((Iterable<? extends K>)c);
	}

	public boolean retainAll(Collection<?> c) {
		List<K> toRemove = new ArrayList<K>();
		for (K key : this) {
			if (!c.contains(key))
				toRemove.add(key);
		}
		return removeAll(toRemove);
	}

	public boolean removeAll(Collection<?> c) {
		boolean result = false;
		for (Object o : c)
			result |= remove(o);
		return result;
	}

	public void clear() {
		retainAll(Collections.<Object>emptySet());
	}

	public NavigableSet<K> descendingSet() {
		throw new UnsupportedOperationException();
	}

	public Iterator<K> descendingIterator() {
		return new Iterator<K>() {
			private K current = last();

			public boolean hasNext() {
				return current != null;
			}

			public K next() {
				K result = current;
				current = lower(current);
				return result;
			}

			public void remove() {
				TreapSet.this.remove(current);
			}
		};
	}

	public NavigableSet<K> subSet(K fromElement, boolean fromInclusive, K toElement, boolean toInclusive) {
		return new TreapSet<K>(fromElement, toElement, fromInclusive, toInclusive, comparator, root, nullNode);
	}

	public NavigableSet<K> headSet(K toElement, boolean inclusive) {
		return subSet(null, false, toElement, inclusive);
	}

	public NavigableSet<K> tailSet(K fromElement, boolean inclusive) {
		return subSet(fromElement, inclusive, null, false);
	}

	public Comparator<? super K> comparator() {
		return comparator;
	}

	public SortedSet<K> subSet(K fromElement, K toElement) {
		return subSet(fromElement, true, toElement, false);
	}

	public SortedSet<K> headSet(K toElement) {
		return subSet(null, false, toElement, false);
	}

	public SortedSet<K> tailSet(K fromElement) {
		return tailSet(fromElement, true);
	}

	public K first() {
		if (isEmpty())
			return null;
		if (from == null)
			return root.first().key;
		if (fromInclusive)
			return ceiling(from);
		return higher(from);
	}

	public K last() {
		if (isEmpty())
			return null;
		if (to == null)
			return root.last().key;
		if (toInclusive)
			return floor(to);
		return lower(to);
	}

	public K get(int index) {
		if (index >= size() || index < 0)
			throw new IndexOutOfBoundsException(Integer.toString(index));
		if (from != null)
			index += headSet(from, !fromInclusive).size();
		return root.get(index);
	}

	protected int compare(K first, K second) {
		if (first == null || second == null)
			return -1;
		if (comparator != null)
			return comparator.compare(first, second);
		//noinspection unchecked
		return ((Comparable<? super K>)first).compareTo(second);
	}

	protected class Node {
		protected final K key;
		protected final long priority;
		protected Node left;
		protected Node right;
		protected int size;

		protected Node(K key, long priority) {
			this.key = key;
			this.priority = priority;
			left = nullNode;
			right = nullNode;
			size = 1;
		}

		protected Object[] split(K key) {
			if (compare(key, this.key) < 0) {
				Object[] result = left.split(key);
				left = (Node) result[1];
				result[1] = this;
				updateSize();
				return result;
			}
			Object[] result = right.split(key);
			right = (Node) result[0];
			result[0] = this;
			updateSize();
			return result;
		}

		protected void updateSize() {
			size = left.size + right.size + 1;
		}

		protected Node insert(Node node) {
			if (node.priority > priority) {
				Object[] result = split(node.key);
				node.left = (Node) result[0];
				node.right = (Node) result[1];
				node.updateSize();
				return node;
			}
			if (compare(node.key, this.key) < 0) {
				left = left.insert(node);
				updateSize();
				return this;
			}
			right = right.insert(node);
			updateSize();
			return this;
		}

		protected Node merge(Node left, Node right) {
			if (left == nullNode)
				return right;
			if (right == nullNode)
				return left;
			if (left.priority > right.priority) {
				left.right = left.right.merge(left.right, right);
				left.updateSize();
				return left;
			}
			right.left = right.left.merge(left, right.left);
			right.updateSize();
			return right;
		}

		protected Node erase(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return merge(left, right);
			if (value < 0) {
				left = left.erase(key);
				updateSize();
				return this;
			}
			right = right.erase(key);
			updateSize();
			return this;
		}

		protected Node lower(K key) {
			if (compare(key, this.key) <= 0)
				return left.lower(key);
			Node result = right.lower(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node floor(K key) {
			if (compare(key, this.key) < 0)
				return left.floor(key);
			Node result = right.floor(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node higher(K key) {
			if (compare(key, this.key) >= 0)
				return right.higher(key);
			Node result = left.higher(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node ceil(K key) {
			if (compare(key, this.key) > 0)
				return right.ceil(key);
			Node result = left.ceil(key);
			if (result == nullNode)
				return this;
			return result;
		}

		protected Node first() {
			if (left == nullNode)
				return this;
			return left.first();
		}

		protected Node last() {
			if (right == nullNode)
				return this;
			return right.last();
		}

		protected Node search(K key) {
			int value = compare(key, this.key);
			if (value == 0)
				return this;
			if (value < 0)
				return left.search(key);
			return right.search(key);
		}

		public int indexOf(Node node) {
			if (this == node)
				return left.size;
			if (compare(node.key, this.key) > 0)
				return left.size + 1 + right.indexOf(node);
			return left.indexOf(node);
		}

		public K get(int index) {
			if (index < left.size)
				return left.get(index);
			else if (index == left.size)
				return key;
			else
				return right.get(index - left.size - 1);
		}
	}

	private class NullNode extends Node {
        private Object[] splitResult = new Object[2];

		private NullNode() {
			super(null, Long.MIN_VALUE);
			left = this;
			right = this;
			size = 0;
		}

		protected Object[] split(K key) {
            splitResult[0] = splitResult[1] = this;
			return splitResult;
		}

		protected Node insert(Node node) {
			return node;
		}

		protected Node erase(K key) {
			return this;
		}

		protected Node lower(K key) {
			return this;
		}

		protected Node floor(K key) {
			return this;
		}

		protected Node higher(K key) {
			return this;
		}

		protected Node ceil(K key) {
			return this;
		}

		protected Node first() {
			throw new NoSuchElementException();
		}

		protected Node last() {
			throw new NoSuchElementException();
		}

		protected void updateSize() {
		}

		protected Node search(K key) {
			return this;
		}


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