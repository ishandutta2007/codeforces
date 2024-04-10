import java.util.Scanner;
import java.io.PrintWriter;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Watermelon implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);

	private int w;
	private String ans;

	public static void main(String[] args) {
		new Thread(new Watermelon()).start();
	}

	private void read() {
		w = in.nextInt();
	}

	private void solve() {
		if (w % 2 == 0 && w >= 4)
			ans = "YES";
		else
			ans = "NO";
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