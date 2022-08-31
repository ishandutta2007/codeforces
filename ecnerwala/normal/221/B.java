import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PrB {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}

	public static int go(BufferedReader br) throws Exception {
		int x = Integer.parseInt(br.readLine());
		boolean[] digits = new boolean[10];
		int temp = x;
		while(temp > 0) {
			digits[temp % 10] = true;
			temp /= 10;
		}
		int out = 0;
		for(int d = 1; d * d <= x; d++) {
			if(x % d == 0) {
				if(share(d, digits)) out++;
				if(d * d != x && share(x / d, digits)) out ++; 
			}
		}
		return out;
	}
	
	public static boolean share(int d, boolean[] digits) {
		while(d > 0) {
			if(digits[d%10]) return true;
			d /= 10;
		}
		return false;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}