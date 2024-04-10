import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int M = input.nextInt(), R = input.nextInt();

        // the different values added are
        // 1^2 + 2^2 + ... + (M - 1) ^2 twice
        // 2 * M
        // and 1 + sqrt(2) M^2 - M times

        // dividing by M we get
        // (M - 1)(2M - 1) / 3 + 2 + (1 + sqrt(2)) * (M - 1)
        double Answer = (double)(M - 1) / M * (2 * M - 1) / 3.0 + 2.0 / M + (1 + Math.sqrt(2)) * (double)(M - 1) / M;

        // but for most trips we win back
        // for (M - 2) * (M - 1) instead of the usual 1 + sqrt(2) + 2 we have 1 + sqrt(2) * 2 so we win 2 - sqrt(2)
        Answer -= (double)(M - 2) / M * (double)(M - 1) / M * (2 - Math.sqrt(2));
        Answer *= R;

        System.out.println(Answer);
    }
}