import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BertownSubwayE31C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        //int n = 100000;
        int[] subway = new int[n];
        for (int i = 0; i < n; i++) subway[i] = in.nextInt() - 1;
        //or (int i = 0; i < n; i++) subway[i] = (i) % n;
        boolean[] found = new boolean[n];
        ArrayList<Long> cycles = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (found[i]) continue;
            int cur = i;
            long total = 0;
            while (!found[cur]) {
                found[cur] = true;
                total += 1;
                cur = subway[cur];
            }
            cycles.add(-1 * total);
        }
        Collections.sort(cycles);
        if (cycles.size() == 1) {
            long m = n;
            System.out.println(m * m);
            return;
        }
        long sum = cycles.get(0) + cycles.get(1);
        sum = sum * sum;
        for (int i = 2; i < cycles.size(); i++) {
            sum += cycles.get(i) * cycles.get(i);
        }
        System.out.println(sum);
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