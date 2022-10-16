import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class TaskB {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		in.close();
		char cChar = ("" + c).charAt(0);
		BigDecimal ad = BigDecimal.valueOf(a);
		BigDecimal bd = BigDecimal.valueOf(b);
		BigDecimal res = ad.divide(bd, (int)1e5, RoundingMode.FLOOR);
		String resStr = res.toEngineeringString();
		int i = 2;
		while(i < resStr.length() - 1) {
			char cc = resStr.charAt(i);
			if (cc == cChar) {
				System.out.println(i - 1);
				System.exit(0);
			}
			++i;
		}
		System.out.println(-1);
	}
}