import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt(), M = input.nextInt(), g = input.nextInt();
        comb = new Combinations(N + M);
        System.out.println(solve(N, M, g));
    }

    private static long solve(int N, int M, int g) {
        if (N + M == 1) {
            if (g == 0 && N > 0)
                return 1;
            if (g == 1 && M > 0)
                return 1;
            return 0;
        }

        if (g == 1)
            if (N == 0)
                return 0;
            else
                return solve(N - 1, M, 0);
       else {
            int aux = (int)(comb.combinations(N + M, N) - solve(N, M, 1));
            if (aux < 0)
                aux += kModulo;
            return aux;
        }
    }

    private static int kModulo = 1000000007;
    private static Combinations comb;
}

class Combinations {
    Combinations(int maxValue) {
        fact = new int[maxValue + 1];
        ifact = new int[maxValue + 1];

        fact[0] = ifact[0] = 1;

        for (int i = 1; i <= maxValue; ++i)
            fact[i] = (int)(((long)fact[i - 1] * i) % kModulo);

        ifact[maxValue] = powfast(fact[maxValue], kModulo - 2);
        for (int i = maxValue - 1; i > 0; --i)
            ifact[i] = (int)(((long)ifact[i + 1] * (i + 1)) % kModulo);
    }

    public int combinations(int A, int B) {
        int aux = fact[A];
        aux = (int)(((long)aux * ifact[B]) % kModulo);
        aux = (int)(((long)aux * ifact[A - B]) % kModulo);
        return aux;
    }

    private int powfast(int A, int B) {
        if (B == 0)
            return 1;
        if (B % 2 == 1)
            return (int)(((long)powfast(A, B - 1) * A) % kModulo);

        int half = powfast(A, B / 2);
        return (int)(((long)half * half) % kModulo);
    }

    private int[] fact, ifact;
    private static int kModulo = 1000000007;
}