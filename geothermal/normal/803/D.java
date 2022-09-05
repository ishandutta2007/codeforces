import java.io.*;
import java.util.StringTokenizer;

public class MagAdE20D {
    
    static int k;
    static int[] words;
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        k = in.nextInt();
        String s = in.nextLine();
        String[] strings = s.split("-| ");
        words = new int[strings.length];
        for (int i = 0; i < strings.length - 1; i++) {
            words[i] = strings[i].length() + 1;
        }
        words[strings.length - 1] = strings[strings.length - 1].length();
        
        int min = 0;
        int max = 2000000;
        int best = 1000000;
        for (int i = 0; i < 30; i++) {
            int cur = min + max;
            cur /= 2;
            if (isPossible(cur)) {
                best = cur;
                max = cur;
            } else min = cur;
        }
        
        System.out.println(best);
    }
    
    static boolean isPossible(int len) {
        int lines = 1;
        int cur = 0;
        for (int i = 0; i < words.length; i++) {
            if (cur + words[i] <= len) {
                cur += words[i];
            } else if (words[i] <= len) {
                lines++;
                cur = words[i];
            } else return false;
        }
        
        if (lines <= k) return true;
        
        return false;
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