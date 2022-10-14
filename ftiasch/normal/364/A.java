import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public void run() {
        try {
            int a = reader.nextInt();
            String s = reader.next();
            int n = s.length();
            int[] count = new int[n * 10];
            for (int i = 0; i < n; ++ i) {
                int sum = 0;
                for (int j = i; j < n; ++ j) {
                    sum += s.charAt(j) - '0';
                    count[sum] ++;
                }
            }
            long answer = 0;
            for (int i = 0; i < n; ++ i) {
                int sum = 0;
                for (int j = i; j < n; ++ j) {
                    sum += s.charAt(j) - '0';
                    if (sum == 0) {
                        if (a == 0) {
                            answer += n * (n + 1) / 2;
                        }
                    } else if (a % sum == 0) {
                        int b = a / sum;
                        if (b < n * 10) {
                            answer += count[b];
                        }
                    }
                }
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