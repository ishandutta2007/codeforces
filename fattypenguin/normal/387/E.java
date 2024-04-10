import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Stack;
import java.util.ArrayList;
import java.util.Vector;
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
        int k = in.nextInt();

        int[] arr = in.nextIntArray(n);
        for (int i = 0; i < arr.length; ++i) {
            --arr[i];
        }

        int[] at = ArrayUtils.reversePermutation(arr);
        int[] b = in.nextIntArray(k);
        for (int i = 0; i < b.length; ++i) {
            --b[i];
        }

        boolean[] occurance = new boolean[arr.length];
        for (int i : b) {
            occurance[i] = true;
        }

        int[] leftRadius = new int[n];
        int[] rightRadius = new int[n];

        {
            List<IntPair> stack = new ArrayList<IntPair>();
            for (int i = 0; i < n; ++i) {
                int low = 0, high = stack.size() - 1;
                while (low < high) {
                    int mid = ((low + high) >> 1) + 1;
                    if (stack.get(mid).first <= arr[i]) {
                        low = mid;
                    } else {
                        high = mid - 1;
                    }
                }

                if (stack.isEmpty() || stack.get(low).first > arr[i]) {
                    leftRadius[i] = -1;
                } else {
                    leftRadius[i] = stack.get(low).second + 1;
                }

                if (occurance[arr[i]]) {
                    if (stack.isEmpty() || stack.get(low).first > arr[i]) {
                        stack.clear();
                    }
                    while (stack.size() > low + 1) {
                        stack.remove(stack.size() - 1);
                    }
                    stack.add(IntPair.of(arr[i], i));
                }
            }
        }

        {
            Stack<IntPair> stack = new Stack<IntPair>();
            for (int i = n - 1; i >= 0; --i) {
                int low = 0, high = stack.size() - 1;
                while (low < high) {
                    int mid = ((low + high) >> 1) + 1;
                    if (stack.get(mid).first <= arr[i]) {
                        low = mid;
                    } else {
                        high = mid - 1;
                    }
                }

                if (stack.isEmpty() || stack.get(low).first > arr[i]) {
                    rightRadius[i] = n;
                } else {
                    rightRadius[i] = stack.get(low).second - 1;
                }

                if (occurance[arr[i]]) {
                    if (stack.isEmpty() || stack.get(low).first > arr[i]) {
                        stack.clear();
                    }
                    while (stack.size() > low + 1) {
                        stack.remove(stack.size() - 1);
                    }
                    stack.add(IntPair.of(arr[i], i));
                }
            }
        }

        int[] removed = new int[n - k];
        {
            int ptr = 0;
            for (int i = 0; i < arr.length; ++i) {
                if (!occurance[i]) {
                    removed[ptr++] = i;
                }
            }

            if (ptr != removed.length) {
                throw new IllegalStateException();
            }

            Arrays.sort(removed);
        }

        long answer = 0;
        BitIndexedTree tree = new BitIndexedTree(n + 10);
        for (int i : removed) {
            int where = at[i];
            int from = Math.max(0, leftRadius[where]);
            int to = Math.min(n - 1, rightRadius[where]);

//            out.println("i = " + i + " from = " + from + " to = " + to);

            answer += to - from + 1 - tree.getSum(to) + tree.getSum(from - 1);
            tree.update(where, 1);
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

    public int[] nextIntArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; ++i) {
            result[i] = nextInt();
        }
        return result;
    }

    }

class ArrayUtils {


    public static int[] reversePermutation(int[] permutation) {
        int[] result = new int[permutation.length];
        for (int i = 0; i < permutation.length; i++)
            result[permutation[i]] = i;
        return result;
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

class BitIndexedTree {
    private int arr[];
    private int size;

    public BitIndexedTree(int size) {
        this.size = size;
        arr = new int[size + 2];
    }

    private int lowbit(int x) {
        return x & -x;
    }

    public void update(int x, int y) {
        ++x;
        while (x < arr.length) {
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