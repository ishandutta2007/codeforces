import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int[] a, b;
    int n;
    long[] dp;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        a = new int[n];
        b = new int[n];

        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        for (int i = 0; i < n; ++i) b[i] = in.nextInt();

        dp = new long[n];
        Arrays.fill(dp, Long.MAX_VALUE / 2);
        dp[0] = 0;

        solve(0, n - 1);

        out.println(dp[n - 1]);
    }

    private Point[] solve(int left, int right) {
        if (left == right) {
            return new Point[]{new Point(b[left], -dp[left], left)};
        }

        int mid = (left + right) >> 1;
        Point[] cl = solve(left, mid);

        for (int i = mid + 1; i <= right; ++i) {
            int low = 0, high = cl.length - 1;
            while (low < high) {
                int m = ((low + high) >> 1) + 1;
                if ((cl[m].y - cl[m - 1].y) >= a[i] * (cl[m].x - cl[m - 1].x)) {
                    low = m;
                } else {
                    high = m - 1;
                }
            }

            dp[i] = Math.min(dp[i], dp[cl[low].at] + b[cl[low].at] * (long)a[i]);
        }

        solve(mid + 1, right);

        ArrayList<Point> list = new ArrayList<Point>();
        Point[] cand = new Point[cl.length + right - mid];
        for (int i = 0; i < cl.length; ++i) cand[i] = cl[i];
        for (int i = 0; i < right - mid; ++i) cand[i + cl.length] = new Point(b[mid + 1 + i], -dp[mid + 1 + i], mid + 1 + i);
        Arrays.sort(cand);
        for (int i = 0; i < cand.length; ++i) {
            while (list.size() > 1) {
                Point u = list.get(list.size() - 1);
                Point v = list.get(list.size() - 2);
                Point x = cand[i];
                if ((x.y - u.y) / (double)(x.x - u.x) >= (u.y - v.y) / (double)(u.x - v.x)) {
                    list.remove(list.size() - 1);
                } else {
                    break;
                }
            }

            list.add(cand[i]);
        }

        return list.toArray(new Point[list.size()]);

    }

}

class Point implements Comparable<Point>{
    long x, y;
    int at;
    Point(long x, long y) {
        this.x = x;
        this.y = y;
    }
    Point(long x, long y, int at) {
        this.x = x;
        this.y = y;
        this.at = at;
    }

    public int compareTo(Point point) {
        return Long.signum(x - point.x);
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