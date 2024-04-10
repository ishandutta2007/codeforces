import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            int c = 0;
            int x;
            x = sc.nextInt();
            c += x;
            x = sc.nextInt();
            c += x;
            x = sc.nextInt();
            c += x;
            cnt += (c / 2);
        }
        System.out.println(cnt);
    }
}