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

	public static long go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		long ab = Long.parseLong(st.nextToken()), 
				bc = Long.parseLong(st.nextToken()), 
				ca = Long.parseLong(st.nextToken()),
				abc = (long) Math.sqrt(ab * bc * ca);
		return 4 * (abc / ab + abc / bc + abc / ca);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}