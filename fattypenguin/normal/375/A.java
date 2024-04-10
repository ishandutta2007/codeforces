import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int[] res = new int[7];
        int[] s = new int[]{1, 6, 8, 9};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int r = 0; r < 4; ++r) {
                        if (i != j && j != k && k != r && i != r && i != k && j != r) {
                            int t = s[i] * 1000 + s[j] * 100 + s[k] * 10 + s[r];
                            res[t % 7] = t;
                        }
                    }
                }
            }
        }
        char[] string = in.next().toCharArray();
        StringBuilder builder = new StringBuilder();
        boolean[] have = new boolean[4];
        for (int i = 0; i < string.length; ++i) {
            boolean ok = false;
            for (int j = 0; j < 4; ++j) {
                if (string[i] - '0' == s[j] && !have[j]) {
                    have[j] = true;
                    ok = true;
                }
            }
            if (!ok) {
                builder.append(string[i]);
            }
        }
        int rem = 0, delta = 1;
        char[] filtered = builder.toString().toCharArray();
        for (int i = filtered.length - 1; i >= 0; --i) {
            rem = (rem + delta * (filtered[i] - '0')) % 7;
            delta = delta * 10 % 7;
        }

        for (int i = 0; i < 7; ++i) {
            if ((rem + delta * i) % 7 == 0) {
                out.println(res[i] + builder.toString());
                return;
            }
        }

        throw new RuntimeException();
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

    }