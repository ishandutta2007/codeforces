import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    int l = Integer.parseInt(reader.readLine());
    String s = reader.readLine();

    int m = l + 1;
    for (int i = 0; i < l - 1; i++) {
      if (s.charAt(i + 1) != '0') {
        m = Math.min(Math.abs(l - 2*i - 2), m);
      }
    }

    BigInteger best = new BigInteger(s);
    for (int i = 0; i < l - 1; i++) {
      if (s.charAt(i + 1) != '0' && Math.abs(l - 2*i - 2) <= m + 1) {
        BigInteger cur = (new BigInteger(s.substring(0, i + 1))).add(new BigInteger(s.substring(i + 1, l)));
        if (best.compareTo(cur) > 0) best = cur;
      }
    }
    PrintWriter writer = new PrintWriter(System.out);
    System.out.println(best.toString());
  }

  static void pl(Object o) {
    System.out.println(o);
  }
}