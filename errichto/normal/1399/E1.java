import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
 
public class E1 {
    ArrayList<int[]>[] adj;
 
    public static void main(String[] args) throws IOException {
        new E1().solve();
    }
 
    private void solve() throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
 
        int t = Integer.parseInt(f.readLine());
        for (int t1 = 0; t1 < t; t1++) {
            StringTokenizer tokenizer = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(tokenizer.nextToken());
            long s = Long.parseLong(tokenizer.nextToken());
            adj = new ArrayList[n];
            for (int i = 0; i < n; i++) adj[i] = new ArrayList<int[]>();
 
            for (int i = 0; i < n - 1; i++) {
                tokenizer = new StringTokenizer(f.readLine());
                int a = Integer.parseInt(tokenizer.nextToken()) - 1;
                int b = Integer.parseInt(tokenizer.nextToken()) - 1;
                int dist = Integer.parseInt(tokenizer.nextToken());
                int[] a1 = {b, dist};
                int[] a2 = {a, dist};
                adj[a].add(a1);
                adj[b].add(a2);
            }
 
            PriorityQueue<EdgeValue> edgeTrueWeights = new PriorityQueue<EdgeValue>();
            dfsLeaves(0, -1, edgeTrueWeights);
            long sum = 0;
            for (EdgeValue weight : edgeTrueWeights) sum += (long) weight.dist * weight.leaves;
            //System.out.println(sum);
            int moves = 0;
            while (sum > s) {
                EdgeValue heaviest = edgeTrueWeights.remove();
                sum -= (long) heaviest.dist * heaviest.leaves;
                heaviest.dist /= 2;
                sum += (long) heaviest.dist * heaviest.leaves;
                int dist = heaviest.dist;
                int leaves = heaviest.leaves;
                heaviest.comparison = (long) dist * leaves -  ((long) (dist / 2) * leaves);
                moves++;
                edgeTrueWeights.add(heaviest);
            }
 
            out.println(moves);
 
        }
 
        out.close();
    }
 
    private static class EdgeValue implements Comparable<EdgeValue> {
        int dist;
        int leaves;
        long comparison;
 
        public EdgeValue(int dist, int leaves) {
            this.dist = dist;
            this.leaves = leaves;
            comparison = (long) dist * leaves -  ((long) (dist / 2) * leaves);
        }
 
        @Override
        public int compareTo(EdgeValue o) {
            return Long.compare(comparison, o.comparison) * (-1);
        }
    }
 
    private int dfsLeaves(int node, int prev, PriorityQueue<EdgeValue> pq) {
        if (adj[node].size() == 1 && adj[node].get(0)[0] == prev) return 1;
 
        int leaves = 0;
        for (int[] adjacent : adj[node]) {
            if (adjacent[0] == prev) continue;
            int childLeaves = dfsLeaves(adjacent[0], node, pq);
            leaves += childLeaves;
            pq.add(new EdgeValue(adjacent[1], childLeaves));
            //System.out.println(adjacent[1] + " " + childLeaves);
        }
 
        return leaves;
    }
}