//package Codeforces;

/**
 * Created by Jay Leeds on 12/6/2016.
 */
import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Jay Leeds on 11/28/2016.
 */
public class Tea746D {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        in.nextInt();
        int k = in.nextInt();
        int g = in.nextInt();
        int b = in.nextInt();
        if (g == b) {
            for (int i = 0; i < g; i++) {
                System.out.print("GB");
            }
            System.out.println();
        } else {
            boolean moreG = g > b;
            String maxCharacter;
            String minCharacter;
            if (moreG) {
                maxCharacter = "G";
                minCharacter = "B";
            } else {
                maxCharacter = "B";
                minCharacter = "G";
            }
            int max = Math.max(g, b);
            int min = Math.min(g, b);
            int compartments = min+1;
            if (compartments * k >= max) {
                int numMax = max / compartments;
                int remainder = max % compartments;
                for (int i = 0; i < remainder; i++) {
                    for (int i2 = 0; i2 < numMax + 1; i2++) {
                        System.out.print(maxCharacter);
                    }
                    if (i != min) System.out.print(minCharacter);
                }
                for (int i = remainder; i < compartments; i++) {
                    for (int i2 = 0; i2 < numMax; i2++) {
                        System.out.print(maxCharacter);
                    }
                    if (i != min) System.out.print(minCharacter);
                }
                System.out.println();

            } else {
                System.out.println("NO");
            }

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