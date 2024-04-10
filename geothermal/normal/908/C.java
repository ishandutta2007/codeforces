
import java.io.*;
import java.util.StringTokenizer;

public class NewYearCurling908C {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        
        double r = (double) in.nextInt();
        double[] answers = new double[n];
        double[] xCoords = new double[n];
        for (int i = 0; i < n; i++) xCoords[i] = (double) in.nextInt();
        
        answers[0] = r;
        for (int i = 1; i < n; i++) {
            double bound = r;
            for (int j = 0; j < i; j++) {
                double xDif = xCoords[i] - xCoords[j];
                double y = answers[j];
                double yNew = y + Math.sqrt(4 * r * r - xDif * xDif);
                if (yNew > bound) bound = yNew;
            }
            answers[i] = bound;
        }
        for (int i = 0; i < n; i++) System.out.print(answers[i] + " ");
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