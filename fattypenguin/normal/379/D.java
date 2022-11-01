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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    int k, x, n, m;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        k = in.nextInt();
        x = in.nextInt();
        n = in.nextInt();
        m = in.nextInt();
        for (int b1 = 0; b1 < 3; ++b1) {
            for (int e1 = 0; e1 < 3; ++e1) {
                if (n == 1 && b1 != e1) continue;
                for (int b2 = 0; b2 < 3; ++b2) {
                    for (int e2 = 0; e2 < 3; ++e2) {
                        if (m == 1 && b2 != e2) continue;
                        if (go(b1, e1, b2, e2, out)) {
                            return;
                        }
                    }
                }
            }
        }
        out.println("Happy new year!");
    }

    private boolean go(int b1, int e1, int b2, int e2, PrintWriter out) {
        long[] k1, k2, c;
        int[] head, rear;
        k1 = new long[k + 1];
        k2 = new long[k + 1];
        c = new long[k + 1];
        head = new int[k + 1];
        rear = new int[k + 1];
        head[1] = b1;
        rear[1] = e1;
        head[2] = b2;
        rear[2] = e2;
        k1[1] = 1; k2[1] = c[1] = 0;
        k1[2] = c[2] = 0; k2[2] = 1;
        for (int i = 3; i <= k; ++i) {
            k1[i] = k1[i - 1] + k1[i - 2];
            k2[i] = k2[i - 1] + k2[i - 2];
            head[i] = head[i - 2];
            rear[i] = rear[i - 1];
            c[i] = c[i - 1] + c[i - 2] + (rear[i - 2] == 0 && head[i - 1] == 1 ? 1 : 0);
        }

        boolean[][][] dp = new boolean[n + 1][n + 1][3];
        int[][][] from = new int[n + 1][n + 1][3];
        dp[1][0][b1] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int last = 0; last < 3; ++last) {
                    for (int next = 0; next < 3; ++next) {
                        if (i + 1 == n && next != e1) continue;
                        if (!dp[i][j][last]) continue;
                        int nj = j + (last == 0 && next == 1 ? 1 : 0);
                        dp[i + 1][nj][next] = true;
                        from[i + 1][nj][next] = i * 3000000 + j * 3000 + last;
                    }
                }
            }
        }

        boolean[][][] dp2 = new boolean[m + 1][m + 1][3];
        int[][][] from2 = new int[m + 1][m + 1][3];
        dp2[1][0][b2] = true;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                for (int last = 0; last < 3; ++last) {
                    for (int next = 0; next < 3; ++next) {
                        if (i + 1 == m && next != e2) continue;
                        if (!dp2[i][j][last]) continue;
                        int nj = j + (last == 0 && next == 1 ? 1 : 0);
                        dp2[i + 1][nj][next] = true;
                        from2[i + 1][nj][next] = i * 3000000 + j * 3000 + last;
                    }
                }
            }
        }

        for (int c1 = 0; c1 <= n; ++c1) {
            for (int c2 = 0; c2 <= m; ++c2) {
                if (k1[k] * c1 + k2[k] * c2 + c[k] == x) {
                    int a = -1, b = -1;
                    for (int i = 0; i < 3; ++i) {
                        if (dp[n][c1][i]) {
                            a = i;
                            break;
                        }
                    }
                    for (int i = 0; i < 3; ++i) {
                        if (dp2[m][c2][i]) {
                            b = i;
                            break;
                        }
                    }
                    char[] s = new char[]{'A', 'C', 'D'};
                    if (a != -1 && b != -1) {
                        StringBuilder s1 = new StringBuilder();
                        int i = n, j = c1, t = a;
                        while (i > 0) {
                            s1.append(s[t]);
                            int last = from[i][j][t];
//                            out.println("i = " + i + " ni = " + last / 3000000);
                            i = last / 3000000;
                            j = last % 3000000 / 3000;
                            t = last % 3;
//                            out.println(dp[i][j][t]);
                        }

                        StringBuilder s2 = new StringBuilder();
                        i = m; j = c2; t = b;
                        while (i > 0) {
                            s2.append(s[t]);
                            int last = from2[i][j][t];
                            i = last / 3000000;
                            j = last % 3000000 / 3000;
                            t = last % 3;
                        }

//                        out.println("s1 = " + s1.length() + " s2 = " + s2.length() + " n = " + n + " m = " + m);

                        out.println(s1.reverse().toString());
                        out.println(s2.reverse().toString());
                        return true;
                    }
                }
            }
        }
        return false;
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