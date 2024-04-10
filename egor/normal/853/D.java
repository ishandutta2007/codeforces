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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int[] a = IOUtils.readIntArray(in, n);
            int[] last1K = new int[n];
            int current = -1;
            for (int i = 0; i < n; i++) {
                last1K[i] = current;
                if (a[i] == 1000) {
                    current = i;
                }
            }
            int[] next1K = new int[n];
            current = -1;
            for (int i = n - 1; i >= 0; i--) {
                next1K[i] = current;
                if (a[i] == 1000) {
                    current = i;
                }
            }
            long[] sums = ArrayUtils.partialSums(a);
            long answer = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                //No partial
                long cost = sums[i + 1];
                long bonus = cost / 10;
                long pwb = sums[n] - sums[i + 1];
                if (bonus >= pwb) {
                    answer = Math.min(answer, cost);
                }
                if (a[i] != 1000 && last1K[i] != -1) {
                    cost = sums[i + 1] - 1000;
                    bonus = cost / 10;
                    pwb = sums[n] - sums[i + 1] + 1000;
                    if (bonus >= pwb && sums[last1K[i]] >= 10000) {
                        answer = Math.min(answer, cost);
                    }
                }
                if (next1K[i] != i + 1 && next1K[i] != -1) {
                    cost = sums[i + 1] + 1000;
                    bonus = cost / 10;
                    pwb = sums[n] - sums[i + 1] - 1000;
                    if (bonus >= pwb && sums[i + 1] / 10 >= (next1K[i] - i - 1) * 2000) {
                        answer = Math.min(answer, cost);
                    }
                }
                //Partial
                cost = sums[i];
                bonus = cost / 10;
                pwb = sums[n] - sums[i + 1];
                int partial = i;
                if (bonus >= pwb) {
                    long remaining = bonus - pwb;
                    cost += Math.max(0, a[partial] - remaining);
                    answer = Math.min(answer, cost);
                }
                if (a[i] != 1000 && last1K[i] != -1) {
                    cost = sums[i + 1] - 1000;
                    bonus = cost / 10;
                    pwb = sums[n] - sums[i + 1];
                    partial = last1K[i];
                    if (bonus >= pwb) {
                        long remaining = bonus - pwb;
                        remaining = Math.min(remaining, sums[partial] / 10);
                        cost += Math.max(0, a[partial] - remaining);
                        answer = Math.min(answer, cost);
                    }
                    cost = sums[i] - 1000;
                    bonus = cost / 10;
                    pwb = sums[n] - sums[i + 1] + 1000;
                    partial = i;
                    if (bonus >= pwb && sums[last1K[i]] >= 10000) {
                        long remaining = bonus - pwb;
                        cost += Math.max(0, a[partial] - remaining);
                        answer = Math.min(answer, cost);
                    }
                }
                if (next1K[i] != i + 1 && next1K[i] != -1 && next1K[next1K[i]] != -1) {
                    cost = sums[i + 1] + 1000;
                    bonus = cost / 10;
                    pwb = sums[n] - sums[i + 1] - 2000;
                    partial = next1K[next1K[i]];
                    if (bonus >= pwb && sums[i + 1] / 10 >= (next1K[i] - i - 1) * 2000) {
                        long remaining = bonus - pwb;
                        cost += Math.max(0, a[partial] - remaining);
                        answer = Math.min(answer, cost);
                    }
                }
/*            long cost = sums[i + 1];
            long bonus = cost / 10;
            long payWithBonus = sums[n] - sums[i + 1];
            int partial = i;
            if (bonus >= payWithBonus) {
                long remaining = bonus - payWithBonus;
                remaining -= a[partial] / 10;
                if (remaining >= 0) {
                    cost -= min(a[partial], remaining);
                }
                answer = Math.min(answer, cost);
            }
            if (a[i] != 1000 && last1K[i] != -1) {
                cost = sums[i + 1];
                bonus = cost / 10;
                payWithBonus = sums[n] - sums[i + 1];
                partial = last1K[i];
                if (bonus >= payWithBonus) {
                    long remaining = bonus - payWithBonus;
                    remaining -= a[partial] / 10;
                    if (remaining >= 0) {
                        cost -= min(a[partial], min(remaining, (sums[partial] - sums[0]) / 10));
                    }
                    answer = Math.min(answer, cost);
                }
                if (sums[last1K[i]] >= 10000) {
                    cost = sums[i + 1] - 1000;
                    bonus = cost / 10;
                    payWithBonus = sums[n] - sums[i + 1] + 1000;
                    partial = i;
                    if (bonus >= payWithBonus) {
                        long remaining = bonus - payWithBonus;
                        remaining -= a[partial] / 10;
                        if (remaining >= 0) {
                            cost -= min(a[partial], remaining);
                        }
                        answer = Math.min(answer, cost);
                    }
                    if (last1K[last1K[i]] != -1) {
                        cost = sums[i + 1] - 1000;
                        bonus = cost / 10;
                        payWithBonus = sums[n] - sums[i + 1] + 1000;
                        partial = last1K[last1K[i]];
                        if (bonus >= payWithBonus) {
                            long remaining = bonus - payWithBonus;
                            remaining -= a[partial] / 10;
                            if (remaining >= 0) {
                                cost -= min(a[partial], min(min(remaining, (sums[partial] - sums[0]) / 10),
                                        sums[last1K[i]] / 10 - 1100));
                            }
                            answer = Math.min(answer, cost);
                        }
                    }
                }
            }
            if (next1K[i] != -1 && next1K[i] != i + 1) {
                cost = sums[i + 1] + 1000;
                bonus = cost / 10;
                payWithBonus = sums[n] - sums[i + 1] - 1000;
                partial = next1K[i];
                if (bonus >= payWithBonus && sums[i + 1] / 10 >= 2000 * (next1K[i] - i - 1)) {
                    long remaining = bonus - payWithBonus;
                    remaining -= a[partial] / 10;
                    if (remaining >= 0) {
                        cost -= min(a[partial], remaining);
                    }
                    answer = Math.min(answer, cost);
                }
                if (next1K[next1K[i]] != -1) {
                    cost = sums[i + 1] + 1000;
                    bonus = cost / 10;
                    payWithBonus = sums[n] - sums[i + 1] - 2000;
                    partial = next1K[next1K[i]];
                    if (bonus >= payWithBonus && sums[i + 1] / 10 >= 2000 * (next1K[i] - i - 1)) {
                        long remaining = bonus - payWithBonus;
                        if (remaining >= 0) {
                            cost -= min(a[partial], remaining);
                        }
                        answer = Math.min(answer, cost);
                    }
                }
            }*/
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

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = in.readInt();
            }
            return array;
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

    }

    static class ArrayUtils {
        public static long[] partialSums(int[] array) {
            long[] result = new long[array.length + 1];
            for (int i = 0; i < array.length; i++) {
                result[i + 1] = result[i] + array[i];
            }
            return result;
        }

    }
}