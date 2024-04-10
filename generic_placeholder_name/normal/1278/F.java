import java.util.*;

public class Main
{
    public static final long MOD=998244353;
    static long add(long x, long y) {
        return ((x+y)%MOD+MOD)%MOD;
    }
    static long mult(long x, long y) {
        return ((x*y*1L)%MOD+MOD)%MOD;
    }
    static long exp(long x, long y) {
        if(y==0) return 1;
        else {
            long k = exp(x, y/2);
            if(y%2==0) return mult(k, k);
            else return mult(mult(k, k), x);
        }
    }
    static long inv(long x) {
        return exp(x, MOD-2);
    }
    
	public static void main(String[] args) {
	    //f you CollegeBoard for making me write in Java
	    Scanner sc = new Scanner(System.in);
	    long n = sc.nextLong();
	    long m = sc.nextLong();
	    int k = sc.nextInt();
	    long[][] dp = new long[k+1][k+1];
	    dp[0][0]=1;
	    for(int i=0; i<k; i++) {
		    for(int j=0; j<k; j++) {
			    dp[i+1][j] = add(dp[i+1][j], mult(dp[i][j], j));
			    dp[i+1][j+1] = add(dp[i+1][j+1], mult(dp[i][j], n-j));
		    }
	    }
	    long ans=0; 
	    for(int i=1; i<=k; i++) ans=add(ans, mult(dp[k][i], exp(inv(m), i)));
	    System.out.println(ans);
	}
}