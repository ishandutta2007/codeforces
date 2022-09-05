import java.io.PrintWriter;
import java.util.Scanner;
import java.util.stream.IntStream;

public class C {

    public void run(Scanner in, PrintWriter out) {
        int N = in.nextInt();
        long res = 0;
        for (int i = 1; i <= N; i++) {
            res -= N / i;
        }
        for (int i = 1; i <= 9; i++) {
            long as = (N + 9 - i) / 9;
            for (int j = 1; j <= 9; j++) {
                long bs = (N + 9 - j) / 9;
                int k = (i * j) % 9;
                if (k == 0) k = 9;
                long cs = (N + 9 - k) / 9;
                res += as * bs * cs;
            }
        }
        out.println(res);
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new C().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}