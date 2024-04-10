import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrB {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}

	public static double go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		double r1 = -1;
		for(int i = Integer.parseInt(st.nextToken()); i > 0; i--) {
			int c = Integer.parseInt(st.nextToken());
			if(c > r1) r1 = c;
		}
		st = new StringTokenizer(br.readLine());
		double p1 = -1;
		for(int i = Integer.parseInt(st.nextToken()); i > 0; i--) {
			int c = Integer.parseInt(st.nextToken());
			if(c > p1) p1 = c;
		}
		st = new StringTokenizer(br.readLine());
		double p2 = 5001;
		for(int i = Integer.parseInt(st.nextToken()); i > 0; i--) {
			int c = Integer.parseInt(st.nextToken());
			if(c < p2) p2 = c;
		}
		st = new StringTokenizer(br.readLine());
		double a = Integer.parseInt(st.nextToken());
		double b = Integer.parseInt(st.nextToken());
		return r1 / Math.sqrt((a * p2) / (b * p1) + 1);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}