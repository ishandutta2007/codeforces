import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
            ArrayList<Long> primes = new ArrayList<>();
            for (long i = 2; i < 32000; i++) {
                boolean prime = true;
                for (long p : primes) {
                    if (i % p == 0) {
                        prime = false;
                        break;
                    }
                }
                if (prime) primes.add(i);
            }
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                long x = in.nextLong();
            /*long temp = x;
            Counter<Long> factors = new Counter<>();
            for (long p : primes) {
                while (temp % p == 0) {
                    temp = temp / p;
                    factors.add(p);
                }
            }
            factors.add(temp);*/
                boolean works = false;
                if (x == 0) {
                    out.printLine("1 1");
                    continue;
                }
                for (long j = 1; j <= Math.sqrt(1000000000); j++) {
                    if (x % j == 0) {
                        long k = x / j; // n = k; floor(n / m) = j
                        if (k % 2 != j % 2) continue;
                        long n = (j + k) / 2;
                        long z = k - n;
                        long m = (long) Math.floor((double) n / (double) z);
                        if (n > 0 && m > 0 && n <= 1000000000 && m <= 1000000000 && n * n - Math.floor(n / m) * Math.floor(n / m) == x) {
                            out.printLine(n + " " + m);
                            works = true;
                            break;
                        }
                    }
                }
                if (!works) {
                    out.printLine(-1);
                }

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

        public int nextInt() {
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printLine(int i) {
            writer.println(i);
        }

        public void printLine(String s) {
            writer.println(s);
        }

        public void close() {
            writer.close();
        }

    }
}