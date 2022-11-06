import java.io.*;
import java.util.*;
public class Main {
    public static void main(String args[]) throws Exception {
        Scanner cin=new Scanner(System.in);
		int n=cin.nextInt(),temp1=0,temp2=0;
		for(int i=1;i<=n;i++)
		{
			int x=cin.nextInt();
			if(x%2==1) temp1++;
			else temp2++;
		}
		int ans;
		if(temp1>temp2) ans=temp2;
		else ans=temp1;
		if(temp1>temp2)
		{
			temp1=temp1-temp2;
			ans+=temp1/3;
		}
        System.out.println(ans);
    }
}