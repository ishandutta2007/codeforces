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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    int mod = 1000000007;

    long comp(String s1, String s2) {
        int n = s1.length();
        long poss = 1;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == '?' && s1.charAt(i) == s2.charAt(i)) {
                poss = (poss*55) % mod;
            }
            else if (s1.charAt(i) == '?') {
                poss = (poss * (10 - (s2.charAt(i) - '0'))) % mod;
            }
            else if (s2.charAt(i) == '?') {
                poss = (poss * (1 + (s1.charAt(i) - '0'))) % mod;
            }
            else if (s1.charAt(i) < s2.charAt(i)) {
                return 0;
            }
        }

        return poss;
    }

    long ucomp(String s1, String s2) {
        int n = s1.length();
        long poss = 1;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == '?' && s1.charAt(i) == s2.charAt(i)) {
                poss = (poss*55) % mod;
            }
            else if (s2.charAt(i) == '?') {
                poss = (poss * (10 - (s1.charAt(i) - '0'))) % mod;
            }
            else if (s1.charAt(i) == '?') {
                poss = (poss * (1 + (s2.charAt(i) - '0'))) % mod;
            }
            else if (s2.charAt(i) < s1.charAt(i)) {
                return 0;
            }
        }

        return poss;
    }

    long eq(String s1, String s2) {
        int n = s1.length();
        long poss = 1;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == '?' && s1.charAt(i) == s2.charAt(i)) {
                poss = (poss*10) % mod;
            }
            else if (s2.charAt(i) == '?' || s1.charAt(i) == '?' || (s1.charAt(i) == s2.charAt(i))) {

            }
            else {
                return 0;
            }
        }

        return poss;
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        String s1 = in.next();
        String s2 = in.next();

        long poss = 1;
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == '?') poss = (poss*10) % mod;
            if (s2.charAt(i) == '?') poss = (poss*10) % mod;
        }

        poss = (((poss - comp(s1,s2)) % mod) + mod) % mod;
        poss = (((poss - ucomp(s1,s2)) % mod) + mod) % mod;
        poss = (((poss + eq(s1,s2)) % mod) + mod) % mod;

        out.println(poss);
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