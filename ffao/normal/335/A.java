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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    int[] freq = new int[100];
    int n;

    boolean check(int a) {
        int t = 0;
        for (int i = 0; i < 26; i++) {
            t += (freq[i]+a-1) / a;
        }
        return t <= n;
    }
    public void solve(int testNumber, Parser in, OutputWriter out) {
        String s = in.next();
        n = in.nextInt();
        
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
        
            if (freq[s.charAt(i) - 'a']==0) cnt++;
            freq[s.charAt(i) - 'a']++;
        }

        int st = 1, end = s.length();
        while (st < end) {
            int mid = (st+end)/2;
            if (check(mid)) end = mid;
            else st = mid+1;
        }

        if (cnt > n) {
            out.println(-1);
            return;
        }

        out.println(st);
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            int t = (freq[i] + st-1)/st;
            for (int j = 0; j < t; j++) ans.appendCodePoint('a' + i);
        }

        int l = ans.length();
        for (int t = 0; t < n-l; t++) ans.append('a');
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

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }