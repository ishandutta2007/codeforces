import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class GauntRingManthanB {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        long p = in.nextLong();
        long q = in.nextLong();
        long r = in.nextLong();
        
        long[][] dp = new long[3][n];
       
        ArrayList<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(in.nextLong());
        }
        dp[0][0] = p * list.get(0);
        dp[1][0] = p * list.get(0) + q * list.get(0);
        dp[2][0] = p * list.get(0) + q * list.get(0) + r * list.get(0);
        
        for (int i = 1; i < n; i++) {
            dp[0][i] = Long.max(dp[0][i-1], p * list.get(i));
        }
        
        for (int i = 1; i < n; i++) {
            dp[1][i] = Long.max(dp[1][i-1], dp[0][i] + q * list.get(i));
        }
        
        for (int i = 1; i < n; i++) {
            dp[2][i] = Long.max(dp[2][i-1], dp[1][i] + r * list.get(i));
        }
        
        System.out.println(dp[2][n-1]);
        
        
        
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }
}