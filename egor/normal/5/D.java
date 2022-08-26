import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Egor Kulikov (egor@egork.net)
 *         Created on 14.03.2010
 */
public class Rules implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private double a, v, l, d, w;
	private double ans;

	public static void main(String[] args) {
		new Thread(new Rules()).start();
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}

	private void read() {
		a = in.nextInt();
		v = in.nextInt();
		l = in.nextInt();
		d = in.nextInt();
		w = in.nextInt();
	}

	private double remaining(double v0, double dst) {
		double t = (v - v0) / a;
		double d = a * t * t / 2 + t * v0;
		if (d > dst)
			return (Math.sqrt(v0 * v0 + 2 * a * dst) - v0) / a;
		return t + (dst - d) / v;
	}

	private void solve() {
		if (w * w >= 2 * a * d || w >= v) {
			ans = remaining(0, l);
			return;
		}
		{
			double t1 = v / a;
			double t2 = (v - w) / a;
			double dd = a * t1 * t1 / 2 + a * t2 * t2 / 2 + w * t2;
			if (dd < d) {
				ans = t1 + t2 + (d - dd) / v + remaining(w, l - d);
				return;
			}
		}
		double t1 = w / a;
		double rd = d - t1 * t1 * a / 2;
		double t2 = (Math.sqrt(w * w + a * rd) - w) / a;
		ans = t1 + 2 * t2 + remaining(w, l - d);
	}

	private void write() {
		out.printf("%.7f\n", ans);
	}
}