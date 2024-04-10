import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

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
		System.out.print(n);
		for(int i = 1; i < n; i++) {
			System.out.print(" ");
			System.out.print(i);
		}
		System.out.println();
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}