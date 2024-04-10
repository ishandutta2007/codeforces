import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Chess implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private String[] s = new String[8];
	private int ans;

	public static void main(String[] args) {
		new Thread(new Chess()).start();
	}

	private void read() {
		for (int i = 0; i < 8; i++)
			s[i] = in.next();
	}

	private void solve() {
		ans = 0;
		for (int i = 0; i < 8; i++) {
			boolean vertical = true;
			boolean horizontal = true;
			for (int j = 0; j < 8; j++) {
				if (s[i].charAt(j) == 'W')
					horizontal = false;
				if (s[j].charAt(i) == 'W')
					vertical = false;
			}
			if (horizontal)
				ans++;
			if (vertical)
				ans++;
		}
		if (ans == 16)
			ans = 8;
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