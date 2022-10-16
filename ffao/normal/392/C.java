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
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    int mod = 1000000007;

    public void solve(int testNumber, Parser in, OutputWriter out) {
        long n = in.nextLong();
        int k = in.nextInt();

        long[][] pas = MathUtils.pas(41, mod);
        Matrix a = new Matrix(83);

        a.a[0][0] = 1;
        a.a[0][k+1] = 1;

        for (int pot = 0; pot <= 40; pot++) {
            for (int coef = 0; coef <= pot; coef++) {
                a.a[pot+1][coef+1] = pas[pot][coef];
                a.a[pot+1][coef+42] = (pas[pot][coef] * ((1L << (pot-coef)) % mod)) % mod;
            }
        }

        for (int pot = 0; pot <= 40; pot++) {
            a.a[pot+42][pot+1] = 1;
        }

        Matrix b = new Matrix(83);
        for (int i = 1; i <= 42; i++) b.a[i][0] = 1;

        a = a.modpow(n, mod);
        a = a.multiply(b, mod);
        /*for (int i = 0; i < 83; i++) {
            System.out.println("i " + i + " elem: " + a.a[i][0]);
        }*/

        out.println(a.a[0][0]);
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

    public static long[][] pas(int n, int mod) {
        long[][] ret = new long[n+1][n+1];

        for (int i = 0; i <= n; i++) {
            ret[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                ret[i][j] = (ret[i-1][j-1] + ret[i-1][j]) % mod;
            }
        }

        return ret;
    }

    }

class Matrix {
    int n;
    long a[][];

    public Matrix(int n) {
        this.n = n;
        a = new long[n][n];
    }

    public static Matrix identity(int n) {
        Matrix ret = new Matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret.a[i][j] = 0;
            }
            ret.a[i][i] = 1;
        }

        return ret;
    }

    Matrix multiply(Matrix b, long mod) {
        Matrix resp = new Matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                resp.a[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    resp.a[i][j] = (resp.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }

        return resp;
    }

    Matrix modpow(long exp, long mod) {
        if (exp == 0) return identity(n);
        if (exp == 1) return this;

        Matrix h = modpow(exp/2, mod);
        h = h.multiply(h, mod);
        if (exp % 2 == 1) h = h.multiply(this, mod);

        return h;
    }

    }