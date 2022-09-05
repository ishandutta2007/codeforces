import java.util.Scanner;

public class PetyaAndStrings112A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s1 = scan.next();
		String s2 = scan.next();
		System.out.println(compare(s1, s2));
	}
	public static int compare(String s1, String s2) {
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		for (int i = 0; i < c1.length; i++) {
			if (!(Character.toLowerCase(c1[i]) == Character.toLowerCase(c2[i]))) {
				if (Character.compare(Character.toLowerCase(c1[i]), Character.toLowerCase(c2[i])) > 0) {
					return 1;
				} else return -1;
			}
		}
		return 0;
	}

}