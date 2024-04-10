import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PrB {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br) throws Exception {
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int s = 0;
		int[] digits = new int[10];
		int[] m3 = new int[3];
		for(; n > 0; n--) {
			int cur = Integer.parseInt(st.nextToken());
			digits[cur]++;
			cur %= 3;
			m3[cur] ++;
			s += cur;
			s %=3;
		}
		if(digits[0] == 0) {
			System.out.println(-1);
			return;
		}
		if(s != 0) {
			if(m3[s] == 0) {
				if(m3[3 - s] < 2) {
					System.out.println(-1);
					return;
				}
				else {
					int i = 3 - s;
					for(int num = 0; num < 2; num++) {
						for(; i < 10; i+=3) {
							if(digits[i] > 0) {
								digits[i]--;
								break;
							}
						}
					}
				}
			} else  {
				for(int i = s; i < 10; i+=3) {
					if(digits[i] > 0) {
						digits[i]--;
						break;
					}
				}
			}
		}
		boolean printed = false;
		for(int i = 9; i >= 0; i--) {
			if(i == 0 && !printed) {
				System.out.println(0);
				return;
			}
			while(digits[i] > 0) {
				digits[i] --;
				System.out.print(i);
				printed = true;
			}
		}
		System.out.println();
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}