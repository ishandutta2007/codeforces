import java.io.*;
import java.util.StringTokenizer;

public class ShortProgram879C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int zeroes = 0;
        int ones = 1023;
        for (int i = 0; i < n; i++) {
            char c = in.nextToken().charAt(0);
            int j = in.nextInt();
            if (c == '|') {
                zeroes = zeroes | j;
                ones = ones | j;
            } else if (c == '&') {
                zeroes = zeroes & j;
                ones = ones & j;
            } else {
                zeroes = zeroes ^ j;
                ones = ones ^ j;
            }
        }
        
        int and = 0;
        int or = 0;
        int xor = 0;
        for (int i = 1; i < 1024; i = i * 2) {
            boolean zero = zeroes % (2 * i) == i;
            if (zero) zeroes -= i;
            boolean one = ones % (2 * i) == i;
            if (one) ones -= i;
            if (zero && one) {
                and += i;
                or += i;
            } else if (zero) {
                and += i;
                xor += i;
            } else if (one) {
                and += i;
            }
        }
        
        System.out.println(3);
        System.out.println("& " + and);
        System.out.println("| " + or);
        System.out.println("^ " + xor);
                
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