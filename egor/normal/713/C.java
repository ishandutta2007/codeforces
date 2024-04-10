import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
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
            int[] a = IOUtils.readIntArray(in, n);
            List<TaskC.Function> current = new ArrayList<>();
            TaskC.Function f = new TaskC.Function();
            f.start = Integer.MIN_VALUE;
            f.end = Integer.MAX_VALUE;
            current.add(f);
            for (int i : a) {
                List<TaskC.Function> next = new ArrayList<>();
                for (TaskC.Function fu : current) {
                    fu.start++;
                    if (fu.end != Integer.MAX_VALUE) {
                        fu.end++;
                    }
                    fu.delta -= fu.k;
                    if (fu.end <= i) {
                        fu.k--;
                        fu.delta += i;
                        next.add(fu);
                    } else if (fu.start >= i) {
                        fu.k++;
                        fu.delta -= i;
                        next.add(fu);
                    } else {
                        TaskC.Function nf = new TaskC.Function();
                        nf.start = fu.start;
                        nf.end = i;
                        nf.k = fu.k - 1;
                        nf.delta = fu.delta + i;
                        next.add(nf);
                        fu.start = i + 1;
                        fu.k++;
                        fu.delta -= i;
                        next.add(fu);
                    }
                }
                current.clear();
                TaskC.Function best = next.get(0);
                current.add(best);
                long result = (long) best.k * best.end + best.delta;
                TaskC.Function cst = new TaskC.Function();
                cst.start = best.end + 1;
                cst.end = best.end;
                cst.delta = result;
                for (int j = 1; j < next.size(); j++) {
                    TaskC.Function fu = next.get(j);
                    if (fu.k > 0) {
                        fu.delta += (long) fu.k * fu.start;
                        fu.k = 0;
                    }
                    if ((long) fu.k * fu.end + fu.delta >= result) {
                        cst.end = fu.end;
                    } else if ((long) fu.k * fu.start + fu.delta <= result) {
                        if (cst.start <= cst.end) {
                            current.add(cst);
                        }
                        if (fu.k == 0) {
                            cst = fu;
                            result = cst.delta;
                        } else {
                            current.add(fu);
                            cst = new TaskC.Function();
                            cst.start = fu.end + 1;
                            cst.end = fu.end;
                            result = cst.delta = (long) fu.k * fu.end + fu.delta;
                        }
                    } else {
                        long x = IntegerUtils.trueDivide(cst.delta - fu.delta, fu.k) + 1;
                        cst.end = (int) (x - 1);
                        current.add(cst);
                        fu.start = (int) x;
                        if (fu.k == 0) {
                            cst = fu;
                            result = cst.delta;
                        } else {
                            current.add(fu);
                            cst = new TaskC.Function();
                            cst.start = fu.end + 1;
                            cst.end = fu.end;
                            result = cst.delta = (long) fu.k * fu.end + fu.delta;
                        }
                    }
                }
                cst.end = Integer.MAX_VALUE;
                current.add(cst);
            }
            out.printLine(current.get(current.size() - 1).delta);
        }

        static class Function {
            long start;
            long end;
            long k;
            long delta;

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

    static class IntegerUtils {
        public static long trueDivide(long a, long b) {
            return (a - trueMod(a, b)) / b;
        }

        public static long trueMod(long a, long b) {
            a %= b;
            a += b;
            a %= b;
            return a;
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