import java.io.PrintWriter;
import java.util.Scanner;

public class E {

    int[] coins;

    int calcCount(int x, int maxCoin) {
        int res = 0;
        for (int i = maxCoin; i >= 0; i--) {
            res += x / coins[i];
            x = x % coins[i];
        }
        return res;
    }

    int calcXRec(int target, int prevSum, int prevCount, int maxCoin) {
        if (maxCoin == 0) return Integer.MAX_VALUE;
        int x= Integer.MAX_VALUE;
        int c = (target - prevSum + coins[maxCoin] - 1)/ coins[maxCoin];
        int sum = prevSum + c * coins[maxCoin];
        int count = prevCount + c;
        int rest = sum - target;
        int restCount = calcCount(rest, maxCoin - 1);
        if (restCount >= count) {
            x = Math.min(x, sum);
        }
        x = Math.min(x, calcXRec(target, sum - coins[maxCoin], count - 1, maxCoin - 1));
        if (c == 2 && prevSum + coins[maxCoin] + coins[maxCoin - 1] > target) {
            x = Math.min(x, calcXRec(target, prevSum, prevCount, maxCoin - 1));
        }
        return x;
    }

    int calcX(int maxCoin) {
        int prevSum = 0;
        int prevCount = 0;
        int x = calcXRec(coins[maxCoin], 0, 0, maxCoin - 1);
        if (x == Integer.MAX_VALUE) return -1;
        return x;
    }

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        coins = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            coins[i] = in.nextInt();
        }
        for (int i = 1; i < n; i++) {
            int x = calcX(i);
            if (x != -1 && (i == n - 1 || x < coins[i + 1])) {
                out.println(x);
                return;
            }
        }
        out.println(-1);
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new E().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}