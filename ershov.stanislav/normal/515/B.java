import java.io.*;
import java.util.*;

public class HelloWorld {

    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public void run() {
        Scanner in = new Scanner(System.in);
        PrintWriter out= new PrintWriter(System.out);

        int n = in.nextInt();
        int m = in.nextInt();
        boolean[] good = new boolean[gcd(n, m)];
        int b = in.nextInt();
        for (int i = 0; i < b; i++) {
            int a = in.nextInt();
            good[a % gcd(n, m)] = true;
        }
        int g = in.nextInt();
        for (int i = 0; i < g; i++) {
            int a = in.nextInt();
            good[a % gcd(n, m)] = true;
        }
        boolean best = true;
        for (int i = 0; i < gcd(n, m); i++) {
            if (!good[i]) {
                best = false;
            }
        }

        if (best) {
            out.println("Yes");
        } else {
            out.println("No");
        }

        out.close();
    }
    public static void main(String[] args) {
        HelloWorld all = new HelloWorld();
        all.run();
    }
}