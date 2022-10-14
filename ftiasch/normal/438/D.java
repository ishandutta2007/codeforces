import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    int getLocation(int l, int r) {
        return l + r | (l != r ? 1 : 0);
    }

    long[] sum;
    Pair[] max;

    long getSum(int l, int r, int a, int b) {
        if (b < l || r < a) {
            return 0;
        }
        int id = getLocation(l, r);
        if (a <= l && r <= b) {
            return sum[id];
        }
        int m = l + r >> 1;
        return getSum(l, m, a, b) + getSum(m + 1, r, a, b);
    }

    Pair getMax(int l, int r, int a, int b) {
        if (b < l || r < a) {
            return new Pair(-1, -1);
        }
        int id = getLocation(l, r);
        if (a <= l && r <= b) {
            return max[id];
        }
        int m = l + r >> 1;
        return myMax(getMax(l, m, a, b), getMax(m + 1, r, a, b));
    }

    void modify(int l, int r, int k, int v) {
        if (k < l || r < k) {
            return;
        }
        int id = getLocation(l, r);
        if (l == r) {
            sum[id] = v;
            max[id] = new Pair(v, l);
        } else {
            int m = l + r >> 1;
            modify(l, m, k, v);
            modify(m + 1, r, k, v);
            sum[id] = sum[getLocation(l, m)] + sum[getLocation(m + 1, r)];
            max[id] = myMax(max[getLocation(l, m)], max[getLocation(m + 1, r)]);
        }
    }

    public void run() {
        try {
            int n = reader.nextInt();
            int m = reader.nextInt();
            sum = new long[n << 1];
            max = new Pair[n << 1];
            Arrays.fill(max, new Pair(-1, -1));
            int[] a = new int[n];
            for (int i = 0; i < n; ++ i) {
                a[i] = reader.nextInt();
                modify(0, n - 1, i, a[i]);
            }
            while (m > 0) {
                m --;
                int t = reader.nextInt();
                if (t == 1) {
                    int l = reader.nextInt() - 1;
                    int r = reader.nextInt() - 1;
                    writer.println(getSum(0, n - 1, l, r));
                } else if (t == 2) {
                    int l = reader.nextInt() - 1;
                    int r = reader.nextInt() - 1;
                    int x = reader.nextInt();
                    while (true) {
                        Pair mp = getMax(0, n - 1, l, r);
                        if (mp.max < x) {
                            break;
                        }
                        int i = mp.index;
                        modify(0, n - 1, i, mp.max % x);
                    }
                } else if (t == 3) {
                    int k = reader.nextInt() - 1;
                    int x = reader.nextInt();
                    modify(0, n - 1, k, x);
                } else {
                    assert false;
                }
            }
        } catch (IOException ex) {
        }
        writer.close();
    }

    Pair myMax(Pair a, Pair b) {
        return a.compareTo(b) > 0 ? a : b;
    }

    class Pair implements Comparable {
        Pair(int max, int index) {
            this.max   = max;
            this.index = index;
        }

        @Override
        public int compareTo(Object other) {
            return max - ((Pair)other).max;
        }

        int max, index;
    }

    Main() {
        reader = new InputReader(System.in);
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Main().run();
    }

    private void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    private InputReader reader;
    private PrintWriter writer;
}

class InputReader {
    InputReader(InputStream in) {
        reader    = new BufferedReader(new InputStreamReader(in));
        tokenizer = new StringTokenizer("");
    }

    private String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    public Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private BufferedReader  reader;
    private StringTokenizer tokenizer;
}