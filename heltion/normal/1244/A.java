import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for(int i = 0; i < t; i += 1){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            int k = scanner.nextInt();
            int x = -1, y = -1;
            for(int j = 0; j <= k; j += 1)
                if(j * c >= a && (k - j) * d >= b){
                    x = j;
                    y = k - j;
                }
            if(x == -1) System.out.println(-1);
            else System.out.printf("%d %d\n", x, y);
        }
    }
}