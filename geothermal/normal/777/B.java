import java.io.*;
import java.util.StringTokenizer;


public class CreditCards401B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        String sString = in.nextToken();
        String mString = in.nextToken();
        int[] m1 = new int[10];
        int[] m2 = new int[10];
        int[] s1 = new int[10];
        int[] s2 = new int[10];
        for (int i = 0; i < n; i++) {
            int mTemp = Character.getNumericValue(mString.charAt(i));
            int sTemp = Character.getNumericValue(sString.charAt(i));
            m1[mTemp % 10]++;
            m2[mTemp % 10]++;
            mTemp = mTemp / 10;
            s1[sTemp % 10]++;
            s2[sTemp % 10]++;
            sTemp = sTemp / 10;
        }

        int result1 = 0;
        for (int i = 0; i < n; i++) {
            int sCur = findMinGreater(s1, 0);
            s1[sCur]--;
            int mCur = findMinGreater(m1, sCur);
            if (mCur > -1) {
                m1[mCur]--;
            } else {
                result1++;
                mCur = findMinGreater(m1, 0);
                m1[mCur]--;
            }
        }
        System.out.println(result1);
        int result2 = 0;
        for (int i = 0; i < n; i++) {
            int sCur = findMinGreater(s2, 0);
            s2[sCur]--;
            int mCur = findMinGreater(m2, sCur + 1);
            if (mCur > -1) {
                m2[mCur]--;
                result2++;
            } else {
                mCur = findMinGreater(m2, 0);
                m2[mCur]--;
            }
        }
        System.out.println(result2);
    }

    public static int findMinGreater(int[] array, int n) {

        for (int i = n; i < 10; i++) {
            if(array[i] > 0) return i;
        }
        return -1;
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