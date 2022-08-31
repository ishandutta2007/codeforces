import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskO solver = new TaskO();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskO {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            Point p = Point.readPoint(in);
            double vx = in.readInt();
            double vy = in.readInt();
            double h = Math.hypot(vx, vy);
            vx /= h;
            vy /= h;
            Vector vector = new Vector(vx, vy);
            Vector other = new Vector(vy, -vx);
            int a = in.readInt();
            int b = in.readInt();
            int c = in.readInt();
            int d = in.readInt();
            p = go(p, vector, b);
            out.printLine(p.x, p.y);
            p = go(p, vector, -b);
            p = go(p, other, -a / 2d);
            out.printLine(p.x, p.y);
            p = go(p, other, -(c - a) / 2d);
            out.printLine(p.x, p.y);
            p = go(p, vector, -d);
            out.printLine(p.x, p.y);
            p = go(p, other, c);
            out.printLine(p.x, p.y);
            p = go(p, vector, d);
            out.printLine(p.x, p.y);
            p = go(p, other, -(c - a) / 2d);
            out.printLine(p.x, p.y);
        }

        private Point go(Point p, Vector vector, double times) {
            return new Point(p.x + vector.x * times, p.y + vector.y * times);
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

    static class Vector {
        public final double x;
        public final double y;
        public final Point point;

        public Vector(double x, double y) {
            this.x = x;
            this.y = y;
            point = new Point(x, y);
        }

        public Vector(Point point) {
            this.x = point.x;
            this.y = point.y;
            this.point = point;
        }

        public Vector(Point from, Point to) {
            this(to.x - from.x, to.y - from.y);
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

    static class GeometryUtils {
        public static double epsilon = 1e-8;

    }

    static class Point {
        public final double x;
        public final double y;


        public String toString() {
            return "(" + x + ", " + y + ")";
        }

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Point point = (Point) o;

            return Math.abs(x - point.x) <= GeometryUtils.epsilon && Math.abs(y - point.y) <= GeometryUtils.epsilon;
        }


        public int hashCode() {
            int result;
            long temp;
            temp = x != +0.0d ? Double.doubleToLongBits(x) : 0L;
            result = (int) (temp ^ (temp >>> 32));
            temp = y != +0.0d ? Double.doubleToLongBits(y) : 0L;
            result = 31 * result + (int) (temp ^ (temp >>> 32));
            return result;
        }

        public static Point readPoint(InputReader in) {
            double x = in.readDouble();
            double y = in.readDouble();
            return new Point(x, y);
        }

    }
}