import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        long n = in.nextLong();

        long p = 1;
        TreeSet<BigInteger> ts = new TreeSet<BigInteger>();

        while (p <= 2*n) {
            long k = p - 1;

            BigInteger b = BigInteger.valueOf(k).multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
            BigInteger d = b.multiply(b).add(BigInteger.valueOf(8*n));

            BigInteger t = MathUtils.sqrt(d);
            if (!t.multiply(t).equals(d)) {
                p <<= 1;
                continue;
            }

            BigInteger o = b.negate().add(t);
            //System.out.println(p + " " + k + " " + b + " " + t + " " + o);
            if (o.mod(BigInteger.valueOf(2)) == BigInteger.ZERO && o.mod(BigInteger.valueOf(4)) != BigInteger.ZERO)
                ts.add(o.divide(BigInteger.valueOf(2)).multiply(BigInteger.valueOf(p)));

            p <<= 1;
        }

        int f = 0;
        for (BigInteger b : ts) {
            if (b.compareTo(BigInteger.ZERO) > 0) {
                f++;
                out.println(b);
            }
        }

        if (f == 0) out.println(-1);
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

    public long nextLong()
    {
        return Long.parseLong(next());
    }

    }

class MathUtils {

    public static BigInteger sqrt(BigInteger b) {
        BigInteger st = BigInteger.ZERO;
        BigInteger end = b;
        while (st.compareTo(end) < 0) {
            BigInteger mid = (st.add(end).divide(BigInteger.valueOf(2)));
            int c = mid.multiply(mid).compareTo(b);

            //System.out.println(st + " " + end + " " + mid + " gives " + c);
            if (c < 0) st = mid.add(BigInteger.ONE);
            else end = mid;
        }
        return st;
    }

    }