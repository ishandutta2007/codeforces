import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] argv) {
        Scanner input = new  Scanner(System.in);

        int A = input.nextInt(), B = input.nextInt(), C = input.nextInt(), D = input.nextInt();

        long P, Q;
        if (A * D == B * C) {
            P = 0;
            Q = 1;
        } else if(A * D > B * C) {
            // B and D are actually equal in reality
            A *= D;
            C *= B;
            B *= D;
            D = B;

            // now they're at the same scale
            Q = (long) A * B;
            P = Q - (long) C * D;
            long d = Main.gcd(P, Q);

            P /= d;
            Q /= d;
        } else {
            // A and C are actually equal in reality
            B *= C;
            D *= A;
            A *= C;
            C = A;

            // now they're at the same scale
            Q = (long) A * B;
            P = Q - (long) C * D;
            long d = Main.gcd(P, Q);

            P /= d;
            Q /= d;
        }

        System.out.println(P + "/" + Q);
    }

    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}