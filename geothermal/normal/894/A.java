import java.io.*;
import java.util.StringTokenizer;

public class QAQ894A {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        String s = in.nextLine();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                int low = 0;
                for (int j = 0; j < i; j++) {
                    if (s.charAt(j) == 'Q') {
                        low++;
                    }
                }
                int high = 0;
                for (int j = i+1; j < s.length(); j++) {
                    if (s.charAt(j) == 'Q') {
                        high++;
                    }
                }
                count += low * high;
            }
        }
        System.out.println(count);
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