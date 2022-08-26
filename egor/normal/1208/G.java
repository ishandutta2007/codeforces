import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
            int k = in.readInt();
            if (k == 1) {
                out.printLine(3);
                return;
            }
            long[] phi = MultiplicativeFunction.PHI.calculateUpTo(n + 1);
            phi = Arrays.copyOfRange(phi, 5, n + 1);
            Arrays.sort(phi);
            long answer = 6;
            for (int i = 0; i < k - 2; i++) {
                answer += phi[i];
            }
            out.printLine(answer);
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

        public void printLine(long i) {
            writer.println(i);
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class IntegerUtils {
        public static int[] generateDivisorTable(int upTo) {
            int[] divisor = new int[upTo];
            for (int i = 1; i < upTo; i++) {
                divisor[i] = i;
            }
            for (int i = 2; i * i < upTo; i++) {
                if (divisor[i] == i) {
                    for (int j = i * i; j < upTo; j += i) {
                        divisor[j] = i;
                    }
                }
            }
            return divisor;
        }

    }

    static abstract class MultiplicativeFunction {
        public static final MultiplicativeFunction PHI = new MultiplicativeFunction() {

            protected long value(long p, int exponent, long power) {
                return power / p * (p - 1);
            }
        };

        protected abstract long value(long p, int exponent, long power);

        public long[] calculateUpTo(int upTo) {
            int[] divisor = IntegerUtils.generateDivisorTable(upTo);
            long[] result = new long[upTo];
            if (upTo <= 1) {
                return result;
            }
            result[1] = 1;
            for (int i = 2; i < upTo; i++) {
                int iDivided = i;
                int exponent = 0;
                do {
                    iDivided /= divisor[i];
                    exponent++;
                } while (iDivided % divisor[i] == 0);
                result[i] = result[iDivided] * value(divisor[i], exponent, i / iDivided);
            }
            return result;
        }

    }
}