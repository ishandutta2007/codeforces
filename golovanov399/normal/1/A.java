import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        long x = (a + c - 1) / c;
        x *= (b + c - 1) / c;
        System.out.println(x);
    }
}