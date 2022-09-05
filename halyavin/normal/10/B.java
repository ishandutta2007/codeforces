import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    int k;

    int total_dist(int x, int yl, int yr) {
        int res = Math.abs(x - (k / 2)) * (yr - yl);
        if (yl <= k / 2 && k / 2 < yr) {
            res += (k / 2 - yl) * (k / 2 - yl + 1) / 2;
            res += (yr - k / 2 - 1) * (yr - k / 2) / 2;
        } else if (yr <= k / 2) {
            res += (k / 2 - yl) * (k / 2 - yl + 1) / 2;
            res -= (k / 2 - yr) * (k / 2 - yr + 1) / 2;
        } else { // k/2 < yl
            res += (yr - k / 2 - 1) * (yr - k / 2) / 2;
            res -= (yl - k / 2 - 1) * (yl - k / 2) / 2;
        }
        return res;
    }

    int[][] table;

    int[] executeRequest(int request) {
        int optx = -1;
        int opty = -1;
        int optValue = Integer.MAX_VALUE;
        for (int x = 0; x < k; x++) {
            int count = 0;
            for (int i = 0; i < request; i++) {
                count += table[x][i];
            }
            for (int y = 0; y <= k - request; y++) {
                if (count == 0) {
                    int value = total_dist(x, y, y + request);
                    if (value < optValue || (value == optValue && x < optx) ||
                            (value == optValue && x == optx && y < opty)) {
                        optValue = value;
                        optx = x;
                        opty = y;
                    }
                }
                if (y < k - request) {
                    count += table[x][y + request];
                    count -= table[x][y];
                }
            }
        }
        if (optx != -1) {
            for (int i = 0; i < request; i++) {
                table[optx][opty+i]=1;
            }
            return new int[]{optx, opty};
        }

        return new int[0];
    }

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        k = in.nextInt();
        table = new int[k][k];
        for (int i = 0; i < n; i++) {
            int request = in.nextInt();
            int[] res = executeRequest(request);
            if (res.length == 0) {
                out.println(-1);
            } else {
                out.println((res[0] + 1) + " " + (res[1] + 1) + " " + ((res[1] + 1 + request) - 1));
            }
        }
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new B().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}