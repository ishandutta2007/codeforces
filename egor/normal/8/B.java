import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Robot implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private String s;
	private char[] dir = {'L', 'U', 'R', 'D'};
	private int[] dx = {-1, 0, 1, 0};
	private int[] dy = {0, 1, 0, -1};
	private String ans;

	private static class Position {
		private int x, y;

		private Position(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) {
				return true;
			}
			if (o == null || getClass() != o.getClass()) {
				return false;
			}

			Position position = (Position) o;

			if (x != position.x) {
				return false;
			}
			if (y != position.y) {
				return false;
			}

			return true;
		}

		@Override
		public int hashCode() {
			int result = x;
			result = 31 * result + y;
			return result;
		}
	}

	public static void main(String[] args) {
		new Thread(new Robot()).start();
	}

	private void read() {
		s = in.next();
	}

	private void solve() {
		Set<Position> w = new HashSet<Position>();
		int x = 0;
		int y = 0;
		for (char c : s.toCharArray()) {
			for (int i = 0; i < 4; i++) {
				if (c != dir[i])
					w.add(new Position(x + dx[i], y + dy[i]));
			}
			w.add(new Position(x, y));
			for (int i = 0; i < 4; i++) {
				if (c == dir[i]) {
					x += dx[i];
					y += dy[i];
				}
			}
			if (w.contains(new Position(x, y))) {
				ans = "BUG";
				return;
			}
		}
		ans = "OK";
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