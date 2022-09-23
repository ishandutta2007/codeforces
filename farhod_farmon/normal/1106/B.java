import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner input = new Scanner(new FileInputStream("input.txt"));
        //PrintStream output = new PrintStream(new FileOutputStream("output.txt"));
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        Integer a[] = new Integer[n];
        int c[] = new int[n];

        for(int i = 0; i < n; ++i){
            a[i] = input.nextInt();
        }
        for(int i = 0; i < n; ++i) {
            c[i] = input.nextInt();
        }
        Integer v[] = new Integer[n];
        for(int i = 0; i < n; ++i){
            v[i] = i;
        }
        Arrays.sort(v, new Comparator<Integer>()
        {
            public int compare(Integer i, Integer j){
                if(c[i] == c[j]){
                    return i - j;
                }
                return c[i] - c[j];
            }
        });
        int it = 0;
        for(int i = 0; i < m; ++i){
            int t = input.nextInt() - 1;
            int d = input.nextInt();
            int g = Math.min(d, a[t]);
            d -= g;
            a[t] -= g;
            long res = (long)g * c[t];
            while(d > 0 && it < n){
                int x = v[it];
                g = Math.min(d, a[x]);
                d -= g;
                a[x] -= g;
                res += (long)g * c[x];
                if(a[x] == 0){
                    it += 1;
                }
            }
            if(d > 0){
                res = 0;
            }
            System.out.println(res);
        }

        //input.close();
        //output.close();
    }
}