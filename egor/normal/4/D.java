import java.io.PrintWriter;
import java.util.*;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class MysteriousPackage implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);

	private static class Card implements Comparable<Card> {
		int w, h, n;

		private Card(int w, int h, int n) {
			this.w = w;
			this.h = h;
			this.n = n;
		}

		public int compareTo(Card o) {
			return w - o.w; 
		}
	}

	private int n, w, h;
	private List<Card> cards = new ArrayList<Card>();
	private List<Integer> ans = new ArrayList<Integer>();

	public static void main(String[] args) {
		new Thread(new MysteriousPackage()).start();
	}

	private void read() {
		n = in.nextInt();
		w = in.nextInt();
		h = in.nextInt();
		for (int i = 0; i < n; i++) {
			int ww = in.nextInt();
			int hh = in.nextInt();
			if (ww > w && hh > h)
				cards.add(new Card(ww, hh, i + 1));
		}
	}

	private void solve() {
		Collections.sort(cards);
		n = cards.size();
		int[] d = new int[n];
		int[] l = new int[n];
		int mx = 0;
		int nmx = -1;
		for (int i = 0; i < n; i++) {
			d[i] = 1;
			l[i] = -1;
			for (int j = 0; j < i; j++) {
				if (cards.get(j).h < cards.get(i).h && cards.get(j).w < cards.get(i).w && d[i] <= d[j]) {
					d[i] = d[j] + 1;
					l[i] = j;
				}
			}
			if (d[i] > mx) {
				mx = d[i];
				nmx = i;
			}
		}
		for (int i = mx; i > 0; i--) {
			ans.add(cards.get(nmx).n);
			nmx = l[nmx];
		}
		Collections.reverse(ans);
	}

	private void write() {
		out.println(ans.size());
		if (ans.size() != 0) {
			out.print(ans.get(0));
			for (int i = 1; i < ans.size(); i++)
				out.print(" " + ans.get(i));
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