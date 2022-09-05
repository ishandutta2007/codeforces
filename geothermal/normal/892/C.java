import java.io.*;
import java.util.StringTokenizer;

public class Pride892C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int[] list = new int[n];
        int countOnes = 0;
        int[] curGCDs = new int[n];
        int[] length = new int[n];
        for (int i = 0; i < n; i++) {
            list[i] = in.nextInt();
            curGCDs[i] = list[i];
            length[i] = 2 * n;
            if (list[i] == 1) countOnes++;
            for (int j = 0; j < i; j++) {
                if (curGCDs[j] <= 1) continue;
                curGCDs[j] = gcd(curGCDs[j], list[i]);
                if (curGCDs[j] == 1) length[j] = i - j;
            }
        }
        
        if (countOnes > 0) {
            System.out.println(n - countOnes);
            return;
        }
        
        int min = 2 * n;
        for (int i = 0; i < n; i++) {
            if (length[i] < min) min = length[i];
        }
        
        if (min == 2 * n) {
            System.out.println(-1);
        } else System.out.println(min + n - 1);
    }
    
    public static int gcd(int a, int b) {
        while (true) {
            if (a < b) {
                int c = b;
                b = a;
                a = c;
            }
            a = a % b;
            if (a == 0) return b;
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