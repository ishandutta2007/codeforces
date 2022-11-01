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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {

        int[] prev, next, value;
        prev = new int[2000000];
        next = new int[2000000];
        value = new int[2000000];

        int head = 0;
        prev[0] = next[0] = -1;
        int n = in.nextInt();

        int m = in.nextInt();
        int[] step = new int[m];
        for (int i = 0; i < m; ++i) {
            step[i] = in.nextInt();
        }
        for (int i = m - 1; i > 0; --i) {
            step[i] = step[i] - step[i - 1];
        }

        int rear = 0;

        int[] current = new int[m];
        Arrays.fill(current, -1);
        int[] delta = new int[m];

        int lastNode = 1;

        int opCount = 0, n0 = n;

        while (n-- > 0) {
            int x = in.nextInt();
            if (x != -1) {
                value[lastNode] = x;
                next[rear] = lastNode;
                prev[lastNode] = rear;
                next[lastNode] = -1;
                rear = lastNode++;
                continue;
            }

            if (current[0] == -1) {
                current[0] = head;
                delta[0] = 0;
            }

            for (int i = 0; i < m; ++i) {
                if (delta[i] < 0) {
                    if (i + 1 < m) delta[i + 1] += delta[i];
                    delta[i] = 0;
                    current[i] = current[i - 1];
                }
                if (current[i] == -1) {
                    current[i] = current[i - 1];
                    delta[i] = 0;
                }
                while (delta[i] < step[i] && next[current[i]] != -1) {
                    ++opCount;
                    current[i] = next[current[i]];
                    ++delta[i];
                    if (i + 1 < m) --delta[i + 1];
                }
                if (delta[i] < step[i]) {
                    break;
                } else {
                    --delta[i];
                    next[prev[current[i]]] = next[current[i]];
                    if (next[current[i]] != -1) {
                        prev[next[current[i]]] = prev[current[i]];
                    } else {
                        rear = prev[current[i]];
                    }
                    current[i] = prev[current[i]];
                }
            }
        }
        if (opCount > 2 * n0) throw new RuntimeException();
        head = next[head];
        if (head == -1) {
            out.println("Poor stack!");
            return;
        }
        while (head != -1) {
            out.print(value[head]);
            head = next[head];
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