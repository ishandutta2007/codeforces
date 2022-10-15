import java.util.*;
import java.io.*;

public class P476B {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		String real = br.readLine();
		String fake = br.readLine();
		int realPos = 0;
		for (int i = 0; i < real.length(); i++) {
			if (real.charAt(i) == '+') realPos++;
			else realPos--;
		}
		int fakePos = 0;
		int fakeUnsure = 0;
		for (int i = 0; i < fake.length(); i++) {
			if (fake.charAt(i) == '?') fakeUnsure++;
			else if (fake.charAt(i) == '+') fakePos++;
			else fakePos--;
		}
		if ((fakeUnsure - Math.abs(realPos - fakePos)) % 2 == 1) {
			out.println(0.0);
		}
		else {
			int n = fakeUnsure;
			int r = (fakeUnsure - Math.abs(realPos - fakePos)) / 2;
			if (r < 0 || r > n) {
				out.println(0.0);
			}
			else {
				int numer = 1;
				for (int i = 0; i < r; i++) {
					numer *= n - i;
					numer /= i + 1;
				}
				double denom = Math.pow(2, fakeUnsure);
				out.println(numer / denom);
			}
		}
		out.flush();
		System.exit(0);
	}
	
}