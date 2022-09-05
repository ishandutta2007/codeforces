
import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class E977 {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt(); int m = in.nextInt();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1, b = in.nextInt() - 1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        
        
        
        ArrayList<ArrayList<Integer>> components = new ArrayList<>();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Stack<Integer> q = new Stack<>();
                q.add(i);
                visited[i] = true;
                components.add(new ArrayList<>());
                while (!q.isEmpty()) {
                    int cur = q.pop();
                    components.get(components.size() - 1).add(cur);

                    for (int x : graph.get(cur)) {
                        if (!visited[x]) {
                            visited[x] = true;
                            q.add(x);
                        }
                    }
                }
            }
        }
        
        int count = 0;
        loop: for (int i = 0; i < components.size(); i++) {
            if (components.get(i).size() < 3) continue loop;
            for (int j = 0; j < components.get(i).size(); j++) {
                if (graph.get(components.get(i).get(j)).size() != 2) {
                    continue loop;
                }
                int x = components.get(i).get(j);
                int a = graph.get(x).get(0);
                int b = graph.get(x).get(1);
                int y;
                if (j == 0) {
                    y = components.get(i).get(components.get(i).size() - 1);
                } else {
                    y = components.get(i).get(j-1);
                }
                int z;
                if (j == components.get(i).size() - 1) {
                    z = components.get(i).get(0);
                } else {
                    z = components.get(i).get(j+1);
                }
                if (a != y && a != z) continue loop;
                if (b != y && b != z) continue loop;
                
            }
            count++;
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