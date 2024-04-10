import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public void run() {
        try {
            String a = reader.next();
            String b = reader.next();
            String c = reader.next();
            int[][] go = new int[c.length() + 1][26];
            int[] fail = new int[c.length() + 1];
            go[0][c.charAt(0) - 'A'] = 1;
            fail[1] = 0;
            for (int i = 1; i <= c.length(); ++ i) {
                for (int j = 0; j < 26; ++ j) {
                    if (i < c.length() && c.charAt(i) - 'A' == j) {
                        go[i][j] = i + 1;
                        fail[i + 1] = go[fail[i]][j];
                    } else {
                        go[i][j] = go[fail[i]][j];
                    }
                }
            }
            int[][][] maximum = new int[a.length() + 1][b.length() + 1][c.length() + 1];
            for (int i = a.length(); i >= 0; -- i) {
                for (int j = b.length(); j >= 0; -- j) {
                    maximum[i][j][c.length()] = Integer.MIN_VALUE;
                    for (int k = 0; k < c.length(); ++ k) {
                        if (i < a.length() && j < b.length()) {
                            maximum[i][j][k] = Math.max(maximum[i + 1][j][k], maximum[i][j + 1][k]);
                            if (a.charAt(i) == b.charAt(j)) {
                                maximum[i][j][k] = Math.max(maximum[i][j][k], maximum[i + 1][j + 1][go[k][a.charAt(i) - 'A']] + 1);
                            }
                        } else {
                            maximum[i][j][k] = 0;
                        }
                    }
                }
            }
            if (maximum[0][0][0] > 0) {
                StringBuffer buffer = new StringBuffer("");
                for (int i = 0, j = 0, k = 0; maximum[i][k][k] > 0; ) {
                    if (maximum[i + 1][j][k] == maximum[i][j][k]) {
                        i ++;
                    } else if (maximum[i][j + 1][k] == maximum[i][j][k]) {
                        j ++;
                    } else {
                        buffer.append(a.charAt(i));
                        k = go[k][a.charAt(i) - 'A'];
                        i ++;
                        j ++;
                    }
                }
                writer.println(buffer.toString());
            } else {
                writer.println(0);
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