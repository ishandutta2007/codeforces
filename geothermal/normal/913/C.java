
import java.io.*;
import java.util.StringTokenizer;

public class PartyLemonade913C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt(); 
        int total = in.nextInt();
        
        long[] prices = new long[n];
        for (int i = 0; i < n; i++) prices[i] = in.nextLong();
        long[] costs = new long[33];
        costs[0] = prices[0];
        for (int i = 1; i < 33; i++) {
            if (i < n) {
                costs[i] = Math.min(2 * costs[i-1], prices[i]);
            } else {
                costs[i] = 2 * costs[i-1];
            }
        }
        long sum = 0L;
        for (int i = 0; i < 33; i++) {
            
            if (total % 2 == 1) {
                sum += costs[i];
            } else {
                if (costs[i] < sum) {
                    sum = costs[i];
                }
            }
            total = total / 2;
        }
        
        System.out.println(sum);
        
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