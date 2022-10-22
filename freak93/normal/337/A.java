import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] argv) {
        Scanner input = new  Scanner(System.in);

        int K = input.nextInt(), N = input.nextInt();
        --K;

        Integer[] A = new Integer[N];
        for (int i = 0; i < N; ++i)
            A[i] = new Integer(input.nextInt());

        Arrays.sort(A);

        int Answer = A[N - 1] - A[0];
        for (int i = 0; i < N - K; ++i)
            Answer = Math.min(Answer, A[i + K] - A[i]);

        System.out.println(Answer);
    }
}