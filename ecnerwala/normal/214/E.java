import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrE {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}

	public static int go(BufferedReader br) throws Exception {
		int n = Integer.parseInt(br.readLine());
		if(n == 1) return Integer.parseInt(br.readLine());
		int[][] grid = new int[n][n];
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				grid[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int[][] best = new int[n][n];
		best[0][0] = grid[0][0];
		for(int s = 1; s <= 2 * (n - 1); s++) {
			int[][] next = new int[n][n];
			for(int a = (s > n - 1 ? s - (n - 1) : 0); a < n && a <= s; a++) {
				for(int b = a; b < n && b <= s; b++) {
					next[a][b] = Integer.MIN_VALUE;
					if(a != 0 && 				best[a-1][b-1] > next[a][b]) next[a][b] = best[a-1][b-1];
					if(s-b != 0 && 				best[a  ][b  ] > next[a][b]) next[a][b] = best[a  ][b  ];
					if(a != 0 && s-b != 0 && 	best[a-1][b  ] > next[a][b]) next[a][b] = best[a-1][b  ];
					if(a != b && 				best[a  ][b-1] > next[a][b]) next[a][b] = best[a  ][b-1];
					next[a][b] += grid[a][s-a] + (a == b ? 0 : grid[b][s-b]);
				}
			}
			best = next;
		}
		return best[n-1][n-1];
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}