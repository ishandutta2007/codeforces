import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static final int maxn = 100000;
    static ArrayList<Integer>[] G = new ArrayList[maxn + 1];
    static long[][] c = new long[3][maxn + 1];
    static int[] p = new int[maxn + 1];
    static int[] cans = new int[maxn + 1];
    static int id = 0;
    static void DFS(int u, int pa){
        p[id += 1] = u;
        for(int v : G[u])
            if(v != pa)
                DFS(v, u);
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for(int i = 0; i < 3; i += 1)
            for(int j = 1; j <= n; j += 1)
                c[i][j] = scanner.nextLong();
        for(int i = 1; i <= n; i += 1) G[i] = new ArrayList();
        for(int i = 1; i < n; i += 1){
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            G[u].add(v);
            G[v].add(u);
        }
        int root = 0;
        for(int i = 1; i <= n; i += 1){
            if(G[i].size() > 2){
                System.out.print(-1);
                return;
            }
            if(G[i].size() == 1 && root == 0) root = i;
        }
        DFS(root, 0);
        long ans = 1000000000000000000L;
        int x = 0, y = 0;
        for(int i = 0; i < 3; i += 1)
            for(int j = 0; j < 3; j += 1) if(i != j){
                int[] r = {3 - i - j, i, j};
                long pans = 0;
                for(int k = 1; k <= n; k += 1) pans += c[r[k % 3]][p[k]];
                if(pans < ans){
                    ans = pans;
                    x = i;
                    y = j;
                }
            }
        int[] r = {3 - x - y, x, y};
        for(int i = 1; i <= n; i += 1) cans[p[i]] = r[i % 3] + 1;
        System.out.println(ans);
        for(int i = 1; i <= n; i += 1) System.out.printf("%d ", cans[i]);
    }
}