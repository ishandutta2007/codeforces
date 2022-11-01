import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        TreeSet<Integer> set = new TreeSet<Integer>();
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < n; ++i) {
            set.add(i);
        }
        int[] beaten = new int[n];
        for (int i = 0; i < m; ++i) {
            int l = in.nextInt(), r = in.nextInt(), x = in.nextInt();
            --l; --r; --x;
            l = set.higher(l - 1);
            while (l <= r) {
                Integer next = set.higher(l);
                if (l != x) {
                    beaten[l] = x + 1;
                    set.remove(l);
                }
                if (next == null) break;
                l = next;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(beaten[i]);
        }
        out.println();
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