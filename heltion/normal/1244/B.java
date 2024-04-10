import java.util.Scanner;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i += 1){
            int n = scanner.nextInt();
            String s = scanner.next();
            int x = n;
            for(int j = 0; j < n; j += 1) if(s.charAt(j) == '1') x = min(x, min(j, n - j - 1));
            System.out.println(max(2 * (n - x), n));
        }
    }
}