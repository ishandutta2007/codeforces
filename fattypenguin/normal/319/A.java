import java.io.InputStreamReader;
import java.io.IOException;
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
    final int MOD = 1000000007;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        long ans = 0;
        char[] s = in.next().toCharArray();
        int n = s.length;
        int[] pow2 = new int[10 * n + 1];
        pow2[0] = 1;
        for (int i = 1; i < pow2.length; ++i) pow2[i] = pow2[i - 1] * 2 % MOD;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans = (ans + pow2[i] * (long)pow2[(n - i - 1) * 2]) % MOD;
            }
        }

        out.println(ans);
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

    }