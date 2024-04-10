import java.io.InputStreamReader;
import java.io.IOException;
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
        int a = in.nextInt();
        char[] s = in.next().toCharArray();
        int[] count = new int[4000 * 100];
        for (int i = 0; i < s.length; ++i) {
            int sum = 0;
            for (int j = i; j < s.length; ++j) {
                sum += s[j] - '0';
                ++count[sum];
            }
        }
        long all = 0;
        for (int i = 0; i < count.length; ++i) {
            all += count[i];
        }
        long result = 0;
        for (int i = 0; i < s.length; ++i) {
            int sum = 0;
            for (int j = i; j < s.length; ++j) {
                sum += s[j] - '0';
                if (a == 0) {
                    if (sum == 0) {
                        result += all;
                    } else {
                        result += count[0];
                    }
                    continue;
                }
                if (sum != 0 && a % sum == 0 && a / sum < count.length) {
                    result += count[a / sum];
                }
            }
        }

        out.print(result);
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