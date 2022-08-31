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
            int a = in.readInt();
            int b = in.readInt();
            double[] p = IOUtils.readDoubleArray(in, n);
            double[] u = IOUtils.readDoubleArray(in, n);
            boolean[] throwP = new boolean[n];
            boolean[] throwU = new boolean[n];
            double answer = 0;
            int tries = a + b;
            for (int i = 0; i < tries; i++) {
                double bestP = 0;
                int atP = -1;
                int useU = -1;
                if (a != 0) {
                    for (int j = 0; j < n; j++) {
                        if (!throwP[j]) {
                            double cand;
                            if (throwU[j]) {
                                cand = p[j] * (1 - u[j]);
                            } else {
                                cand = p[j];
                            }
                            if (cand > bestP) {
                                bestP = cand;
                                atP = j;
                            }
                        }
                    }
                } else {
                    double bestRem = -1;
                    for (int j = 0; j < n; j++) {
                        if (!throwP[j]) {
                            double cand;
                            if (throwU[j]) {
                                cand = p[j] * (1 - u[j]);
                            } else {
                                cand = p[j];
                            }
                            if (cand > bestP) {
                                bestP = cand;
                                atP = j;
                            }
                        }
                        if (throwP[j] && !throwU[j]) {
                            double cand = u[j] - p[j];
                            if (cand > bestRem) {
                                bestRem = cand;
                                useU = j;
                            }
                        }
                    }
                    bestP += bestRem;
                }
                double bestU = 0;
                int atU = -1;
                int useP = -1;
                if (b != 0) {
                    for (int j = 0; j < n; j++) {
                        if (!throwU[j]) {
                            double cand;
                            if (throwP[j]) {
                                cand = u[j] * (1 - p[j]);
                            } else {
                                cand = u[j];
                            }
                            if (cand > bestU) {
                                bestU = cand;
                                atU = j;
                            }
                        }
                    }
                } else {
                    double bestRem = -1;
                    for (int j = 0; j < n; j++) {
                        if (!throwU[j]) {
                            double cand;
                            if (throwP[j]) {
                                cand = u[j] * (1 - p[j]);
                            } else {
                                cand = u[j];
                            }
                            if (cand > bestU) {
                                bestU = cand;
                                atU = j;
                            }
                        }
                        if (throwU[j] && !throwP[j]) {
                            double cand = p[j] - u[j];
                            if (cand > bestRem) {
                                bestRem = cand;
                                useP = j;
                            }
                        }
                    }
                    bestU += bestRem;
                }
                if (Math.max(bestU, bestP) <= 0) {
                    break;
                }
                if (bestP > bestU) {
                    answer += bestP;
                    throwP[atP] = true;
                    a--;
                    if (useU != -1) {
                        throwP[useU] = false;
                        throwU[useU] = true;
                        a++;
                        b--;
                    }
                } else {
                    answer += bestU;
                    throwU[atU] = true;
                    b--;
                    if (useP != -1) {
                        throwU[useP] = false;
                        throwP[useP] = true;
                        b++;
                        a--;
                    }
                }
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

    static class IOUtils {
        public static double[] readDoubleArray(InputReader in, int size) {
            double[] array = new double[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readDouble();
            }
            return array;
        }

    }
}