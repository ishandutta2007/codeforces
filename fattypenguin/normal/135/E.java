import java.util.*;
import java.io.*;

public class Main
{
    static int MOD = 1000000007;
    static int dfac[],fac[],inv[];
    
    public static void generateInv(int maxn)
    {
        inv = new int[maxn+1];
        inv[1] = 1;
        for (int i = 2;i <= maxn;++i)
            inv[i] = (int)((long) inv[MOD%i] * (MOD - MOD/i) % MOD); 
    }
    
    public static int A(int n,int r)
    {
        return (int)((long)fac[n] * dfac[n-r] % MOD);
    }
    
    public static int quickPow(int x,int n)
    {
        long ans = 1;
        for (;n != 0;n >>= 1)
        {
            if ((n & 1) != 0) ans = ans * x % MOD;
            x = (int)((long) x * x % MOD);
        }
        return (int)ans;
    }
    
    public static int eat(int len,int k,int w)
    {
        long ret = A(k,len);
        int delta = len - (w - 1);
        if (delta >= 0)
        {
            ret = ret * A(k-delta,len-delta) % MOD;
        }
        else
        {
            ret = ret * A(k,len) % MOD;
            ret = ret * quickPow(k,w-1-len) % MOD;
        }
        return (int)ret;
    }
    
    public static int fuck(int k,int w,boolean inclusive)
    {
        long ret = 0;
        for (int i = inclusive ? 1 : 2;i <= k;++i)
            ret = (ret + eat(i,k,w)) % MOD;
        return (int)ret;
    }
    
    public static int gao(int k,int w)
    {
        fac = new int[k+1];
        dfac = new int[k+1];
        fac[0] = 1;
        for (int i = 1;i <= k;++i)
            fac[i] = (int)((long)fac[i-1] * i % MOD);
        generateInv(k);
        dfac[0] = 1;
        for (int i = 1;i <= k;++i)
            dfac[i] = (int)((long)dfac[i-1] * inv[i] % MOD);
        return ( (fuck(k,w+1,true) - fuck(k,w,false) ) % MOD + MOD) % MOD;
    }
    
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int k = cin.nextInt(), w = cin.nextInt();
        System.out.println(gao(k,w));
    }
}