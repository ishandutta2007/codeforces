import java.io.BufferedReader;
import java.io.InputStreamReader;

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
		char[] in = br.readLine().toCharArray();
		String a = "";
		String b = "";
		for(int i = 0; i < in.length; i++) {
			char c = in[i];
			if(c == ' ') break;
			a += String.valueOf(c);
		}
		for(int i = in.length - 1; i >= 0; i--) {
			char c = in[i];
			if(c == ' ') break;
			b += String.valueOf(c);
		}
		return Integer.parseInt(a) + Integer.parseInt(b);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}