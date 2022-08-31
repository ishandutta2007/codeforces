import java.util.Scanner;

public class qwe {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.print(n * n * (n - 1) / 2 - n * (n - 1) * (2 * n - 1) / 6 + n);
    }
}