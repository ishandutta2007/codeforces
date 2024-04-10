import java.io.*;
import java.util.*;

public class C {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int maxH = 0;
		boolean possible = true;
		st = new StringTokenizer(br.readLine());
		int prevPos = Integer.parseInt(st.nextToken());
		int prevH = Integer.parseInt(st.nextToken());
		if (prevH + prevPos - 1 > maxH) {
			maxH = prevH + prevPos - 1;
		}
		for (int i = 1; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int pos = Integer.parseInt(st.nextToken());
			int h = Integer.parseInt(st.nextToken());
			int slack = (pos - prevPos) - (int) Math.abs(h - prevH);
			if (slack < 0) {
				possible = false;
				break;
			}
			int localMax = slack / 2 + Math.max(prevH, h);
			if (localMax > maxH) {
				maxH = localMax;
			}
			prevPos = pos;
			prevH = h;
		}
		if (n - prevPos + prevH > maxH) {
			maxH = n - prevPos + prevH;
		}
		if (possible) out.println(maxH);
		else out.println("IMPOSSIBLE");
		out.flush();
		System.exit(0);
	}

}