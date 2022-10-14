import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner input = new Scanner(System.in);
	    int q = input.nextInt();
	    while(q-->0) {
		    int n = input.nextInt();
		    System.out.println(Math.max(4-n, n%2));
	    }
	}
}