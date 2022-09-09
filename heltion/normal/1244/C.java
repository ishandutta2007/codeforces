import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        Long n = scanner.nextLong();
        Long p = scanner.nextLong();
        Long w = scanner.nextLong();
        Long d = scanner.nextLong();
        Long x = -1L, y = -1L, z = -1L;
        for(Long i = 0L; i <= w; i += 1)
            if(i * d <= p && (p - i * d) % w == 0 && (p - i * d) / w + i <= n){
                System.out.printf("%d %d %d\n", (p - i * d) / w, i, n - (p - i * d) / w - i);
                return;
            }
        System.out.print(-1);
    }
}