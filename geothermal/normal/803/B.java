import java.io.*;
import java.util.StringTokenizer;

public class DistToZeroE20B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int l = in.nextInt();
        //int l = 200000;
        int[] arr = new int[l];

        
        for (int i = 0; i < l; i++) arr[i] = in.nextInt();
        //for (int i = 0; i < l; i++) arr[i] = 0;
        
        int[] pre = new int[l];
        int[] post = new int[l];
        int last = -1000000000;
        for (int i = 0; i < l; i++) {
            if (arr[i] == 0) last = i;
            pre[i] = i - last;
        }

        last = 1000000000;
        for (int i = l - 1; i >= 0; i--) {
            if (arr[i] == 0) last = i;
            post[i] = last - i;
        }
        
        
        
        for (int i = 0; i < l; i++) System.out.print(Math.min(pre[i], post[i]) + " ");
        System.out.println();
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