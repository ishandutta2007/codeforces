import java.util.HashMap;
import java.util.Scanner;

public class Polycarp {

	public static void main(String[] args) {
		HashMap<String, Integer> map = new HashMap<>();
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String first, second;
		map.put("polycarp", 1);
		for (int i = 0; i < n; i++) {
			first = in.next().toLowerCase();
			in.next();
			second = in.next().toLowerCase();
			map.put(first, map.get(second)+1);
		}
		int max = -1;
		for (int value: map.values()) {
			max = Math.max(value, max);
		}
		System.out.println(max);
	}

}