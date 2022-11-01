import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.HashSet;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        int m = in.nextInt();
        Interval[] query = new Interval[m];
        for (int i = 0; i < m; ++i) {
            query[i] = new Interval(in.nextInt() - 1, in.nextInt() - 1, i);
        }
        Arrays.sort(query, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.r - i2.r;
            }
        });

        int[] result = new int[m];
        int[] previous = new int[n];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ++i) {
            int value = a[i];
            previous[i] = map.containsKey(value) ? map.get(value) : -1;
            map.put(value, i);
        }

        Interval[] maxIntervals = new Interval[n];
        Set<Integer> visited = new HashSet<Integer>();
        for (int i = n - 1; i >= 0; --i) {
            if (visited.contains(a[i])) continue;
            visited.add(a[i]);
            int now = i, next = n - 1;
            while (now != -1) {
                int prevNow = now;
                while (previous[now] != -1 && previous[previous[now]] != -1
                        && now - previous[now] == previous[now] - previous[previous[now]]) {
                    now = previous[now];
                }
                int newL;
                if (previous[now] == -1) {
                    newL = 0;
                } else if (previous[previous[now]] == -1) {
                    newL = 0;
                } else {
                    newL = previous[previous[now]] + 1;
                }
                int newR = next;

                int current = prevNow;
                while (true) {
                    maxIntervals[current] = new Interval(newL, newR, current);
                    if (current == now) break;
                    current = previous[current];
                }

                next = now - 1;
                now = previous[now];
            }
        }

        int pointer = 0;
        BitIndexedTree tree = new BitIndexedTree(n);
        IntervalTree intervalTree = new IntervalTree(n);
        Interval[] maxIntervalsByRightPoint = maxIntervals.clone();
        Arrays.sort(maxIntervalsByRightPoint, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.r - i2.r;
            }
        });

        map.clear();
        int rightPointer = 0;
        for (int i = 0; i < n; ++i) {
            intervalTree.insert(i, maxIntervals[i].l);
            while (rightPointer < maxIntervalsByRightPoint.length
                    && maxIntervalsByRightPoint[rightPointer].r + 1 == i) {
                intervalTree.insert(maxIntervalsByRightPoint[rightPointer++].id, Integer.MAX_VALUE);
            }
            int value = a[i];
            if (map.containsKey(value)) {
                tree.update(map.get(value), -1);
            }
            tree.update(i, 1);
            map.put(value, i);

            while (pointer < query.length && query[pointer].r == i) {
                int queryId = query[pointer].id;
                result[queryId] = tree.getSum(i) - tree.getSum(query[pointer].l - 1) + 1;
                if (intervalTree.getMinValue(query[pointer].l, i) <= query[pointer].l) {
                    --result[queryId];
                }
                ++pointer;
            }
        }
        for (int i = 0; i < m; ++i) {
            out.println(result[i]);
        }
    }

    private static class Interval implements Comparable<Interval>{
        public int l, r, id;
        public Interval(int l, int r) {
            this(l, r, 0);
        }

        public Interval(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
        }

        public int compareTo(Interval interval) {
            if (l != interval.l) return l - interval.l;
            if (r != interval.r) return r - interval.r;
            return hashCode() - interval.hashCode();
        }
    }

    private static class BitIndexedTree {
        private int arr[];
        private int size;

        BitIndexedTree(int size) {
            this.size = size;
            arr = new int[size + 1];
        }

        private int lowbit(int x) {
            return x & -x;
        }

        public void update(int x, int y) {
            ++x;
            while (x <= size) {
                arr[x] += y;
                x += lowbit(x);
            }
        }

        public int getSum(int x) {
            ++x;
            int ret = 0;
            while (x > 0) {
                ret += arr[x];
                x -= lowbit(x);
            }

            return ret;
        }
    }

    private static class IntervalTree {
        private int size;
        private int val[];

        public IntervalTree(int length) {
            this.size = length;
            val = new int[length * 4 + 100];
            Arrays.fill(val, Integer.MAX_VALUE);
        }

        int getMinValue(int left, int right, int l, int r, int x) {
            if (l <= left && r >= right) {
                return val[x];
            }
            int mid = (left + right) >> 1;
            int ret = Integer.MAX_VALUE;
            if (l <= mid) ret = getMinValue(left, mid, l, r, x * 2);
            if (r > mid) ret = Math.min(ret, getMinValue(mid + 1, right, l, r, x * 2 + 1));
            return ret;
        }

        int getMinValue(int left, int right) {
            return getMinValue(0, size - 1, left, right, 1);
        }

        void insert(int left, int right, int pos, int x, int value) {
            if (left == right) {
                val[x] = value;
                return;
            }

            int mid = (left + right) >> 1;
            if (pos <= mid) {
                insert(left, mid, pos, x * 2, value);
            } else {
                insert(mid + 1, right, pos, x * 2 + 1, value);
            }

            val[x] = Math.min(val[x * 2], val[x * 2 + 1]);
        }

        void insert(int pos, int value) {
            insert(0, size - 1, pos, 1, value);
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