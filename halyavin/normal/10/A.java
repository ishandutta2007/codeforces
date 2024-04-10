import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    int p1, p2, p3;
    int t1, t2;

    int waitEnergy(int t) {
        if (t < t1) return t * p1;
        if (t < t1 + t2) return t1 * p1 + (t - t1) * p2;
        return t1 * p1 + t2 * p2 + (t - t1 - t2) * p3;
    }

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        p1 = in.nextInt();
        p2 = in.nextInt();
        p3 = in.nextInt();
        t1 = in.nextInt();
        t2 = in.nextInt();
        int total = 0;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int l = in.nextInt();
            int r = in.nextInt();
            if (i == 0) prev = l;
            total += waitEnergy(l - prev);
            total += (r - l) * p1;
            prev = r;
        }
        out.println(total);
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new A().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}