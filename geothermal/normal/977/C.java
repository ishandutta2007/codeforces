
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C977 {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt(); int k = in.nextInt();
        ArrayList<Integer> data = new ArrayList<>(); for (int i = 0; i < n; i++) data.add(in.nextInt());
        Collections.sort(data);
        if (k == 0 && data.get(0) != 1) {
            System.out.println(1);
            return;
        } else if (k == 0) {
            System.out.println(-1);
            return;
        } else if (k == n) {
            System.out.println(data.get(n-1));
            return;
        } else {
            k--;
            if (data.get(k) - data.get(k+1) != 0) {
                System.out.println(data.get(k));
            } else {
                System.out.println(-1);
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