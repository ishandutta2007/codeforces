import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    private static final int MAX_VALUE = 0x3F3F3F3F;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();

        int a = in.nextInt() - 1;
        int b = in.nextInt() - 1;
        int c = in.nextInt() - 1;

        char[][] adj = new char[n][];
        for (int i = 0; i < n; ++i) {
            adj[i] = in.next().toCharArray();
        }

        int[][][] dis = new int[n][n][n];
        long[][][] from = new long[n][n][n];
        ArrayUtils.fill(dis, MAX_VALUE);
        ArrayUtils.fill(from, -1);
        dis[a][b][c] = 0;
        dis[a][c][b] = 0;
        dis[b][a][c] = 0;
        dis[b][c][a] = 0;
        dis[c][a][b] = 0;
        dis[c][b][a] = 0;

        Queue<Integer> q = new LinkedList<Integer>();
        for (a = 0; a < n; ++a) {
            for (b = 0; b < n; ++b) {
                for (c = 0; c < n; ++c) {
                    if (dis[a][b][c] == 0) {
                        q.add(a * 10000 + b * 100 + c);
                    }
                }
            }
        }

        while (!q.isEmpty()) {
            int state = q.poll();

            a = state / 10000;
            b = state % 10000 / 100;
            c = state % 100;

            int[] states = new int[] {a, b, c};
            for (int move : states) {
                int[] others = new int[2];
                int count = 0;
                for (int other : states) {
                    if (other != move) {
                        others[count++] = other;
                    }
                }

                if (count != 2) {
                    throw new IllegalStateException();
                }

                for (int p = 0; p < n; ++p) {
                    if (p == a || p == b || p == c) continue;
                    if (adj[move][p] == adj[others[0]][others[1]]) {
                        if (dis[p][others[0]][others[1]] == MAX_VALUE) {
                            dis[p][others[0]][others[1]] = dis[a][b][c] + 1;
                            from[p][others[0]][others[1]] = state * 10000L + move * 100L + p;
                            q.add(p * 10000 + others[0] * 100 + others[1]);
                        }
                    }
                }
            }
        }

        int x = 0, y = 1, z = 2;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i != j && j != k && k != i && dis[i][j][k] < dis[x][y][z]) {
                        x = i;
                        y = j;
                        z = k;
                    }
                }
            }
        }

        if (dis[x][y][z] == MAX_VALUE) {
            out.println(-1);
            return;
        }

        int current = x * 10000 + y * 100 + z;
        ArrayList<IntPair> steps = new ArrayList<IntPair>();
        while (true) {
            int state = current;
            a = state / 10000;
            b = state % 10000 / 100;
            c = state % 100;

            if (from[a][b][c] == -1) {
                break;
            }

            int nextState = (int) (from[a][b][c] / 10000);
            steps.add(new IntPair((int) (from[a][b][c] % 10000 / 100), (int) (from[a][b][c] % 100)));
            current = nextState;
        }

        out.println(steps.size());
        for (int i = steps.size() - 1; i >= 0; --i) {
            out.println((steps.get(i).first + 1) + " " + (steps.get(i).second + 1));
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
    public static void fill(long[][] array, long value) {
        for (int i = 0; i < array.length; ++i) {
            Arrays.fill(array[i], value);
        }
    }

    public static void fill(long[][][] array, long value) {
        for (int i = 0; i < array.length; ++i) {
            fill(array[i], value);
        }
    }

    }

class IntPair extends ComparablePair<Integer, Integer> {

    public IntPair() {
        super();
    }

    public IntPair(Integer first, Integer second) {
        super(first, second);
    }
}

class ComparablePair<F extends Comparable<F>, S extends Comparable<S>>
        extends Pair<F, S> implements Comparable<ComparablePair<F, S>> {

    public ComparablePair() {
        super();
    }

    public ComparablePair(F first, S second) {
        super(first, second);
    }

    public int compareTo(ComparablePair<F, S> to) {
        if (this.first.compareTo(to.first) != 0) {
            return this.first.compareTo(to.first);
        }
        return this.second.compareTo(to.second);
    }
}

class Pair<F, S> {
    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public Pair() {
        this(null, null);
    }

    public boolean equals(Object o) {
        Pair<F, S> to = (Pair<F, S>) o;
        return first == to.first && second == to.second;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }

    public String toString() {
        return "[" + first.toString() + " " + second.toString() + "]";
    }
}