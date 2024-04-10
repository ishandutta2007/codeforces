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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
/*        if (n == 1) {
            out.printLine(1);
            return;
        }
        long[] pOdd = new long[]{0, 1, 0, 0};
        long[] pEven = new long[]{0, 0, 1, 0};
        PrimeFastFourierTransform fft = new PrimeFastFourierTransform(MODF);
        while (pOdd.length <= n) {
            long[] oddOdd = new long[pOdd.length];
            for (int i = 1; i < pOdd.length; i += 2) {
                oddOdd[i] = pOdd[i];
            }
            long[] evenEven = new long[pEven.length];
            for (int i = 0; i < pEven.length; i += 2) {
                evenEven[i] = pEven[i];
            }
            long[] npOdd  = new long[pOdd.length * 2 + 1];
            fft.multiply(npOdd, evenEven, pEven, pOdd.length);
            long[] npEven = new long[pEven.length * 2 + 1];
            fft.multiply(npEven, oddOdd, pEven, pEven.length);
            for (int i = npOdd.length - 1; i > 0; i--) {
                npOdd[i] = npOdd[i - 1];
                npEven[i] = npEven[i - 1];
            }
            fill(npOdd, 0, pOdd.length, 0);
            fill(npEven, 0, pOdd.length, 0);
            pOdd = npOdd;
            pEven = npEven;
        }
        out.printLine((pOdd[n] + pEven[n]) % MODF);*/
            int current = 1;
            while (current + 1 < n) {
                if ((current & 1) == 1) {
                    current = 2 * current + 2;
                } else {
                    current = 2 * current + 1;
                }
            }
            if (n >= current && n <= current + 1) {
                out.printLine(1);
            } else {
                out.printLine(0);
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

        public void printLine(int i) {
            writer.println(i);
        }

    }
}