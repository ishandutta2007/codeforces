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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        char[] s = in.next().toCharArray();

        long[] answer = new long[27];
        int maxDiv = 0;
        outer: for (int div = 1; div <= 26; ++div) {
            int[] count = new int[26];
            int current = 0;
            int right = 0;
            int[] count2 = new int[26];
            int right2 = 0;
            int current2 = 0;
            for (int i = 0; i < s.length; ++i) {
                while (right < s.length && current <= div) {
                    ++count[s[right] - 'a'];
                    if (count[s[right] - 'a'] == 1) {
                        ++current;
                    }
                    if (current > div) {
                        --count[s[right] - 'a'];
                        --current;
                        break;
                    }
                    ++right;
                }
                while (right2 < s.length && current2 < div) {
                    ++count2[s[right2] - 'a'];
                    if (count2[s[right2] - 'a'] == 1) {
                        ++current2;
                    }
                    if (current2 >= div) {
                        --count2[s[right2] - 'a'];
                        --current2;
                        break;
                    }
                    ++right2;
                }
                if (current < div) continue outer;
                maxDiv = div;
                answer[div] += right - right2;

                --count[s[i] - 'a'];
                if (count[s[i] - 'a'] == 0) {
                    --current;
                }

                --count2[s[i] - 'a'];
                if (count2[s[i] - 'a'] == 0) {
                    --current2;
                }
            }
        }

        out.println(maxDiv);
        for (int i = 1; i <= maxDiv; ++i) {
            out.println(answer[i]);
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

    }