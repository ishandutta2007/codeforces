import java.util.Arrays;
import java.util.Scanner;

public  class Puzzle {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] coins = new int[n];
		for (int i = 0; i < n; i++) {
			coins[i] = in.nextInt();
		}
		in.close();
		int max = -1;
		int currentMax = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
			currentMax++;
			} else if (coins[i]>=coins[i-1]) {
				currentMax++;
			} else {
				max = Math.max(currentMax, max);
				currentMax = 1;
			}
		}
		max = Math.max(currentMax, max);
		System.out.println(max);
	}

}