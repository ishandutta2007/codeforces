import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;
import java.io.Writer;
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
            int[] x = new int[n];
            int[] y = new int[n];
            int[] r = new int[n];
            in.readIntArrays(x, y, r);
            Circle[] circles = new Circle[n];
            for (int i = 0; i < n; i++) {
                circles[i] = new Circle(new Point(x[i], y[i]), r[i]);
            }
            List<Point> points = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    Point[] intersect = circles[i].intersect(circles[j]);
                    if (intersect != null) {
                        points.addAll(Arrays.asList(intersect));
                    }
                }
            }
            boolean[] bad = new boolean[points.size()];
            for (int i = 0; i < points.size(); i++) {
                for (int j = 0; j < i; j++) {
                    if (points.get(i).equals(points.get(j))) {
                        bad[i] = true;
                        break;
                    }
                }
            }
            int nVertices = ArrayUtils.count(bad, false);
            int nEdges = 0;
            IndependentSetSystem setSystem = new RecursiveIndependentSetSystem(points.size());
            for (int i = 0; i < n; i++) {
                int current = 0;
                IntList onThis = new IntArrayList();
                for (int j = 0; j < points.size(); j++) {
                    if (!bad[j] && Math.abs(circles[i].center.distance(points.get(j)) - r[i]) < GeometryUtils.epsilon) {
                        current++;
                        onThis.add(j);
                    }
                }
                for (int j = 1; j < onThis.size(); j++) {
                    setSystem.join(onThis.get(j), onThis.get(0));
                }
                nEdges += Math.max(current, 1);
            }
            int nComponents = setSystem.getSetCount() - ArrayUtils.count(bad, true);
            out.printLine(1 + nEdges - nVertices + nComponents);
        }

    }

    static class Line {
        public final double a;
        public final double b;
        public final double c;

        public Line(Point p, double angle) {
            a = Math.sin(angle);
            b = -Math.cos(angle);
            c = -p.x * a - p.y * b;
        }

        public Line(double a, double b, double c) {
            double h = GeometryUtils.fastHypot(a, b);
            this.a = a / h;
            this.b = b / h;
            this.c = c / h;
        }

        public Point intersect(Line other) {
            if (parallel(other)) {
                return null;
            }
            double determinant = b * other.a - a * other.b;
            double x = (c * other.b - b * other.c) / determinant;
            double y = (a * other.c - c * other.a) / determinant;
            return new Point(x, y);
        }

        public boolean parallel(Line other) {
            return Math.abs(a * other.b - b * other.a) < GeometryUtils.epsilon;
        }

        public Line perpendicular(Point point) {
            return new Line(-b, a, b * point.x - a * point.y);
        }

        public double value(Point point) {
            return a * point.x + b * point.y + c;
        }

        public Point[] intersect(Circle circle) {
            double distance = distance(circle.center);
            if (distance > circle.radius + GeometryUtils.epsilon) {
                return new Point[0];
            }
            Point intersection = intersect(perpendicular(circle.center));
            if (Math.abs(distance - circle.radius) < GeometryUtils.epsilon) {
                return new Point[]{intersection};
            }
            double shift = Math.sqrt(circle.radius * circle.radius - distance * distance);
            return new Point[]{new Point(intersection.x + shift * b, intersection.y - shift * a),
                    new Point(intersection.x - shift * b, intersection.y + shift * a)};
        }

        public double distance(Point center) {
            return Math.abs(value(center));
        }


        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            Line line = (Line) o;

            if (!parallel(line)) {
                return false;
            }
            if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon ||
                    Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon) {
                return false;
            }

            return true;
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

    static class Circle {
        public final Point center;
        public final double radius;

        public Circle(Point center, double radius) {
            this.center = center;
            this.radius = radius;
        }

        public Point[] intersect(Circle other) {
            double distance = center.distance(other.center);
            if (distance < GeometryUtils.epsilon) {
                return null;
            }
            Line line = new Line(2 * (other.center.x - center.x), 2 * (other.center.y - center.y), other.radius * other
                    .radius - radius * radius + center.x * center.x - other.center.x * other.center.x +
                    center.y * center.y - other.center.y * other.center.y);
            return line.intersect(this);
        }

    }

    static class IntArrayList extends IntAbstractStream implements IntList {
        private int size;
        private int[] data;

        public IntArrayList() {
            this(3);
        }

        public IntArrayList(int capacity) {
            data = new int[capacity];
        }

        public IntArrayList(IntCollection c) {
            this(c.size());
            addAll(c);
        }

        public IntArrayList(IntStream c) {
            this();
            if (c instanceof IntCollection) {
                ensureCapacity(((IntCollection) c).size());
            }
            addAll(c);
        }

        public IntArrayList(IntArrayList c) {
            size = c.size();
            data = c.data.clone();
        }

        public IntArrayList(int[] arr) {
            size = arr.length;
            data = arr.clone();
        }

        public int size() {
            return size;
        }

        public int get(int at) {
            if (at >= size) {
                throw new IndexOutOfBoundsException("at = " + at + ", size = " + size);
            }
            return data[at];
        }

        private void ensureCapacity(int capacity) {
            if (data.length >= capacity) {
                return;
            }
            capacity = Math.max(2 * data.length, capacity);
            data = Arrays.copyOf(data, capacity);
        }

        public void addAt(int index, int value) {
            ensureCapacity(size + 1);
            if (index > size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size) {
                System.arraycopy(data, index, data, index + 1, size - index);
            }
            data[index] = value;
            size++;
        }

        public void removeAt(int index) {
            if (index >= size || index < 0) {
                throw new IndexOutOfBoundsException("at = " + index + ", size = " + size);
            }
            if (index != size - 1) {
                System.arraycopy(data, index + 1, data, index, size - index - 1);
            }
            size--;
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

        public void readIntArrays(int[]... arrays) {
            for (int i = 0; i < arrays[0].length; i++) {
                for (int j = 0; j < arrays.length; j++) {
                    arrays[j][i] = readInt();
                }
            }
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

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void addAt(int index, int value);

        public abstract void removeAt(int index);

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }


        default public void add(int value) {
            addAt(size(), value);
        }

    }

    static class GeometryUtils {
        public static double epsilon = 1e-8;

        public static double fastHypot(double x, double y) {
            return Math.sqrt(x * x + y * y);
        }

    }

    static class ArrayUtils {
        public static int count(boolean[] array, boolean value) {
            int result = 0;
            for (boolean i : array) {
                if (i == value) {
                    result++;
                }
            }
            return result;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static class RecursiveIndependentSetSystem implements IndependentSetSystem {
        private final int[] color;
        private final int[] rank;
        private int setCount;
        private IndependentSetSystem.Listener listener;

        public RecursiveIndependentSetSystem(int size) {
            color = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) {
                color[i] = i;
            }
            setCount = size;
        }

        public RecursiveIndependentSetSystem(RecursiveIndependentSetSystem other) {
            color = other.color.clone();
            rank = other.rank.clone();
            setCount = other.setCount;
        }

        public boolean join(int first, int second) {
            first = get(first);
            second = get(second);
            if (first == second) {
                return false;
            }
            if (rank[first] < rank[second]) {
                int temp = first;
                first = second;
                second = temp;
            } else if (rank[first] == rank[second]) {
                rank[first]++;
            }
            setCount--;
            color[second] = first;
            if (listener != null) {
                listener.joined(second, first);
            }
            return true;
        }

        public int get(int index) {
            int start = index;
            while (color[index] != index) {
                index = color[index];
            }
            while (start != index) {
                int next = color[start];
                color[start] = index;
                start = next;
            }
            return index;
        }

        public int getSetCount() {
            return setCount;
        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static interface IndependentSetSystem {
        public boolean join(int first, int second);

        public int getSetCount();

        public static interface Listener {
            public void joined(int joinedRoot, int root);

        }

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public void add(int value) {
            throw new UnsupportedOperationException();
        }

        default public IntCollection addAll(IntStream values) {
            for (IntIterator it = values.intIterator(); it.isValid(); it.advance()) {
                add(it.value());
            }
            return this;
        }

    }

    static interface IntReversableCollection extends IntCollection {
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

        public double distance(Point other) {
            return GeometryUtils.fastHypot(x - other.x, y - other.y);
        }

    }
}