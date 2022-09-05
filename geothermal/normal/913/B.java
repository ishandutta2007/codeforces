
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Spruce913B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        boolean[] leaf = new boolean[n];
        for (int i = 0; i < n; i++) leaf[i] = true;
        
        ArrayList<ArrayList<Integer>> children = new ArrayList<>();
        for (int i = 0; i < n; i++) children.add(new ArrayList<>());
        
        for (int i = 1; i < n; i++) {
            int j = in.nextInt() - 1;
            children.get(j).add(i);
            leaf[j] = false;
        }
        
        for (int i = 0; i < n; i++) {
            if (leaf[i]) continue;
            int count = 0;
            for (int j : children.get(i)) {
                if (leaf[j]) {
                    count++;
                }
            }
            if (count < 3) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
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