import java.util.*;
import java.math.*;

public class a
{
	public static void main(String arg[])
	{
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		boolean[] flag = new boolean[26];
		int difChar = 10;
		
		BigInteger ans = BigInteger.ONE;
		for (int i = 0; i < s.length(); i++)
			if (s.charAt(i) == '?') 
				ans = ans.multiply(BigInteger.valueOf(10 - (i == 0 ? 1 : 0)));
			else
				if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')
				{
					if (flag[s.charAt(i) - 'A'] == true) continue;
					flag[s.charAt(i) - 'A'] = true;
					ans = ans.multiply(BigInteger.valueOf(difChar - (i == 0 ? 1 : 0)));
					difChar--;
				}
				
		System.out.println(ans);
	}
}