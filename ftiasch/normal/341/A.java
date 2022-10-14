import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public void run() {
        try {
            int n = reader.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++ i) {
                a[i] = reader.nextInt();
            }
            Arrays.sort(a);
            long num = 0;
            long sum = 0;
            for (int i = 0; i < n; ++ i) {
                num += (long)a[i] * i - sum;
                sum += a[i];
            }
            num *= 2;
            for (int i = 0; i < n; ++ i) {
                num += a[i];
            }
            long den = n;
            long g = gcd(num, den);
            num /= g;
            den /= g;
            writer.println(num + " " + den);
        } catch (IOException ex) {
        }
        writer.close();
    }

    InputReader reader;
    PrintWriter writer;

    Main() {
        reader = new InputReader();
        writer = new PrintWriter(System.out);
    }

    public static void main(String[] args) {
        new Main().run();
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