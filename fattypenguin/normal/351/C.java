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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private static final long MAX_VALUE = 10000000000000L;
    private int n, m;
    private int[] a, b;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {

            b[i] = in.nextInt();
        }

        long[][] dp = new long[81][81];
        ArrayUtils.fill(dp, MAX_VALUE);
        for (int i = 0; i <= 80; ++i) {
            dp[i][i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            long[][] next = new long[81][81];
            ArrayUtils.fill(next, MAX_VALUE);
            for (int j = 0; j <= 80; ++j) {
                for (int k = 0; k <= 80; ++k) {
                    if (k > 0) {
                        next[j][k - 1] = Math.min(next[j][k - 1], dp[j][k] + b[i]);
                    }
                    if (k + 1 <= 80) {
                        next[j][k + 1] = Math.min(next[j][k + 1], dp[j][k] + a[i]);
                    }
                }
            }
            dp = next;
        }

        long[][] result = new long[81][81];
        ArrayUtils.fill(result, MAX_VALUE);
        for (int i = 0; i <= 80; ++i) {
            result[i][i] = 0;
        }

        for (; m > 0; m >>= 1) {
            if (m % 2 == 1) result = mul(result, dp);
            dp = mul(dp, dp);
        }

        out.println(result[0][0]);
    }

    private long[][] mul(long[][] a, long[][] b) {
        long[][] c = new long[81][81];
        ArrayUtils.fill(c, MAX_VALUE);
        for (int k = 0; k <= 80; ++k) {
            for (int i = 0; i <= 80; ++i) {
                for (int j = 0; j <= 80; ++j) {
                    c[i][j] = Math.min(c[i][j], a[i][k] + b[k][j]);
                }
            }
        }
        return c;
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

class ArrayUtils {


    public static void fill(long[][] array, long value) {
        for (int i = 0; i < array.length; ++i) {
            Arrays.fill(array[i], value);
        }
    }

    }