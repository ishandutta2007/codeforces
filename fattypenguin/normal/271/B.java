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
    int next[];
    private void gen() {
        final int LIMIT = 200000;
        next = new int[LIMIT];
        boolean notPrime[] = new boolean[LIMIT];
        int primes[] = new int[LIMIT];
        int totalPrimes = 0;
        for (int i = 2; i < LIMIT; ++i) {
            if (!notPrime[i]) {
                primes[totalPrimes++] = i;
                for (int j = i + i; j < LIMIT; j += i) {
                    notPrime[j] = true;
                }
            }
        }

        int ptr = 0;
        for (int i = 0; i <= 110000; ++i) {
            if (ptr < totalPrimes && primes[ptr] < i) {
                ++ptr;
            }

            next[i] = primes[ptr];
        }
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        gen();
        int n = in.nextInt();
        int m = in.nextInt();
        int a[][] = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = in.nextInt();
            }
        }

        long minCost = Long.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            long cost = 0;
            for (int j = 0; j < m; ++j) {
                cost += next[a[i][j]] - a[i][j];
            }
            minCost = Math.min(cost, minCost);
        }

        for (int i = 0; i < m; ++i) {
            int cost = 0;
            for (int j = 0; j < n; ++j) {
                cost += next[a[j][i]] - a[j][i];
            }

            minCost = Math.min(minCost, cost);
        }

        out.println(minCost);
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