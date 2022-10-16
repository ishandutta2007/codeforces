import java.util.Arrays;
import java.util.Scanner;

public class MahmudTriangles {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] lengths = new int[n];
		for (int i = 0; i < n; i++) {
			lengths[i] = in.nextInt();
		}
		in.close();
		Arrays.sort(lengths);
		for (int i = n-1; i >= 2; i--) {
			if (lengths[i] < lengths[i-1] + lengths[i-2]) {
				System.out.println("YES");
				System.exit(0);
			}
		}
		System.out.println("NO");
	}

}