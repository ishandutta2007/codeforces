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
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        char[] bin = in.next().toCharArray();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        ArrayUtils.reverse(a);
        ArrayUtils.reverse(bin);

        int result = 0;
        int prefix = 0;
        for (int i = 0; i < n; ++i) {
            sum -= a[i];
            if (bin[i] == '1') {
                result = Math.max(result, prefix + sum);
                prefix += a[i];
            }
        }

        result = Math.max(result, prefix);
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

class ArrayUtils {

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }


    public static void swap(char[] array, int i, int j) {
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    /** reverse **/
    public static void reverse(char[] array) {
        for (int i = 0; i < array.length - 1 - i; ++i) {
            swap(array, i, array.length - 1 - i);
        }
    }

    public static void reverse(int[] array) {
        for (int i = 0; i < array.length - 1 - i; ++i) {
            swap(array, i, array.length - 1 - i);
        }
    }

    }