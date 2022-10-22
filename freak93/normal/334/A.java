import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();

        int[][] A = new int[N][N];

        for (int i = 0, j = 0; i < N * N; i += N, j += 1) {
            int[] B = new int[N];
            for (int k = i; k < i + N; ++k)
                B[k - i] = k;

            int[] C = new int[N];
            for (int k = 0; k < N; ++k)
                C[(k + j) % N] = B[k];
            for (int k = 0; k < N; ++k)
                A[k][j] = C[k];
        }

        for (int[] row : A) {
            for (int value : row)
                System.out.print((value + 1) + " ");
            System.out.println();
        }
    }
}