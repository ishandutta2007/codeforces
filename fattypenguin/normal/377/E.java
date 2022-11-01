import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.ArrayDeque;
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
        int n = in.nextInt();
        long s = in.nextLong();

        IntPair[] cookies = new IntPair[n];
        for (int i = 0; i < n; ++i) {
            int speed = in.nextInt();
            int price = in.nextInt();
            cookies[i] = IntPair.of(price, speed);
        }

        Arrays.sort(cookies, new Comparator<IntPair>() {
            @Override
            public int compare(IntPair p1, IntPair p2) {
                if (p1.first != p2.first) return p1.first - p2.first;
                return p2.second - p1.second;
            }
        });

        List<IntPair> usefulCookies = new ArrayList<IntPair>();
        for (int i = 0, last = Integer.MIN_VALUE; i < n; ++i) {
            if (cookies[i].second > last) {
                last = cookies[i].second;
                usefulCookies.add(cookies[i]);
            }
        }

        n = usefulCookies.size();
        cookies = usefulCookies.toArray(new IntPair[n]);

        ArrayDeque<Line> activeLines = new ArrayDeque<Line>();
        long headTime = 0;
        for (int i = 0; i < n; ++i) {
            IntPair cookie = cookies[i];
            if (cookie.first >= s) break;
            if (activeLines.isEmpty()) {
                if (cookie.first > 0) {
                    throw new IllegalArgumentException();
                }
                activeLines.addLast(new Line(new IntPoint(0, 0), cookie.second));
                continue;
            }
//            out.println("activeLines.size() = " + activeLines.size());

            while (activeLines.size() > 1) {
                long needTime = (cookie.first - activeLines.getFirst().basePoint.y  + activeLines.getFirst().dv - 1)
                        / activeLines.getFirst().dv + activeLines.getFirst().basePoint.x;

                Line first = activeLines.pollFirst();
                if (needTime >= activeLines.getFirst().leapTime) {
                    // do nothing.
                } else {
                    activeLines.addFirst(first);
                    break;
                }
            }

//            out.println("activeLines.size() = " + activeLines.size());

            IntPoint current;

            {
                long needTime = (cookie.first - activeLines.getFirst().basePoint.y  + activeLines.getFirst().dv - 1)
                        / activeLines.getFirst().dv;
                current = new IntPoint(needTime + activeLines.getFirst().basePoint.x,
                        activeLines.getFirst().basePoint.y + activeLines.getFirst().dv * needTime - cookie.first);
            }

            Line line = new Line(current, cookie.second);
            while (true) {
                long leapTime = line.getLeapTime(activeLines.getLast());
                if (activeLines.size() > 1 && leapTime <= activeLines.getLast().leapTime) {
                    activeLines.removeLast();
                } else {
                    line.leapTime = leapTime;
                    activeLines.addLast(line);
                    break;
                }
            }

//            out.println("i = " + i + " current = " + current + " leapTime = " + activeLines.getLast().leapTime + " size = " + activeLines.size());
        }

        long answer = Long.MAX_VALUE;

        while (activeLines.size() > 1) {
            long needTime = (s - activeLines.getFirst().basePoint.y  + activeLines.getFirst().dv - 1)
                    / activeLines.getFirst().dv + activeLines.getFirst().basePoint.x;

            Line first = activeLines.pollFirst();
            if (needTime >= activeLines.getFirst().leapTime) {
                // do nothing.
            } else {
                activeLines.addFirst(first);
                break;
            }
        }

        {
            long needTime = (s - activeLines.getFirst().basePoint.y + activeLines.getFirst().dv - 1)
                    / activeLines.getFirst().dv;
            answer = needTime + activeLines.getFirst().basePoint.x;
        }

        out.println(answer);
    }

    private static class Line {
        IntPoint basePoint;
        long dv, leapTime;

        Line(IntPoint basePoint, long dv) {
            this.basePoint = basePoint;
            this.dv = dv;
        }

        public long getY(long time) {
            if (time < basePoint.x) {
                throw new IllegalArgumentException();
            }

            return basePoint.y + (time - basePoint.x) * dv;
        }

        public long getLeapTime(Line to) {
            if (dv < to.dv) {
                throw new IllegalArgumentException();
            }

            long his = to.getY(basePoint.x);
            if (his <= basePoint.y) {
                if (to.basePoint.x != basePoint.x) {
                    throw new IllegalArgumentException();
                }
                return basePoint.x;
            }

            long delta = dv - to.dv;
            return (his - basePoint.y + delta - 1) / delta + basePoint.x;
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    }

class IntPair extends ComparablePair<Integer, Integer> {

    public static IntPair of(Integer first, Integer second) {
        return new IntPair(first, second);
    }

    public IntPair() {
        super();
    }

    public IntPair(Integer first, Integer second) {
        super(first, second);
    }
}

class IntPoint implements Comparable<IntPoint>, Point {

    public long x, y;

    public IntPoint(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public long det(IntPoint o) {
        return x * o.y - y * o.x;
    }


    public int compareTo(IntPoint point) {
        return Long.signum(det(point));
    }

    public String toString() {
        return "[" + x + ", " + y + "]";
    }

    public IntPoint clone() {
        return new IntPoint(x, y);
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

interface Point {
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
        return first.equals(to.first) && second.equals(to.second);
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