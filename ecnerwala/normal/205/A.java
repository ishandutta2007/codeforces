import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

/*
 ID: he.andr1
 LANG: JAVA
 TASK: PrA
 */

public class PrA {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br, System.out);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br, PrintStream out) throws Exception {
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int min = Integer.MAX_VALUE;
		String output = "Still Rozdil";
		for(int i = 1; i <= n; i++) {
			int cur = Integer.parseInt(st.nextToken());
			if(cur < min) {
				min = cur;
				output = Integer.toString(i);
			} else if (cur == min) output = "Still Rozdil";
		}
		out.println(output);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}