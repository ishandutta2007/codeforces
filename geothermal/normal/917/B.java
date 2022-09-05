
import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class MadMax917B {
    static boolean[][][] win, processed;
    static char cur;
    static int N, M;
    static ArrayList<ArrayList<Edge>> graph;
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        N = in.nextInt(); M = in.nextInt();
        PriorityQueue<Edge> q = new PriorityQueue<>();
        graph = new ArrayList<>();
        win = new boolean[N][N][27]; processed = new boolean[N][N][27];
        
        for (int i = 0; i < N; i++) graph.add(new ArrayList<>());
        
        for (int i = 0; i < M; i++) {
            int a = in.nextInt() - 1; int b = in.nextInt() - 1;
            char c = in.nextToken().charAt(0);
            Edge e = new Edge(a, b, c);
            q.add(e);
        }
        
        for(int l = 26; l >= 0; l--) {
            while (!q.isEmpty() && (int) q.peek().c - (int) 'a' == l) {
                Edge e = q.poll();
                graph.get(e.a).add(e);
            }
            cur = (char) ((int) 'a' + l);
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (!processed[i][j][l]) dfs(i, j);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (win[i][j][0]) System.out.print("A"); else System.out.print("B");
            }
            System.out.println();
        } 
        
    }
    
    public static void dfs(int i, int j) {
        int id = (int) cur - (int) 'a';
        processed[i][j][id] = true;
        //System.out.println("Entering DFS " + i + " " + j + " " + id);
        if (graph.get(i).size() == 0) {
            win[i][j][id] = false;
            //System.out.println("No outgoing edges, terminating DFS " + i + " " + j + " " + id);
            return;
        }
        boolean isTru = false;
        for (int k = 0; k < graph.get(i).size(); k++) {
            if (graph.get(i).get(k).c != cur) {
                boolean works = win[j][graph.get(i).get(k).b][(int) graph.get(i).get(k).c - (int) 'a'];
                if (!works) {
                    //System.out.println("Working edge " + graph.get(i).get(k).b + " " + graph.get(i).get(k).c);
                    isTru = true;
                    break;
                }
            } else {
                int x = graph.get(i).get(k).b;
                if (!processed[j][x][id]) {
                    dfs(j, x);
                }
                boolean works = win[j][x][id];
                if (!works) {
                    //System.out.println("Working edge " + graph.get(i).get(k).b + " " + graph.get(i).get(k).c);
                    isTru = true;
                    break;
                }
            }
        }
       // System.out.println("Ending DFS " + i + " " + j + " " + id + " " + isTru);
        win[i][j][id] = isTru;
    }
    
    public static class Edge implements Comparable<Edge> {
        int a, b;
        char c;
        public Edge(int a, int b, char c) {
            this.a = a; this.b = b; this.c = c;
        }
        
        public int compareTo(Edge e) {
            return -1 * new Character(c).compareTo(e.c);
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