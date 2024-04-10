import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public void run(Scanner in, PrintWriter out) {
        int opt = -1;
        double dist1 = 1e+100;
        double dist2 = 1e+100;
        int n = in.nextInt();
        double vb = in.nextDouble();
        double vs = in.nextDouble();
        double[] coords = new double[n];
        for (int i = 0; i < n; i++) {
            coords[i]=in.nextDouble();
        }
        double xu = in.nextDouble();
        double yu = in.nextDouble();
        for (int i = 1; i < n; i++) {
            double cur2 = Math.hypot(xu-coords[i],yu)/vs;
            double cur1 = coords[i]/vb + cur2;
            if (cur1 < dist1 - 1e-10 || (Math.abs(cur1-dist1)<1e-10 && cur2 < dist2 - 1e-10)) {
                dist1 = cur1;
                dist2 = cur2;
                opt = i;
            }
        }
        out.println(opt + 1);
    }
    public static void main(String[] args) {
        try(
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
                ) {
            new Main().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}