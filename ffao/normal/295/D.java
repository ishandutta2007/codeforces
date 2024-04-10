import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    int mod = 1000000007;
    long[][] sum1d = new long[3000][3000];
    long[][] sum2d = new long[3000][3000];

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();

        for (int rows = 0; rows <= n; rows++) {
            for (int i = 2; i <= m; i++) {
                sum1d[rows][i] = (rows==0) ? 1 : sum2d[rows-1][i]+1;
                if (i != 0) sum1d[rows][i] = (sum1d[rows][i] + sum1d[rows][i-1]) % mod;

                sum2d[rows][i] = sum1d[rows][i];
                if (i != 0) sum2d[rows][i] = (sum2d[rows][i] + sum2d[rows][i-1]) % mod;
            }
        }


        long tot = 0;
        for (int i = 0; i < n; i++) {
            for (int mid = 2; mid <= m; mid++) {
                // res=(res+(((((pd[w][t][1]-pd[w][t-1][1]+M)%M)*pd[w][n-t+1][1])%M)*(m-w+1))%M)%M;
                long top = (i==0) ? 1 : (sum2d[i-1][mid-1]+sum1d[i-1][mid-1]+1);
                long bot = (n-i-1==0) ? 1 : sum2d[n-i-2][mid]+1;

                bot = (bot * top) % mod;
                bot = (bot * (m-mid+1)) % mod;
                tot = (tot + bot) % mod;
            }
        }

        out.println(tot);
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