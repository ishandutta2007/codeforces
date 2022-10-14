import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    int[] a;
    
    void update(int k, int v) {
        a[k] = v;
        int type = 0;
        while (k > 1) {
            k >>= 1;
            if (type == 0) {
                a[k] = a[k << 1] | a[k << 1 | 1];
            } else {
                a[k] = a[k << 1] ^ a[k << 1 | 1];
            }
            type ^= 1;
        }
    }

    public void run() {
        try {
            int n = reader.nextInt();
            int m = reader.nextInt();
            a = new int[1 << n + 1];
            for (int i = 1 << n; i < 1 << n + 1; ++ i) {
                update(i, reader.nextInt());
            }
            while (m > 0) {
                m --;
                int k = reader.nextInt();
                int v = reader.nextInt();
                update(k - 1 + (1 << n), v);
                writer.println(a[1]);
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