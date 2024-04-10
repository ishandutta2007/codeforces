import java.io.*;
import java.util.StringTokenizer;

public class RomaPokerE20E {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int k = in.nextInt();
        String s = in.nextToken();
        
        StringBuilder[] last = new StringBuilder[2 * k + 1]; //index - k;
        
        if (s.charAt(0) == 'W') {
            last[k+1] = new StringBuilder("W");
        } else if (s.charAt(0) == 'L') {
            last[k - 1] = new StringBuilder("L");
        } else if (s.charAt(0) == 'D') {
            last[k] = new StringBuilder("D");
        } else {
            last[k+1] = new StringBuilder("W");
            last[k] = new StringBuilder("D");
            last[k - 1] = new StringBuilder("L");
        }
        
        for (int i = 2; i < n+1; i++) {
            StringBuilder[] cur = new StringBuilder[2 * k + 1];
            if (s.charAt(i-1) == 'W' || s.charAt(i-1) == '?') {
                for (int j = 1; j < 2 * k; j++) {
                    if (last[j] != null) {
                        StringBuilder temp = new StringBuilder(last[j]);
                        cur[j+1] = temp.append('W');
                    }
                }
            }
            if (s.charAt(i-1) == 'L' || s.charAt(i-1) == '?') {
                for (int j = 1; j < 2 * k; j++) {
                    if (last[j] != null) {
                        StringBuilder temp = new StringBuilder(last[j]);
                        cur[j-1] = temp.append('L');
                    }
                }
            }
            
            if (s.charAt(i-1) == 'D' || s.charAt(i-1) == '?') {
                for (int j = 1; j < 2 * k; j++) {
                    if (last[j] != null) {
                        StringBuilder temp = new StringBuilder(last[j]);
                        cur[j] = temp.append('D');
                    }
                }
            }
            
            last = cur;
        }
        
        if (last[2 * k] == null) {
            if (last[0] == null) {
                System.out.println("NO");
            } else {
                System.out.println(last[0].toString());
            }
        } else {
            System.out.println(last[2 * k].toString());
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