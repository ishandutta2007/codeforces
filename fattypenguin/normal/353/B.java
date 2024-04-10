import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;
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
        n *= 2;
        int[] arr = new int[n];
        HashMap<Integer, Integer> occurance = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; ++i) {
            int a = in.nextInt();
            arr[i] = a;
            if (!occurance.containsKey(a)) {
                occurance.put(a, 1);
            } else {
                occurance.put(a, 2);
            }
        }
        int[] which = new int[n];
        Arrays.fill(which, -1);
        int first = 0, second = 0, rest = 0;
        Map<Integer, Integer> result = new HashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> entry : occurance.entrySet()) {
            if (entry.getValue() == 1) {
                ++rest;
            } else {
                ++first;
                ++second;
                for (int i = 0; i < n; ++i) {
                    if (arr[i] == entry.getKey()) {
                        which[i] = 1;
                        for (int j = i + 1; j < n; ++j) {
                            if (arr[j] == entry.getKey()) {
                                which[j] = 0;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        int answer = 0;
        int left = 0;
        for (int i = 0; i <= rest; ++i) {
            if ((first + i) * (second + rest - i) >= answer && first + i <= n / 2 && second + rest - i <= n / 2) {
                answer = (first + i) * (second + rest - i);
                left = i;
            }
        }

        for (Map.Entry<Integer, Integer> entry : occurance.entrySet()) {
            if (entry.getValue() == 1) {
                if (left-- > 0) {
                    for (int i = 0; i < n; ++i) {
                        if (arr[i] == entry.getKey()) {
                            which[i] = 1;
                            break;
                        }
                    }
                } else {
                    for (int i = 0; i < n; ++i) {
                        if (arr[i] == entry.getKey()) {
                            which[i] = 0;
                            break;
                        }
                    }
                }
            }
        }
        int count1 = 0;
        for (int i = 0; i < n; ++i) {
            if (which[i] == 0) {
                ++count1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (which[i] == -1) {
                if (count1++ < n / 2) {
                    which[i] = 0;
                } else {
                    which[i] = 1;
                }
            }
        }
        out.println(answer);
        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(which[i] + 1);
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