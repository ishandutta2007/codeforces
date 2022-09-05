import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Diversity844A {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        String s = in.nextLine();
        int n = in.nextInt();
        if (n > s.length()) {
            System.out.println("impossible");
            return;
        }

        HashSet<Character> c = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            c.add(s.charAt(i));
        }
        
        System.out.println(Math.max(0, n - c.size()));
        
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