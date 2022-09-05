import java.util.ArrayList;
import java.util.Scanner;

public class StringTask118A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		scan.close(); 
		char[] characters = s.toCharArray();
		ArrayList<Character> chars = new ArrayList<Character>();
		for (char c : characters) {
			chars.add(c);
		}
		for (int i = 0; i < chars.size(); i++) {
			chars.set(i, Character.toLowerCase(chars.get(i)));
			char c = chars.get(i);
			if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y') {
				chars.remove(i);
				i--;
			} else {
				chars.add(i, '.');
				i++;
			}
		}
		
		String s2 = "";
		for (char c : chars) {
			s2 = s2.concat(Character.toString(c));
		}
		System.out.print(s2);

		} 
		
	}