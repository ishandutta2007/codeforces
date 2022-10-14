// Codeforces Beta Round #79
// Problem C -- Vector
import java.util.*;

public class C{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        long p[][] = new long[3][2];
        for(int i = 0; i < 3; ++ i){
            for(int j = 0; j < 2; ++ j){
                p[i][j] = scanner.nextInt();
            }
        }
        for(int i = 0; i < 4; ++ i){
            long temp = p[0][0];
            p[0][0] = - p[0][1];
            p[0][1] = temp;
            long c[] = new long[2];
            c[0] = p[1][0] - p[0][0];
            c[1] = p[1][1] - p[0][1];
            long a[] = new long[2];
            a[0] = p[2][0];
            a[1] = p[2][1];
            long b[] = new long[2];
            b[0] = - p[2][1];
            b[1] = p[2][0];
            long delta = a[0] * b[1] - b[0] * a[1];
            if(delta == 0){
                if(c[0] != 0 || c[1] != 0){
                    continue;
                }
                System.out.println("YES");
                return;
            }
            if((b[1] * c[0] - c[1] * b[0]) % delta != 0){
                continue;
            }
            if((a[1] * c[0] - c[1] * a[0]) % delta != 0){
                continue;
            }
            System.out.println("YES");
            return;
        }
        System.out.println("NO");
    }
}