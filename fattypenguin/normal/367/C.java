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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] u = new int[m], v = new int[m];
        for (int i = 0; i < m; ++i) {
            u[i] = in.nextInt();
            v[i] = in.nextInt();
        }
        Arrays.sort(v);
        ArrayUtils.reverse(v);
        int t = 1;
        while (t + 1 <= v.length && t * (t + 1) / 2 + 1 <= n) ++t;
        if (t % 2 == 0) {
            if (t * (t - 1) / 2 + t / 2 > n) {
                --t;
            }
        }

//        out.println("t = " + t);

        long ans = 0;
        for (int i = 0; i < t; ++i) {
            ans += v[i];
        }
        out.println(ans);
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

class ArrayUtils {

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }


    public static void reverse(int[] array) {
        for (int i = 0; i < array.length - 1 - i; ++i) {
            swap(array, i, array.length - 1 - i);
        }
    }

    }