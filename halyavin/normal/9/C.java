import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public void run(Scanner in, PrintWriter out) {
        int n = in.nextInt();
        String s = Integer.toString(n);
        StringBuilder b = new StringBuilder();
        boolean bigDigitSeen = false;
        for (int i = 0; i < s.length(); i++) {
            bigDigitSeen |= s.charAt(i) > '1';
            if (bigDigitSeen) {
                b.append('1');
            } else {
                b.append(s.charAt(i));
            }
        }
        out.println(Integer.parseInt(b.toString(), 2));
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)) {
            new Main().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}