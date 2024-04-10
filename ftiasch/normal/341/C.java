import java.io.*;
import java.math.*;
import java.util.*;

public class C {
    final static int MOD = (int)1e9 + 7;

    public void run() {
        try {
            int n = reader.nextInt();
            int[] a = new int[n];
            boolean[] occur = new boolean[n];
            int need = 0;
            for (int i = 0; i < n; ++ i) {
                a[i] = reader.nextInt();
                if (a[i] == -1) {
                    need ++;
                } else {
                    a[i] --;
                    occur[a[i]] = true;
                }
            }
            int[] ways = new int[n + 1];
            ways[0] = 1;
            for (int i = 0; i < n; ++ i) {
                if (a[i] == -1) {
                    int[] newWays = new int[n + 1];
                    for (int j = 0; j <= n; ++ j) {
                        if (ways[j] == 0) {
                            continue;
                        }
                        newWays[j] += ways[j];
                        newWays[j] %= MOD;
                        if (!occur[i]) {
                            newWays[j + 1] += ways[j];
                            newWays[j + 1] %= MOD;
                        }
                    }
                    ways = newWays;
                }
            }
            int[] factorial = new int[n + 1];
            factorial[0] = 1;
            for (int i = 1; i <= n; ++ i) {
                factorial[i] = (int)((long)factorial[i - 1] * i % MOD);
            }
            int answer = 0;
            for (int i = 0; i <= need; ++ i) {
                long sign = i % 2 == 0 ? 1 : -1;
                answer += sign * ways[i] * factorial[need - i] % MOD;
                answer %= MOD;
            }
            writer.println((answer + MOD) % MOD);
        } catch (IOException ex) {
        }
        writer.close();
    }

    InputReader reader;
    PrintWriter writer;

    C() {
        reader = new InputReader();
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new C().run();
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}