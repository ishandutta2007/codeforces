import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt(), M = input.nextInt();

        boolean[] badLines = new boolean[N + 1];
        boolean[] badColumns = new boolean[N + 1];

        for (int i = 1; i <= N; ++i) {
            badLines[i] = badColumns[i] = false;
        }
        for (int i = 0; i < M; ++i) {
            int x = input.nextInt(), y = input.nextInt();
            badLines[x] = true;
            badColumns[y] = true;
        }

        int answer = 0;
        for(int i = 2; i <= N - i + 1; ++i) {
            if (i != N - i + 1) {
                if (!badLines[i])
                    ++answer;
                if (!badLines[N - i + 1])
                    ++answer;
                if (!badColumns[i])
                    ++answer;
                if (!badColumns[N - i + 1])
                    ++answer;
            } else {
                if (!badLines[i] || !badColumns[i])
                    ++answer;
            }
        }

        System.out.println(answer);
    }
}