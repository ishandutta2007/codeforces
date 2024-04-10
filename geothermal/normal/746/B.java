//package Codeforces;

/**
 * Created by Jay Leeds on 12/6/2016.
 */

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Jay Leeds on 11/28/2016.
 */
public class Decoding746B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        String string = in.nextToken();

            char[] result = new char[n];
            int cur = (n - 1) / 2;
            for (int i = 1; i < n + 1; i++) {
                result[cur] = string.charAt(0);
                string = string.substring(1);
                if (i % 2 == 0 && n % 2 == 0 || i % 2 == 1 && n % 2 == 1) {
                    cur = cur - i;
                } else cur = cur + i;
            }

        System.out.println(result);

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