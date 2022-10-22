import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        long N = input.nextLong();

        for (long x = 3; ; x *= 3) {
            if (N % x != 0) {
                long answer = (N + x - 1) / x;
                System.out.println(answer);
                return;
            }
        }
    }
}