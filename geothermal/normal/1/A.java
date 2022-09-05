import java.util.Scanner;

public class TheatreSquare1A {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		long x = scanner.nextLong();
		long y = scanner.nextLong();
		long a = scanner.nextLong();
		scanner.close();
		long xsize = x / a;
		if (x % a != 0) xsize++;
		long ysize = y / a;
		if (y % a != 0) ysize++;
		System.out.println(xsize * ysize);
	}
}