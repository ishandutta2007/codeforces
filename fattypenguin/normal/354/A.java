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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n, l, r, ql, qr;
        n = in.nextInt();
        l = in.nextInt();
        r = in.nextInt();
        ql = in.nextInt();
        qr = in.nextInt();
        long[] sum = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + in.nextInt();
        }
        long result = Long.MAX_VALUE;
        for (int pl = 0; pl <= n; ++pl) {
            long lSum = sum[pl];
            long rSum = sum[n] - lSum;
            long current = lSum * l + rSum * r;
            if (pl >= n - pl + 1) {
                current += (pl - n + pl - 1) * ql;
            }
            if (n - pl >= pl + 1) {
                current += (n - pl - pl - 1) * qr;
            }
            result = Math.min(result, current);
        }
        out.println(result);
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