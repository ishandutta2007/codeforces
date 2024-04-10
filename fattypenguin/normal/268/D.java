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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    final int MOD = 1000000009;
    int MAX, h;

    private int get(int x, int y, int z) {
        return x * h * h + y * h + z;
    }

    private int getSorted(int x, int y, int z) {
        int a[] = new int[]{x, y, z};
        Arrays.sort(a);
        x = a[0];
        y = a[1];
        z = a[2];

        return get(x, y, z);
    }

    private int move(int x) {
        return x == 0 ? 0 : x + 1;
    }

    private void add(int a[], int x, int y) {
        a[x] += y;
        if (a[x] >= MOD) {
            a[x] -= MOD;
        }
    }

    private int[] pre(int n, int h) {
        int dp[] = new int[MAX];
        dp[0] = 4;

        int next[] = new int[MAX];
        for (int i = 1; i < n; ++i) {
            Arrays.fill(next, 0);
            for (int x = 0; x < h; ++x) {
                for (int y = x; y < h; ++y) {
                    for (int z = y; z < h; ++z) {

                        int state = get(x, y, z);
                        if (dp[state] == 0) {
                            continue;
                        }

                        {
                            int x0 = move(x), y0 = move(y), z0 = move(z);
                            if (x0 < h && y0 < h && z0 < h) {
                                int nextState = getSorted(x0, y0, z0);
                                add(next, nextState, dp[state]);
                            }
                        }

                        if (x == 0) {
                            int x0 = move(y), y0 = move(z), z0 = 1;
                            if (x0 < h && y0 < h && z0 < h) {
                                int nextState = getSorted(x0, y0, z0);
                                int coff = 1;
                                if (y == 0) {
                                    ++coff;
                                }

                                if (z == 0) {
                                    ++coff;
                                }

                                for (int iter = 0; iter < coff; ++iter) {
                                    add(next, nextState, dp[state]);
                                }
                            }
                        }

                        int a[] = new int[]{x, y, z};
                        int b[] = new int[]{move(x), move(y), move(z)};
                        for (int nextChoose = 2; nextChoose >= 0 && a[nextChoose] != 0; --nextChoose) {
                            int bak = b[nextChoose];
                            b[nextChoose] = 1;
                            if (b[0] < h && b[1] < h && b[2] < h) {
                                int nextState = getSorted(b[0], b[1], b[2]);
                                add(next, nextState, dp[state]);
                            }
                            b[nextChoose] = bak;
                        }
                    }
                }
            }

            int[] tmp = dp;
            dp = next;
            next = tmp;
        }

        return dp;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        h = in.nextInt();

        //TODO: H = 1
    //    if (h == 1) {
   //         out.println(4);
   //         return;
   //     }

        MAX = (h + 1) * (h + 1) * (h + 1);

        int dp0[] = pre(Math.min(h, n), h);
        if (n <= h) {
            int ans = 0;
            for (int i : dp0) {
                ans = ans + i;
                if (ans >= MOD) {
                    ans -= MOD;
                }
            }

            out.println(ans);
            return;
        }


        int dp[][] = new int[2][MAX];
        dp[0] = dp0;
        int next[][] = new int[2][MAX];
        for (int i = 0; i < n - h; ++i) {
            Arrays.fill(next[0], 0);
            Arrays.fill(next[1], 0);
            for (int last = 0; last < 2; ++last) {
                for (int x = 0; x < h; ++x) {
                    for (int y = x; y < h; ++y) {
                        for (int z = y; z < h; ++z) {

                            int state = get(x, y, z);
                            if (dp[last][state] == 0) {
                                continue;
                            }

                            {
                                int x0 = move(x), y0 = move(y), z0 = move(z);
                                x0 = (x0 == h ? 0 : x0);
                                y0 = (y0 == h ? 0 : y0);
                                z0 = (z0 == h ? 0 : z0);
                                if (x0 < h && y0 < h && z0 < h) {
                                    int nextState = getSorted(x0, y0, z0);
                                    add(next[last], nextState, dp[last][state]);
                                }
                            }

                            if (x == 0) {
                                int x0 = move(y), y0 = move(z), z0 = last == 0 ? 1 : 0;
                                x0 = (x0 == h ? 0 : x0);
                                y0 = (y0 == h ? 0 : y0);
                                z0 = (z0 == h ? 0 : z0);
                                if (x0 < h && y0 < h && z0 < h) {
                                    int nextState = getSorted(x0, y0, z0);
                                    int coff = 1;
                                    if (y == 0) {
                                        ++coff;
                                    }

                                    if (z == 0) {
                                        ++coff;
                                    }

                                    for (int iter = 0; iter < coff; ++iter) {
                                        add(next[1], nextState, dp[last][state]);
                                    }
                                }
                            }

                            int a[] = new int[]{x, y, z};
                            int b[] = new int[]{move(x), move(y), move(z)};
                            for (int k = 0; k < 3; ++k) {
                                if (b[k] == h) {
                                    b[k] = 0;
                                }
                            }
                            for (int nextChoose = 2; nextChoose >= 0 && a[nextChoose] != 0; --nextChoose) {
                                int bak = b[nextChoose];
                                b[nextChoose] = last == 0 ? (h == 1 ? 0 : 1) : 0;
                                if (b[0] < h && b[1] < h && b[2] < h) {
                                    int nextState = getSorted(b[0], b[1], b[2]);
                                    add(next[0], nextState, dp[last][state]);
                                }
                               b[nextChoose] = bak;
                            }
                        }
                    }
                }
            }

            int[][] tmp = dp;
            dp = next;
            next = tmp;
        }

        int ans = 0;
        for (int i = 1; i < MAX; ++i) {
            ans += dp[1][i];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }
        for (int i = 0; i < MAX; ++i) {
            ans += dp[0][i];
            if (ans >= MOD) {
                ans -= MOD;
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