import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int[] rem = new int[100000];
    int cnt;

    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        TreeSet<Integer> s = new TreeSet<Integer>();

        for (int i = 0; i < n; i++) {
            int t = in.nextInt();
            s.add(t);
        }

        int a =in.nextInt();
        int b =in.nextInt();
        int ans = 0;

        while (a != b) {
            ans++;
            cnt = 0;

            int nxt = a-1;
            for (Integer i : s) {
                if (a-(a%i) >= b) nxt = Math.min(a-(a%i),nxt);
                else rem[cnt++]=i;
            }

            for (int i = 0; i < cnt; i++) {
                s.remove(rem[i]);
            }

            a = nxt;
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

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }