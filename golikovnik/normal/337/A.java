import java.util.Arrays;
import java.util.Scanner;

public  class Puzzle {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] frames = new int[m];
		for (int i = 0; i < m; i++) {
			frames[i] = in.nextInt();
		}
		in.close();
		Arrays.sort(frames);
		int min = Integer.MAX_VALUE;
		for (int m1 = 0; m1 <= m-n; m1++) {
			min = Math.min(min, frames[m1+n-1]-frames[m1]);
		}
		System.out.println(min);
	}

}