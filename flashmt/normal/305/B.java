import java.util.*;
import java.math.*;

public class b
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		BigInteger p = sc.nextBigInteger();
		BigInteger q = sc.nextBigInteger();
		int n = sc.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) a[i] = sc.nextLong();
		
		BigInteger numerator = BigInteger.valueOf(a[n - 1]);
		BigInteger denominator = BigInteger.ONE;
		
		for (int i = n - 2; i >= 0; i--)
		{
			BigInteger tmp = numerator;
			numerator = denominator;
			denominator = tmp;
			numerator = numerator.add(denominator.multiply(BigInteger.valueOf(a[i])));
		}
		
		System.out.println(numerator.multiply(q).compareTo(p.multiply(denominator)) == 0 ? "YES" : "NO");
	}
}