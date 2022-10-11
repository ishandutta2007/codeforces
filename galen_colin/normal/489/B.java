/* testing code for haddadi */

import java.util.Arrays;
import java.util.Scanner;
 
public class CF489B {
 
	
	static int [] b;
	static int[] g;
	static int [][] dp;
	public static int sol(int i, int j, int n, int m) {
 
		if(i==n) return 0;
		if(j==m) return 0;
		if(dp[i][j] !=-1) return dp[i][j];
		int tmp1=0, tmp2=0, tmp3=0;
		tmp2 = sol(i+1, j, n, m);
		tmp3 = sol(i, j+1, n, m);
		if(Math.abs(b[i] - g[j]) <=1) {
			tmp1 = 1 + sol(i+1, j+1, n, m);
		}
		return dp[i][j]= Math.max(tmp1, Math.max(tmp2, tmp3));
	}
	
	
	
	
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m;
		n=sc.nextInt();
		b = new int[n];
		for(int i=0;i<n;i++) {
			b[i] = sc.nextInt();			
		}
		m=sc.nextInt();
		g = new int[m];
		for(int i=0;i<m;i++) {
			g[i] = sc.nextInt();			
		}
		Arrays.sort(b);
		Arrays.sort(g);
		dp = new int [102][102];
		for(int i=0;i<102;i++) {
			for(int j=0;j<102;j++) {
				dp[i][j] = -1;
			}
		}
		int ans =0;
		ans = sol(0,0, n, m);
		System.out.println(ans);
		
		
	}
 
}