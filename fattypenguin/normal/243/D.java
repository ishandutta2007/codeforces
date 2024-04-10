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
		Cubes solver = new Cubes();
		solver.solve(1, in, out);
		out.close();
	}
}

class Cubes {

    private static long vx, vy; // vertical vector
    private static long ux, uy; // horizontal vector

    class Cube implements Comparable<Cube>{
        long low;
        long left, right;

        int height;

        Cube(long x, long y, int height) {
            this.low = Long.MAX_VALUE;
            this.left = Long.MAX_VALUE;
            this.right = Long.MIN_VALUE;
            this.height = height;

            for (long dx = 0; dx <= 1; ++dx) {
                for (long dy = 0; dy <= 1; ++dy) {
                    long realX = x + dx;
                    long realY = y + dy;

                    long imagY = realX * vx + realY * vy;
                    long imagX = realX * ux + realY * uy;

                    this.low = Math.min(this.low, imagY);
                    this.left = Math.min(this.left, imagX);
                    this.right = Math.max(this.right, imagX);
                }
            }
        }


        public int compareTo(Cube o) {
            return Long.signum(this.low - o.low);
        }
    }

    class Order {

        private long arr[];

        Order(long orig[]) {
            long temp[] = orig.clone();
            Arrays.sort(temp);

            int total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    ++total;

            arr = new long[total];
            arr[0] = temp[0];
            total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    arr[total++] = temp[i];
        }

        public int size() {
            return arr.length;
        }

        public int get(long x) {
            return Arrays.binarySearch(arr, x);
        }

        }

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        vx = in.nextInt();
        vy = in.nextInt();
        ux = vy;
        uy = -vx;

        Cube[] cubes = new Cube[n * n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int h = in.nextInt();
                cubes[n * i + j] = new Cube(i, j, h);
            }
        }

        Arrays.sort(cubes);
        long diffX[] = new long[n * n * 2];
        for (int i = 0; i < n * n; ++i) {
            diffX[i * 2] = cubes[i].left;
            diffX[i * 2 + 1] = cubes[i].right;
        }

        Order order = new Order(diffX);
        IntervalTree tree = new IntervalTree(order.size());

        long ans = 0;
        for (Cube cube : cubes) {
            int l = order.get(cube.left), r = order.get(cube.right) - 1;
            int minH = tree.getMin(l, r);
            if (minH <= cube.height) {
                ans += cube.height - minH;
            }
            tree.update(l, r, cube.height);
        }

        out.println(ans);
	}

    class IntervalTree {
        private int cover[];
        private int minimum[];
        private int length;

        IntervalTree(int length) {
            this.length = length;
            minimum = new int[length * 4 + 100];
            cover = new int[length * 4 + 100];
        }

        private void push_down(int x) {
            if (cover[x] != 0) {
                minimum[x * 2] = Math.max(cover[x], minimum[x * 2]);
                cover[x * 2] = Math.max(cover[x], cover[x * 2]);

                minimum[x * 2 + 1] = Math.max(cover[x], minimum[x * 2 + 1]);
                cover[x * 2 + 1] = Math.max(cover[x], cover[x * 2 + 1]);

                cover[x] = 0;
            }
        }

        private void update(int left, int right, int l, int r, int x, int h) {
            if (h <= minimum[x]) {
                return;
            }

            if (l <= left && r >= right) {
                minimum[x] = Math.max(minimum[x], h);
                cover[x] = Math.max(cover[x], h);
                return;
            }

            push_down(x);
            int mid = (left + right) >> 1;
            if (l <= mid) update(left, mid, l, r, x * 2, h);
            if (r > mid) update(mid + 1, right, l, r, x * 2 + 1, h);

            minimum[x] = Math.min(minimum[x * 2], minimum[x * 2 + 1]);
        }

        public void update(int l, int r, int h) {
            update(0, length - 1, l, r, 1, h);
        }

        private int getMin(int left, int right, int l, int r, int x) {
            if (l <= left && r >= right) {
                return minimum[x];
            }

            push_down(x);
            int mid = (left + right) >> 1;
            int ret = Integer.MAX_VALUE;

            if (l <= mid) ret = getMin(left, mid, l, r, x * 2);
            if (r > mid) ret = Math.min(ret, getMin(mid + 1, right, l, r, x * 2 + 1));

            return ret;
        }

        public int getMin(int l, int r) {
            return getMin(0, length - 1, l, r, 1);
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
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }