import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BuyLowSellHigh437E {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        ArrayList<Long> data = new ArrayList<>();
        for (int i = 0; i < n; i++) data.add(in.nextLong());
        
        long result = 0;
        PriorityQueue<Long> options = new PriorityQueue<>();
        options.add(data.get(0));
        for (int i = 1; i < n; i++) {
            options.add(data.get(i));
            if (data.get(i) > options.peek()) {
                long val = options.poll();
                result += data.get(i) - val;
                options.add(data.get(i));
            }
        }
        System.out.println(result);
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