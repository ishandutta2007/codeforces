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
        private static final int[] DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int s = in.readInt();
            int m = in.readInt();
            int h = in.readInt();
            int day = in.readInt() - 1;
            int date = in.readInt() - 1;
            int month = in.readInt() - 1;
            int n = in.readInt();
            for (int i = 0; i < n; i++) {
                long t = in.readLong() + 1;
                if (s != -1) {
                    long secs = t % 60;
                    if (secs > s) {
                        t += s - secs + 60;
                    } else {
                        t += s - secs;
                    }
                }
                if (m != -1) {
                    long mins = (t / 60) % 60;
                    if (mins != m && s == -1) {
                        t -= t % 60;
                    }
                    if (mins > m) {
                        t += (m - mins + 60) * 60;
                    } else {
                        t += (m - mins) * 60;
                    }
                }
                if (h != -1) {
                    long hours = (t / 60 / 60) % 24;
                    if (hours != h) {
                        if (s == -1) {
                            t -= t % 60;
                        }
                        if (m == -1) {
                            t -= ((t / 60) % 60) * 60;
                        }
                    }
                    if (hours > h) {
                        t += (h - hours + 24) * 60 * 60;
                    } else {
                        t += (h - hours) * 60 * 60;
                    }
                }
                long fullDay = 24 * 60 * 60;
                long daysSince = t / fullDay;
                long add = t % fullDay;
                long weekDay = (daysSince + 3) % 7;
                daysSince += 90 * 366 + 280 * 365;
                long cycled = daysSince % (97 * 366 + 303 * 365);
                int cy;
                for (int j = 0; ; j++) {
                    int cYear = 365;
                    if (isLeap(j)) {
                        cYear = 366;
                    }
                    if (cycled < cYear) {
                        cy = j;
                        break;
                    } else {
                        cycled -= cYear;
                    }
                }
                int cm;
                for (int j = 0; ; j++) {
                    int cMonth = DAYS_IN_MONTH[j];
                    if (j == 1 && isLeap(cy)) {
                        cMonth = 29;
                    }
                    if (cycled < cMonth) {
                        cm = j;
                        break;
                    } else {
                        cycled -= cMonth;
                    }
                }
                int cd = (int) cycled;
                long currentDate = daysSince;
                while (true) {
                    boolean dayOk;
                    if (day == -2) {
                        if (date == -2) {
                            dayOk = true;
                        } else {
                            dayOk = cd == date;
                        }
                    } else {
                        if (date == -2) {
                            dayOk = weekDay == day;
                        } else {
                            dayOk = weekDay == day || cd == date;
                        }
                    }
                    boolean monthOk = month == -2 || cm == month;
                    if (dayOk && monthOk) {
                        break;
                    }
                    currentDate++;
                    weekDay++;
                    if (weekDay == 7) {
                        weekDay = 0;
                    }
                    cd++;
                    int cMonth = DAYS_IN_MONTH[cm];
                    if (cm == 1 && isLeap(cy)) {
                        cMonth = 29;
                    }
                    if (cd == cMonth) {
                        cd = 0;
                        cm++;
                    }
                    if (cm == 12) {
                        cm = 0;
                        cy++;
                    }
                }
                if (currentDate != daysSince) {
                    currentDate -= 90 * 366 + 280 * 365;
                    if (s == -1) {
                        add -= add % 60;
                    }
                    if (m == -1) {
                        add -= (add / 60 % 60) * 60;
                    }
                    if (h == -1) {
                        add -= (add / (60 * 60) % 24) * (60 * 60);
                    }
                    t = currentDate * fullDay + add;
                }
                out.printLine(t);
            }
        }

        protected boolean isLeap(int j) {
            return j % 400 == 0 || j % 4 == 0 && j % 100 != 0;
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

        public void close() {
            writer.close();
        }

        public void printLine(long i) {
            writer.println(i);
        }

    }
}