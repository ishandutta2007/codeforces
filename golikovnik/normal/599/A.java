import java.util.*;

public class TaskA {

	public static void main(String[] args) {
		Scanner in = new Scanner (System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		System.out.println(Math.min(Math.min(2*a+2*b, 2*b+2*c), Math.min(a+b+c, 2*a+2*c)));
		in.close();
	}

}