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
 * @author ffao
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    int MOD = 1000000007;

    public void solve(int testNumber, Parser in, PrintWriter out) {
        String A = in.next();
        int k = in.nextInt();
        int n = A.length();

        long pot = 1;
        int rat = (int)MathUtils.modpow(2, n, MOD);
        long ratk = MathUtils.modpow(rat, k, MOD);
        long ratinv = MathUtils.modpow( ((1-rat) + MOD) % MOD, MOD-2, MOD);

        long ans = 0;

        for (int i = 0; i < n; i++) {
            if (A.charAt(i) == '0' || A.charAt(i) == '5') {
                // 2^i + 2^(i+n) + ...
                long mult = (((pot * (1 - ratk)) % MOD) + MOD) % MOD;
                mult = (mult * ratinv) % MOD;

                ans = (ans + mult) % MOD;
            }

            pot = (pot << 1) % MOD;
        }

        out.println(ans);
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