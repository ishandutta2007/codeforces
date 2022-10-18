import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class A {
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] x = new int[n], y = new int[n];
        for (int i = 0; i < n; ++i) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        
        Arrays.sort(x);
        Arrays.sort(y);
        
        int area = (x[n - 1] - x[0]) * (y[n - 1] - y[0]);
        if (area == 0) area = -1;
        
        System.out.println(area);
    }

}