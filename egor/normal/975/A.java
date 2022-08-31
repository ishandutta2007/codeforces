import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.HashSet;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Set;
import java.io.IOException;
import java.io.Writer;
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
        ProblemAAramejskijManuskript solver = new ProblemAAramejskijManuskript();
        solver.solve(1, in, out);
        out.close();
    }

    static class ProblemAAramejskijManuskript {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            String[] words = in.readStringArray(n);
            Set<String> roots = new HashSet<>();
            for (String word : words) {
                char[] c = word.toCharArray();
                Arrays.sort(c);
                c = ArrayUtils.unique(c);
                roots.add(new String(c));
            }
            out.printLine(roots.size());
        }

    }

    static interface CharList extends CharReversableCollection {
        public abstract char get(int index);

        public abstract void addAt(int index, char value);

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


        default public void add(char value) {
            addAt(size(), value);
        }

        default CharList unique() {
            char last = Character.MAX_VALUE;
            CharList result = new CharArrayList();
            int size = size();
            for (int i = 0; i < size; i++) {
                char current = get(i);
                if (current != last) {
                    result.add(current);
                    last = current;
                }
            }
            return result;
        }

    }

    static class CharArrayList extends CharAbstractStream implements CharList {
        private int size;
        private char[] data;

        public CharArrayList() {
            this(3);
        }

        public CharArrayList(int capacity) {
            data = new char[capacity];
        }

        public CharArrayList(CharCollection c) {
            this(c.size());
            addAll(c);
        }

        public CharArrayList(CharStream c) {
            this();
            if (c instanceof CharCollection) {
                ensureCapacity(((CharCollection) c).size());
            }
            addAll(c);
        }

        public CharArrayList(CharArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public CharArrayList(char[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public char get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, char value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
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

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
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

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

    static interface CharCollection extends CharStream {
        public int size();

        default public void add(char value) {
            throw new UnsupportedOperationException();
        }

        default public char[] toArray() {
            int size = size();
            char[] array = new char[size];
            int i = 0;
            for (CharIterator it = charIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

        default public CharCollection addAll(CharStream values) {
            for (CharIterator it = values.charIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface CharReversableCollection extends CharCollection {
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

    static class ArrayUtils {
        public static char[] unique(char[] array) {
            return new CharArray(array).unique().toArray();
        }

    }

    static interface CharIterator {
        public char value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

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

        public void addAt(int index, char value) {
            throw new UnsupportedOperationException();
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

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

    }
}