import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class MinimalLabelE25E {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();

        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        int[] count = new int[n];
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            graph.get(b).add(a);
            count[a]++;
        }

        PriorityQueue<Integer> q = new PriorityQueue<>();
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) {
                q.add(-1 * i);
                answer[i] = -1;
            }

        }



        int nextLabel = n;
        while (!q.isEmpty()) {
            int cur = -1 * q.poll();
            answer[cur] = nextLabel;
            nextLabel--;
            for (int i : graph.get(cur)) {
                count[i]--;
                if (count[i] == 0 && answer[i] == 0) {
                    answer[i] = -1;
                    q.add(i * -1);
                }
            }

        }

        for (int i = 0; i < n; i++) {
            System.out.print(answer[i] + " ");
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