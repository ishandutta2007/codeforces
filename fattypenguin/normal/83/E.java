import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.Random;

public class Main 
{    
    static int res;
    static int n,prefix[][],suffix[][];
    static int f[][],a[],L,sum[];
    public static void put(int id,int best)
    {
        if (id>=0)res = Math.min(res, best+sum[n-1]);
        if (-1 == id)
        {
            f[0][L]=best;
            return;
        }
        for (int i = 0;i < L+1;++i)
            f[suffix[id][i]][i] = Math.min(f[suffix[id][i]][i],best);
    }
    public static int distance(int a,int b)
    {
        if (-1 == a || b >= n) return L;
        for (int i = 0;i < L;++i)
            if (suffix[a][i] == prefix[b][i])
                return i;
        return L;
    }
    public static void main(String[] args)   
    {
        Scanner cin=new Scanner(System.in);
        n = cin.nextInt();
        a = new int[n+10];
        String buf;
        for (int i = 0;i < n;++i)
        {
            buf = cin.next();
            L = buf.length();
            a[i] = 0;
            for (int j = 0;j < L;++j)
                a[i] = a[i] * 2 + (buf.charAt(j) - '0');
        }
        if (n == 1)
        {
            System.out.println(L);
            return;
        }
        prefix = new int[n+10][L+1];
        suffix = new int[n+10][L+1];
        sum = new int[n+10];
        f = new int[1<<L][L+1];
        int dp[] = new int[n+10];
        for (int i = 0;i < n;++i)
        {
            for (int j = 0;j < L+1;++j)
            {
                suffix[i][j] = a[i] & ((1 << (L-j))-1);
                prefix[i][j] = a[i] >> j; 
            }
        }
        for (int i = 0;i < (1<<L);++i)
            for (int j = 0;j < L+1;++j)
                f[i][j] = 0x7f7f7f7f;
        sum[0] = 0;
    //  System.out.println("ll");
        for (int i = 1;i < n;++i)
        {
            sum[i] = distance(i-1,i);
            if (i > 0) sum[i] += sum[i-1];
       //   System.out.println(sum[i]);
        }
        sum[n] = sum[n-1];
        res = 0x7f7f7f7f;
        put(-1,0);
        for (int i = 0;i < n;++i)
        {
            int step = 0x7f7f7f7f;
            for (int j = 0;j < L+1;++j)
                step = Math.min(step, f[prefix[i][j]][j] + j + sum[Math.max(0,i-1)]);
            put(i-1,step-sum[i]);
        //  System.out.println(step);
            if (i == n-1) res = Math.min(res,step);
        }
        System.out.println(res);
    }
}