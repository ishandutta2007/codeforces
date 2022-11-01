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
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int sumx = 0, sumy = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt() % 2;
            b[i] = in.nextInt() % 2;
            sumx ^= a[i];
            sumy ^= b[i];
        }

        int answer = Integer.MAX_VALUE;
        if (sumx + sumy == 0) answer = 0;
        for (int i = 0; i < n; ++i) {
            if (sumx == (a[i] ^ b[i]) && sumy == (b[i] ^ a[i])) {
                answer = Math.min(answer, 1);
            }
            for (int j = i + 1; j < n; ++j) {
                if (sumx == (a[i] ^ a[j] ^ b[i] ^ b[j]) && sumy == (b[i] ^ b[j] ^ a[i] ^ a[j])) {
                    answer = Math.min(answer, 2);
                }
            }
        }
        if (answer > 2) answer = -1;
        out.println(answer);
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