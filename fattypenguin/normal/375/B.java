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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), m = in.nextInt();
        char[][] matrix = new char[n][];
        for (int i = 0; i < n; ++i) {
            matrix[i] = in.next().toCharArray();
        }

        int[][] sum = new int[m + 1][m + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ) {
                if (matrix[i][j] == '0') {
                    ++j; continue;
                }
                int k = j;
                while (k < m && matrix[i][k] == '1') ++k;
                int l = j, r = k - 1;

//                out.println("l = " + l + " r = " + r);
                ++sum[l + 1][m - r];
                j = k;
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
//                if (12 == (j - i + 1) * (sum[m - i][j + 1])) out.println("i = " + i + " j = " + j + " res = " + sum[m - i][j + 1]);
                ans = Math.max(ans, (j - i + 1) * (sum[i + 1][m - j]));
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