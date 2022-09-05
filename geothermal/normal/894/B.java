import java.io.*;
import java.util.StringTokenizer;

public class MagicField894B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        long n = (in.nextLong() - 1);
        long m = (in.nextLong() - 1);
        int k = in.nextInt();
        if (k == -1 && n % 2 != m % 2) {
            System.out.println(0);
            return;
        }
        n = n % 1000000006;
        m = m % 1000000006;
        long x = n * m;
        x = x % 1000000006;

        
        
        long[] twos = new long[35];
        twos[0] = 1;
        for (int i = 1; i < 35; i++) twos[i] = twos[i-1] * 2;
        long[] twoVals = new long[35]; //2^2^i
        twoVals[0] = 2;
        for (int i = 1; i < 35; i++) twoVals[i] = (twoVals[i-1] * twoVals[i-1]) % 1000000007;
        
        long val = 1;
        for (int i = 34; i >= 0; i--) {
            if (x >= twos[i]) { //if x contains 2^i
                x -= twos[i];
                val *= twoVals[i]; 
                val = val % 1000000007;
            }
        }
        
        System.out.println(val);
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