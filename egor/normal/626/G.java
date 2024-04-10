import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int t = in.readInt();
            int q = in.readInt();
            int[] p = IOUtils.readIntArray(in, n);
            int[] l = IOUtils.readIntArray(in, n);
            int[] bought = new int[n];
            double[] valueLeft = new double[n];
            double[] valueRight = new double[n];
            Heap left = new Heap((x, y) -> Double.compare(valueLeft[x], valueLeft[y]), n);
            Heap right = new Heap((x, y) -> Double.compare(valueRight[y], valueRight[x]), n);
            double answer = 0;
            for (int i = 0; i < n; i++) {
                valueRight[i] = value(l[i], 0) * p[i];
                right.add(i);
            }
            int rem = t;
            for (int i = 0; i < t && !right.isEmpty(); i++) {
                int current = right.poll();
                rem--;
                answer += valueRight[current];
                left.remove(current);
                valueLeft[current] = value(l[current], bought[current]) * p[current];
                left.add(current);
                bought[current]++;
                if (bought[current] < l[current]) {
                    valueRight[current] = value(l[current], bought[current]) * p[current];
                    right.add(current);
                }
            }
            for (int i = 0; i < q; i++) {
                int type = in.readInt();
                int id = in.readInt() - 1;
                answer -= (double) bought[id] / (bought[id] + l[id]) * p[id];
                if (type == 1) {
                    l[id]++;
                } else {
                    l[id]--;
                }
                while (bought[id] > l[id]) {
                    bought[id]--;
                    rem++;
                }
                answer += (double) bought[id] / (bought[id] + l[id]) * p[id];
                left.remove(id);
                if (bought[id] != 0) {
                    valueLeft[id] = value(l[id], bought[id] - 1) * p[id];
                    left.add(id);
                }
                right.remove(id);
                if (bought[id] != l[id]) {
                    valueRight[id] = value(l[id], bought[id]) * p[id];
                    right.add(id);
                }
                while (rem != 0 && !right.isEmpty()) {
                    int current = right.poll();
                    rem--;
                    answer += valueRight[current];
                    left.remove(current);
                    valueLeft[current] = value(l[current], bought[current]) * p[current];
                    left.add(current);
                    bought[current]++;
                    if (bought[current] < l[current]) {
                        valueRight[current] = value(l[current], bought[current]) * p[current];
                        right.add(current);
                    }
                }
                while (!left.isEmpty() && !right.isEmpty() && valueLeft[left.peek()] < valueRight[right.peek()]) {
                    int curRight = right.poll();
                    int curLeft = left.poll();
                    answer += valueRight[curRight];
                    left.remove(curRight);
                    valueLeft[curRight] = value(l[curRight], bought[curRight]) * p[curRight];
                    left.add(curRight);
                    bought[curRight]++;
                    if (bought[curRight] < l[curRight]) {
                        valueRight[curRight] = value(l[curRight], bought[curRight]) * p[curRight];
                        right.add(curRight);
                    }
                    bought[curLeft]--;
                    answer -= valueLeft[curLeft];
                    right.remove(curLeft);
                    valueRight[curLeft] = value(l[curLeft], bought[curLeft]) * p[curLeft];
                    right.add(curLeft);
                    if (bought[curLeft] > 0) {
                        valueLeft[curLeft] = value(l[curLeft], bought[curLeft] - 1) * p[curLeft];
                        left.add(curLeft);
                    }
                }
                out.printLine(answer);
            }
        }

        double value(int a, int b) {
            return (double) a / (a + b) / (a + b + 1);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface IntQueue extends IntCollection {
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static interface IntComparator {
        public static final IntComparator DEFAULT = (first, second) -> {
            if (first < second) {
                return -1;
            }
            if (first > second) {
                return 1;
            }
            return 0;
        };

        public int compare(int first, int second);

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static interface IntCollection extends IntStream {
    }

    static class Heap implements IntQueue {
        private IntComparator comparator;
        private int size = 0;
        private int[] elements;
        private int[] at;

        public Heap(int maxElement) {
            this(10, maxElement);
        }

        public Heap(IntComparator comparator, int maxElement) {
            this(10, comparator, maxElement);
        }

        public Heap(int capacity, int maxElement) {
            this(capacity, IntComparator.DEFAULT, maxElement);
        }

        public Heap(int capacity, IntComparator comparator, int maxElement) {
            this.comparator = comparator;
            elements = new int[capacity];
            at = new int[maxElement];
            Arrays.fill(at, -1);
        }

        public boolean isEmpty() {
            return size == 0;
        }

        public void add(int element) {
            ensureCapacity(size + 1);
            elements[size] = element;
            at[element] = size;
            shiftUp(size++);
        }

        public void shiftUp(int index) {
            //		if (index < 0 || index >= size)
            //			throw new IllegalArgumentException();
            int value = elements[index];
            while (index != 0) {
                int parent = (index - 1) >>> 1;
                int parentValue = elements[parent];
                if (comparator.compare(parentValue, value) <= 0) {
                    elements[index] = value;
                    at[value] = index;
                    return;
                }
                elements[index] = parentValue;
                at[parentValue] = index;
                index = parent;
            }
            elements[0] = value;
            at[value] = 0;
        }

        public void shiftDown(int index) {
            if (index < 0 || index >= size) {
                throw new IllegalArgumentException();
            }
            while (true) {
                int child = (index << 1) + 1;
                if (child >= size) {
                    return;
                }
                if (child + 1 < size && comparator.compare(elements[child], elements[child + 1]) > 0) {
                    child++;
                }
                if (comparator.compare(elements[index], elements[child]) <= 0) {
                    return;
                }
                swap(index, child);
                index = child;
            }
        }

        public int getIndex(int element) {
            return at[element];
        }

        private void swap(int first, int second) {
            int temp = elements[first];
            elements[first] = elements[second];
            elements[second] = temp;
            at[elements[first]] = first;
            at[elements[second]] = second;
        }

        private void ensureCapacity(int size) {
            if (elements.length < size) {
                int[] oldElements = elements;
                elements = new int[Math.max(2 * elements.length, size)];
                System.arraycopy(oldElements, 0, elements, 0, this.size);
            }
        }

        public int peek() {
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
            return elements[0];
        }

        public int poll() {
            if (isEmpty()) {
                throw new IndexOutOfBoundsException();
            }
            int result = elements[0];
            at[result] = -1;
            if (size == 1) {
                size = 0;
                return result;
            }
            elements[0] = elements[--size];
            at[elements[0]] = 0;
            shiftDown(0);
            return result;
        }

        public boolean remove(int element) {
            int index = getIndex(element);
            if (index == -1) {
                return false;
            }
            int result = elements[index];
            at[result] = -1;
            if (index == size - 1) {
                size--;
                return true;
            }
            elements[index] = elements[--size];
            at[elements[index]] = index;
            shiftDown(index);
            shiftUp(index);
            return true;
        }


        public IntIterator intIterator() {
            return new IntIterator() {
                private int at;


                public int value() throws NoSuchElementException {
                    return elements[at];
                }


                public boolean advance() throws NoSuchElementException {
                    return ++at < size;
                }


                public boolean isValid() {
                    return at < size;
                }


                public void remove() throws NoSuchElementException {
                    throw new UnsupportedOperationException();
                }
            };
        }

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
        }

    }
}