import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

public class PrC {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br, System.out);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br, PrintStream out) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		char[] in = new char[n];
		br.read(in);
		int swap = 0;
		if(k == 2) {
			for(int i = 0; i < n; i++) {
				if(in[i] != ((i % 2 == 0) ? 'A' : 'B')) swap ++;
			}
			if(swap < n - swap) {
				System.out.println(swap);
				for(int i = 0; i < n; i++) 
					System.out.print((i % 2 == 0) ? 'A' : 'B');
				System.out.println();
				return;
			} else {
				System.out.println(n - swap);
				for(int i = 0; i < n; i++) 
					System.out.print((i % 2 == 0) ? 'B' : 'A');
				System.out.println();
				return;
			}
		}
		for(int i = 1; i < n; i++) {
			if(in[i - 1] == in[i]) {
				swap ++;
				in[i] ++;
				if(in[i] == 'A' + k) in[i] = 'A';
				if(i + 1 != n && in[i] == in[i + 1]) {
					in[i] ++;
					if(in[i] == 'A' + k) in[i] = 'A';
				}
			}
		}
		System.out.println(swap);
		System.out.println(new String(in));
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}