import java.util.Scanner;

public class Codeforces_392_A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] wealth = new int[n];
		int current_maximum = -1;
		for (int i = 0; i < n; i++) {
			wealth[i] = in.nextInt();
			if (wealth[i] > current_maximum) {
				current_maximum = wealth[i];
			}
		}
		in.close();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum+=current_maximum-wealth[i];
		}
		System.out.println(sum);
	}

}