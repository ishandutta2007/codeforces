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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), k = in.nextInt();
        int[] sum = new int[1000001];
        for (int i = 0; i < n; ++i) {
            ++sum[in.nextInt()];
        }
        for (int i = 1; i < sum.length; ++i) {
            sum[i] += sum[i - 1];
        }
        int result = 1;
        for (int i = 2; i <= 1000000; ++i) {
            int k0 = Math.min(i - 1, k);
            int all = 0;
            for (int j = i; j < sum.length; j += i) {
                int upper = Math.min(j + k0, sum.length - 1);
                all += sum[upper] - sum[j - 1];
            }
            if (all == n) {
                result = Math.max(result, i);
            }
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