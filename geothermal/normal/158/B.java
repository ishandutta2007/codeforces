import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Taxi158B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		ArrayList<Integer> groups = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			groups.add(scan.nextInt());
		}
		Collections.sort(groups);
		Collections.reverse(groups);
		int result = 0;
		while (groups.size() != 0) {
			if (groups.size() == 1) {
				result++;
				groups.remove(0);
			} else {
				int size = 0;
				size = size + groups.get(0);
				groups.remove(0);
				while (groups.size() != 0 && size + groups.get(groups.size() - 1) <= 4) {
					size = size + groups.get(groups.size() - 1);
					groups.remove(groups.size() - 1);
				}
				result++;
			}
		}
		scan.close();
		System.out.println(result);
	}

}