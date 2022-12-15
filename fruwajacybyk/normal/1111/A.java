import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
	
    public static void main(String[] args) {
    		Scanner in = new Scanner(System.in);

				String s = in.next();
				String t = in.next();
				String vowels = "aeiou";

				int n = s.length();
				int m = t.length();
					if (n != m) {
						System.out.println("No");
						return;
					}
				for (int i = 0; i < n; ++i) {
					boolean s_vowel = (vowels.indexOf(s.charAt(i)) != -1);
					boolean t_vowel = (vowels.indexOf(t.charAt(i)) != -1);
					if (s_vowel != t_vowel) {
						System.out.println("No");
						return;
					}
				}
				System.out.println("Yes");
		}
}