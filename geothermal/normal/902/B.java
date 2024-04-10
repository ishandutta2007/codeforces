//package Codeforces;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class ColoringTree902B {
    static ArrayList<ArrayList<Integer>> children = new ArrayList<>();
    static int[] colors;
    static int count = 0;
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        int n = in.nextInt();
        colors = new int[n];
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
            children.add(new ArrayList<>());
        }
        for (int i = 1; i < n; i++) {
            int a = in.nextInt() - 1;
            graph.get(i).add(a);
            graph.get(a).add(i);
        }
        for (int i = 0; i < n; i++) {
            colors[i] = in.nextInt();
        }
        
        boolean[] found = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        found[0] = true;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i : graph.get(cur)) {
                if (!found[i]) {
                    found[i] = true;
                    children.get(cur).add(i);
                    q.add(i);
                }
            }
        }
        search(0, -1);
        System.out.println(count);
    }
    
    /*public static int search(int node) {
        count++;
        if (children.get(node).size() == 0) {
            return colors[node];
        }
        //boolean notNeg = false;
        int col = colors[node];
        //if (col != -1) notNeg = true;
        for (int i = 0; i < children.get(node).size(); i++) {
            int cur = search(children.get(node).get(i));
            //if (cur != -1) notNeg = true;
            if (cur != col) col = -1;
        }
        if (col != -1) count -= children.get(node).size();
        
        return colors[node];
    }*/
    
    public static void search(int node, int color) {
        if (colors[node] != color) {
            color = colors[node];
            count++;
        }
        for (int i = 0; i < children.get(node).size(); i++) {
            search(children.get(node).get(i), color);
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