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

	public static int go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] enemies = new int[n][2];
		for(int i = 0; i < n; i++) {
			enemies[i][0] = -1;
			enemies[i][1] = -1;
		}
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			enemies[a][(enemies[a][0] == -1 ? 0 : 1)] = b;
			enemies[b][(enemies[b][0] == -1 ? 0 : 1)] = a;
		}
		int output = 0;
		boolean[] reached = new boolean[n];
		bigLoop: for(int i = 0; i < n; i++) {
			if(!reached[i] && enemies[i][0] != -1) {
				int cur = i;
				int last = enemies[i][0];
				reached[cur] = true;
				int length = 1;
				while(true) {
					int temp = cur;
					cur = enemies[cur][0] + enemies[cur][1] - last;
					last = temp;
					if(cur == i) {
						output += length % 2;
						continue bigLoop;
					}
					if(cur == -1 || reached[cur]) continue bigLoop;
					reached[cur] = true;
					length ++;
				}
			}
		}
		return output + (n - output) % 2;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}