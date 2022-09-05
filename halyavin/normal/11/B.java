import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public void run(Scanner in, PrintWriter out) {
        int x = Math.abs(in.nextInt());
        if (x == 0) {
            out.println(0);
            return;
        }
        int n = (int) Math.round(Math.floor(Math.sqrt(2 * x) - 1));
        while (n * (n + 1) / 2 < x || ((n * (n + 1) / 2 - x) & 1) != 0) n++;
        out.println(n);
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)
        ) {
            new B().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}