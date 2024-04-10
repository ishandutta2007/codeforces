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
            int t = in.readInt();
            char[] mark = IOUtils.readCharArray(in, n);
            int dot = ArrayUtils.find(mark, '.');
            for (int i = dot + 1; i < n; i++) {
                if (mark[i] >= '5') {
                    int pos = i + 1;
                    for (int j = i - 1; j > dot; j--) {
                        mark[j]++;
                        t--;
                        pos = j + 1;
                        if (t == 0 || mark[j] < '5') {
                            break;
                        }
                    }
                    if (t > 0 && mark[dot + 1] >= '5' || mark[dot + 1] == '9' + 1) {
                        mark[dot - 1]++;
                        int at = dot - 1;
                        while (at >= 0 && mark[at] == '9' + 1) {
                            mark[at] = '0';
                            if (at > 0) {
                                mark[at - 1]++;
                            }
                            at--;
                        }
                        if (at < 0) {
                            out.print(1);
                        }
                        out.printLine(new String(mark).substring(0, dot));
                        return;
                    }
                    out.printLine(new String(mark).substring(0, pos));
                    return;
                }
            }
            out.printLine(mark);
        }

    }

    static interface CharIterator {
        public char value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class ArrayUtils {
        public static int find(char[] array, char value) {
            return new CharArray(array).find(value);
        }

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

        default public int find(char value) {
            int size = size();
            for (int i = 0; i < size; i++) {
                if (get(i) == value) {
                    return i;
                }
            }
            return -1;
        }

    }

    static interface CharCollection extends CharStream {
        public int size();

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

        public char readCharacter() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            return (char) c;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

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

        public void printLine(char[] array) {
            writer.println(array);
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
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

    static class IOUtils {
        public static char[] readCharArray(InputReader in, int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readCharacter();
            }
            return array;
        }

    }

    static interface CharReversableCollection extends CharCollection {
    }
}