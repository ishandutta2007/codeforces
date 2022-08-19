import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class PrD {

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
		StringTokenizer l2 = new StringTokenizer(br.readLine());
		StringTokenizer l3 = new StringTokenizer(br.readLine());
		int[] prizes = new int[5];
		long[] output = new long[prizes.length];
		int curP = 0;
		for(int i = 0; i < prizes.length; i++) prizes[i] = Integer.parseInt(l3.nextToken());
		for(int i = 0; i < n; i++) {
			curP += Integer.parseInt(l2.nextToken());
			for(int p = prizes.length - 1; p >= 0; p--) {
				output[p] += curP / prizes[p];
				curP %= prizes[p];
			}
		}
		for(int i = 0; i < output.length; i++) {
			out.print(output[i]);
			if(i + 1 == output.length) out.println();
			else out.print(" ");
		}
		out.println(curP);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}