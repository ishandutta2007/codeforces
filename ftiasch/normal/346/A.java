import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public void run() {
        try {
            int n = reader.nextInt();
            int m = 0;
            int g = 0;
            for (int i = 0; i < n; ++ i) {
                int a = reader.nextInt();
                g = gcd(g, a);
                m = Math.max(m, a);
            }
            writer.println((m / g - n) % 2 == 1 ? "Alice" : "Bob");
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