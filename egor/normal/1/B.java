import java.util.Scanner;
import java.io.PrintWriter;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Spreadsheets implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private String s, ans;

	public static void main(String[] args) {
		new Thread(new Spreadsheets()).start();
	}

	private void read() {
		s = in.next();
	}

	private void solve() {
		if (s.matches("R\\d+C\\d+")) {
			s = s.replace('R', ' ').replace('C', ' ');
			Scanner ss = new Scanner(s);
			int r = ss.nextInt();
			int c = ss.nextInt();
			c--;
			StringBuffer b = new StringBuffer();
			int c26 = 26;
			int cc = 0;
			while (cc + c26 <= c) {
				cc += c26;
				c26 *= 26;
			}
			c -= cc;
			while (c26 > 1) {
				c26 /= 26;
				b.append((char) (c / c26 + 'A'));
				c %= c26;
			}
			ans = b.toString() + r;
		} else {
			int p = 0;
			while (!Character.isDigit(s.charAt(p))) {
				p++;
			}
			int c26 = 1;
			int cc = 0;
			for (int i = 0; i < p; i++) {
				cc += c26;
				c26 *= 26;
			}
			for (int i = 0; i < p; i++) {
				c26 /= 26;
				cc += c26 * (s.charAt(i) - 'A');
			}
			ans = "R" + s.substring(p) + "C" + cc;
		}
	}

	private void write() {
		out.println(ans);
	}

	public void run() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			read();
			solve();
			write();
		}
		out.close();
	}
}