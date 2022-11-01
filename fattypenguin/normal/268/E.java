import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Point songs[] = new Point[n];
        for (int i = 0; i < n; ++i) {
            songs[i] = new Point(in.nextInt(), 100 - in.nextInt());
        }

        Arrays.sort(songs);

        double ex = 0;
        long sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            ex += (100 - songs[i].y) * 0.01 * sum * 0.01 * songs[i].x;
            ex += songs[i].x;
            sum += songs[i].y;
        }

        out.printf("%.13f\n", ex);
    }
}

class Point implements Comparable<Point> {
    public long x, y;

    Point(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public int compareTo(Point arg0) {
        return -Long.signum(x * arg0.y * (100 - y) - y * arg0.x * (100 - arg0.y));
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