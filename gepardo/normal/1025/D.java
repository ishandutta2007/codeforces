import java.io.*;
import java.util.*;

public class taskD {
	private static int gcd(int a, int b) {
		return (b != 0) ? gcd(b, a%b) : a;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			v[i] = in.nextInt();
		}
		Arrays.sort(v);
		boolean[][] g = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = gcd(v[i], v[j]) != 1;
			}
		}
		boolean[][] L = new boolean[n][n], R = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			L[i][i] = R[i][i] = true;
		}
		for (int i = n-1; i >= 0; i--) {
			for (int j = i+1; j < n; j++) {
				for (int k = i; k < j; k++) {
					if (g[j][k]) {
						L[i][j] |= L[i][k] && R[j-1][k];
						if (L[i][j]) {
							break;
						}
					}
				}
				for (int k = i+1; k <= j; k++) {
					if (g[i][k]) {
						R[j][i] |= L[i+1][k] && R[j][k];
						if (R[j][i]) {
							break;
						}
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (L[0][i] && R[n-1][i]) {
				System.out.println("Yes\n");
				return;
			}
		}
		System.out.println("No\n");
	}
}