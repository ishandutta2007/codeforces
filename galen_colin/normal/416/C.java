import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner r = new Scanner(System.in);
        
        int n = ni(r);
        int[] c = new int[n], p = new int[n];
        boolean[] dead = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            c[i] = ni(r);
            p[i] = ni(r);
        }
        
        int k = ni(r);
        boolean[] used = new boolean[k];
        int[] a = new int[k];
        
        for (int i = 0; i < k; i++) {
            a[i] = ni(r);
        }
        
        int[] taken = new int[n], table = new int[n];
        int cnt = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            int mindex = -1;
            for (int j = 0; j < k; j++) {
                if (!used[j]) {
                    if (mindex == -1 || a[j] < a[mindex]) {
                        mindex = j;
                    }
                }
            }
            
            if (mindex != -1) {
                int best = -1;
                for (int j = 0; j < n; j++) {
                    if (!dead[j] && c[j] <= a[mindex]) {
                        if (best == -1 || p[j] > p[best]) {
                            best = j;
                        }
                    }
                }
                
                if (best != -1) {
                    ans += p[best];
                    taken[cnt] = best + 1;
                    table[cnt] = mindex + 1;
                    ++cnt;
                    
                    dead[best] = true;
                }
                used[mindex] = true;
            }
        }
        
        System.out.println(cnt + " " + ans);
        for (int i = 0; i < cnt; i++) {
            System.out.println(taken[i] + " " + table[i]);
        }
    }
    
    static int ni(Scanner s) {
        return Integer.parseInt(s.next());
    }
}