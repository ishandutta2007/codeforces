import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int h = in.nextInt();
        long[] all = new long[n + 1];
        all[0] = 1;
        for (int i = 1; i <= n; i++) {
            long res = 0;
            for (int k = 0; k < i; k++) {
                res += all[k] * all[i - k - 1];
            }
            all[i] = res;
        }
        long[][] table = new long[n + 1][h + 1];
        table[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= h; j++) {
                long res = 0;
                int nextH = Math.max(0, j - 1);
                for (int k = 0; k < i; k++) {
                    res -= table[k][nextH] * table[i - k - 1][nextH];
                    res += table[k][nextH] * all[i - k - 1];
                    res += all[k] * table[i - k - 1][nextH];
                }
                table[i][j] = res;
            }
        }
        out.println(table[n][h]);
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)) {
            new Main().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
        // write your code here
    }
}