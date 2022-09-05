import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MaxGCDE20C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        long n = in.nextLong();
        long k = in.nextLong();
        if (k >= 200000 || k * (k + 1) / 2 > n) {
            System.out.println("-1");
            return;
        }
        
        long tri = k * (k + 1) / 2;
        ArrayList<Long> factors = new ArrayList<Long>();
        long val = -1;
        for (long i = 1; i < Math.sqrt(n) + 0.000001; i++) {
            if (n % i == 0) {
                factors.add(i);
                if (n / i < tri) {
                    val = factors.get(factors.size() - 2);
                    break;
                }
            }
        }
        
        if (val == -1) {
            ArrayList<Long> factorsNew = new ArrayList<Long>();
            for (int i = factors.size() - 1; i >= 0; i--) {
                long num = n / factors.get(i);
                if (factors.get(i) < tri) {
                    if (factorsNew.size() >= 1) {
                        val = factorsNew.get(factorsNew.size() - 1);
                    } else {
                        val = factors.get(factors.size() - 1);
                    }
                    break;
                }
                factorsNew.add(num);
            }
        }
        
        for (long i = 1; i < k; i++) {
            System.out.print(val * i + " ");
        }
        long finalVal = k + n / val - tri;
        System.out.println(finalVal * val);
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