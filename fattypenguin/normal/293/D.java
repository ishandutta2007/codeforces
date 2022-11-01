import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    private double go(Point points[]) {
        int n = points.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int at = 0;
        for (int i = 0; i < points.length; ++i) {
            if (points[i].x < min) {
                at = i;
                min = (int)points[i].x;
            }

            max = Math.max((int)points[i].x, max);
        }

        int next = at;
        int prev = at;

        int low, high;
        low = high = 0;

        int numPoints[] = new int[max - min + 1];
        for (int i = min; i <= max; ++i) {
            while (points[(next + 1) % n].x >= points[next].x && points[(next + 1) % n].x <= i) {
                next = (next + 1) % n;
            }

            while (points[(prev + n - 1) % n].x >= points[prev].x && points[(prev + n - 1) % n].x <= i) {
                prev = (prev + n - 1) % n;
            }

            if (points[next].x == i) low = (int)points[next].y;
            else {
                while (points[(next + 1) % n].subtract(points[next]).det(new Point(i, low).subtract(points[next])) < 0) {
                    ++low;
                }
                while (points[(next + 1) % n].subtract(points[next]).det(new Point(i, low - 1).subtract(points[next])) >= 0) {
                    --low;
                }
            }
            if (points[prev].x == i) high = (int)points[prev].y;
            else {
                while (points[(prev + n - 1) % n].subtract(points[prev]).det(new Point(i, high).subtract(points[prev])) > 0) {
                    --high;
                }

                while (points[(prev + n - 1) % n].subtract(points[prev]).det(new Point(i, high + 1).subtract(points[prev])) <= 0) {
                    ++high;
                }
            }

            int num = 0;
            if (points[next].x == i && points[prev].x == i) {
                num = (int)Math.abs(points[next].y - points[prev].y) + 1;
            } else {
                if (low <= high) {
                    num = high - low + 1;
                }
            }

            numPoints[i - min] = num;
        }

        double sumPoints = 0;
        double sumCord = 0;
        for (int i = min; i <= max; ++i) {
            sumPoints += numPoints[i - min];
            sumCord += i * (double)numPoints[i - min];
        }

        double res = 0;
        double choose2 = sumPoints * (sumPoints - 1) * 0.5;
        for (int i = min; i <= max; ++i) {
            int num = numPoints[i - min];
            res += i * (double)i * 2 / sumPoints * num;
            res -= (sumCord - i) * i / choose2 * num;
        }

        //System.out.println("sumPoints = " + sumPoints + " res = " + res);

        return res;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Point points[] = new Point[n];
        for (int i = 0; i < n; ++i) {
            points[i] = new Point(in.nextInt(), in.nextInt());
        }

        if (poly_area(points) < 0) {
            for (int i = 0; n - 1 - i > i; ++i) {
                Point tmp = points[i];
                points[i] = points[n - 1 - i];
                points[n - 1 - i] = tmp;
            }
        }

        double ans = go(points);
        for (Point o : points) {
            o.turnLeft();
        }

        ans += go(points);

        out.printf("%.10f\n", ans / 2.0);

    }

    private long poly_area(Point points[]) {
        long ret = 0;
        for (int i = 1; i + 1 < points.length; ++i) {
            ret += points[i].subtract(points[0]).det(points[i + 1].subtract(points[0]));
        }
        return ret;
    }
}

class Point implements Comparable<Point> {
    long x, y;

    Point(long x, long y) {
        this.x = x;
        this.y = y;
    }

    Point(long x, long y, int color) {
        this.x = x;
        this.y = y;
    }

    Point subtract(Point o) {
        return new Point(x - o.x, y - o.y);
    }

    long det(Point o) {
        return x * o.y - y * o.x;
    }

    void turnLeft() {
        long tmp = this.y;
        this.y = -this.x;
        this.x = tmp;
    }

    public int compareTo(Point point) {
        if (x != point.x) return Long.signum(x - point.x);
        return Long.signum(y - point.y);
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }