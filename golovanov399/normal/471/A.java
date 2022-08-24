import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] a = new int[6];
        for (int i = 0; i < 6; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        if (a[3] == a[0]){
            if (a[4] < a[5]){
                System.out.println("Bear");
            } else {
                System.out.println("Elephant");
            }
        } else
            if (a[4] == a[1]){
                System.out.println("Bear");
            } else
                if (a[5] == a[2]){
                    if (a[0] < a[1]){
                        System.out.println("Bear");
                    } else {
                        System.out.println("Elephant");
                    }
                } else
                    System.out.println("Alien");
    }
}