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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    private static final int UPPER = 10000007;
    private boolean[] notPrime;
    private int[] count;
    private int[] sum;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        sum = new int[UPPER];
        count = new int[UPPER];
        notPrime = new boolean[UPPER];
        int n = in.nextInt();
        int[] a = in.nextIntArray(n);
        for (int i : a) {
            ++count[i];
        }
        for (int i = 2; i < UPPER; ++i) {
            if (notPrime[i]) {
                sum[i] = sum[i - 1];
                continue;
            }
            int res = 0;
            for (int j = i; j < UPPER; j += i) {
                notPrime[j] = true;
                res += count[j];
            }

            sum[i] = sum[i - 1] + res;
        }

        int q = in.nextInt();
        for (int i = 0; i < q; ++i) {
            int l = in.nextInt();
            int r = in.nextInt();
            l = Math.min(l, UPPER - 1);
            r = Math.min(r, UPPER - 1);
            out.println(sum[r] - sum[l - 1]);
        }

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

    public int[] nextIntArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; ++i) {
            result[i] = nextInt();
        }
        return result;
    }

    }