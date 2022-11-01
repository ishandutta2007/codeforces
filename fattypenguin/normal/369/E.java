import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt(), q = in.nextInt();
        ArrayList<Event> events = new ArrayList<Event>();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; ++i) {
            l[i] = in.nextInt();
            r[i] = in.nextInt();
            events.add(new Event(l[i], 1, -1, 0, l[i], r[i]));
            events.add(new Event(r[i], -1, 1, 0, l[i], r[i]));
        }
        int[] answer = new int[q];
        int[] last = new int[q];
        Arrays.fill(last, -1);
        for (int i = 0; i < q; ++i) {
            int mi = in.nextInt();
            for (int j = 0; j < mi; ++j) {
                int at = in.nextInt();
                events.add(new Event(at, 0, 0, i));
            }
        }

        Event[] allEvents = events.toArray(new Event[events.size()]);
        Arrays.sort(allEvents);

        BitIndexedTree tree1, tree2;
        tree1 = new BitIndexedTree(1000010);
        tree2 = new BitIndexedTree(1000010);

        for (Event event : allEvents) {
            if (event.priority != 0) {
                tree1.update(event.l, event.delta);
                tree2.update(event.r, event.delta);
                continue;
            }
            answer[event.which] += tree2.getValue(1000003) - tree2.getValue(event.at - 1);
//            out.println("answer = " + answer[event.which] + " which = " + event.which + " at = " + event.at);
            if (last[event.which] != -1) {
                answer[event.which] -= tree1.getValue(last[event.which]);
            }
            last[event.which] = event.at;
        }

        for (int i = 0; i < q; ++i) {
            out.println(answer[i]);
        }

    }
    class Event implements Comparable<Event> {
        int at;
        int delta;
        int priority;
        int which;
        int l, r;
        Event(int at, int delta, int priority, int which) {
            this.at = at;
            this.delta = delta;
            this.priority = priority;
            this.which = which;
            l = r = -1;
        }
        Event(int at, int delta, int priority, int which, int l, int r) {
            this.at = at;
            this.delta = delta;
            this.priority = priority;
            this.which = which;
            this.l = l;
            this.r = r;
        }

        public int compareTo(Event event) {
            if (at != event.at) return at - event.at;
            return priority - event.priority;
        }
    }

    class BitIndexedTree {
        private int arr[];
        private int size;

        BitIndexedTree(int size) {
            this.size = size;
            arr = new int[size + 10];
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

        public int getValue(int x) {
            ++x;
            int ret = 0;
            while (x > 0) {
                ret += arr[x];
                x -= lowbit(x);
            }

            return ret;
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