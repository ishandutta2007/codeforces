import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
		static int n, k, m;
		static int[] v = new int[123456];

    public static void main(String[] args) {
    		Scanner in = new Scanner(System.in);

				n = in.nextInt();
				k = in.nextInt();
				m = in.nextInt();
				long sum = 0;
				for (int i = 0; i < n; i++) {
					v[i] = in.nextInt();
					sum += v[i];
				}
				Arrays.sort(v, 0, n);
				double best = (sum+Math.min(m*1., k * 1. * n))*1./n;
				for (int i = 0; i < n-1; i++) {
					if (m == i) break;
					sum -= v[i];
					best = Math.max(best, (sum + Math.min(m - i - 1, k*1.*(n-1-i)))*1./ (n-i-1));

				}
				System.out.println(best);
		}
}