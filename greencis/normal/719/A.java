import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int[] p = new int[n];
    for (int i = 0; i < n; ++i)
      p[i] = in.nextInt();
    if (p[n - 1] == 0)
      out.println("UP");
    else if (p[n - 1] == 15)
      out.println("DOWN");
    else if (n == 1)
      out.println("-1");
    else if (p[n - 2] > p[n - 1])
      out.println("DOWN");
    else
      out.println("UP");
    out.close(); // important!
  }
}