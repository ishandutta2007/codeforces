import java.util.Scanner;

public class BitPlusPlus282A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (scan.next().toCharArray()[1] == '+') {
				x++;
			} else x--;
		}
		scan.close();
		System.out.println(x);
	}
}