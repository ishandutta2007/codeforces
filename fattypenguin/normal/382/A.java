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
 * @author fattychicken
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
    private static final String IMPOSSIBLE = "Impossible";
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String weights = in.next();
        String extra = in.next();

        int index = weights.indexOf('|');
        String left = weights.substring(0, index);
        String right = weights.substring(index + 1, weights.length());
        if (Math.abs(left.length() - right.length()) > extra.length() ||
                (extra.length() - Math.abs(left.length() - right.length())) % 2 != 0) {
            out.println(IMPOSSIBLE);
            return;
        }

        int delta = Math.abs(left.length() - right.length());
        if (left.length() < right.length()) {
            left = left + extra.substring(0, delta);
            extra = extra.substring(delta, extra.length());
        } else {
            right = right + extra.substring(0, delta);
            extra = extra.substring(delta, extra.length());
        }

        left = left + extra.substring(0, extra.length() / 2);
        right = right + extra.substring(extra.length() / 2, extra.length());

        out.println(left + "|" + right);
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