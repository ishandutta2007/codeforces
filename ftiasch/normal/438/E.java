import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static int MOD = 998244353;

    int[][] permutations;
    long[] generators;

    void transform(long[] a, int oper) {
        int n = a.length;
        int k = 31 - Integer.numberOfLeadingZeros(n);
        long[] backup = new long[n];
        for (int i = 0; i < n; ++ i) {
            backup[i] = a[permutations[k][i]];
        }
        for (int i = 0; i < n; ++ i) {
            a[i] = backup[i];
        }
        for (int d = 0; 1 << d < n; ++ d) {
            int m = 1 << d, m2 = m << 1;
            long g = generators[d + 1];
            if (oper == -1) {
                g = inverse(g);
            }
            for (int i = 0; i < n; i += m2) {
                long unit = 1;
                for (int j = 0; j < m; ++ j) {
                    long p1 = a[i + j + m];
                    long p2 = a[i + j];
                    long t = unit * p1 % MOD;
                    p1 = p2 + MOD - t;
                    if (p1 >= MOD) {
                        p1 -= MOD;
                    }
                    p2 += t;
                    if (p2 >= MOD) {
                        p2 -= MOD;
                    }
                    unit = unit * g % MOD;
                    a[i + j + m] = p1;
                    a[i + j] = p2;
                }
            }
        }
    }

    long[] weights, ways;
    long[][] buffers;

    long[] copyOf(long[] array, int size, int actualSize) {
        long[] newArray = new long[actualSize];
        for (int i = 0; i < size; ++ i) {
            newArray[i] = array[i];
        }
        return newArray;
    }

    void solve(int l, int r) {
        if (r - l > 1) {
            int m = l + r >> 1;
            solve(l, m);
            long[] newWays = new long[r - l << 1];
            for (int i = l; i < m; ++ i) {
                newWays[i - l] = ways[i];
            }
            transform(newWays, 1);
            long[] newWays2 = copyOf(ways, r - l, r - l << 1);
            transform(newWays2, 1);
            int k = 31 - Integer.numberOfLeadingZeros(r - l);
            long[] product = new long[r - l << 1];
            for (int i = 0; i < r - l << 1; ++ i) {
                product[i] = newWays[i] * newWays2[i] % MOD * buffers[k][i] % MOD;
            }
            transform(product, -1);
            long t = inverse(1 << k + 1);
            for (int i = m; i < r; ++ i) {
                long p = product[i - l] * t % MOD;
                if (r - l <= l) {
                    p += p;
                    if (p >= MOD) {
                        p -= MOD;
                    }
                }
                ways[i] += p;
                if (ways[i] >= MOD) {
                    ways[i] -= MOD;
                }
            }
            solve(m, r);
        }
    }

    long inverse(long a) {
        return a == 1 ? 1 : (MOD - MOD / a) * inverse(MOD % a) % MOD;
    }

    public void run() {
        generators = new long[20];
        generators[19] = 363395222;
        for (int i = 18; i >= 0; -- i) {
            generators[i] = generators[i + 1] * generators[i + 1] % MOD;
        }
        try {
            int m = reader.nextInt();
            int n = reader.nextInt();
            int k = 32 - Integer.numberOfLeadingZeros(n);
            weights = new long[1 << k];
            for (int i = 0; i < m; ++ i) {
                int c = reader.nextInt();
                if (c < 1 << k) {
                    weights[c] = 1;
                }
            }
            permutations = new int[k + 2][];
            for (int _ = 0; _ <= k + 1; ++ _) {
                int nn = 1 << _;
                int[] p = permutations[_] = new int[nn];
                for (int i = 0; i < nn; ++ i) {
                    p[i] = i;
                }
                for (int i = 1, j = 0; i < nn - 1; ++ i) {
                    int s = nn;
                    do {
                        j ^= s >>= 1;
                    } while ((~j & s) > 0);
                    if (i < j) {
                        int t = p[i];
                        p[i] = p[j];
                        p[j] = t;
                    }
                }
            }
            buffers = new long[k + 1][];
            for (int i = 0; i <= k; ++ i) {
                buffers[i] = new long[1 << i + 1];
                for (int j = 0; j < 1 << i; ++ j) {
                    buffers[i][j] = weights[j];
                }
                transform(buffers[i], 1);
            }
            ways = new long[1 << k];
            ways[0] = 1;
            solve(0, 1 << k);
            for (int i = 1; i <= n; ++ i) {
                writer.println(ways[i]);
            }
        } catch (IOException ex) {
        }
        writer.close();
    }

    Main() {
        reader = new InputReader(System.in);
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    private void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    private InputReader reader;
    private PrintWriter writer;
}

class InputReader {
    InputReader(InputStream in) {
        reader    = new BufferedReader(new InputStreamReader(in));
        //try {
        //    reader    = new BufferedReader(new FileReader(new File("sample.in")));
        //} catch (FileNotFoundException ex) {
        //}
        tokenizer = new StringTokenizer("");
    }

    private String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
}