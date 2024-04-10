import java.util.Scanner;

public class Mesto {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		double n = in.nextInt();
		double m = in.nextInt();
		double k = in.nextInt();
		in.close();
		int ryad = (int)Math.ceil(k/(2*m));
		int parta = 0;
		if (k%(2*m) == 0) {
			parta = (int) (2*m)/2;
		} else {
		parta = (int)Math.ceil((k%(2*m))/2);
		}
		if (k%2 == 0) {
			System.out.println(ryad + " " + parta + " R");
		} else if (k%2==1) {
			System.out.println(ryad + " " + parta + " L");
		}
	}

}