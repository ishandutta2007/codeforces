import java.io.*;
import java.util.*;


public class A {
    
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(in.readLine());
        
        String[] nums = in.readLine().split(" ");
        
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = Integer.valueOf(nums[i]);
        
        long ans = 0, add = 0;
        
        for (int i = 0; i < n; ++i) {
            ans += Math.abs(arr[i] - add);
            add += arr[i] - add;
        }
        
        System.out.println(ans);
    }

}