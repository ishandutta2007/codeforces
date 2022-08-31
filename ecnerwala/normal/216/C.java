import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class PrC {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayDeque<Integer> output = go(br);
		System.out.println(output.size());
		while(!output.isEmpty()) {
			System.out.print(output.remove());
			if(output.isEmpty()) System.out.println();
			else System.out.print(" ");
		}
		br.close();
		System.exit(0);
	}

	public static ArrayDeque<Integer> go(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		ArrayDeque<Integer> output = new ArrayDeque<Integer>();
		if(k == 1) {
			for(int i = 1; i < n + m + 1;i += n - 1) 
				output.add(i);
		} else if(m == n) {
			for(int i = 0; i < k; i++) output.add(1);
			output.add(n);
			for(int i = 0; i < k - 1; i++) 
				output.add(n + 1);
			output.add(n + m);
		} else {
			for(int i = 0; i < k; i++) 
				output.add(1);
			output.add(n);
			for(int i = 0; i < k - 1; i++) 
				output.add(n + 1);
		}
		return output;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}