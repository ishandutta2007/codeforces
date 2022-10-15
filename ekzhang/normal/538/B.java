import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		String N = br.readLine();
		int len = N.length();
		int[] dig = new int[len];
		for (int i = 0; i < len; i++) {
			dig[i] = N.charAt(i) - '0';
		}
		List<Integer> nums = new ArrayList<>();
		while (true) {
			String nextNum = "";
			for (int i = 0; i < len; i++) {
				if (dig[i] != 0) {
					dig[i]--;
					nextNum = nextNum.concat("1");
				}
				else {
					nextNum = nextNum.concat("0");
				}
			}
			int nextInt = Integer.parseInt(nextNum);
			if (nextInt != 0) {
				nums.add(nextInt);
			}
			else {
				break;
			}
		}
		int sz = nums.size();
		out.println(sz);
		for (int i = 0; i < sz; i++) {
			if (i != 0) {
				out.print(' ');
			}
			out.print(nums.get(i));
		}
		out.println();
		out.flush();
		System.exit(0);
	}

}