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
        int[] numbers = new int[5];
        int n = in.nextInt();
        for (int i = 0; i < n; ++i) {
            int a = in.nextInt();
            ++numbers[a];
        }
        if (numbers[1] + numbers[2] == 0) {
            out.println(0);
            return;
        }
        int allDesks = numbers[1] + numbers[2] + numbers[3] + numbers[4];
        int allPeoples = numbers[1] + numbers[2] * 2 + numbers[3] * 3 + numbers[4] * 4;

        int result = Integer.MAX_VALUE;
        for (int desks = 1; desks <= allDesks; ++desks) {
            if (desks < (allPeoples + 3) / 4) continue;
            int toRemove = allDesks - desks;
            int[] current = numbers.clone();
            int extra = 0;
            for (int i = 1; i <= 4 && toRemove != 0; ++i) {
                if (toRemove <= numbers[i]) {
                    extra += toRemove * i;
                    numbers[i] -= toRemove;
                    toRemove = 0;
                } else {
                    extra += numbers[i] * i;
                    toRemove -= numbers[i];
                    numbers[i] = 0;
                }
            }
            int firstStep = extra;
            if (extra >= 2 * numbers[1]) {
                extra -= 2 * numbers[1];
                numbers[1] = 0;
            } else {
                numbers[1] -= extra / 2;
                extra = extra % 2;
            }

            if (extra > 0 && numbers[1] > 0) {
                ++numbers[2];
                --numbers[1];
                --extra;
            }

            if (extra >= numbers[2]) {
                extra -= numbers[2];
                numbers[2] = 0;
            } else {
                numbers[2] -= extra;
                extra = 0;
            }

            if (numbers[1] > 0 || numbers[2] > 0) {
                int need = 2 * numbers[1] + numbers[2];
                if (need <= numbers[4]) {
                    result = Math.min(result, need + firstStep);
                }
            } else {
                if (extra <= (desks - numbers[4])) {
                    result = Math.min(result, firstStep);
                }
            }

            numbers = current;
        }

        if (result == Integer.MAX_VALUE) result = -1;
        out.println(result);
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