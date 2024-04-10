import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Train implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private String s, t1, t2;
	private boolean forward, backward;

	public static void main(String[] args) {
		new Thread(new Train()).start();
	}

	private void read() {
		s = in.next();
		t1 = in.next();
		t2 = in.next();
	}

	private void solve() {
		int index = s.indexOf(t1);
		if (index != -1)
			forward = s.indexOf(t2, index + t1.length()) != -1;
		StringBuilder buf = new StringBuilder(s);
		buf.reverse();
		s = buf.toString();
		index = s.indexOf(t1);
		if (index != -1)
			backward = s.indexOf(t2, index + t1.length()) != -1;
	}

	private void write() {
		if (forward) {
			if (backward)
				out.println("both");
			else
				out.println("forward");
		} else {
			if (backward)
				out.println("backward");
			else
				out.println("fantasy");
		}
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}