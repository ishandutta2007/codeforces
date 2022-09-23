import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner input = new Scanner(new FileInputStream("input.txt"));
        //PrintStream output = new PrintStream(new FileOutputStream("output.txt"));
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        Integer a[] = new Integer[n];
        for(int i = 0; i < n; ++i){
            a[i] = input.nextInt();
        }
        Arrays.sort(a);
        long res = 0;
        for(int i = 0; i < n / 2; i++){
            res += (long)(a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
        }
        System.out.println(res);

        //input.close();
        //output.close();
    }
}