import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    //f you CollegeBoard for making me write in Java
	    Scanner input = new Scanner(System.in);
	    int n = input.nextInt(); 
	    int m = input.nextInt();
	    long[] fact = new long[n+1];
	    fact[0]=1;
	    for(int i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%m;
	    long ans = 0;
	    for(int i=1; i<=n; i++) {
	        long v=(1L*(n-i+1)*(n-i+1))%m;
	        v*=(fact[i]*fact[n-i])%m;
	        ans+=v; ans%=m;
	    } 
	    System.out.println(ans);
	}
}