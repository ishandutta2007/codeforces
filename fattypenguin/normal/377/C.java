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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int m = in.nextInt();
        int[] heros = new int[m];
        for (int i = 0; i < m; ++i) {
            heros[i] = a[n - 1 - i];
        }
        a = null;
        n = -1;
        char[] op;
        int[] whichTeam;
        op = new char[m];
        whichTeam = new int[m];
        for (int i = 0; i < m; ++i) {
            op[i] = in.next().toCharArray()[0];
            whichTeam[i] = in.nextInt();
        }

        int[] who = new int[1 << m];
        for (int i = 0; i < m; ++i) {
            who[1 << i] = i;
        }

        Integer[] dp = new Integer[1 << m];
        Integer[] next = new Integer[1 << m];

        dp[0] = 0;
        for (int i = m - 1; i >= 0; --i) {
            Arrays.fill(next, null);
            for (int mask = 0; mask < (1 << m); ++mask) {
                if (dp[mask] == null) continue;
                for (int sub = (1 << m) - 1 - mask; sub > 0; sub -= sub & -sub) {
                    int low = sub & -sub;
                    if (whichTeam[i] == 1) {
                        if (op[i] == 'b') {
                            next[mask + low] = max(next[mask + low], dp[mask]);
                        } else {
                            next[mask + low] = max(next[mask + low], dp[mask] + heros[who[low]]);
                        }
                    } else {
                        if (op[i] == 'b') {
                            next[mask + low] = min(next[mask + low], dp[mask]);
                        } else {
                            next[mask + low] = min(next[mask + low], dp[mask] - heros[who[low]]);
                        }
                    }
                }
            }
//            out.println(Arrays.deepToString(next));
            Integer[] temp = dp; dp = next; next = temp;
        }

        out.println(dp[(1 << m) - 1]);
    }

    private int min(Integer a, int b) {
        if (a == null) return b;
        return Math.min(a, b);
    }

    private int max(Integer a, int b) {
        if (a == null) return b;
        return Math.max(a, b);
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