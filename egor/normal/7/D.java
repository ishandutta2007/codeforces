import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Palindrome implements Runnable {
	private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private PrintWriter out = new PrintWriter(System.out);
	private String s;
	private long ans;

	public static void main(String[] args) {
		new Thread(new Palindrome()).start();
	}

	private void read() {
		try {
			s = in.readLine();
			s = s.trim();
		} catch (IOException e) {
			e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
		}
	}

	private void solve() {
		int n = s.length();
		char[] c = new char[n];
		for (int i = 0; i < n; i++) {
			c[i] = s.charAt(n - i - 1);
		}
		String t = s + "$" + new String(c);
		int[] p = new int[n + 1];
		int[] z = new int[2 * n + 1];
		z[0] = 0;
		int l = 0;
		int r = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (i > r) {
				int j;
				for (j = 0; i + j <= 2 * n && t.charAt(i + j) == t.charAt(j); j++);
				z[i] = j;
				l = i;
				r = i + j - 1;
			} else {
				if (z[i - l] < r - i + 1)
					z[i] = z[i - l];
				else {
					int j;
					for (j = 1; r + j <= 2 * n && t.charAt(r + j) == t.charAt(r - i + j); j++);
					z[i] = r - i + j;
					l = i;
					r = r + j - 1;
				}
			}
		}
		ans = 0;
		for (int k = 1; k <= n; k++) {
			if (z[2 * n + 1 - k] == k) {
				p[k] = p[k / 2] + 1;
				ans += p[k];
			}
		}
	}

	private void write() {
		out.println(ans);
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}