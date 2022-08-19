import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;

public class PrC {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br));
		br.close();
		System.exit(0);
	}

	@SuppressWarnings("unchecked")
	public static int go(BufferedReader br) throws Exception {
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] comp = new int[n];
		for(int i = 0; i < n; i++) comp[i] = Integer.parseInt(st.nextToken()) - 1;
		ArrayDeque<Integer>[] outE = new ArrayDeque[n];
		for(int i = 0; i < n; i++) outE[i] = new ArrayDeque<Integer>();
		int[] inDeg = new int[n];
		for(int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			inDeg[i] = Integer.parseInt(st.nextToken());
			for(int j = 0; j < inDeg[i]; j++) {
				int c = Integer.parseInt(st.nextToken()) - 1;
				outE[c].add(i);
			}
		}
		int output = 3 * n;
		for(int start = 0; start < 3; start++) {
			int[] inD = Arrays.copyOf(inDeg, n);
			ArrayDeque<Integer>[] ready = new ArrayDeque[3];
			for(int i = 0; i < 3; i++) ready[i] = new ArrayDeque<Integer>();
			for(int i = 0; i < n; i++) 
				if(inD[i] == 0) ready[comp[i]].push(i);
			int moves = 0;
			for(int done = 0; done < n; moves++) {
				int cur = (moves + start) % 3;
				while(!ready[cur].isEmpty()) {
					int c = ready[cur].pop();
					done++;
					for(int i : outE[c]) {
						inD[i] --;
						if(inD[i] == 0) ready[comp[i]].push(i);
					}
				}
			}
			moves += n;
			moves--;
			if(moves < output) output = moves;
		}
		return output;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}