import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
            int x1 = in.readInt();
            int y1 = in.readInt();
            int x2 = in.readInt();
            int y2 = in.readInt();
            int[] rx = new int[n];
            int[] ry = new int[n];
            int[] vx = new int[n];
            int[] vy = new int[n];
            IOUtils.readIntArrays(in, rx, ry, vx, vy);
            Rational start = Rational.ZERO;
            Rational end = Rational.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if (vx[i] > 0) {
                    if (rx[i] >= x2) {
                        out.printLine(-1);
                        return;
                    }
                    end = MiscUtils.min(end, new Rational(x2 - rx[i], vx[i]));
                    if (rx[i] < x1) {
                        start = MiscUtils.max(start, new Rational(x1 - rx[i], vx[i]));
                    }
                } else if (vx[i] < 0) {
                    if (rx[i] <= x1) {
                        out.printLine(-1);
                        return;
                    }
                    end = MiscUtils.min(end, new Rational(rx[i] - x1, -vx[i]));
                    if (rx[i] > x2) {
                        start = MiscUtils.max(start, new Rational(rx[i] - x2, -vx[i]));
                    }
                } else if (rx[i] <= x1 || rx[i] >= x2) {
                    out.printLine(-1);
                    return;
                }
                if (vy[i] > 0) {
                    if (ry[i] >= y2) {
                        out.printLine(-1);
                        return;
                    }
                    end = MiscUtils.min(end, new Rational(y2 - ry[i], vy[i]));
                    if (ry[i] < y1) {
                        start = MiscUtils.max(start, new Rational(y1 - ry[i], vy[i]));
                    }
                } else if (vy[i] < 0) {
                    if (ry[i] <= y1) {
                        out.printLine(-1);
                        return;
                    }
                    end = MiscUtils.min(end, new Rational(ry[i] - y1, -vy[i]));
                    if (ry[i] > y2) {
                        start = MiscUtils.max(start, new Rational(ry[i] - y2, -vy[i]));
                    }
                } else if (ry[i] <= y1 || ry[i] >= y2) {
                    out.printLine(-1);
                    return;
                }
            }
            if (start.compareTo(end) >= 0) {
                out.printLine(-1);
                return;
            }
            out.printLine((double) start.numerator / start.denominator);
        }

    }

    static class MiscUtils {
        public static <T extends Comparable<T>> T min(T first, T second) {
            if (first.compareTo(second) <= 0) {
                return first;
            }
            return second;
        }

        public static <T extends Comparable<T>> T max(T first, T second) {
            if (first.compareTo(second) <= 0) {
                return second;
            }
            return first;
        }

    }

    static class IOUtils {
        public static void readIntArrays(InputReader in, int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = in.readInt();
                }
            }
        }

    }

    static class Rational implements Comparable<Rational> {
        public static final Rational MAX_VALUE = new Rational(Integer.MAX_VALUE, 1);
        public static final Rational ZERO = new Rational(0, 1);
        public final long numerator;
        public final long denominator;

        public Rational(long numerator, long denominator) {
            if (denominator == 0) {
                throw new IllegalArgumentException();
            }
            long gcd = IntegerUtils.gcd(Math.abs(numerator), Math.abs(denominator));
            if (denominator > 0) {
                this.numerator = numerator / gcd;
                this.denominator = denominator / gcd;
            } else {
                this.numerator = -numerator / gcd;
                this.denominator = -denominator / gcd;
            }
        }


        public String toString() {
            return numerator + "/" + denominator;
        }

        public int compareTo(Rational other) {
            return IntegerUtils.longCompare(numerator * other.denominator, denominator * other.numerator);
            //		return BigInteger.valueOf(numerator).multiply(BigInteger.valueOf(other.denominator)).compareTo(
            //			BigInteger.valueOf(other.numerator).multiply(BigInteger.valueOf(denominator)));
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Rational rational = (Rational) o;

            if (denominator != rational.denominator) {
                return false;
            }
            if (numerator != rational.numerator) {
                return false;
            }

            return true;
        }


        public int hashCode() {
            int result = (int) (numerator ^ (numerator >>> 32));
            result = 31 * result + (int) (denominator ^ (denominator >>> 32));
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

        public void printLine(int i) {
            writer.println(i);
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

    static class IntegerUtils {
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

        public static int longCompare(long a, long b) {
            if (a < b) {
                return -1;
            }
            if (a > b) {
                return 1;
            }
            return 0;
        }

    }
}