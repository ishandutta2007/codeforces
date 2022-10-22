import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] argv) {
        Scanner input = new Scanner(System.in);

        int N = input.nextInt();

        int[] A = new int[N];

        for (int i = 0; i < N; ++i)
            A[i] = input.nextInt();

        List<Integer> Answer = new ArrayList<Integer>();
        for (int i = 30; i >= 0; --i) {
            int And = Integer.MAX_VALUE;
            for (int x : A)
                if ((x & (1 << i)) != 0)
                    And &= x;
            if ((And & ((1 << i) - 1)) != 0)
                continue;

            for (int x : A)
                if ((x & (1 << i)) != 0)
                    Answer.add(new Integer(x));
            break;
        }

        System.out.println(Answer.size());
        for (Integer x : Answer)
            System.out.print(x + " ");
    }
}