import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
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
    private static final double PI = Math.PI;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        double l = in.nextInt();
        double r = in.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        double[] a = new double[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
            a[i] = in.nextInt() / 180.0 * PI;
        }
        double[] dp = new double[1 << n];
        Arrays.fill(dp, l);
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) % 2 == 1) continue;
                double x1 = dp[mask] - x[i];
                double y1 = -y[i];
                double angle = Math.atan2(y1, x1);
                if (angle + a[i] > -FloatPoint.eps) {
                    out.printf("%.10f\n", r - l);
                    return;
                }
                angle += a[i];
                double to = y[i] * Math.tan(PI * 0.5 + angle) + x[i];
                if (to >= r - FloatPoint.eps) {
                    out.printf("%.10f\n", r - l);
                    return;
                }
                dp[mask | (1 << i)] = Math.max(dp[mask | (1 << i)], to);
            }
        }

        out.printf("%.10f\n", dp[(1 << n) - 1] - l);
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

class FloatPoint implements Comparable<FloatPoint>, Point, Cloneable {

    public static double eps = 1e-10;

    public double x, y;

    public static int signum(double value) {
        return value > eps ? 1 : value < -eps ? -1 : 0;
    }

    public FloatPoint(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double det(FloatPoint o) {
        return x * o.y - y * o.x;
    }

    public int compareTo(FloatPoint point) {
        return signum(det(point));
    }

    public String toString() {
        return "[" + x + ", " + y + "]";
    }

    public FloatPoint clone() {
        return new FloatPoint(x, y);
    }

    }

interface Point {
    }