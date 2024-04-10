import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class AncientBerlandCircus implements Runnable {
	{
		Locale.setDefault(Locale.US);
	}

	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);

	public static final double EPSILON = 1e-5;

	public static class Line {
		public final double a, b, c;

		public Line(double x1, double y1, double x2, double y2) {
			if (Math.abs(x1 - x2) < EPSILON && Math.abs(y1 - y2) < EPSILON) {
				throw new RuntimeException("Points are equal");
			}
			a = y1 - y2;
			b = x2 - x1;
			c = -a * x1 - b * y1;
		}

		public Line(Point a, Point b) {
			this(a.x, a.y, b.x, b.y);
		}

		public Line perpendicular(Point p) {
			return new Line(p, new Point(p.x + a, p.y + b));
		}

		public Point intersect(Line l) {
			double d = a * l.b - b * l.a;
			if (Math.abs(d) < EPSILON) {
				throw new RuntimeException("Lines are parallel");
			}
			return new Point((l.c * b - c * l.b) / d, (l.a * c - l.c * a) / d);
		}
	}

	public static class Point {
		public final double x, y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}


	private double x1, x2, x3, y1, y2, y3;
	private double ans;

	public static void main(String[] args) {
		new Thread(new AncientBerlandCircus()).start();
	}

	private void read() {
		x1 = in.nextDouble();
		y1 = in.nextDouble();
		x2 = in.nextDouble();
		y2 = in.nextDouble();
		x3 = in.nextDouble();
		y3 = in.nextDouble();
	}

	private void solve() {
		Line l1 = new Line(x1, y1, x2, y2);
		Line l2 = new Line(x1, y1, x3, y3);
		Line m1 = l1.perpendicular(new Point((x1 + x2) / 2, (y1 + y2) / 2));
		Line m2 = l2.perpendicular(new Point((x1 + x3) / 2, (y1 + y3) / 2));
		Point c = m1.intersect(m2);
		double a1 = Math.abs(Math.atan2(y2 - c.y, x2 - c.x) - Math.atan2(y1 - c.y, x1 - c.x));
		double a2 = Math.abs(Math.atan2(y3 - c.y, x3 - c.x) - Math.atan2(y1 - c.y, x1 - c.x));
		a1 /= 2 * Math.PI;
		a2 /= 2 * Math.PI;
		for (int i = 1; ; i++) {
			if (Math.abs(((int)(a1 * i + EPSILON) - a1 * i)) < EPSILON && Math.abs(((int)(a2 * i + EPSILON) - a2 * i)) < EPSILON) {
				ans = i * Math.sin(2 * Math.PI / i) * ((x1 - c.x) * (x1 - c.x) + (y1 - c.y) * (y1 - c.y)) / 2;
				return;
			}
		}
	}

	private void write() {
		out.println(ans);
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}