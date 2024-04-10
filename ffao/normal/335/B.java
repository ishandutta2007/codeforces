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
 * @author ffao
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
    int[][] pd = new int[3000][3000];
    int[] freq = new int[30];
    int n;
    String s;
    OutputWriter out;

    void reconstruct(int st, int len, int sz) {
        if (len == 0 || sz == 100) return;
        if (len == 1) {
            out.print(s.charAt(st));
            return;
        }

        if (s.charAt(st) == s.charAt(st+len-1)) {
            out.print(s.charAt(st));
            reconstruct(st+1, len-2, sz+2);
            out.print(s.charAt(st));
            return;
        }

        else if (pd[st+1][len-1] > pd[st][len-1]) reconstruct(st+1,len-1,sz);
        else reconstruct(st,len-1,sz);
    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        s = in.next();
        n = s.length();
        this.out = out;

        if (s.length() > 2600) {
            for (int i = 0; i < s.length(); i++) {
                freq[s.charAt(i) - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                if (freq[i] >= 100) {
                    for (int j = 0; j < 100; j++) out.print((char)('a' + i));
                    out.println();
                    return;
                }
            }
        }


        for (int i = 0; i < n; i++) {
            pd[i][0] = 0;
            pd[i][1] = 1;
        }

        for (int len = 2; len <= n; len++) {
            for (int st = 0; st+len <= n; st++) {
                if (s.charAt(st) == s.charAt(st+len-1)) {
                    pd[st][len] = 2 + pd[st+1][len-2];
                }
                else {
                    pd[st][len] = Math.max(pd[st+1][len-1], pd[st][len-1]);
                }
            }
        }

        reconstruct(0, n, 0);
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

    }