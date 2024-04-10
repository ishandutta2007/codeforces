import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    int n, m;
    int[] edgesFrom;
    int[] edgesTo;
    int[][] pairs;

    public void replace(int[] from, int[] to) {
        for (int i = 0; i < pairs.length; i++) {
            if (pairs[i][0] == from[0] && pairs[i][1] == from[1]) {
                pairs[i] = to.clone();
            }
        }
    }

    public boolean checkAll(int[] pair) {
        for (int i = 0; i < pairs.length; i++) {
            if (pairs[i][0] != pair[0] || pairs[i][1] != pair[1]) {
                return false;
            }
        }
        return true;
    }

    public boolean addEdge(int from, int to) {
        if (from != pairs[from][0] && from != pairs[from][1]) {
            return false;
        }
        if (to != pairs[to][0] && to != pairs[to][1]) {
            return false;
        }
        int fromOther = pairs[from][0] + pairs[from][1] - from;
        int toOther = pairs[to][0] + pairs[to][1] - to;
        if (fromOther == -1 || toOther == -1) return false;
        if (fromOther == to) {
            if (!checkAll(pairs[from])) return false;
            replace(pairs[from], new int[]{-1, -1});
            return true;
        }
        int[] newPair = new int[]{Math.min(fromOther, toOther), Math.max(fromOther, toOther)};
        replace(pairs[from], newPair);
        replace(pairs[to], newPair);
        return true;
    }

    public void run(Scanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        if (n == 1) {
            if (m == 0) {
                out.println("YES");
                out.println("1");
                out.println("1 1");
                return;
            }
            if (m == 1) {
                out.println("YES");
                out.println("0");
                return;
            }
            out.println("NO");
            return;
        }
        edgesFrom = new int[m];
        edgesTo = new int[m];
        for (int i = 0; i < m; i++) {
            edgesFrom[i] = in.nextInt() - 1;
            edgesTo[i] = in.nextInt() - 1;
            if (edgesFrom[i] == edgesTo[i]) {
                out.println("NO");
                return;
            }
        }
        pairs = new int[n][];
        for (int i = 0; i < n; i++) {
            pairs[i] = new int[]{i, i};
        }
        for (int i = 0; i < m; i++) {
            if (!addEdge(edgesFrom[i], edgesTo[i])) {
                out.println("NO");
                return;
            }
        }
        if (n == 2) {
            out.println("YES");
            out.println(2 - m);
            for (int i = 0; i < 2 - m; i++) {
                out.println("1 2");
            }
            return;
        }
        List<int[]> answer = new ArrayList<int[]>();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (addEdge(i, j)) {
                    answer.add(new int[]{i + 1, j + 1});
                }
            }
        }
        if (!checkAll(new int[]{-1, -1})) {
            out.println("NO");
            return;
        }
        out.println("YES");
        out.println(answer.size());
        for (int[] pair : answer) {
            out.println(pair[0] + " " + pair[1]);
        }
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