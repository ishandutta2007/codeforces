import java.util.*;
import java.math.*;

public class c
{
  static final BigInteger ZERO = new BigInteger("0");
	static final BigInteger ONE = new BigInteger("1");
	static final BigInteger TWO = new BigInteger("2");
	static final BigInteger TEN = new BigInteger("10");
  
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    BigInteger a = sc.nextBigInteger();
    TreeMap <BigInteger, BigInteger> map = new TreeMap <BigInteger, BigInteger>();
    
    while (true)
    {
      BigInteger x = new BigInteger(60, new Random());
      BigInteger u = sumF(x);
      
      BigInteger low = ZERO, high = TEN.pow(18), res = ZERO;
      while (low.compareTo(high) < 0)
      {
        BigInteger mid = low.add(high).divide(TWO);
        if (sumF(x.add(mid)).subtract(u).compareTo(a.subtract(u.mod(a))) >= 0)
        {
          res = mid;
          high = mid.subtract(ONE);
        }
        else low = mid.add(ONE);
      }
      
      x = x.add(res);
      BigInteger v = sumF(x).mod(a);
      BigInteger y = map.get(v);
      if (y != null && y.compareTo(x) != 0)
      {
        System.out.println(x.min(y).add(ONE) + " " + x.max(y));
        return;
      }
      
      map.put(v, x);
    }
  }
  
  private static BigInteger sumF(BigInteger x)
  {
    BigInteger res = sumDigit(x);
    BigInteger power = ONE;
    while (x.compareTo(power) != -1)
    {
      int digit = x.divide(power).mod(TEN).intValue();
      for (int d = 1; d < 10; d++)
      {
        BigInteger prefix = x.divide(power).divide(TEN);
        BigInteger suffix = x.mod(power);
        BigInteger count = prefix.add(d < digit ? ONE : ZERO).multiply(power);
        if (d == digit) count = count.add(suffix);
        res = res.add(count.multiply(BigInteger.valueOf(d)));
      }
      
      power = power.multiply(TEN);
    }
    return res;
  }
  
  private static BigInteger sumDigit(BigInteger x)
  {
    return x.compareTo(TEN) < 0 ? x : sumDigit(x.divide(TEN)).add(x.mod(TEN));
  }
}