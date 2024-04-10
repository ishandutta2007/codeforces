import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
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
            long n = in.readLong();
            List<TaskC.Variant> variants = new ArrayList<>();
            variants.add(new TaskC.Variant(1, n, 1, n));
            while (true) {
                double best = Double.POSITIVE_INFINITY;
                TaskC.Variant variant = null;
                for (TaskC.Variant v : variants) {
                    long x = v.aFrom + ((v.aTo - v.aFrom) / 3);
                    long y = v.bFrom + ((v.bTo - v.bFrom) / 3);
                    double total1 = 2 * v.score() / 3;
                    double total2 = 2 * v.score() / 3;
                    double total3 = 2 * v.score() / 3;
                    for (TaskC.Variant vv : variants) {
                        if (v == vv) {
                            continue;
                        }
                        if (vv.aTo > x) {
                            if (vv.aFrom > x) {
                                total1 += vv.score();
                            } else {
                                total1 += (double) (vv.aTo - x) * (vv.bTo - vv.bFrom + 1);
                            }
                        }
                        if (vv.bTo > y) {
                            if (vv.bFrom > y) {
                                total2 += vv.score();
                            } else {
                                total2 += (double) (vv.bTo - y) * (vv.aTo - vv.aFrom + 1);
                            }
                        }
                        if (x > vv.aTo || y > vv.bTo) {
                            total3 += vv.score();
                        } else if (x > v.aFrom) {
                            total3 += (double) (x - vv.aFrom) * (vv.bTo - vv.bFrom + 1);
                        } else if (y > v.bFrom) {
                            total3 += (double) (y - vv.bFrom) * (vv.aTo - vv.aFrom + 1);
                        }
                    }
                    double value = Math.max(total1, Math.max(total2, total3));
                    if (value < best) {
                        variant = v;
                        best = value;
                    }
                }
                long x = variant.aFrom + ((variant.aTo - variant.aFrom) / 3);
                long y = variant.bFrom + ((variant.bTo - variant.bFrom) / 3);
                out.printLine(x, y);
                out.flush();
                int answer = in.readInt();
                if (answer == 0) {
                    return;
                }
                List<TaskC.Variant> next = new ArrayList<>();
                int num = 0;
                for (TaskC.Variant v : variants) {
                    if (answer == 1) {
                        if (v.aTo <= x) {
                            continue;
                        }
                        v.aFrom = Math.max(v.aFrom, x + 1);
                        next.add(v);
                    } else if (answer == 2) {
                        if (v.bTo <= y) {
                            continue;
                        }
                        v.bFrom = Math.max(v.bFrom, y + 1);
                        next.add(v);
                    } else {
                        if (x <= v.aFrom && y <= v.bFrom) {
                            continue;
                        }
                        if (x > v.aTo || y > v.bTo) {
                            next.add(v);
                            continue;
                        }
                        int all = 0;
                        if (x > v.aFrom) {
                            next.add(new TaskC.Variant(v.aFrom, x - 1, Math.max(y, v.bFrom), v.bTo));
                            all++;
                        }
                        if (y > v.bFrom) {
                            next.add(new TaskC.Variant(Math.max(x, v.aFrom), v.aTo, v.bFrom, y - 1));
                            all++;
                        }
                        if (x > v.aFrom && y > v.bFrom) {
                            next.add(new TaskC.Variant(v.aFrom, x - 1, v.bFrom, y - 1));
                            all++;
                        }
                        if (all == 3) {
                            num++;
                        }
                    }
                }
                variants = next;
            }
        }

        static class Variant {
            long aFrom;
            long aTo;
            long bFrom;
            long bTo;

            public Variant(long aFrom, long aTo, long bFrom, long bTo) {
                this.aFrom = aFrom;
                this.aTo = aTo;
                this.bFrom = bFrom;
                this.bTo = bTo;
            }

            double score() {
                return (double) (aTo - aFrom + 1) * (bTo - bFrom + 1);
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

        public long readLong() {
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

        public void flush() {
            writer.flush();
        }

    }
}