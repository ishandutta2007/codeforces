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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] at = new int[n];
        for (int i = 0; i < n; ++i) {
            at[i] = in.nextInt();
        }

        int t = in.nextInt();

        IntPair[] events = new IntPair[n * 2];
        for (int i = 0; i < n; ++i) {
            events[i * 2] = new IntPair(at[i] - t, 1);
            events[i * 2 + 1] = new IntPair(at[i] + 1, -1);
        }

        int sum = 0, answer = 0;
        Arrays.sort(events);
        for (IntPair event : events) {
            sum += event.second;
            answer = Math.max(answer, sum);
        }

        out.println(answer);
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