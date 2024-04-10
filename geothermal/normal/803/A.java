import java.io.*;
import java.util.StringTokenizer;

public class MaxMatrixE20A {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int[][] matrix = new int[n][n];
        int k = in.nextInt();
        boolean done = false;
        int doneY = 0;
        if (k > n * n) {
            System.out.println(-1);
            return;
        }
        for (int x = 0; x < n; x++) {
            for (int y = x; y < n; y++) {
                if (x == y) {
                    if (k >= 1) {
                        matrix[x][y] = 1;
                        k--;
                    } else {
                        done = true;
                        doneY = y;
                        break;
                    }
                } else {
                    if (k >= 2) {
                        matrix[x][y] = 1;
                        matrix[y][x] = 1;
                        k -= 2;
                    } else {
                        done = true;
                        doneY = y;
                        break;
                    }
                }
            }
            if (done && k == 1) {
                if (doneY < x) {
                    matrix[x][x] = 1;
                } else if (x+1 < n) {
                    matrix[x+1][x+1] = 1;
                }
            }
            if (done) break;
        }
        
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                System.out.print(matrix[x][y] + " ");
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