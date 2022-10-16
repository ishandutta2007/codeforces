import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
 * @author ffao
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
    int[][][] gr = new int[110][110][3];

    public int grundy(int l, int r, int o) {
        if (gr[l][r][o] != -1) return gr[l][r][o];
        if (l == 0 && r == 0) return 0;

        TreeSet<Integer> seen = new TreeSet<Integer>();
        for (int i = 0; i < l; i++) {
            int left_remain_top = i;
            int right_remain_top = Math.max(i-1-o, 0);

            //System.out.println("left " + i + " goes to " + left_remain_top + " " + right_remain_top + " " + o + " from  " + l + " " + r + " " + o);
            int f = grundy(left_remain_top, right_remain_top, o);

            int left_remain_bottom = l - i - 1;
            int right_remain_bottom = Math.max(0, r - (i+1) - 1 + o);

            //System.out.println("left " + i + " bottom goes to " + left_remain_bottom + " " + right_remain_bottom + " " + o + " from  " + l + " " + r + " " + o);
            int s = grundy(left_remain_bottom, right_remain_bottom, 1);

            seen.add(f ^ s);

        }

        for (int i = 0; i < r; i++) {
            int right_remain_top = i;
            int left_remain_top = Math.max(i-1+o, 0);

            int f = grundy(left_remain_top, right_remain_top, o);

            int right_remain_bottom = r - i - 1;
            int left_remain_bottom = Math.max(0, l - (i+1) - 1 - o);

            int s = grundy(right_remain_bottom, left_remain_bottom, 1);

            seen.add(f ^ s);
        }

        for (int i = 0; ; i++) {
            if (!seen.contains(i)) {
                //System.out.println(l + " " + r + " " + o + " -> " + i);
                return gr[l][r][o]=i;
            }
        }

    }

    public void solve(int testNumber, Parser in, OutputWriter out) {
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                Arrays.fill(gr[i][j], -1);
            }
        }

        int n = in.nextInt();
        int m = in.nextInt();
        boolean[][] b = new boolean[n+10][4];

        for (int i = 0; i < m; i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            b[x][y] = true;
            for (int ot = x-1; ot <= x+1; ot++) {
                if (ot <= 0 || ot > n) continue;
                b[ot][3-y] = true;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int o;

            if (!b[i][1]) {
                int left = 1;
                for (int j = i+1; j <= n; j++) {
                    if (!b[j][1]) left++;
                    else break;
                }

                int right = 0;
                if (!b[i][2]) o = 0;
                else o = 1;
                for (int j = i+o; j <= n; j++) {
                    if (!b[j][2]) right++;
                    else break;
                }

                //System.out.println("LASK FOR " + left + " " + right + " " + o);
                ans ^= grundy(left, right, o);

                i = Math.max(i + o + right - 1, i + left - 1);
            }

            else if (!b[i][2]) {
                int left = 1;
                for (int j = i+1; j <= n; j++) {
                    if (!b[j][2]) left++;
                    else break;
                }

                int right = 0;
                o = 1;
                for (int j = i+o; j <= n; j++) {
                    if (!b[j][1]) right++;
                    else break;
                }

                //System.out.println("ASK FOR " + left + " " + right + " " + o);
                ans ^= grundy(left, right, o);

                i = Math.max(i + o + right - 1, i + left - 1);
            }
        }

        if (ans != 0) out.println("WIN");
        else out.println("LOSE");
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