import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		String s = br.readLine();
		String want = "CODEFORCES";
		if (s.length() <= want.length()) {
			out.println("NO");
			out.flush();
			System.exit(0);
		}
		int i;
		for (i = 0; i < want.length(); i++) {
			if (s.charAt(i) != want.charAt(i)) {
				break;
			}
		}
		int remaining = want.length() - i;
		boolean works = true;
		for (i = 0; i < remaining; i++) {
			if (s.charAt(s.length() - 1 - i) != 
					want.charAt(want.length() - 1 - i)) {
				works = false;
				break;
			}
		}
		if (works) {
			out.println("YES");
		}
		else out.println("NO");
		out.flush();
		System.exit(0);
	}

}