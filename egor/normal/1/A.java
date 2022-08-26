import java.util.Scanner;
import java.io.PrintWriter;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class TheatreSquare implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private int n, m, a;
	private long ans;

	public static void main(String[] args) {
		new Thread(new TheatreSquare()).start();
	}

	private void read() {
		n = in.nextInt();
		m = in.nextInt();
		a = in.nextInt();
	}

	private void solve() {
		ans = (n + a - 1) / a;
		ans *= (m + a - 1) / a;
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