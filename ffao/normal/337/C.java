import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
 * @author ffao
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
    int mod = 1000000009;

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();

        int o = m;
        m -= n - (n/k);
        if (m < 0) m = 0;

        long temp = n/k;
        long ans;
        if (m == 0) ans = 0;
        else {
            ans = (MathUtils.modpow(2, m+1, mod) + mod - 2) % mod;
            ans = (ans * k) % mod;
        }

        out.println((ans + (o - m*k)) % mod);
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

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }

class MathUtils {

    public static long modpow(int b, int e, int m) {
        if (e == 0) return 1%m;
        else if (e == 1) return b%m;

        long temp = modpow(b, e/2, m);
        temp = (temp * temp) % m;
        if (e % 2 == 1) temp = (temp * b) % m;

        return temp;
    }

    }