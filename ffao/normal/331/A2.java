import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
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
		TaskA1 solver = new TaskA1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA1 {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int[] p = new int[n];
        TreeMap<Integer, Integer> first = new TreeMap<Integer, Integer>();
        TreeMap<Integer, Integer> last = new TreeMap<Integer, Integer>();

        long[] sum = new long[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            if (!first.containsKey(p[i])) {
                first.put(p[i], i);
            }
            else {
                last.put(p[i], i);
            }

            if (i != 0) sum[i] = sum[i-1];
            if (p[i] > 0) sum[i] += p[i];
        }

        boolean f = true;
        long best = 0;
        int st = -1, end = -1;
        for (Integer k : first.navigableKeySet()) {
            if (last.containsKey(k)) {
                int tst = first.get(k);
                int tend = last.get(k);
                long s = sum[tend-1] - sum[tst] + 2*k;
                if (f || best < s) {
                    f = false;
                    best = s;
                    st = tst; end = tend;
                }
            }
        }

        ArrayList<Integer> rem = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if (i < st || i > end || (p[i] < 0 && i != st && i != end)) rem.add(i);
        }

        out.println(best + " " + rem.size());
        for (int i = 0; i < rem.size(); i++) {
            out.print(rem.get(i)+1);
            out.print(" ");
        }
        out.println();

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