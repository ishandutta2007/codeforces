import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class PrE {

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
		int k = Integer.parseInt(st.nextToken()) - 1;
		int b = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		long num0 = 0, str0 = 0;
		long out = 0;
		int sum = 0;
		HashMap<Integer, Integer> num = new HashMap<Integer,Integer>(10000);
		num.put(0, 1);
		for(; n > 0; n--) {
			int cur = Integer.parseInt(st.nextToken());
			if(cur == 0) {
				str0 ++;
				num0 += str0;
			} else str0 = 0;
			sum += cur;
			sum %= k;
			Integer i = num.get((sum - b + k) % k);
			if(i == null) i = 0;
			out += i;
			i = num.get(sum);
			if(i == null) i = 0;
			num.put(sum, i + 1);
		}
		if(b == 0) return num0;
		if(b == k) return out - num0;
		return out;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}