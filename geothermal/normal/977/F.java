
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class F977 {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int[] data = new int[n]; for (int i = 0; i < n; i++) data[i] = in.nextInt();
        HashMap<Integer, Integer> last = new HashMap<>();
        int[] dp = new int[n];
        int[] prev = new int[n];
        int best = 0;
        int bestLoc = -1;
        ArrayList<Integer> traceback = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (last.containsKey(data[i] - 1)) {
                dp[i] = dp[last.get(data[i] - 1)] + 1;
                prev[i] = last.get(data[i] - 1);
            } else {
                dp[i] = 1;
                prev[i] = -1;
            }
            last.put(data[i], i);
            best = Math.max(best, dp[i]);
            if (dp[i] == best) bestLoc = i;

        }

        traceback = new ArrayList<>();
        traceback.add(bestLoc + 1);
        int cur = bestLoc;
        while (prev[cur] != -1) {
            cur = prev[cur];
            traceback.add(cur + 1);
        }
        Collections.reverse(traceback);
        System.out.println(best);
        for (int i = 0; i < traceback.size(); i++) {
            System.out.print(traceback.get(i) + " ");
        }
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