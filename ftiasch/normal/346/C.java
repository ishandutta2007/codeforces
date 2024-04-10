import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public void run() {
        try {
            int n = reader.nextInt();
            int[] x = new int[n];
            for (int i = 0; i < n; ++ i) {
                x[i] = reader.nextInt();
            }
            Arrays.sort(x);
            if (true) {
                int total = 0;
                for (int i = 0; i < n; ++ i) {
                    if (total == 0 || x[total - 1] < x[i]) {
                        x[total ++] = x[i];
                    }
                }
                n = total;
            }
            int answer = 0;
            int b = reader.nextInt();
            int a = reader.nextInt();
            while (a != b) {
                while (n > 0 && b - b % x[n - 1] < a) {
                    n --;
                }
                int best = b - 1;
                for (int i = 0; i < n; ++ i) {
                    int next = b - b % x[i];
                    if (next < best && next >= a) {
                        best = next;
                    }
                }
                b = best;
                answer ++;
            }
            writer.println(answer);
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