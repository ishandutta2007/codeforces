import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrA {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}

	public static int go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		return a * (b - 1) + b * (c - 1) + c * (a - 1) + 1;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}