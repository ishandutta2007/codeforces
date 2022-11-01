import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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

    class Event implements Comparable<Event> {
        int at, t;
        Event(int at, int t) {
            this.at = at;
            this.t = t;
        }

        public int compareTo(Event event) {
            if (at != event.at) return at - event.at;
            return event.t - t;
        }
    }

    class Query implements Comparable<Query> {
        int at, t;

        Query(int at, int t) {
            this.at = at;
            this.t = t;
        }

        public int compareTo(Query query) {
            return t - query.t;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        TreeMap<Integer, Integer> set = new TreeMap<Integer, Integer>();
        int m = in.nextInt();
        int n = in.nextInt();
        int l[] = new int[n],
            r[] = new int[n],
            t[] = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            t[i] = in.nextInt() + 1;
        }

        Query q[] = new Query[m];
        for (int i = 0; i < m; ++i) {
            q[i] = new Query(i, in.nextInt() + 1);
        }

        Event events[] = new Event[2 * n];
        for (int i = 0; i < n; ++i) {
            events[2 * i] = new Event(l[i], t[i]);
            events[2 * i + 1] = new Event(r[i], -t[i]);
        }

        Arrays.sort(events);
        ArrayList<Integer> left, right, time;
        left = new ArrayList<Integer>();
        right = new ArrayList<Integer>();
        time = new ArrayList<Integer>();

        for (int i = 0; i < events.length; ) {

            if (i != 0 && events[i - 1].at != events[i].at && set.size() > 0) {
                left.add(events[i - 1].at);
                right.add(events[i].at);
                time.add(set.firstKey());
            }

            int j = i;
            while (j < events.length && events[i].at == events[j].at && Long.signum(events[i].t) == Long.signum(events[j].t)) {
                int val = events[j].t, key = Math.abs(val);
                int lastTime = 0;

                if (set.containsKey(key)) {
                    lastTime = set.get(key);
                    set.remove(key);
                }

                if (val < 0) {
                    --lastTime;
                } else {
                    ++lastTime;
                }

                if (lastTime != 0) {
                    set.put(key, lastTime);
                }

                ++j;
            }

            i = j;
        }

        Arrays.sort(q);

        events = new Event[left.size() * 2];
        for (int i = 0; i < left.size(); ++i) {
            events[i * 2] = new Event(time.get(i) - left.get(i), -(i + 1));
            events[i * 2 + 1] = new Event(time.get(i) - right.get(i), i + 1);
        }

        int numSegments = 0;
        long work = 0, fixed = 0;
        Arrays.sort(events);
        int ptrEvents = 0;
        long ans[] = new long[m];
        for (int i = 0; i < q.length; ++i) {
            while (ptrEvents < events.length && events[ptrEvents].at <= q[i].t) {
                int index = Math.abs(events[ptrEvents].t) - 1;
                work += (right.get(index) - time.get(index)) * Long.signum(events[ptrEvents].t);
                numSegments += Long.signum(events[ptrEvents].t);
                if (events[ptrEvents].t < 0) {
                    fixed += right.get(index) - left.get(index);
                }
                ++ptrEvents;
            }

             ans[q[i].at] = work + q[i].t * (long)numSegments + fixed;
        }

        for (int i = 0; i < m; ++i) {
            out.println(ans[i]);
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