import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
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
        int n = in.nextInt();
        double[] res = new double[n * 2];
        for (int i = 0; i < n * 2; ++i) {
            res[i] = in.nextDouble();
            res[i] -= Math.floor(res[i] + 1e-8);
        }
        Arrays.sort(res);
        ArrayList<Double> list = new ArrayList<Double>();
        double sum = 0;
        for (int i = 0; i < n * 2; ++i) {
            if (Math.abs(res[i]) > 1e-8) {
                list.add(res[i]);
                sum += res[i];
            }
        }
        double result = 1e100;
        int rest = 2 * n - list.size();
        int min = Math.max(0, n - rest);
        int max = n;
        for (int i = min; i <= max; ++i) {
            result = Math.min(result, Math.abs(sum - i));
        }
        out.printf("%.3f\n", Math.abs(result));
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

    public double nextDouble() {
        return Double.parseDouble(next());
    }

}