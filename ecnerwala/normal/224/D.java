import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class PrD {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(go(br.readLine().toCharArray(), br.readLine().toCharArray()) ? "Yes" : "No");
		br.close();
		System.exit(0);
	}

	public static boolean go(char[] s, char[] t) throws Exception {
		int[] index = new int[t.length];
		for(int i = s.length - 1, j = t.length - 1; j >= 0; i --) {
			if(i < 0) return false;
			if(s[i] == t[j]) {
				index[j] = i;
				j--;
			}
		}
		int[] lastOcc = new int[26];
		Arrays.fill(lastOcc, -1);
		for(int i = 0, j = 0; i < s.length; i++) {
			if(j != t.length && s[i] == t[j]) {
				lastOcc[s[i] - 'a'] = j;
				j++;
			} else {
				if(lastOcc[s[i] - 'a'] < 0) return false;
				if(lastOcc[s[i] - 'a'] != t.length - 1 && index[lastOcc[s[i] - 'a'] + 1] <= i) return false;
			}
		}
		return true;
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}