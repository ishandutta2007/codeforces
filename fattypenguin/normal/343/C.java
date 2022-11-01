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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long[] head = new long[n];
        long[] toRead = new long[m];
        for (int i = 0; i < n; ++i) {
            head[i] = in.nextLong();
        }
        for (int i = 0; i < m; ++i) {
            toRead[i] = in.nextLong();
        }

        long low = 0, high = 100000000000L;
        while (low < high) {
            long mid = (low + high) >> 1;
            int pointer = 0;
            {
                for (int i = 0; i < n && pointer < m; ++i) {
                    if (toRead[pointer] > head[i]) {
                        while (pointer < m && toRead[pointer] - head[i] <= mid) {
                            ++pointer;
                        }
                    } else {
                        long needHere = head[i] - toRead[pointer];
                        if (needHere > mid) break;
                        while (pointer < m && toRead[pointer] <= head[i]) {
                            ++pointer;
                        }
                        while (pointer < m) {
                            long toGo = toRead[pointer] - head[i];
                            if (Math.min(toGo, needHere) + toGo + needHere <= mid) {
                                ++pointer;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
            if (pointer == m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        out.println(low);
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