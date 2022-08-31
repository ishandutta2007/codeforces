import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Order implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private int xs, ys, n;
	private int[] x, y;

	public static void main(String[] args) {
		new Thread(new Order()).start();
	}

	private void read() {
		xs = in.nextInt();
		ys = in.nextInt();
		n = in.nextInt();
		x = new int[n];
		y = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
	}

	private void solve() {
		int[] res = new int[1 << n];
		int[] last = new int[1 << n];
		Arrays.fill(res, Integer.MAX_VALUE);
		int[] ds = new int[n];
		for (int i = 0; i < n; i++) {
			ds[i] = (x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys);
		}
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		}
		res[0] = 0;
		for (int i = 1; i < (1 << n); i++) {
			for (int j = 0; j < n; j++) {
				if (((i >> j) & 1) != 0) {
					if (res[i - (1 << j)] + 2 * ds[j] < res[i]) {
						res[i] = res[i - (1 << j)] + 2 * ds[j];
						last[i] = i - (1 << j);
					}
					for (int k = j + 1; k < n; k++) {
						if (((i >> k) & 1) != 0) {
							if (res[i - (1 << j) - (1 << k)] + ds[j] + ds[k] + d[j][k] < res[i]) {
								res[i] = res[i - (1 << j) - (1 << k)] + ds[j] + ds[k] + d[j][k];
								last[i] = i - (1 << j) - (1 << k);
							}
						}
					}
					break;
				}
			}
		}
		int cur = (1 << n) - 1;
		out.println(res[cur]);
		while (cur != 0) {
			out.print("0 ");
			int dif = cur - last[cur];
			for (int i = 0; i < n && dif != 0; i++) {
				if (((dif >> i) & 1) != 0) {
					out.print((i + 1) + " ");
					dif -= (1 << i);
				}
			}
			cur = last[cur];
		}
		out.println("0");
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