import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            int digCount = digCount(n - 1) + digCount(m - 1);
            if (digCount > 7) {
                out.printLine(0);
                return;
            }
            int answer = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    String s = Integer.toString(i, 7) + Integer.toString(j, 7);
                    while (s.length() < digCount) {
                        s += "0";
                    }
                    if (ArrayUtils.maxElement(new CharArray(s.toCharArray()).qty()) <= 1) {
                        answer++;
                    }
                }
            }
            out.printLine(answer);
        }

        private int digCount(int n) {
            int answer = 0;
            while (n > 0) {
                n /= 7;
                answer++;
            }
            return Math.max(answer, 1);
        }

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

        default public int max() {
            int result = Integer.MIN_VALUE;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                int current = it.value();
                if (current > result) {
                    result = current;
                }
            }
            return result;
        }

    }

    static interface CharReversableCollection extends CharCollection {
    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class ArrayUtils {
        public static int maxElement(int[] array) {
            return new IntArray(array).max();
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static interface CharCollection extends CharStream {
        public int size();

    }

    static interface CharList extends CharReversableCollection {
        public abstract char get(int index);

        public abstract void removeAt(int index);

        default public CharIterator charIterator() {
            return new CharIterator() {
                private int at;
                private boolean removed;

                public char value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

    }

    static class CharArray extends CharAbstractStream implements CharList {
        private char[] data;

        public CharArray(char[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public char get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface CharIterator {
        public char value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface CharStream extends Iterable<Character>, Comparable<CharStream> {
        public CharIterator charIterator();

        default public Iterator<Character> iterator() {
            return new Iterator<Character>() {
                private CharIterator it = charIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Character next() {
                    char result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(CharStream c) {
            CharIterator it = charIterator();
            CharIterator jt = c.charIterator();
            while (it.isValid() && jt.isValid()) {
                char i = it.value();
                char j = jt.value();
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

        default public char max() {
            char result = Character.MIN_VALUE;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                char current = it.value();
                if (current > result) {
                    result = current;
                }
            }
            return result;
        }

        default public int[] qty(int bound) {
            int[] result = new int[bound];
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                result[(int) it.value()]++;
            }
            return result;
        }

        default public int[] qty() {
            return qty((int) (max() + 1));
        }

    }

    static interface IntCollection extends IntStream {
        public int size();

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

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void removeAt(int index);

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

    }

    static abstract class CharAbstractStream implements CharStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof CharStream)) {
                return false;
            }
            CharStream c = (CharStream) o;
            CharIterator it = charIterator();
            CharIterator jt = c.charIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
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
}