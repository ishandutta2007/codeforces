import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    int signum(int x) {
        if (x == 0) {
            return 0;
        }
        return x < 0 ? -1 : 1;
    }

    public void run() {
        try {
            String buffer = reader.next();
            boolean[] weights = new boolean[11];
            for (int i = 0; i < 10; ++ i) {
                weights[i + 1] = buffer.charAt(i) == '1';
            }
            int m = reader.nextInt();
            int[][][] valid = new int[m + 1][21][11];
            for (int i = 0; i <= m; ++ i) {
                for (int j = 0; j <= 20; ++ j) {
                    for (int k = 0; k <= 10; ++ k) {
                        valid[i][j][k] = -1;
                    }
                }
            }
            valid[0][10][0] = 0;
            for (int i = 0; i < m; ++ i) {
                int sign = i % 2 == 0 ? 1 : -1;
                for (int j = 0; j <= 20; ++ j) {
                    for (int last = 0; last <= 10; ++ last) {
                        if (valid[i][j][last] != -1) {
                            for (int k = 1; k <= 10; ++ k) {
                                if (weights[k] && last != k && signum(j - 10 + sign * k) == sign) {
                                    valid[i + 1][j + sign * k][k] = last;
                                }
                            }
                        }
                    }
                }
            }
            boolean found = false;
            for (int j = 0; j <= 20 && !found; ++ j) {
                for (int k = 0; k <= 10 && !found; ++ k) {
                    if (valid[m][j][k] != -1) {
                        found = true;
                        writer.println("YES");
                        int[] ways = new int[m];
                        for (int i = m - 1; i >= 0; -- i) {
                            int sign = i % 2 == 0 ? 1 : -1;
                            ways[i] = k;
                            k = valid[i + 1][j][k];
                            j -= sign * ways[i];
                        }
                        for (int i = 0; i < m; ++ i) {
                            writer.print(ways[i] + " ");
                        }
                    }
                }
            }
            if (!found) {
                writer.println("NO");
            }
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