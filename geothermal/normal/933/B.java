
import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        long Por = in.nextLong(), Kor = in.nextLong();
        BigInteger K = BigInteger.valueOf(Kor), P = BigInteger.valueOf(Por);

        K = K.multiply(BigInteger.valueOf(-1));
        ArrayList<Integer> data = new ArrayList<Integer>();
        BigInteger coef = BigInteger.ONE;
        while (P != BigInteger.ZERO) {
            int cur = 0;
            BigInteger absCo = coef.abs(), absP = P.abs(), absK = K.abs();
            while (absP.remainder(absCo) == BigInteger.ZERO && absP.divide(absCo).remainder(absK) != BigInteger.ZERO) {
                P = P.subtract(coef);
                absP = P.abs();
                cur++;
            }
            data.add(cur);
            coef = coef.multiply(K);
        }

        System.out.println(data.size());
        for (int i = 0; i < data.size(); i++) {
            System.out.print(data.get(i) + " ");
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