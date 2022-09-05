import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

public class E {

    char[] step;
    int[] skips;
    int finalSkip;
    int totalSkip;
    int steps;

    public void run(Scanner in, PrintWriter out) {
        String s = in.next();
//        StringBuilder b = new StringBuilder();
//        Random r = new Random(12);
//        for (int i = 0; i < 1000000; i++) {
//            switch (r.nextInt(3)) {
//                case 0:
//                    b.append('X');
//                    break;
//                case 1:
//                    b.append('L');
//                    break;
//                case 2:
//                    b.append('R');
//                    break;
//            }
//        }
//        s = b.toString();
//        long t = System.nanoTime();
        step = new char[s.length()];
        skips = new int[s.length()];
        steps = 0;
        int skip = 0;
        totalSkip = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'X':
                    skip++;
                    totalSkip++;
                    break;
                case 'L':
                case 'R':
                    step[steps] = s.charAt(i);
                    if (steps > 0 && step[steps - 1] == step[steps] && skip == 0) {
                        skip = 1;
                        totalSkip++;
                    }
                    skips[steps] = skip;
                    steps++;
                    skip = 0;
                    break;
                default:
                    throw new RuntimeException();
            }
        }
        if (steps == 0) {
            out.println("0.000000");
            return;
        }
        finalSkip = skip;
        if (finalSkip == 0 && skips[0] == 0 && step[0] == step[steps - 1]) {
            if (step[0] == 'L') finalSkip++;
            else skips[0]++;
            totalSkip++;
        }
        int oddTotal = totalSkip + steps;
        if (oddTotal % 2 == 0) {
            oddTotal++;
        }
        double left = steps / (double) (2 * oddTotal);
        left = Math.floor(left * 1e8) / 1e8;
        double right = 1;
        while (right > left + 1.5e-8) {
            double middle = (left + right) / 2;
            middle = Math.round(middle * 1e8) / 1e8;
            double finalScore = calcDyn(middle);
            if (finalScore >= -1e-10) {
                left = middle;
            } else {
                right = middle;
            }
        }
        out.println(new DecimalFormat("0.000000").format(Math.round(left * 1e8) / 1e6));
//        System.err.println((System.nanoTime() - t) / 1000000);
    }

    private double calcDyn(double middle) {
        double curEven = -1e+100;
        double curOdd = 0;
        double diff = -(totalSkip + steps) * middle;
        for (int i = 0; i < steps; i++) {
            double nextEven;
            double nextOdd;
            //double delta = -(skips[i] + 1) * middle;
            int odd = skips[i] & 1;
            if (odd == 0) {
                nextEven = Math.max(curEven - middle, curOdd);
                nextOdd = Math.max(curEven, curOdd - middle);
            } else {
                nextEven = Math.max(curEven, curOdd - middle);
                nextOdd = Math.max(curEven - middle, curOdd);
            }
            if (step[i] == 'L') {
                nextEven += 1;
            } else {
                nextOdd += 1;
            }
            curEven = nextEven;
            curOdd = nextOdd;
        }
        int odd = finalSkip & 1;
        return Math.max(curEven - (odd ^ 1) * middle, curOdd - (odd) * middle) + diff;
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)
        ) {
            Locale.setDefault(Locale.US);
            new E().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}