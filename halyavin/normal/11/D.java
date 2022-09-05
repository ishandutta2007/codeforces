import java.io.PrintWriter;
import java.util.Scanner;

public class D {

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[][] graph = new int[n][n];
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        long[][] dyn = new long[1 << n][n];
        for (int i = 0; i < n; i++) {
            dyn[1 << i][i] = 1;
        }
        long answer = 0;
        for (int mask = 1; mask < 1 << n; mask++) {
            int start = Integer.numberOfTrailingZeros(mask);
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) continue;
                for (int j = start + 1; j < n; j++) {
                    if (graph[i][j] > 0 && (mask & (1 << j)) == 0) {
                        dyn[mask + (1 << j)][j] += dyn[mask][i];
                    }
                }
                if (graph[i][start] > 0) {
                    answer += dyn[mask][i];
                }
            }
        }
        out.println((answer - m)/ 2);
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)
        ) {
            new D().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}