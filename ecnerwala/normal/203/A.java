import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrA {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br) ? "YES" : "NO");
		br.close();
		System.exit(0);
	}

	public static boolean go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		if(x == 0) return true;
		int t = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int da = Integer.parseInt(st.nextToken());
		int db = Integer.parseInt(st.nextToken());
		for(int i = 0; i < t; i++) 
			if(a - i * da == x || b - i * db == x) return true;
		for(int ia = 0; ia < t; ia++) 
			for(int ib = 0; ib < t; ib++) 
				if(a - ia * da + b - ib * db == x) return true;
		return false;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}