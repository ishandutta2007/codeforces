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
        E solver = new E();
        solver.solve(1, in, out);
        out.close();
    }

    static class E {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.readInt();
            int m = in.readInt();
            String[][] start = in.readStringTable(n, m);
            String[][] end = in.readStringTable(n, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    start[i][j] = StringUtils.reverse(start[i][j]);
                    end[i][j] = StringUtils.reverse(end[i][j]);
                }
            }
            int row = -1;
            int col = -1;
            for (int i = 0; i < n && row == -1; i++) {
                for (int j = 0; j < m && row == -1; j++) {
                    int st = 0;
                    int en = 0;
                    for (int k = 0; k < n; k++) {
                        if (i != k) {
                            st += start[k][j].length();
                            en += end[k][j].length();
                        }
                    }
                    for (int k = 0; k < m; k++) {
                        if (j != k) {
                            st += start[i][k].length();
                            en += end[i][k].length();
                        }
                    }
                    if (st <= en) {
                        row = i;
                        col = j;
                    }
                }
            }
            int[] zero = new int[n];
            int[] one = new int[m];
            List<E.Step> answer = new ArrayList<>();
            int altRow = row == 0 ? 1 : 0;
            int altCol = col == 0 ? 1 : 0;
            for (int i = 0; i < start[row][col].length(); i++) {
                if (start[row][col].charAt(i) == '0') {
                    zero[altRow]++;
                    answer.add(new E.Step(row, col, altRow, col));
                } else {
                    one[altCol]++;
                    answer.add(new E.Step(row, col, row, altCol));
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int j = 0; j < start[i][col].length(); j++) {
                    if (start[i][col].charAt(j) == '0') {
                        answer.add(new E.Step(i, col, row, col));
                        answer.add(new E.Step(row, col, altRow, col));
                        zero[altRow]++;
                    } else {
                        answer.add(new E.Step(i, col, row, col));
                        answer.add(new E.Step(row, col, row, altCol));
                        one[altCol]++;
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                if (i == col) {
                    continue;
                }
                for (int j = 0; j < start[row][i].length(); j++) {
                    if (start[row][i].charAt(j) == '0') {
                        answer.add(new E.Step(row, i, row, col));
                        answer.add(new E.Step(row, col, altRow, col));
                        zero[altRow]++;
                    } else {
                        answer.add(new E.Step(row, i, row, col));
                        answer.add(new E.Step(row, col, row, altCol));
                        one[altCol]++;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    if (j == col) {
                        continue;
                    }
                    for (int k = 0; k < start[i][j].length(); k++) {
                        if (start[i][j].charAt(k) == '0') {
                            answer.add(new E.Step(i, j, i, col));
                            zero[i]++;
                        } else {
                            answer.add(new E.Step(i, j, row, j));
                            one[j]++;
                        }
                    }
                }
            }
            int nZero = 0;
            int nOne = 0;
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    if (j == col) {
                        continue;
                    }
                    for (int k = 0; k < end[i][j].length(); k++) {
                        if (end[i][j].charAt(k) == '0') {
                            while (zero[nZero] == 0) {
                                nZero++;
                            }
                            answer.add(new E.Step(nZero, col, row, col));
                            zero[nZero]--;
                        } else {
                            while (one[nOne] == 0) {
                                nOne++;
                            }
                            answer.add(new E.Step(row, nOne, row, col));
                            one[nOne]--;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int k = 0; k < end[i][col].length(); k++) {
                    if (end[i][col].charAt(k) == '0') {
                        while (zero[nZero] == 0) {
                            nZero++;
                        }
                        answer.add(new E.Step(nZero, col, row, col));
                        zero[nZero]--;
                    } else {
                        while (one[nOne] == 0) {
                            nOne++;
                        }
                        answer.add(new E.Step(row, nOne, row, col));
                        one[nOne]--;
                    }
                }
            }
            for (int j = 0; j < m; j++) {
                if (j == col) {
                    continue;
                }
                for (int k = 0; k < end[row][j].length(); k++) {
                    if (end[row][j].charAt(k) == '0') {
                        while (zero[nZero] == 0) {
                            nZero++;
                        }
                        answer.add(new E.Step(nZero, col, row, col));
                        zero[nZero]--;
                    } else {
                        while (one[nOne] == 0) {
                            nOne++;
                        }
                        answer.add(new E.Step(row, nOne, row, col));
                        one[nOne]--;
                    }
                }
            }
            for (int k = 0; k < end[row][col].length(); k++) {
                if (end[row][col].charAt(k) == '0') {
                    while (zero[nZero] == 0) {
                        nZero++;
                    }
                    answer.add(new E.Step(nZero, col, row, col));
                    zero[nZero]--;
                } else {
                    while (one[nOne] == 0) {
                        nOne++;
                    }
                    answer.add(new E.Step(row, nOne, row, col));
                    one[nOne]--;
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    if (j == col) {
                        continue;
                    }
                    for (int k = 0; k < end[i][j].length(); k++) {
                        answer.add(new E.Step(row, col, row, j));
                        answer.add(new E.Step(row, j, i, j));
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (i == row) {
                    continue;
                }
                for (int k = 0; k < end[i][col].length(); k++) {
                    answer.add(new E.Step(row, col, i, col));
                }
            }
            for (int j = 0; j < m; j++) {
                if (j == col) {
                    continue;
                }
                for (int k = 0; k < end[row][j].length(); k++) {
                    answer.add(new E.Step(row, col, row, j));
                }
            }
            out.printLine(answer.size());
            for (E.Step step : answer) {
                out.printLine(step.a + 1, step.b + 1, step.c + 1, step.d + 1);
            }
        }

        static class Step {
            int a;
            int b;
            int c;
            int d;

            public Step(int a, int b, int c, int d) {
                this.a = a;
                this.b = b;
                this.c = c;
                this.d = d;
            }

        }

    }

    static class StringUtils {
        public static String reverse(String sample) {
            StringBuilder result = new StringBuilder(sample);
            result.reverse();
            return result.toString();
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

        public String[] readStringArray(int size) {
            String[] array = new String[size];
            for (int i = 0; i < size; i++) {
                array[i] = readString();
            }
            return array;
        }

        public String[][] readStringTable(int rowCount, int columnCount) {
            String[][] table = new String[rowCount][];
            for (int i = 0; i < rowCount; i++) {
                table[i] = this.readStringArray(columnCount);
            }
            return table;
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

        public String readString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
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