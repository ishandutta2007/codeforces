import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(tok.nextToken());
		int m = Integer.parseInt(tok.nextToken());
		long d = Long.parseLong(tok.nextToken());
		Cup[] cup0 = new Cup[n];
		for (int i = 0; i < n; i++) {
			tok = new StringTokenizer(in.readLine());
			cup0[i] = new Cup();
			cup0[i].c = Integer.parseInt(tok.nextToken());
			cup0[i].w = Integer.parseInt(tok.nextToken());
			cup0[i].type = 0;		
		}
		Cup[] cup1 = new Cup[m];
		for (int i = 0; i < m; i++) {
			tok = new StringTokenizer(in.readLine());
			cup1[i] = new Cup();
			cup1[i].c = Integer.parseInt(tok.nextToken());
			cup1[i].w = Integer.parseInt(tok.nextToken());
			cup1[i].type = 1;		
		}
		Arrays.sort(cup0);
		Arrays.sort(cup1);
		long ans = 0;
		int r = 1;
		long w = cup1[0].w;
		long c = cup1[0].c;
		for (int l = 0; l < n; l++) {
			w += cup0[l].w;
			c += cup0[l].c;
			while (r < m && w + cup1[r].w <= d) {
				w += cup1[r].w;
				c += cup1[r].c;
				r++;
			}
			while (r > 1 && w > d) {
				r--;
				w -= cup1[r].w;
				c -= cup1[r].c;
			}
			if (w <= d) {
				ans = Math.max(ans, c);
			}
		}
		in.close();
		System.out.println(ans);
	}
}

class Cup implements Comparable<Cup> {
	public long c, w;
	public long type;
	
	@Override
	public int compareTo(Cup o) {
		if (this.c != o.c) {
			return (int)o.c - (int)this.c;
		} else {
			return (int)this.w - (int)o.w;
		}
	}
}