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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n, k, l, r, sAll, sK;
        n = in.nextInt();
        k = in.nextInt();
        l = in.nextInt();
        r = in.nextInt();
        sAll = in.nextInt();
        sK = in.nextInt();
        int min = sK / k, more = sK % k;
        int[] ans = new int[n];
        for (int i = 0; i < more; ++i) {
            ans[i] = min + 1;
        }
        for (int i = more; i < k; ++i) {
            ans[i] = min;
        }
        int rest = sAll - sK;
        for (int i = k; i < n; ++i) {
            int toPut = (rest + (n - i) - 1) / (n - i);
            ans[i] = toPut;
            rest -= toPut;
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(ans[i]);
        }
        out.println();
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