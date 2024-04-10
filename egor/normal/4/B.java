import java.util.Scanner;
import java.io.PrintWriter;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class BeforeExam implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);

	private int d, sumTime;
	private int[] minTime, maxTime;
	private int[] ans;

	public static void main(String[] args) {
		new Thread(new BeforeExam()).start();
	}

	private void read() {
		d = in.nextInt();
		sumTime = in.nextInt();
		minTime = new int[d];
		maxTime = new int[d];
		for (int i = 0; i < d; i++) {
			minTime[i] = in.nextInt();
			maxTime[i] = in.nextInt();
		}
	}

	private void solve() {
		int smin = 0;
		int smax = 0;
		for (int a : minTime)
			smin += a;
		for (int a : maxTime)
			smax += a;
		if (smin > sumTime || sumTime > smax)
			return;
		ans = new int[d];
		for (int i = 0; i < d; i++) {
			smax -= maxTime[i];
			ans[i] = Math.max(minTime[i], sumTime - smax);
			sumTime -= ans[i];
		}
	}

	private void write() {
		if (ans == null)
			out.println("NO");
		else {
			out.println("YES");
			out.print(ans[0]);
			for (int i = 1; i < ans.length; i++)
				out.print(" " + ans[i]);
			out.println();
		}
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}