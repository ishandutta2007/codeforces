/**
 * Created by Jay Leeds on 12/6/2016.
 */
import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Jay Leeds on 11/28/2016.
 */
public class ShellGame401A {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int num = in.nextInt();
        n = n % 6;
        if (n == 0) {
            if (num == 0) System.out.println(0);
            if (num == 1) System.out.println(1);
            if (num == 2) System.out.println(2);
        } else if (n == 1) {
            if (num == 0) System.out.println(1);
            if (num == 1) System.out.println(0);
            if (num == 2) System.out.println(2);
        } else if (n == 2) {
            if (num == 0) System.out.println(1);
            if (num == 1) System.out.println(2);
            if (num == 2) System.out.println(0);
        } else if (n == 3) {
            if (num == 0) System.out.println(2);
            if (num == 1) System.out.println(1);
            if (num == 2) System.out.println(0);
        } else if (n == 4) {
            if (num == 0) System.out.println(2);
            if (num == 1) System.out.println(0);
            if (num == 2) System.out.println(1);
        } else if (n == 5) {
            if (num == 0) System.out.println(0);
            if (num == 1) System.out.println(2);
            if (num == 2) System.out.println(1);
        }
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