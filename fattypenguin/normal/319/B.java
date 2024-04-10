import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.Vector;
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
        int n = in.nextInt();
        int[] dp = new int[n];
        Stack<Integer> stack = new Stack<Integer>();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = in.nextInt();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int steps = 0;
            while (stack.size() > 0 && a[stack.peek()] < a[i]) {
                steps = Math.max(dp[stack.pop()], steps);
            }
            while (stack.size() > 0 && dp[stack.peek()] == steps) {
                stack.pop();
            }
            if (stack.size() == 0) {
                dp[i] = Integer.MAX_VALUE / 10;
                stack.add(i);
            } else {
                dp[i] = steps + 1;
                ans = Math.max(ans, steps + 1);
                stack.add(i);
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }