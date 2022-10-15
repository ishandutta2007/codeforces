import java.io.*;
import java.util.*;

public class P2B {
	
	static int n;
	static int[][] ar;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		n = Integer.parseInt(br.readLine());
		ar = new int[n][n];
		boolean hasZero = false;
		int zeroA = -1;
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				int k = Integer.parseInt(st.nextToken());
				ar[i][j] = k;
				if (k == 0) {
					hasZero = true;
					zeroA = i;
					ar[i][j] = 10;
				}
			}
		}
		// account for cases with zero
		int best = hasZero ? 1 : Integer.MAX_VALUE;
		int[][] dp2 = new int[n][n];
		int[][] dp5 = new int[n][n];
		char[][] path2 = new char[n][n];
		char[][] path5 = new char[n][n];
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = - (n - 1 - i - Math.abs(n - 1 - i)) / 2; 
					j <= n - 1 - ((n - 1 - i + Math.abs(n - 1 - i)) / 2); j++) {
				int a = j;
				int b = i - j;
				if (a == 0 && b == 0) {
					dp2[a][b] = factors(ar[a][b], 2);
					dp5[a][b] = factors(ar[a][b], 5);
					path2[a][b] = ' ';
					path5[a][b] = ' ';
				}
				else if (a == 0) {
					dp2[a][b] = factors(ar[a][b], 2) + dp2[a][b - 1];
					dp5[a][b] = factors(ar[a][b], 5) + dp5[a][b - 1];
					path2[a][b] = 'R';
					path5[a][b] = 'R';
				}
				else if (b == 0) {
					dp2[a][b] = factors(ar[a][b], 2) + dp2[a - 1][b];
					dp5[a][b] = factors(ar[a][b], 5) + dp5[a - 1][b];
					path2[a][b] = 'D';
					path5[a][b] = 'D';
				}
				else {
					if (dp2[a - 1][b] < dp2[a][b - 1]) {
						dp2[a][b] = factors(ar[a][b], 2) + dp2[a - 1][b];
						path2[a][b] = 'D';
					}
					else {
						dp2[a][b] = factors(ar[a][b], 2) + dp2[a][b - 1];
						path2[a][b] = 'R';
					}
					if (dp5[a - 1][b] < dp5[a][b - 1]) {
						dp5[a][b] = factors(ar[a][b], 5) + dp5[a - 1][b];
						path5[a][b] = 'D';
					}
					else {
						dp5[a][b] = factors(ar[a][b], 5) + dp5[a][b - 1];
						path5[a][b] = 'R';
					}
				}
			}
		}
		if (best < dp2[n - 1][n - 1] && best < dp5[n - 1][n - 1]) {
			out.println(1);
			StringBuilder path = new StringBuilder();
			for (int i = 0; i < zeroA; i++) {
				path.append('D');
			}
			for (int i = 0; i < n - 1; i++) {
				path.append('R');
			}
			for (int i = 0; i < n - zeroA - 1; i++) {
				path.append('D');
			}
			out.println(path.toString());
		}
		else if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1]) {
			out.println(dp2[n - 1][n - 1]);
			out.println(getPath(path2));
		}
		else {
			out.println(dp5[n - 1][n - 1]);
			out.println(getPath(path5));
		}
		out.flush();
		System.exit(0);
	}
	
	static int factors(int n, int d) {
		int ret = 0;
		while (n % d == 0) {
			n /= d;
			ret++;
		}
		return ret;
	}
	
	static String getPath(char[][] path) {
		StringBuilder ret = new StringBuilder();
		int currA = n - 1;
		int currB = n - 1;
		while (path[currA][currB] != ' ') {
			ret.append(path[currA][currB]);
			if (path[currA][currB] == 'D') {
				currA--;
			}
			else {
				currB--;
			}
		}
		return ret.reverse().toString();
	}
	
}