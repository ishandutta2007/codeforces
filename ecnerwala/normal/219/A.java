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
		int k = Integer.parseInt(br.readLine());
		int[] freq = new int[26];
		for(char c : br.readLine().toCharArray()) 
			freq[c - 'a'] ++;
		for(int i = 0; i < freq.length; i++) {
			if(freq[i] % k != 0) {
				out.println(-1);
				return;
			}
			freq[i] /= k;
		}
		String s = "";
		for(char c = 'a'; c <= 'z'; c++) {
			for(; freq[c - 'a'] > 0; freq[c - 'a'] --) {
				s = s + Character.toString(c);
			}
		}
		for(; k > 0; k--) {
			System.out.print(s);
		}
		System.out.println();
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}