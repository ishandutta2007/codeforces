import java.io.*;
import java.util.*;

public class D {
	
	static class Pair {
		public int x;
		public int y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public Pair moveTo(Pair other) {
			return new Pair(other.x - x, other.y - y);
		}
		public Pair move(Pair move) {
			return new Pair(move.x + x, move.y + y);
		}
		public int hashCode() {
			final int prime = 107;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
		public boolean isValid(int n) {
			return x <= n && y <= n && x > 0 && y > 0;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine()); // N <= 50
		boolean[][] attacked = new boolean[2 * n - 1][2 * n - 1];
		Set<Pair> pieces = new HashSet<Pair>();
		Set<Pair> hits = new HashSet<Pair>();
		Set<Pair> empties = new HashSet<Pair>();
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < n; j++) {
				char c = line.charAt(j);
				Pair p = new Pair(j + 1, i + 1);
				if (c == 'o') {
					pieces.add(p);
				}
				else if (c == 'x') {
					hits.add(p);
				}
				else {
					empties.add(p);
				}
			}
		}
		boolean possible = true;
		while (!hits.isEmpty()) {
			possible = false;
			Pair currHit = hits.iterator().next();
			for (Pair piece : pieces) {
				boolean works = true;
				Pair move = piece.moveTo(currHit);
				Set<Pair> remainingHits = new HashSet<>(hits);
				for (Pair piece2 : pieces) {
					Pair moved = piece2.move(move);
					if (moved.isValid(n)) {
						if (empties.contains(moved)) {
							works = false;
						}
						else if (remainingHits.contains(moved)) {
							remainingHits.remove(moved);
						}
					}
				}
				if (works) {
					hits = remainingHits;
					attacked[n - 1 + move.y][n - 1 + move.x] = true;
					possible = true;
					break;
				}
			}
			if (!possible) {
				break;
			}
		}
		if (possible) {
			out.println("YES");
			for (int i = 0; i < 2 * n - 1; i++) {
				for (int j = 0; j < 2 * n - 1; j++) {
					if (i == n - 1 && j == n - 1) {
						out.print('o');
						continue;
					}
					if (attacked[i][j]) out.print('x');
					else out.print('.');
				}
				out.println();
			}
		}
		else {
			out.println("NO");
		}
		out.flush();
		System.exit(0);
	}

}