import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(tok.nextToken());
		}
		int[] lens = new int[n];
		int lsz = 0;
		int knt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i-1] != a[i]) {
				lens[lsz++] = knt;
				knt = 1;
			} else {
				knt++;
			}
		}
		lens[lsz++] = knt;
		for (int i = 1; i < lsz; i++) {
			if (lens[i-1] != lens[i]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}