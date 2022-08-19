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
		int out = 0;
		int max = -1;
		int[] a = new int[Integer.parseInt(br.readLine())];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < a.length; i++) 
			a[i] = Integer.parseInt(st.nextToken());
		int[] b = new int[Integer.parseInt(br.readLine())];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < b.length; i++)
			b[i] = Integer.parseInt(st.nextToken());
		for(int i = 0; i < a.length; i++) {
			for(int j = 0; j < b.length; j++) {
				if(b[j] % a[i] == 0) {
					int c = b[j] / a[i];
					if(c > max) {
						out = 1;
						max = c;
					} else if (c == max) {
						out++;
					}
				}
			}
		}
		return out;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}