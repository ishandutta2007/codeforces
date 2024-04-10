import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, OutputWriter out) {
        long n = in.nextInt();
        long[] dist = in.readLongArray((int) n);

        Arrays.sort(dist);

        BigInteger num = BigInteger.ZERO;
        for (int i = 0; i < n; i++) {
            //out.println(i + " " + dist[i] + " " + (dist[i]*2*i*(i-1) - dist[i]*2*(n-i-1)*(n-i-2)) + " " + ((n-2) * (dist[i] * i - dist[i] * (n-i-1))));
            num = num.add( BigInteger.valueOf( dist[i]*2*(i)*(i-1) - dist[i]*2*(n-i-1)*(n-i-2) ) );
            num = num.add( BigInteger.valueOf( dist[i] * i - dist[i] * (n-i-1) ) );
            num = num.add( BigInteger.valueOf( dist[i] * 2 * i ));
        }

        BigInteger den = BigInteger.valueOf((n-1) * n);

        BigInteger g = num.gcd(den);
        out.println(num.divide(g) + " " + den.divide(g));
    }
}

class Parser
{
    private BufferedReader din;
    private StringTokenizer tokenizer;

    public Parser(InputStream in)
    {
        din = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(din.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    public long nextLong()
    {
        return Long.parseLong(next());
    }

    public long[] readLongArray(int n) {
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) ret[i] = nextLong();
        return ret;
    }
}

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }