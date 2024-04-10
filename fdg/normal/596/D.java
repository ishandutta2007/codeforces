import java.io.*;
import java.util.*;


public class A {
    static double[][][][] dp;
    static int h, n;
    static double p;
    
    static int[] x;
    static int[] toRight, toLeft;
    
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        String[] nums = in.readLine().split(" ");
        
        n = Integer.valueOf(nums[0]);
        h = Integer.valueOf(nums[1]);
        p = Double.valueOf(nums[2]);
        

        x = new int[n];
        nums = in.readLine().split(" ");
        
        for (int i = 0; i < n; ++i) {
            x[i] = Integer.valueOf(nums[i]);
        }
        Arrays.sort(x);
        
        toRight = new int[n];
        toLeft = new int[n];
        for (int i = 0; i < n; ++i) {
            toRight[i] = i;
            while (toRight[i] + 1 < n && x[toRight[i] + 1] - x[toRight[i]] < h)
                ++toRight[i];
            
            toLeft[i] = i;
            while (toLeft[i] > 0 && x[toLeft[i]] - x[toLeft[i] - 1] < h)
                --toLeft[i];
        }
        
        dp = new double[2][2][n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                for (int ii = 0; ii < 2; ++ii)
                    for (int jj = 0; jj < 2; ++jj)
                        dp[ii][jj][i][j] = -1;
        }
        
        System.out.format("%.15f\n", go(0, n - 1, 0, 0));
    }

    private static double go(int l, int r, int hl, int hr) {
        // TODO Auto-generated method stub
        if (l > r) return 0.0;
        
        if (dp[hl][hr][l][r] != -1.0) return dp[hl][hr][l][r];
                
        int left = l > 0 ? x[l - 1] + (hl == 1 ? h : 0) : -1000000000;
        int right = r + 1 < n ? x[r + 1] - (hr == 1 ? h : 0) : 1000000000;
        
        dp[hl][hr][l][r] = 0.5 * p * (Math.min(h, x[l] - left) + go(l + 1, r, 0, hr))
                + 0.5 * (1 - p) * (Math.min(h, right - x[Math.min(toRight[l], r)]) + x[Math.min(toRight[l], r)] - x[l] + go(toRight[l] + 1, r, 1, hr))
                + 0.5 * (1 - p) * (Math.min(h, right - x[r]) + go(l, r - 1, hl, 0))
                + 0.5 * p * (Math.min(h, x[Math.max(l, toLeft[r])] - left) + x[r] - x[Math.max(l, toLeft[r])] + go(l, toLeft[r] - 1, hl, 1));
        
        //System.out.format("dp[%d][%d] = %f\n", l, r, dp[l][r]);
        
        return dp[hl][hr][l][r];
    }

    
    
}