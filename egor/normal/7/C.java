import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Line implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private int a, b, c;

	public static void main(String[] args) {
		new Thread(new Line()).start();
	}

	private void read() {
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
	}

	private void solve() {
		int g = gcd(Math.abs(a), Math.abs(b));
		if (c % g != 0) {
			out.println("-1");
			return;
		}
		a /= g;
		b /= g;
		c /= g;
		if (b == 0) {
			int x = -c / a;
			out.println(x + " 0");
			return;
		}
		if (a == 0) {
			int y = -c / b;
			out.println("0 " + y);
			return;
		}
		BigInteger x = new BigInteger(-c + "").multiply(new BigInteger(a + "").modInverse(new BigInteger(Math.abs(b) + ""))).mod(new BigInteger(Math.abs(b) + ""));
		BigInteger y = new BigInteger(-c + "").subtract(new BigInteger(a + "").multiply(x)).divide(new BigInteger(b + ""));
		out.println(x + " " + y);
	}

	private int gcd(int a, int b) {
		while (b != 0) {
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}

	private void write() {
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}