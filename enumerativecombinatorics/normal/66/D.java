import java.util.*;
import java.math.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        int prime[]=new int[50];
        int now=0;
        if(a==2){
            System.out.println("-1");
            System.exit(0);
        }
        for(int i=2;now<50;i++){
            boolean ok=true;
            for(int j=2;j*j<=i;j++)if(i%j==0)ok=false;
            if(ok)prime[now++]=i;
        }
        
        for(int i=0;i<a;i++){
            BigInteger ret=new BigInteger("1");
            for(int j=0;j<a-1;j++)ret=ret.multiply(new BigInteger(""+prime[(i+j)%a]));
            System.out.println(ret.toString());
        }
    }
}