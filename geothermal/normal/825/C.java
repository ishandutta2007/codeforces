import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class MultiSolvingE25C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int bestSolved = in.nextInt();
        
        ArrayList<Integer> difficulties = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            difficulties.add(in.nextInt());
        }
        Collections.sort(difficulties);
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            while (bestSolved * 2 < difficulties.get(i)) {
                bestSolved = bestSolved * 2;
                count++;
            }
            if (bestSolved < difficulties.get(i)) {
                bestSolved = difficulties.get(i);
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