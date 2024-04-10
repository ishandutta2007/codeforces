import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
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
        COperaciiNeImeyushieSmisla solver = new COperaciiNeImeyushieSmisla();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class COperaciiNeImeyushieSmisla {
        int[] precalc = {3, 1, 7, 1, 15, 5, 31, 1, 63, 21, 127, 1, 255, 85, 511, 73, 1023, 341, 2047, 89, 4095, 1365,
                8191, 1, 16383, 5461, 32767, 4681, 65535, 21845, 131071, 1, 262143, 87381, 524287, 1, 1048575, 349525,
                2097151, 299593, 4194303, 1398101, 8388607, 178481, 16777215, 5592405, 33554431, 1082401};
        IntHashMap special = new IntHashMap();

        {
            for (int i = 0; i < precalc.length; i += 2) {
                special.put(precalc[i], precalc[i + 1]);
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int a = in.readInt();
            if (special.contains(a)) {
                out.printLine(special.get(a));
            } else {
                out.printLine(Integer.highestOneBit(a) * 2 - 1);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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

        public String next() {
            return readString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class IntHashMap {
        private static final Random RND = new Random();
        private static final int[] SHIFTS = new int[4];
        private static final byte PRESENT_MASK = 1;
        private int size;
        private int realSize;
        private int[] keys;
        private int[] values;
        private byte[] present;
        private int step;
        private int ratio;
        private int lastKey = 0;

        static {
            for (int i = 0; i < 4; i++) {
                SHIFTS[i] = RND.nextInt(31) + 1;
            }
        }

        public IntHashMap() {
            this(3);
        }

        public IntHashMap(int capacity) {
            capacity = Math.max(capacity, 1);
            keys = new int[capacity];
            present = new byte[capacity];
            values = new int[capacity];
            ratio = 2;
            initStep(capacity);
        }

        private void initStep(int capacity) {
            step = RND.nextInt(capacity - 2) + 1;
            while (IntegerUtils.gcd(step, capacity) != 1) {
                step++;
            }
        }

        public void put(int key, int value) {
            ensureCapacity((realSize + 1) * ratio + 2);
            int current = getHash(key);
            while (present[current] != 0) {
                if ((present[current] & PRESENT_MASK) != 0 && keys[current] == key) {
                    values[current] = value;
                    return;
                }
                current += step;
                if (current >= values.length) {
                    current -= values.length;
                }
            }
            while ((present[current] & PRESENT_MASK) != 0) {
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            if (present[current] == 0) {
                realSize++;
            }
            present[current] = PRESENT_MASK;
            keys[current] = key;
            values[current] = value;
            size++;
            lastKey = current;
        }

        private int getHash(int key) {
            int result = key;
            for (int i : SHIFTS) {
                result ^= key >> i;
            }
            result %= keys.length;
            if (result < 0) {
                result += keys.length;
            }
            return result;
        }

        private void ensureCapacity(int capacity) {
            if (keys.length < capacity) {
                capacity = Math.max(capacity * 2, keys.length);
                rebuild(capacity);
            }
        }

        private void rebuild(int capacity) {
            initStep(capacity);
            int[] oldKeys = keys;
            byte[] oldPresent = present;
            int[] oldValues = values;
            keys = new int[capacity];
            present = new byte[capacity];
            values = new int[capacity];
            size = 0;
            realSize = 0;
            for (int i = 0; i < oldKeys.length; i++) {
                if ((oldPresent[i] & PRESENT_MASK) == PRESENT_MASK) {
                    put(oldKeys[i], oldValues[i]);
                }
            }
        }

        public boolean contains(int key) {
            int current = getHash(key);
            while (present[current] != 0) {
                if (keys[current] == key && (present[current] & PRESENT_MASK) != 0) {
                    lastKey = current;
                    return true;
                }
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            return false;
        }

        public int get(int key) {
            if ((present[lastKey] & PRESENT_MASK) != 0 && keys[lastKey] == key) {
                return values[lastKey];
            }
            int current = getHash(key);
            while (present[current] != 0) {
                if (keys[current] == key && (present[current] & PRESENT_MASK) != 0) {
                    return values[current];
                }
                current += step;
                if (current >= keys.length) {
                    current -= keys.length;
                }
            }
            throw new NoSuchElementException();
        }

    }

    static class IntegerUtils {
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

    static class OutputWriter {
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

        public void printLine(int i) {
            writer.println(i);
        }

    }
}