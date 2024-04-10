import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.AbstractSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.ArrayList;
import java.util.Map;
import java.io.OutputStreamWriter;
import java.util.NoSuchElementException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.io.BufferedWriter;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.util.List;
import java.util.AbstractMap;
import java.io.Writer;
import java.util.Map.Entry;
import java.util.Comparator;
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
			int p = in.readInt();
			int q = in.readInt();
			Point[] points = new Point[n + 3];
			double x = 0;
			double y = 0;
			for (int i = 0; i < n; i++) {
				points[i] = Point.readPoint(in);
				x = Math.max(x, points[i].x);
				y = Math.max(y, points[i].y);
			}
			points[n] = new Point(x, 0);
			points[n + 1] = new Point(0, y);
			points[n + 2] = Point.ORIGIN;
			points = new EHashSet<>(Arrays.asList(points)).toArray(new Point[0]);
			Segment[] sides = Polygon.convexHull(points).sides();
			Line line = Point.ORIGIN.line(new Point(p, q));
			double dst = 0;
			for (Segment segment : sides) {
				if (segment.line() == null) {
					continue;
				}
				Point point = segment.intersect(line);
				if (point == null) {
					continue;
				}
				dst = Math.max(dst, Point.ORIGIN.distance(point));
			}
			out.printLine(new Point(p, q).distance(Point.ORIGIN) / dst);
		}

	}

	static class EHashMap<E, V> extends AbstractMap<E, V> {
		private static final int[] shifts = new int[10];
		private int size;
		private HashEntry<E, V>[] data;
		private int capacity;
		private Set<Entry<E, V>> entrySet;

		static {
			Random random = new Random(System.currentTimeMillis());
			for (int i = 0; i < 10; i++)
				shifts[i] = 1 + 3 * i + random.nextInt(3);
		}

		public EHashMap() {
			this(4);
		}

		private void setCapacity(int size) {
			capacity = Integer.highestOneBit(4 * size);
			//noinspection unchecked
			data = new HashEntry[capacity];
		}

		public EHashMap(int maxSize) {
			setCapacity(maxSize);
			entrySet = new AbstractSet<Entry<E, V>>() {

				public Iterator<Entry<E, V>> iterator() {
					return new Iterator<Entry<E, V>>() {
						private HashEntry<E, V> last = null;
						private HashEntry<E, V> current = null;
						private HashEntry<E, V> base = null;
						private int lastIndex = -1;
						private int index = -1;

						public boolean hasNext() {
							if (current == null) {
								for (index++; index < capacity; index++) {
									if (data[index] != null) {
										base = current = data[index];
										break;
									}
								}
							}
							return current != null;
						}

						public Entry<E, V> next() {
							if (!hasNext())
								throw new NoSuchElementException();
							last = current;
							lastIndex = index;
							current = current.next;
							if (base.next != last)
								base = base.next;
							return last;
						}

						public void remove() {
							if (last == null)
								throw new IllegalStateException();
							size--;
							if (base == last)
								data[lastIndex] = last.next;
							else
								base.next = last.next;
						}
					};
				}


				public int size() {
					return size;
				}
			};
		}

		public EHashMap(Map<E, V> map) {
			this(map.size());
			putAll(map);
		}


		public Set<Entry<E, V>> entrySet() {
			return entrySet;
		}


		public void clear() {
			Arrays.fill(data, null);
			size = 0;
		}

		private int index(Object o) {
			return getHash(o.hashCode()) & (capacity - 1);
		}

		private int getHash(int h) {
			int result = h;
			for (int i : shifts)
				result ^= h >>> i;
			return result;
		}


		public V remove(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			HashEntry<E, V> last = null;
			while (current != null) {
				if (current.key.equals(o)) {
					if (last == null)
						data[index] = current.next;
					else
						last.next = current.next;
					size--;
					return current.value;
				}
				last = current;
				current = current.next;
			}
			return null;
		}


		public V put(E e, V value) {
			if (e == null)
				return null;
			int index = index(e);
			HashEntry<E, V> current = data[index];
			if (current != null) {
				while (true) {
					if (current.key.equals(e)) {
						V oldValue = current.value;
						current.value = value;
						return oldValue;
					}
					if (current.next == null)
						break;
					current = current.next;
				}
			}
			if (current == null)
				data[index] = new HashEntry<E, V>(e, value);
			else
				current.next = new HashEntry<E, V>(e, value);
			size++;
			if (2 * size > capacity) {
				HashEntry<E, V>[] oldData = data;
				setCapacity(size);
				for (HashEntry<E, V> entry : oldData) {
					while (entry != null) {
						HashEntry<E, V> next = entry.next;
						index = index(entry.key);
						entry.next = data[index];
						data[index] = entry;
						entry = next;
					}
				}
			}
			return null;
		}


		public V get(Object o) {
			if (o == null)
				return null;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return current.value;
				current = current.next;
			}
			return null;
		}


		public boolean containsKey(Object o) {
			if (o == null)
				return false;
			int index = index(o);
			HashEntry<E, V> current = data[index];
			while (current != null) {
				if (current.key.equals(o))
					return true;
				current = current.next;
			}
			return false;
		}


		public int size() {
			return size;
		}

		private static class HashEntry<E, V> implements Entry<E, V> {
			private final E key;
			private V value;
			private HashEntry<E, V> next;

			private HashEntry(E key, V value) {
				this.key = key;
				this.value = value;
			}

			public E getKey() {
				return key;
			}

			public V getValue() {
				return value;
			}

			public V setValue(V value) {
				V oldValue = this.value;
				this.value = value;
				return oldValue;
			}

		}

	}

	static class GeometryUtils {
		public static double epsilon = 1e-8;

		public static double fastHypot(double x, double y) {
			return Math.sqrt(x * x + y * y);
		}

	}

	static class Segment {
		public final Point a;
		public final Point b;
		private Line line = null;

		public Segment(Point a, Point b) {
			this.a = a;
			this.b = b;
		}

		public boolean contains(Point point, boolean includeEnds) {
			if (a.equals(point) || b.equals(point))
				return includeEnds;
			if (a.equals(b))
				return false;
			Line line = line();
			if (!line.contains(point))
				return false;
			Line perpendicular = line.perpendicular(a);
			double aValue = perpendicular.value(a);
			double bValue = perpendicular.value(b);
			double pointValue = perpendicular.value(point);
			return aValue < pointValue && pointValue < bValue || bValue < pointValue && pointValue < aValue;
		}

		public Line line() {
			if (line == null)
				line = a.line(b);
			return line;
		}

		public Point intersect(Line line) {
			Line selfLine = line();
			Point intersect = selfLine.intersect(line);
			if (intersect == null)
				return null;
			if (contains(intersect, true))
				return intersect;
			return null;
		}

	}

	static class Polygon {
		public final Point[] vertices;
		private Segment[] sides;

		public Polygon(Point... vertices) {
			this.vertices = vertices.clone();
		}

		public static boolean over(Point a, Point b, Point c) {
			return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < -GeometryUtils.epsilon;
		}

		private static boolean under(Point a, Point b, Point c) {
			return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > GeometryUtils.epsilon;
		}

		public static Polygon convexHull(Point[] points) {
			if (points.length == 1)
				return new Polygon(points);
			Arrays.sort(points, new Comparator<Point>() {
				public int compare(Point o1, Point o2) {
					int value = Double.compare(o1.x, o2.x);
					if (value != 0)
						return value;
					return Double.compare(o1.y, o2.y);
				}
			});
			Point left = points[0];
			Point right = points[points.length - 1];
			List<Point> up = new ArrayList<Point>();
			List<Point> down = new ArrayList<Point>();
			for (Point point : points) {
				if (point == left || point == right || !under(left, point, right)) {
					while (up.size() >= 2 && under(up.get(up.size() - 2), up.get(up.size() - 1), point))
						up.remove(up.size() - 1);
					up.add(point);
				}
				if (point == left || point == right || !over(left, point, right)) {
					while (down.size() >= 2 && over(down.get(down.size() - 2), down.get(down.size() - 1), point))
						down.remove(down.size() - 1);
					down.add(point);
				}
			}
			Point[] result = new Point[up.size() + down.size() - 2];
			int index = 0;
			for (Point point : up)
				result[index++] = point;
			for (int i = down.size() - 2; i > 0; i--)
				result[index++] = down.get(i);
			return new Polygon(result);
		}

		public Segment[] sides() {
			if (sides == null) {
				sides = new Segment[vertices.length];
				for (int i = 0; i < vertices.length - 1; i++)
					sides[i] = new Segment(vertices[i], vertices[i + 1]);
				sides[sides.length - 1] = new Segment(vertices[vertices.length - 1], vertices[0]);
			}
			return sides;
		}

	}

	static class EHashSet<E> extends AbstractSet<E> {
		private static final Object VALUE = new Object();
		private final Map<E, Object> map;

		public EHashSet() {
			this(4);
		}

		public EHashSet(int maxSize) {
			map = new EHashMap<E, Object>(maxSize);
		}

		public EHashSet(Collection<E> collection) {
			this(collection.size());
			addAll(collection);
		}


		public boolean contains(Object o) {
			return map.containsKey(o);
		}


		public boolean add(E e) {
			if (e == null)
				return false;
			return map.put(e, VALUE) == null;
		}


		public boolean remove(Object o) {
			if (o == null)
				return false;
			return map.remove(o) != null;
		}


		public void clear() {
			map.clear();
		}


		public Iterator<E> iterator() {
			return map.keySet().iterator();
		}


		public int size() {
			return map.size();
		}

	}

	static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return isWhitespace(c);
		}

		public static boolean isWhitespace(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, readInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, readInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
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
			if (parallel(other))
				return null;
			double determinant = b * other.a - a * other.b;
			double x = (c * other.b - b * other.c) / determinant;
			double y = (a * other.c - c * other.a) / determinant;
			return new Point(x, y);
		}

		public boolean parallel(Line other) {
			return Math.abs(a * other.b - b * other.a) < GeometryUtils.epsilon;
		}

		public boolean contains(Point point) {
			return Math.abs(value(point)) < GeometryUtils.epsilon;
		}

		public Line perpendicular(Point point) {
			return new Line(-b, a, b * point.x - a * point.y);
		}

		public double value(Point point) {
			return a * point.x + b * point.y + c;
		}


		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;

			Line line = (Line) o;

			if (!parallel(line)) return false;
			if (Math.abs(a * line.c - c * line.a) > GeometryUtils.epsilon || Math.abs(b * line.c - c * line.b) > GeometryUtils.epsilon)
				return false;

			return true;
		}

	}

	static class Point {
		public static final Point ORIGIN = new Point(0, 0);
		public final double x;
		public final double y;


		public String toString() {
			return "(" + x + ", " + y + ")";
		}

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public Line line(Point other) {
			if (equals(other))
				return null;
			double a = other.y - y;
			double b = x - other.x;
			double c = -a * x - b * y;
			return new Line(a, b, c);
		}


		public boolean equals(Object o) {
			if (this == o)
				return true;
			if (o == null || getClass() != o.getClass())
				return false;

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

		public static Point readPoint(InputReader in) {
			double x = in.readDouble();
			double y = in.readDouble();
			return new Point(x, y);
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
				if (i != 0)
					writer.print(' ');
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
}