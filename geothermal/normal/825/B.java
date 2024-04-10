import java.io.*;
import java.util.StringTokenizer;

public class ConnectFiveE25B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        char[][] matrix = new char[10][10];
        for (int i = 0; i < 10; i++) {
            String s = in.nextLine();
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = s.charAt(j);
            }
        }
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] == '.') {
                    matrix[i][j] = 'X';
                    if (hasWon(matrix)) {
                        System.out.println("YES");
                        return;
                    }
                    matrix[i][j] = '.';
                }
            }
        }
        
        System.out.println("NO");
    }
    
    public static boolean hasWon(char[][] matrix) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] == 'X' && matrix[i+1][j] == 'X' && matrix[i+2][j] == 'X' && matrix[i+3][j] == 'X' && matrix[i+4][j] == 'X') {
                    return true;
                }
            }
        }
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 6; j++) {
                if (matrix[i][j] == 'X' && matrix[i][j+1] == 'X' && matrix[i][j+2] == 'X' && matrix[i][j+3] == 'X' && matrix[i][j+4] == 'X') {
                    return true;
                }
            }
        }
        
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (matrix[i][j] == 'X' && matrix[i+1][j+1] == 'X' && matrix[i+2][j+2] == 'X' && matrix[i+3][j+3] == 'X' && matrix[i+4][j+4] == 'X') {
                    return true;
                }
            }
        }
        
        for (int i = 0; i < 6; i++) {
            for (int j = 4; j < 10; j++) {
                if (matrix[i][j] == 'X' && matrix[i+1][j-1] == 'X' && matrix[i+2][j-2] == 'X' && matrix[i+3][j-3] == 'X' && matrix[i+4][j-4] == 'X') {
                    return true;
                }
            }
        }
        return false;
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