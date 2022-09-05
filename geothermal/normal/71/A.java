import java.util.Scanner;

public class WayTooLongWords71A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for (int i = 0; i < n + 1; i++) {
			String word = scan.nextLine();
			if (word.length() <= 10) {
				System.out.println(word);
			} else {
				System.out.println(word.substring(0, 1) + Integer.toString(word.length() - 2) + word.substring(word.length() - 1, word.length()));
			}
		}
		scan.close();
	}
}