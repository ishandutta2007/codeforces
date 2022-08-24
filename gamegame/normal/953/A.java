import java.util.Scanner;
public class project{
    public static int solve(int n) {
        if (n==0)
         return 0;
       int cnt=0;
       int m=n;
       while(n>1){
           n=n/2;
           cnt=cnt+1;
       }
       int ans=0;
       for(int i=0;i<=cnt;i++){
           n=m;
    	    for(int j=1; j<=i ;j++) n/=2;
    	    ans=ans+1;
    	    while(n>=3){
    	        n/=3;
    	        ans=ans+1;
    	    } 
	    }
       	
       return ans;
    }
    public static void main(String[]args){
	Scanner s = new Scanner(System.in);
	int l =s.nextInt()-1, r=s.nextInt();
	/*for(int i=1;i<=n;i++){
	    int tmp=s.nextInt();
	    if(tmp>=memory && tmp>0)
		sum++;
	    if(i==k)
		memory=tmp;
	}*/
	System.out.println(solve(r)-solve(l));
    }
}