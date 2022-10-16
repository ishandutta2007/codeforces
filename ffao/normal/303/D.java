import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public static int generator (int p, int x) {
        int[] fact = new int[50];
        int cnt = 0;

        int phi = p-1,  n = phi;
        for (int i=2; i*i<=n; ++i)
            if (n % i == 0) {
                fact[cnt++]=i;
                while (n % i == 0)
                    n /= i;
            }
        if (n > 1)
            fact[cnt++]=n;

        int lim = Math.max(x-p, 1);

        for (int res=x-1; res>=lim; --res) {
            boolean ok = true;
            for (int i=0; i<cnt && ok; ++i)
                ok = MathUtils.modpow (res, phi / fact[i], p) != 1;
            if (ok) {
                return res;
            }
        }
        return -1;
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt() + 1;
        int x = in.nextInt();

        if (n == 2) {
            if (x == 2) out.println(-1);
            else out.println(x-1);
            return;
        }

        if (!MathUtils.isPrime(n)) {
            out.println(-1);
            return;
        }

        int ans = generator(n, x);
        if (ans > 1 && ans < x) out.println(ans);
        else out.println(-1);
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

    public static boolean isPrime(int n) {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
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