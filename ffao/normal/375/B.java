import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
    int n, m;
    int[][] right;
    String[] matrix;

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        m = in.nextInt();

        matrix = new String[n];
        right = new int[n][m];

        int ans = 0;

        for (int i = 0; i < n; i++) {
            matrix[i] = in.next();
            int last = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i].charAt(j) == '0') {
                    while (last <= j) {
                        right[i][last] = j-last;
                        last++;
                    }
                }
            }

            while (last <= m-1) {
                right[i][last] = m-last;
                last++;
            }
        }

        int[] count = new int[m+2];
        for (int j = 0; j < m; j++) {
            Arrays.fill(count, 0);
            for (int i = 0; i < n; i++) {
                count[right[i][j]]++;
            }
            
            int tot = 0;
            for (int i = m; i >= 0; i--) {
                tot += count[i];
                ans = Math.max(ans, i * tot);
            }
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