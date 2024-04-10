//package Codeforces;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class HashingTrees902C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int h = in.nextInt();
        int[] depths = new int[h + 1];
        int nodes = 0;
        for (int i = 0; i <= h; i++) {
            depths[i] = in.nextInt();
            nodes += depths[i];
        }
        
        int[] treeOne = new int[nodes];
        int next = 0;
        int nextParent = 0;
        for (int i = 0; i <= h; i++) {
            int tbd = next + 1;
            for (int j = 0; j < depths[i]; j++) {
                treeOne[next] = nextParent;
                next++;
            }
            nextParent = tbd;
        }
        
        int[] treeTwo = Arrays.copyOf(treeOne, nodes);
        boolean good = false;
        int curPar = 0;
        for (int i = 0; i < h; i++) {
            if (depths[i] > 1 && depths[i+1] > 1) {
                int nextPar = curPar + depths[i];
                treeTwo[nextPar + 1] = curPar + 2;
                good = true;
                break;
            }
            curPar += depths[i];
        }
        
        if (!good) {
            System.out.println("perfect");
        } else {
            System.out.println("ambiguous");
            for (int i = 0; i < nodes; i++) {
                System.out.print(treeOne[i] + " ");
            }
            System.out.println();
            for (int i = 0; i < nodes; i++) {
                System.out.print(treeTwo[i] + " ");
            }
            System.out.println();
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