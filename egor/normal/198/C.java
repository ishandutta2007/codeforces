import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
}

class TaskC {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int xp = in.readInt();
        int yp = in.readInt();
        int vp = in.readInt();
        int x = in.readInt();
        int y = in.readInt();
        int v = in.readInt();
        int r = in.readInt();
        double left = 0;
        double R = Math.hypot(xp, yp);
        double right = Math.abs(Math.hypot(x, y) - R) / v + 2 * Math.PI * R / vp;
        double alpha = Math.atan2(yp, xp);
        Circle danger = new Circle(new Point(0, 0), r);
        Point ship = new Point(x, y);
        Point[] shipOrbit = danger.findTouchingPoints(ship);
        if (shipOrbit.length != 2)
            throw new RuntimeException();
        for (int i = 0; i < 1000; i++) {
            double time = (left + right) / 2;
            double currentAlpha = alpha + vp / R * time;
            double cx = Math.cos(currentAlpha) * R;
            double cy = Math.sin(currentAlpha) * R;
            Point planet = new Point(cx, cy);
            double distance;
            if (planet.distance(ship) < GeometryUtils.epsilon || new Segment(planet, ship).intersect(danger).length == 0)
                distance = planet.distance(ship);
            else {
                distance = Double.POSITIVE_INFINITY;
                Point[] planetOrbit = danger.findTouchingPoints(planet);
                if (planetOrbit.length != 2)
                    throw new RuntimeException();
                for (Point first : shipOrbit) {
                    for (Point second : planetOrbit) {
                        double angle = Math.atan2(first.y, first.x) - Math.atan2(second.y, second.x);
                        while (angle > 2 * Math.PI)
                            angle -= 2 * Math.PI;
                        while (angle < 0)
                            angle += 2 * Math.PI;
                        if (angle > Math.PI)
                            angle = 2 * Math.PI - angle;
                        distance = Math.min(distance, first.distance(ship) + second.distance(planet) + angle * r);
                    }
                }
            }
            if (distance < v * time)
                right = time;
            else
                left = time;
        }
        out.printFormat("%.9f\n", (left + right) / 2);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

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

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void printFormat(String format, Object...objects) {
		writer.printf(format, objects);
	}

	public void close() {
		writer.close();
	}

	}

class Circle {
	public final Point center;
	public final double radius;

	public Circle(Point center, double radius) {
		this.center = center;
		this.radius = radius;
	}

	public Point[] findTouchingPoints(Point point) {
        double distance = center.distance(point);
        if (distance < radius - GeometryUtils.epsilon)
            return new Point[0];
        if (distance < radius + GeometryUtils.epsilon)
            return new Point[]{point};
        Circle power = new Circle(point, Math.sqrt((distance - radius) * (distance + radius)));
        return intersect(power);
    }

    private Point[] intersect(Circle other) {
        double distance = center.distance(other.center);
        if (distance > radius + other.radius + GeometryUtils.epsilon || Math.abs(radius - other.radius) > distance + GeometryUtils.epsilon)
            return new Point[0];
        double p = (radius + other.radius + distance) / 2;
        double height = 2 * Math.sqrt(p * (p - radius) * (p - other.radius) * (p - distance)) / distance;
        double l1 = Math.sqrt(radius * radius - height * height);
        double l2 = Math.sqrt(other.radius * other.radius - height * height);
        if (radius * radius + distance * distance < other.radius * other.radius)
            l1 = -l1;
        if (radius * radius > distance * distance + other.radius * other.radius)
            l2 = -l2;
        Point middle = new Point((center.x * l2 + other.center.x * l1) / (l1 + l2),
            (center.y * l2 + other.center.y * l1) / (l1 + l2));
        Line line = center.line(other.center).perpendicular(middle);
        return line.intersect(this);
    }
}

class Point {
	public final double x;
	public final double y;

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

	}

class GeometryUtils {
	public static double epsilon = 1e-8;

	public static double fastHypot(double...x) {
		if (x.length == 0)
			return 0;
		else if (x.length == 1)
			return Math.abs(x[0]);
		else {
			double sumSquares = 0;
			for (double value : x)
				sumSquares += value * value;
			return Math.sqrt(sumSquares);
		}
	}

	}

class Segment {
	public final Point a;
	public final Point b;

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
		return a.line(b);
	}

	public Point[] intersect(Circle circle) {
		Point[] result = line().intersect(circle);
		if (result.length == 0)
			return result;
		if (result.length == 1) {
			if (contains(result[0], true))
				return result;
			return new Point[0];
		}
		if (contains(result[0], true)) {
			if (contains(result[1], true))
				return result;
			return new Point[]{result[0]};
		}
		if (contains(result[1], true))
			return new Point[]{result[1]};
		return new Point[0];
	}
}

class Line {
	public final double a;
	public final double b;
	public final double c;

	public Line(double a, double b, double c) {
		double h = GeometryUtils.fastHypot(a, b);
		if (a < -GeometryUtils.epsilon) {
			a = -a;
			b = -b;
			c = -c;
		} else if (a < GeometryUtils.epsilon && b < -GeometryUtils.epsilon) {
			b = -b;
			c = -c;
		}
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

	public Point[] intersect(Circle circle) {
		double distance = distance(circle.center);
		if (distance > circle.radius + GeometryUtils.epsilon)
			return new Point[0];
		Point intersection = intersect(perpendicular(circle.center));
		if (Math.abs(distance - circle.radius) < GeometryUtils.epsilon)
			return new Point[]{intersection};
		double shift = Math.sqrt(circle.radius * circle.radius - distance * distance);
		return new Point[]{new Point(intersection.x + shift * b, intersection.y - shift * a),
			new Point(intersection.x - shift * b, intersection.y + shift * a)};
	}

	public double distance(Point center) {
		return Math.abs(value(center));
	}
}