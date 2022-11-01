import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Set;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author fattychicken
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        if (n == 1) {
            out.println(-1);
            return;
        }

        int[] a = in.readIntArray(n);
        Arrays.sort(a);

        Set<Integer> result = new TreeSet<Integer>();
        int d = a[1] - a[0];
        if (check(a, a[0] - d)) {
            result.add(a[0] - d);
        }
        if (check(a, a[n - 1] + d)) {
            result.add(a[n - 1] + d);
        }
        for (int i = 0; i + 1 < a.length; ++i) {
            if (a[i + 1] != a[i] + d) {
                if (check(a, a[i] + d)) {
                    result.add(a[i] + d);
                }
                break;
            }
        }
        if ((a[1] - a[0]) % 2 == 0) {
            d = (a[1] - a[0]) / 2;
            if (check(a, a[0] + d)) {
                result.add(a[0] + d);
            }
        }

        out.println(result.size());
        Integer[] res = result.toArray(new Integer[result.size()]);
        for (int i = 0; i < res.length; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
    }

    private boolean check(int[] a, int extra) {
        int[] res = new int[a.length + 1];
        System.arraycopy(a, 0, res, 0, a.length);
        res[a.length] = extra;
        Arrays.sort(res);
        int d = res[1] - res[0];
        for (int i = 2; i < res.length; ++i) {
            if (res[i] - res[i - 1] != d) {
                return false;
            }
        }
        return true;
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

    public int[] readIntArray(int size) {
        int[] result = new int[size];
        for (int i = 0; i < size; ++i) {
            result[i] = nextInt();
        }
        return result;
    }

    }