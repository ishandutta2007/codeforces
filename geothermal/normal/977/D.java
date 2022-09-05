
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D977 {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();

        ArrayList<Long> list = new ArrayList<>();
        int n = in.nextInt(); for (int i = 0; i < n; i++) list.add(in.nextLong());
        
        int numThree = Integer.MIN_VALUE, numTwo = Integer.MAX_VALUE;
        long best = -1;
        
        for (int i = 0; i < n; i++) {
            int curThree = 0;
            int curTwo = 0;
            long cur = list.get(i);
            while (cur % 3 == 0) {
                cur /= 3;
                curThree++;
            }
            while (cur % 2 == 0) {
                cur /= 2;
                curTwo++;
            }
            if (curTwo <= numTwo && curThree >= numThree) {
                numTwo = curTwo; numThree = curThree; best = list.get(i);
            }
        }
        
        ArrayList<Long> answer = new ArrayList<>();
        answer.add(best);
        for (int i = 1; i < n; i++) {
            long cur = answer.get(i-1);
            if (cur <= 1500000000000000000L && list.contains(cur * 2)) {
                answer.add(cur * 2);
            } else {
                answer.add(cur / 3);
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.print(answer.get(i) + " ");
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