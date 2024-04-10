import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
    private int[] primes;

    private int bound, result, n, finished;
    private int[] cnt;
    private int[] ans;
    private boolean[] path;
    HashSet<Integer> set;

    void dfs(int firstDepth, int depth, int maxDepth, long prod, boolean mode) {
        if (cnt[firstDepth] >= (n + 1) / 2 || result >= n) return;
        if (depth == maxDepth) {
            if (result < n && !set.contains((int) prod)) {
                set.add((int) prod);
                ans[result++] = (int) prod;
                for (int i = firstDepth; i < maxDepth; ++i) {
                    if (path[i]) {
                        ++cnt[i];
                    }
                }
            }
            return;
        }
        if (cnt[depth] >= (n + 1) / 2 && mode) {
            dfs(firstDepth, depth + 1, maxDepth, prod, mode);
            return;
        }
        long prodBackup = prod;
        path[depth] = true;
        for (prod *= primes[depth]; result < n && (!mode || cnt[depth] < (n + 1) / 2) && prod <= bound; prod *= primes[depth]) {
            dfs(firstDepth, depth + 1, maxDepth, prod, mode);
        }
        path[depth] = false;
        if (firstDepth != depth) {
            dfs(firstDepth, depth + 1, maxDepth, prodBackup, mode);
        }
    }

    void go(int depth, int maxDepth, long prod) {
        if (result >= n) return;
        if (depth == maxDepth) {
            if (!set.contains((int) prod)) {
                set.add((int) prod);
                ans[result++] = (int) prod;
            }
            return;
        }
        for (; result < n && result < n && prod <= bound; prod *= primes[depth]) {
            go(depth + 1, maxDepth, prod);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        primes = new int[100];
        int iter = 0;
        for (int i = 2; iter < 100; ++i) {
            boolean isPrime = true;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) primes[iter++] = i;
        }

        n = in.nextInt();
        bound = 2 * n * n;
        for (int i = 1; ; ++i) {
            for (int j = 0; j < i; ++j) {
                int t = primes[j];
                primes[j] = primes[i - 1 - j];
                primes[j] = t;
            }
            result = finished = 0;
            cnt = new int[i];
            ans = new int[n];
            path = new boolean[i];
            set = new HashSet<Integer>();
            for (int j = 0; j < i; ++j) {
                dfs(j, j, i, 1, true);
                int k = j;
                while (k > 0 && cnt[j] < (n + 1) / 2) {
                    dfs(j, k--, i, 1, false);
                }
            }
//            System.err.println(Arrays.deepToString(new int[][]{cnt}));
            boolean good = true;
            for (int j = 0; j < i; ++j) {
                if (cnt[j] < (n + 1) / 2) {
                    good = false;
                    break;
                }
            }
//            System.err.println("good = " + good);
            if (good) {
                go(0, i, 1);
                if (result == n) {
                    Arrays.sort(ans);
                    for (int j = 0; j < n; ++j) {
                        if (j > 0) out.print(" ");
                        out.print(ans[j]);
                    }
                    out.println();
                    return;
                }
            }
            for (int j = 0; j < i; ++j) {
                int t = primes[j];
                primes[j] = primes[i - 1 - j];
                primes[j] = t;
            }
        }
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