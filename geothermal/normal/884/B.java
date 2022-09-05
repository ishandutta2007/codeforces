import java.io.*;
import java.util.StringTokenizer;

public class JapaneseCrosswordE31B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        long n = in.nextInt();
        long x = in.nextInt();
        long sum = n - 1;
        for (int i = 0; i < n; i++) {
            sum += in.nextInt();
        }
        if (sum == x) {
            System.out.println("YES");
        } else System.out.println("NO");
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