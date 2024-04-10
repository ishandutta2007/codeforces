import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
		TaskF solver = new TaskF();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF {
    int[][] father;
    int[] dis, depth;
    int lastId;

    private void addNode(int x, int fa) {
        father[x][0] = fa;
        dis[x] = dis[fa] + 1;
        depth[x] = depth[fa] + 1;

        for (int i = 1; i <= 20; ++i) {
            father[x][i] = -1;
            if (father[x][i - 1] >= 0) {
                father[x][i] = father[father[x][i - 1]][i - 1];
            }
        }
    }

    private int lca(int x, int y) {
        if (depth[x] < depth[y]) {
            int t = x; x = y; y = t;
        }

        for (int i = 20; i >= 0; --i) {
            if (father[x][i] != -1 && depth[father[x][i]] >= depth[y]) {
                x = father[x][i];
            }
        }

        if (x == y) return x;
        for (int i = 20; i >= 0; --i) {
            if (father[x][i] != father[y][i]) {
                x = father[x][i];
                y = father[y][i];
            }
        }
        return father[x][0];
    }

    private int getDis(int x, int y) {
        return dis[x] + dis[y] - 2 * dis[lca(x, y)];
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        father = new int[4 + 2 * n][21];
        dis = new int[4 + 2 * n];
        depth = new int[4 + 2 * n];

        lastId = 1;

        Arrays.fill(father[0], -1);
        addNode(lastId++, 0);
        addNode(lastId++, 0);
        addNode(lastId++, 0);

        int p = 1, q = 2;
        for (int i = 0; i < n; ++i) {
            int v = in.nextInt() - 1;
            addNode(lastId++, v);
            addNode(lastId++, v);

            v = lastId - 1;
            int last = getDis(p, q), d1 = getDis(v, p), d2 = getDis(v, q);
            if (Math.max(d1, d2) > last) {
                if (d1 > d2) {
                    q = v;
                } else {
                    p = v;
                }
            }

            out.println(Math.max(last, Math.max(d1, d2)));
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