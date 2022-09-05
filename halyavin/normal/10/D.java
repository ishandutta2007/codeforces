import java.io.PrintWriter;
import java.util.*;

public class D {

    int n;
    int[] seq1;
    int m;
    int[] seq2;
    int[][] table;
    int[][] tablePrev;
    int inf;

    public void run(Scanner in, PrintWriter out) {
        n = in.nextInt();
        seq1 = new int[n];
        for (int i = 0; i < n; i++) seq1[i] = in.nextInt();
        m = in.nextInt();
        seq2 = new int[m];
        for (int i = 0; i < m; i++) seq2[i] = in.nextInt();
        inf = m;
        table = new int[Math.min(n, m)][n];
        tablePrev = new int[Math.min(n, m)][n];
        int[][] value_same = new int[n][];
        for (int i = 0; i < n; i++) {
            int value = seq1[i];
            long size = Arrays.stream(seq2).filter(v -> v == value).count();
            value_same[i] = new int[(int) size];
            int cur_pos = 0;
            for (int j = 0; j < m; j++) {
                if (seq2[j] == value) {
                    value_same[i][cur_pos] = j;
                    cur_pos++;
                }
            }
        }
        int max_layer = -1;
        int max_i = -1;
        for (int i = 0; i < n; i++) {
            if (value_same[i].length != 0) {
                table[0][i] = value_same[i][0];
                max_layer = 0;
                max_i = i;
            } else {
                table[0][i] = inf;
            }
        }
        for (int layer = 1; layer < table.length && max_layer == layer - 1; layer++) {
            for (int i = layer; i < n; i++) {
                if (value_same[i].length == 0) {
                    table[layer][i] = inf;
                    continue;
                }
                int leftPos = inf;
                int prev = -1;
                for (int j = layer - 1; j < i; j++) {
                    if (table[layer - 1][j] < leftPos && seq1[j] < seq1[i]) {
                        leftPos = table[layer - 1][j];
                        prev = j;
                    }
                }
                if (leftPos == inf) {
                    table[layer][i] = inf;
                    continue;
                }
                int res = -1;
                for (int j = 0; j < value_same[i].length; j++) {
                    if (value_same[i][j] > leftPos) {
                        res = value_same[i][j];
                        break;
                    }
                }
                if (res == -1) {
                    table[layer][i] = inf;
                    continue;
                }
                table[layer][i] = res;
                tablePrev[layer][i] = prev;
                max_layer = layer;
                max_i = i;
            }
        }
        out.println(max_layer + 1);
        List<Integer> answer = new ArrayList<>();
        while (max_layer >= 0) {
            answer.add(seq1[max_i]);
            max_i = tablePrev[max_layer][max_i];
            max_layer--;
        }
        Collections.reverse(answer);
        for (Integer v : answer) out.print(v + " ");
        out.println();
    }

    public static void main(String[] args) {
        try (
                Scanner in = new Scanner(System.in);
                PrintWriter out = new PrintWriter(System.out);
        ) {
            new D().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}