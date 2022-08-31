import java.util.*;
public class PrD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        int out = 0;
        for(int j = 1; j <= i; j++) {
            out += j * sc.nextInt();
        }
        System.out.println(out);
    }
}