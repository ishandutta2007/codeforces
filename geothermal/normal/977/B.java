
import java.io.*;
import java.util.StringTokenizer;

public class B977 {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt(); String s = in.nextToken();
        int[] data = new int[676];
        for (int i = 0; i < n - 1; i++) {
            int a = s.charAt(i) - 'A';
            int b = s.charAt(i + 1) - 'A';
            data[26 * b + a]++;
        }
        
        int best = 0;
        char x = 'A', y = 'A';
        for (int i = 0; i < 676; i++) {
            if (data[i] > best) {
                best = data[i];
                x = (char) (i % 26 + 'A');
                y = (char) (i / 26 + 'A');

            }
        }
        
        System.out.print(x);
        System.out.println(y);
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