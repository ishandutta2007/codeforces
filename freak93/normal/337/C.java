import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt(), M = input.nextInt(), K = input.nextInt();

        int groups = (M + K - 2) / (K - 1);

        int Answer;
        if (M + groups - 1 <= N)
            Answer = M;
        else {
            int max_groups = N - M;
            Answer = max_groups * (K - 1);
            M -= max_groups * (K - 1);
            N -= max_groups * K;

            int doubles = M / K;
            M -= doubles * K;

            Answer = (Answer + Main.doubleScore(doubles, K)) % Main.kModulo;
            Answer += M;
        }

        System.out.println(Answer);
    }

    private static int doubleScore(int doubles, int K) {
        int answer = Main.powfast(2, doubles + 1);
        answer -= 2;
        if (answer < 0)
            answer += kModulo;
        return (int)(((long)answer * K) % kModulo);
    }

    private static int powfast(int x, int y) {
        if (y == 0)
            return 1;
        if (y % 2 == 1)
            return (int)(((long)powfast(x, y - 1) * x) % Main.kModulo);
        int half = powfast(x, y / 2);
        return (int)(((long)half * half) % Main.kModulo);
    }

    private static int kModulo = 1000000009;
}