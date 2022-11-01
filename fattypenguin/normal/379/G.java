import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskG solver = new TaskG();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskG {

    private static final int MAX_VALUE = 0x3F3F3F3F;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), m = in.nextInt();
        first = new Edge[n];
        for (int i = 0; i < m; ++i) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            new Edge(u, v);
            new Edge(v, u);
        }

        low = new int[n];
        dfn = new int[n];
        timeStamp = 0;

        stack = new Stack<Integer>();
        ways = new int[n][][];

        go(0);
        for (int i = 0; i <= n; ++i) {
            if (i > 0) out.print(" ");
            int answer = -MAX_VALUE;
            for (int color = 0; color < 3; ++color) {
                answer = Math.max(answer, ways[0][i][color]);
            }
            out.print(answer);
        }
        out.println();
    }

    private int[] low;
    private int[] dfn;
    private int timeStamp;

    private Stack<Integer> stack;

    private int[][][] ways;

    private int[][] mergeComponent(int[][][] dps) {
        int[][][] res = new int[dps[0].length][3][3];
        ArrayUtils.fill(res, -MAX_VALUE);
        for (int i = 0; i < dps[0].length; ++i) {
            for (int color = 0; color < 3; ++color) {
                res[i][color][color] = dps[0][i][color];
            }
        }
        for (int iter = 1; iter < dps.length; ++iter) {
            int[][] current = dps[iter];
            int[][][] next = new int[res.length + current.length - 1][3][3];
            ArrayUtils.fill(next, -MAX_VALUE);
            for (int prevSize = 0; prevSize < res.length; ++prevSize) {
                for (int lastColor = 0; lastColor < 3; ++lastColor) {
                    for (int firstColor = 0; firstColor < 3; ++firstColor) {
                        if (res[prevSize][lastColor][firstColor] == -MAX_VALUE) continue;
                        for (int nowSize = 0; nowSize < current.length; ++nowSize) {
                            for (int nowColor = 0; nowColor < 3; ++nowColor) {
                                if (current[nowSize][nowColor] == -MAX_VALUE) continue;
                                if (nowColor < 2 && lastColor < 2 && nowColor != lastColor) continue;
                                if (iter + 1 == dps.length
                                        && nowColor < 2 && firstColor < 2 && nowColor != firstColor) continue;
                                next[prevSize + nowSize][nowColor][firstColor] = Math.max(
                                        next[prevSize + nowSize][nowColor][firstColor],
                                        res[prevSize][lastColor][firstColor] + current[nowSize][nowColor]);
                            }
                        }
                    }
                }
            }
            res = next;
        }

        int[][] result = new int[res.length][3];
        ArrayUtils.fill(result, -MAX_VALUE);
        for (int i = 0; i < res.length; ++i) {
            for (int lastColor = 0; lastColor < 3; ++lastColor) {
                for (int firstColor = 0; firstColor < 3; ++firstColor) {
                    result[i][firstColor] = Math.max(result[i][firstColor], res[i][lastColor][firstColor]);
                }
            }
        }

        return result;
    }

    private void go(int x) {
        int[][] dp = new int[2][3];
        ArrayUtils.fill(dp, -MAX_VALUE);
        dp[0][2] = 0;
        dp[0][1] = 1;
        dp[1][0] = 0;

        stack.add(x);
        low[x] = dfn[x] = ++timeStamp;
        for (Edge e = first[x]; e != null; e = e.next) {
            if (dfn[e.to] == 0) {
                go(e.to);
                low[x] = Math.min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    ArrayList<int[][]> block = new ArrayList<int[][]>();
                    block.add(dp);
                    while (true) {
                        int top = stack.pop();
                        block.add(ways[top]);
                        ways[top] = null;
                        if (top == e.to) {
                            break;
                        }
                    }

                    dp = mergeComponent(block.toArray(new int[block.size()][][]));
                }
            } else {
                low[x] = Math.min(low[x], dfn[e.to]);
            }
        }
        ways[x] = dp;
    }

    private Edge first[];

    private class Edge {
        int to;
        Edge next;

        public Edge(int from, int to) {
            this.to = to;
            this.next = first[from];
            first[from] = this;
        }
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }

class ArrayUtils {


    public static void fill(int[][] array, int value) {
        for (int i = 0; i < array.length; ++i) {
            Arrays.fill(array[i], value);
        }
    }

    public static void fill(int[][][] array, int value) {
        for (int i = 0; i < array.length; ++i) {
            fill(array[i], value);
        }
    }

    }