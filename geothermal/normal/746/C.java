//package Codeforces;

/**
 * Created by Jay Leeds on 12/6/2016.
 */
import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Jay Leeds on 11/28/2016.
 */
public class Tram746C {
    static int tramDistance(int c, boolean inc, int s, int goal) {
        if ((goal - c > 0 && inc == true) || (goal - c < 0 && inc == false)) {
            return Math.abs(goal - c);
        } else {
            if (inc) {
                return s * 2 - c - goal;
            } else return c + goal;

        }
    }


    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int s = in.nextInt();
        int x1 = in.nextInt();
        int x2 = in.nextInt();
        int t1 = in.nextInt();
        int t2 = in.nextInt();
        int p = in.nextInt();
        boolean inc = in.nextInt() == 1;

        int dirDist = t2 * Math.abs(x2 - x1);
        int tramDist;
        if (x1 > p) {
            tramDist = t1 * (tramDistance(p, inc, s, x1) + tramDistance(x1, true, s, x2));
        } else if (x1 < p) {
            tramDist = t1 * (tramDistance(p, inc, s, x1) + tramDistance(x1, false, s, x2));
        } else {
            tramDist = t1 * tramDistance(p, inc, s, x2);
        }

        System.out.println(Math.min(dirDist, tramDist));

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