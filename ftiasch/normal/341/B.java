import java.io.*;
import java.math.*;
import java.util.*;

public class B {
    public void run() {
        try {
            int n = reader.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++ i) {
                a[i] = reader.nextInt() - 1;
            }
            int[] count = new int[n];
            int[] maximum = new int[n];
            int answer = 0;
            for (int i = 0; i < n; ++ i) {
                for (int k = a[i]; k >= 0; k -= ~k & k + 1) {
                    maximum[i] = Math.max(maximum[i], count[k]);
                }
                maximum[i] ++;
                for (int k = a[i]; k < n; k += ~k & k + 1) {
                    count[k] = Math.max(count[k], maximum[i]);
                }
                answer = Math.max(answer, maximum[i]);
            }
            writer.println(answer);
        } catch (IOException ex) {
        }
        writer.close();
    }

    InputReader reader;
    PrintWriter writer;

    B() {
        reader = new InputReader();
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new B().run();
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    InputReader() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}