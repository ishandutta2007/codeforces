import java.util.Scanner;

public class DominoPiling50A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		System.out.println((a*b)/2);
		scan.close();
	}
}