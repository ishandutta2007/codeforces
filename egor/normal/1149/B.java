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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int q = in.readInt();
            char[] w = in.readCharArray(n);
            for (int i = 0; i < n; i++) {
                w[i] -= 'a';
            }
            int[][] next = new int[n + 1][26];
            Arrays.fill(next[n], n + 1);
            for (int i = n - 1; i >= 0; i--) {
                System.arraycopy(next[i + 1], 0, next[i], 0, 26);
                next[i][w[i]] = i + 1;
            }
            int l1 = 0;
            int l2 = 0;
            int l3 = 0;
            char[] w1 = new char[250];
            char[] w2 = new char[250];
            char[] w3 = new char[250];
            int[][][] answer = new int[251][251][251];
            for (int i = 0; i < q; i++) {
                char type = in.readCharacter();
                int id = in.readInt();
                if (type == '-') {
                    if (id == 1) {
                        l1--;
                    } else if (id == 2) {
                        l2--;
                    } else {
                        l3--;
                    }
                } else {
                    char c = (char) (in.readCharacter() - 'a');
                    int f1 = 0;
                    int t1 = l1;
                    int f2 = 0;
                    int t2 = l2;
                    int f3 = 0;
                    int t3 = l3;
                    if (id == 1) {
                        w1[l1++] = c;
                        f1 = t1 = l1;
                    } else if (id == 2) {
                        w2[l2++] = c;
                        f2 = t2 = l2;
                    } else if (id == 3) {
                        w3[l3++] = c;
                        f3 = t3 = l3;
                    }
                    for (int x = f1; x <= t1; x++) {
                        for (int y = f2; y <= t2; y++) {
                            for (int z = f3; z <= t3; z++) {
                                answer[x][y][z] = n + 1;
                                if (x > 0 && answer[x - 1][y][z] <= n) {
                                    answer[x][y][z] = Math.min(answer[x][y][z], next[answer[x - 1][y][z]][w1[x - 1]]);
                                }
                                if (y > 0 && answer[x][y - 1][z] <= n) {
                                    answer[x][y][z] = Math.min(answer[x][y][z], next[answer[x][y - 1][z]][w2[y - 1]]);
                                }
                                if (z > 0 && answer[x][y][z - 1] <= n) {
                                    answer[x][y][z] = Math.min(answer[x][y][z], next[answer[x][y][z - 1]][w3[z - 1]]);
                                }
                            }
                        }
                    }
                }
                out.printLine(answer[l1][l2][l3] <= n ? "YES" : "NO");
            }
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public char[] readCharArray(int size) {
            char[] array = new char[size];
            for (int i = 0; i < size; i++) {
                array[i] = readCharacter();
            }
            return array;
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
}