import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int d = in.nextInt();
        int[] bs = new int[n];
        for (int i =  0; i < n; i++) {
            bs[i] = in.nextInt();
        }
        int cur = bs[0];
        int answer = 0;
        for (int i = 1; i < n; i++) {
            if (bs[i] > cur) {
                cur = bs[i];
            } else {
                answer += (cur - bs[i]) / d + 1;
                cur = bs[i] + ((cur - bs[i]) / d + 1) * d;
            }
        }
        out.println(answer);
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)
        ) {
            new A().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}