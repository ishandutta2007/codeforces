import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
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
		SoapTime solver = new SoapTime();
		solver.solve(1, in, out);
		out.close();
	}
}

class SoapTime {

    class Point implements Comparable<Point> {
        public int x, y;
        int dist;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        private int sign(int x) {
            return Integer.signum(x);
        }

        public int compareTo(Point arg0) {
            if (x != arg0.x) {
                return sign(x - arg0.x);
            }

            return sign(y - arg0.y);
        }
    }

	public void solve(int testNumber, InputReader in, PrintWriter out) {

        int n = in.nextInt();
        int m = in.nextInt();

        Point man[] = new Point[n];
        Point station[] = new Point[m];

        for (int i = 0; i < n; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            man[i] = new Point((x + y) * 2, (x - y) * 2);
        }

        for (int i = 0; i < m; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            station[i] = new Point((x + y) * 2, (x - y) * 2);
        }


        {
            Event events[] = new Event[n + m];
            for (int i = 0; i < n; ++i) {
                events[i] = new Event(man[i].x, man[i].y, i);
            }

            for (int i = 0; i < m; ++i) {
                events[i + n] = new Event(station[i].x, station[i].y);
            }

            int distToStation[] = findDistToStation(events, n);

            for (int i = 0; i < n; ++i) {
                man[i].dist = distToStation[i];
            }

            Arrays.sort(man, new Comparator<Point>() {
                @Override
                public int compare(Point o1, Point o2) {
                    return o1.dist - o2.dist;
                }
            });
        }

        int ans = man[n - 1].dist;

        int x1[] = new int[n];
        int y1[] = new int[n];
        int x2[] = new int[n];
        int y2[] = new int[n];

        x1[n - 1] = man[n - 1].x;
        y1[n - 1] = man[n - 1].y;
        x2[n - 1] = man[n - 1].x;
        y2[n - 1] = man[n - 1].y;

        for (int i = n - 2; i >= 0; --i) {
            x1[i] = Math.min(man[i].x, x1[i + 1]);
            x2[i] = Math.max(man[i].x, x2[i + 1]);
            y1[i] = Math.min(man[i].y, y1[i + 1]);
            y2[i] = Math.max(man[i].y, y2[i + 1]);
        }

        int leastTime[] = new int[n];
        for (int i = 0; i < n; ++i) {
            leastTime[i] = Math.max(x2[i] - x1[i], y2[i] - y1[i]) / 2;
            x1[i] += leastTime[i];
            x2[i] -= leastTime[i];
            y1[i] += leastTime[i];
            y2[i] -= leastTime[i];
        }

        ans = Math.min(ans, leastTime[0]);

        Event events[] = new Event[n * 4 + m];
        for (int i = 0; i < n; ++i) {
            events[4 * i + 0] = new Event(x1[i], y1[i], i);
            events[4 * i + 1] = new Event(x1[i], y2[i], i);
            events[4 * i + 2] = new Event(x2[i], y1[i], i);
            events[4 * i + 3] = new Event(x2[i], y2[i], i);
        }

        for (int i = 0; i < m; ++i) {
            events[4 * n + i] = new Event(station[i].x, station[i].y);
        }

        int disStationToRectangle[] = findDistToStation(events, n);

        RectangleEvent rectEvents[] = new RectangleEvent[n + m];
        for (int i = 0; i < n; ++i) {
            rectEvents[i] = new RectangleEvent(x1[i], y1[i], x2[i], y2[i], i);
        }

        for (int i = 0; i < m; ++i) {
            rectEvents[n + i] = new RectangleEvent(station[i].x, station[i].y);
        }

        int disStationToRectangle2[] = findRectangleDistToStation(rectEvents, n);
        for (int i = 0; i < n; ++i) {
            disStationToRectangle[i] = Math.min(disStationToRectangle2[i], disStationToRectangle[i]);
        }

        for (int i = n - 1; i > 0; --i) {
            {
                if (man[i - 1].dist == Integer.MAX_VALUE || disStationToRectangle[i] == Integer.MAX_VALUE) {
                    continue;
                }

                int need = (int)(((long)man[i - 1].dist + leastTime[i] + disStationToRectangle[i] + 1) / 2);
                need = Math.max(need, man[i - 1].dist);
                need = Math.max(leastTime[i], need);

                ans = Math.min(ans, need);
            }
        }

        out.println((ans + 1) / 2);
    }

    private int[] findRectangleDistToStation(RectangleEvent events[], int n) {
        int ret[] = new int[n];
        Arrays.fill(ret, Integer.MAX_VALUE);

        int tmp[] = new int[events.length * 2];

        for (int dir = 0; dir < 4; ++dir) {

            for (int i = 0; i < events.length; ++i) {
                tmp[i * 2] = events[i].x1;
                tmp[i * 2 + 1] = events[i].x2;
            }

            Order order = new Order(tmp);
            for (RectangleEvent e : events) {
                e.realX1 = order.get(e.x1);
                e.realX2 = order.get(e.x2);
            }

            IntervalTree tree = new IntervalTree(order.size());
            Arrays.sort(events);

            for (RectangleEvent e : events) {
                if (e.type == 0) {
                    tree.insert(e.realX1, e.y1);
                } else {
                    int l = Math.min(e.realX1, e.realX2);
                    int r = Math.max(e.realX2, e.realX1);
                    int max = tree.getMaxValue(l, r);
                    if (max == Integer.MIN_VALUE) {
                        continue;
                    }

                    if (max >= Math.min(e.y1, e.y2)) {
                        ret[e.updateId] = 0;
                    } else {
                        ret[e.updateId] = Math.min(ret[e.updateId], Math.min(e.y1, e.y2) - max);
                    }
                }
            }

            for (RectangleEvent e : events) {
                e.rotate();
            }
        }

        return ret;
    }

    private int[] findDistToStation(Event events[], int n) {
        int ret[] = new int[n];
        for (Event e : events) {
            int x = e.x;
            int y = e.y;
            e.x = (x + y);
            e.y = (x - y);
        }
        Arrays.fill(ret, Integer.MAX_VALUE);
        int tmp[] = new int[events.length];

        for (int step = 0; step < 4; ++step) {

            int ptr = 0;
            for (Event e : events) {
                tmp[ptr++] = e.x;
            }
            Order order = new Order(tmp);
            for (Event e : events) {
                e.queryX = order.get(e.x);
            }

            IntervalTree tree = new IntervalTree(order.size());
            Arrays.sort(events);

            for (Event e : events) {
                if (e.type == 0) {
                    tree.insert(e.queryX, e.x + e.y);
                } else {
                    int max = tree.getMaxValue(0, e.queryX);
                    if (max == Integer.MIN_VALUE) {
                        continue;
                    }
                    int delta = (int)(((long)e.x + e.y - max) / 2);
                    if (delta < ret[e.id]) {
                        ret[e.id] = delta;
                    }
                }
            }

            for (Event e : events) {
                int t = e.y;
                e.y = -e.x;
                e.x = t;
            }
        }

        return ret;
    }

    class RectangleEvent implements Comparable<RectangleEvent>{
        int type;
        int x1, y1, x2, y2;
        int realX1, realX2;
        int updateId;

        void rotate() {
            int t = y1;
            y1 = -x1;
            x1 = t;

            t = y2;
            y2 = -x2;
            x2 = t;
        }

        RectangleEvent(int x1, int y1, int x2, int y2, int updateId) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.type = 1;
            this.updateId = updateId;
        }

        RectangleEvent(int x, int y) {
            this.x1 = this.x2 = x;
            this.y1 = this.y2 = y;
            this.type = 0;
        }

        public int compareTo(RectangleEvent o) {
            int y = Math.max(y1, y2);
            int oy = Math.max(o.y1, o.y2);
            if (y != oy) {
                return y - oy;
            }

            int x = Math.max(x1, x2);
            int ox = Math.max(o.x1, o.x2);
                if (x != ox) {
                return x - ox;
            }

            return type - o.type;
        }
    }

    class IntervalTree {

        int size;
        int val[];

        IntervalTree(int length) {
            this.size = length;
            val = new int[length * 4 + 100];
            Arrays.fill(val, Integer.MIN_VALUE);
        }

        int getMaxValue(int left, int right, int l, int r, int x) {
            if (l <= left && r >= right) {
                return val[x];
            }
            int mid = (left + right) >> 1;
            int ret = Integer.MIN_VALUE;
            if (l <= mid) ret = getMaxValue(left, mid, l, r, x * 2);
            if (r > mid) ret = Math.max(ret, getMaxValue(mid + 1, right, l, r, x * 2 + 1));
            return ret;
        }

        int getMaxValue(int left, int right) {
             return getMaxValue(0, size - 1, left, right, 1);
        }

        void insert(int left, int right, int pos, int x, int value) {
            if (left == right) {
                val[x] = Math.max(val[x], value);
                return;
            }

            int mid = (left + right) >> 1;
            if (pos <= mid) {
                insert(left, mid, pos, x * 2, value);
            } else {
                insert(mid + 1, right, pos, x * 2 + 1, value);
            }

            val[x] = Math.max(val[x * 2], val[x * 2 + 1]);
        }

        void insert(int pos, int value) {
             insert(0, size - 1, pos, 1, value);
        }


    }

    class Order {

        private int arr[];

        Order(int orig[]) {
            int temp[] = orig.clone();
            Arrays.sort(temp);

            int total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    ++total;

            arr = new int[total];
            arr[0] = temp[0];
            total = 1;
            for (int i = 1; i < temp.length; ++i)
                if (temp[i] != temp[i - 1])
                    arr[total++] = temp[i];
        }

        public int size() {
            return arr.length;
        }

        public int get(int x) {
            return Arrays.binarySearch(arr, x);
        }
    }

    class Event implements Comparable<Event> {
        int type;
        int x, y, id;
        int queryX;

        Event(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
            this.type = 1;
        }

        Event(int x, int y) {
            this.x = x;
            this.y = y;
            this.type = 0;
        }

        public int compareTo(Event o) {
            if (y != o.y) {
                return y - o.y;
            }

            if (x != o.x) {
                return x - o.x;
            }

            return type - o.type;
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