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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int k = in.readInt();
            double[] p = IOUtils.readDoubleArray(in, n);
            double[] answer = new double[1 << n];
            answer[0] = 1;
            for (int i = 1; i < (1 << n); i++) {
                double sum = 0;
                boolean bad = false;
                for (int j = 0; j < n; j++) {
                    if ((i >> j & 1) == 0) {
                        sum += p[j];
                    } else if (p[j] == 0) {
                        bad = true;
                        break;
                    }
                }
                if (bad) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if ((i >> j & 1) == 1) {
                        answer[i] += answer[i - (1 << j)] * p[j] / (p[j] + sum);
                    }
                }
            }
            double[] result = new double[n];
            int qty = Math.min(k, n - ArrayUtils.count(p, 0));
            for (int i = 0; i < (1 << n); i++) {
                if (Integer.bitCount(i) == qty) {
                    for (int j = 0; j < n; j++) {
                        if ((i >> j & 1) == 1) {
                            result[j] += answer[i];
                        }
                    }
                }
            }
            out.printLine(result);
        }

    }

    static class DoubleArray extends DoubleAbstractStream implements DoubleList {
        private double[] data;

        public DoubleArray(double[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public double get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
        }

    }

    static abstract class DoubleAbstractStream implements DoubleStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (DoubleIterator it = doubleIterator(); it.isValid(); it.advance()) {
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
            if (!(o instanceof DoubleStream)) {
                return false;
            }
            DoubleStream c = (DoubleStream) o;
            DoubleIterator it = doubleIterator();
            DoubleIterator jt = c.doubleIterator();
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
            for (DoubleIterator it = doubleIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
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

        public void print(double[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(double[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class IOUtils {
        public static double[] readDoubleArray(InputReader in, int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readDouble();
            }
            return array;
        }

    }

    static interface DoubleCollection extends DoubleStream {
        public int size();

    }

    static class ArrayUtils {
        public static int count(double[] array, double value) {
            return new DoubleArray(array).count(value);
        }

    }

    static interface DoubleStream extends Iterable<Double>, Comparable<DoubleStream> {
        public DoubleIterator doubleIterator();

        default public Iterator<Double> iterator() {
            return new Iterator<Double>() {
                private DoubleIterator it = doubleIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Double next() {
                    double result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(DoubleStream c) {
            DoubleIterator it = doubleIterator();
            DoubleIterator jt = c.doubleIterator();
            while (it.isValid() && jt.isValid()) {
                double i = it.value();
                double j = jt.value();
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

        default public int count(double value) {
            int result = 0;
            for (DoubleIterator it = doubleIterator(); it.isValid(); it.advance()) {
                if (it.value() == value) {
                    result++;
                }
            }
            return result;
        }

    }

    static interface DoubleIterator {
        public double value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface DoubleList extends DoubleReversableCollection {
        public abstract double get(int index);

        public abstract void removeAt(int index);

        default public DoubleIterator doubleIterator() {
            return new DoubleIterator() {
                private int at;
                private boolean removed;

                public double value() {
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

        public double readDouble() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, readInt());
                }
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E') {
                        return res * Math.pow(10, readInt());
                    }
                    if (c < '0' || c > '9') {
                        throw new InputMismatchException();
                    }
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static interface DoubleReversableCollection extends DoubleCollection {
    }
}