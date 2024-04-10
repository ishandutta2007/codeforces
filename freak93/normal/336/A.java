import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int X = input.nextInt(), Y = input.nextInt();

        int X1 = 0, Y1 = sgn(Y) * (Math.abs(X) + Math.abs(Y));
        int X2 = sgn(X) * (Math.abs(X) + Math.abs(Y)), Y2 = 0;

        if (X1 > X2) {
            X1 = X2; X2 = 0;
            Y2 = Y1; Y1 = 0;
        }

        System.out.println(X1 + " " + Y1 + " " + X2 + " " + Y2);
    }

    public static int sgn(int x) {
        if (x > 0)
            return 1;
        if (x < 0)
            return -1;
        return 0;
    }
}