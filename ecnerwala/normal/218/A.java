import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int last = Integer.parseInt(st.nextToken());
		out.print(last);
		out.print(' ');
		for(; n > 0; n--) {
			int peak = Integer.parseInt(st.nextToken());
			int next = Integer.parseInt(st.nextToken());
			if(k > 0 && peak - 1 > last && peak - 1 > next) {
				peak --;
				k--;
			}
			out.print(peak);
			out.print(' ');
			out.print(next);
			if(n != 1) out.print(' ');
			else out.println();
			last = next;
		}
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}