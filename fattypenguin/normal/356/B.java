import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
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
        long p = in.nextLong(), q = in.nextLong();
        char[] a = in.next().toCharArray();
        char[] b = in.next().toCharArray();
        int n = a.length, m = b.length;
        int gcd = BigInteger.valueOf(n).gcd(BigInteger.valueOf(m)).intValue();
        int[] x = new int[n];
        int[] y = new int[m];
        int[] modSum0 = new int[gcd];
        int[] modSum1 = new int[gcd];
        int[] pointer = new int[gcd];
        long allLength = p * n;
        long result = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            for (int i = 0; i < n; ++i) {
                x[i] = a[i] == c ? 1 : 0;
            }
            for (int i = 0; i < m; ++i) {
                y[i] = b[i] == c ? 1 : 0;
            }
            for (int i = 0; i < gcd; ++i) {
                modSum0[i] = modSum1[i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                if (x[i] > 0) {
                    ++modSum1[i % (int)gcd];
                } else {
                    ++modSum0[i % (int)gcd];
                }
            }
            long part = 0;
            for (int i = 0; i < m; ++i) {
                if (y[i] > 0) {
                    part += modSum0[i % (int)gcd];
                } else {
                    part += modSum1[i % (int)gcd];
                }
            }

            long lcm = n * (long)m / gcd;
            long needParts = allLength / lcm;
            result += needParts * part;
        }
        out.println(result / 2);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }