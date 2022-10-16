import java.util.Arrays;
import java.util.Scanner;

public class Ifmo1 {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String s = in.next();
		String t = in.next();
		char[] input = new char[26];
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			char s_char = s.charAt(i);
			char t_char = t.charAt(i);
			int s_index = getIndex(s_char);
			int t_index = getIndex(t_char);
			if (input[s_index] == 0) {
				if (s_char != t_char)
				count++;
				if (input[t_index] != 0) {
					System.out.println("-1");
					System.exit(0);
				}
				input[s_index] = t_char;
				input[t_index] = s_char;
			} else if (input[s_index] == t_char) {
				continue;
			} else {
				System.out.println("-1");
				System.exit(0);
			}
		}
		System.out.println(count);
		for (int i = 0; i < input.length; i++) {
			if (input[i] == 0)
			continue;
			if (getIndex (input[i]) == i)
			continue;
			System.out.println(input[i] + " " + input[getIndex(input[i])]);
			count++;
			input[getIndex(input[i])] = 0;
		}
		in.close();
	}
	
	public static int getIndex(char c) {
		return c - 'a';
	}
	public static char getChar(int index) {
		return (char) ('a' + index);
	}
}