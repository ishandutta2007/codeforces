import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public void run(Scanner in, PrintWriter out) {
        int x = in.nextInt();
        int w = in.nextInt();
        int p = 6 - Math.max(x, w) + 1;
        int q = 6;
        if (p % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        if (p % 3 == 0) {
            p /= 3;
            q /= 3;
        }
        out.println(p + "/" + q);
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new Main().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}