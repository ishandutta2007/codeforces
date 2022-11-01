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
 * @author jiaozhuwudi
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
        int n = in.nextInt(), m = in.nextInt();
        long[] delta = new long[n];
        long[] min = new long[n];
        Arrays.fill(min, 1000000000);
        int[] k, l, r, v;
        k = new int[m];
        l = new int[m];
        r = new int[m];
        v = new int[m];
        for (int i = 0; i < m; ++i) {
            k[i] = in.nextInt();
            l[i] = in.nextInt() - 1;
            r[i] = in.nextInt() - 1;
            v[i] = in.nextInt();
            if (k[i] == 1) {
                for (int j = l[i]; j <= r[i]; ++j) {
                    delta[j] += v[i];
                }
            } else {
                for (int j = l[i]; j <= r[i]; ++j) {
                    min[j] = Math.min(min[j], v[i] - delta[j]);
                }
            }
        }
        int[] result = new int[n];
        Arrays.fill(result, -1000000000);
        delta = new long[n];
        for (int i = 0; i < m; ++i) {
            if (k[i] == 1) {
                for (int j = l[i]; j <= r[i]; ++j) {
                    delta[j] += v[i];
                }
            } else if (k[i] == 2) {
                {
                    boolean flag = false;
                    for (int j = l[i]; j <= r[i]; ++j) {
                        if (min[j] == v[i] - delta[j]) {
                            flag = true;
                            result[j] = (int) min[j];
                            break;
                        }
                    }
                    if (!flag) {
                        out.println("NO");
                        return;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (result[i] < -1000000000 || result[i] > 1000000000) {
                out.println("NO");
                return;
            }
        }

        out.println("YES");
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(result[i]);
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