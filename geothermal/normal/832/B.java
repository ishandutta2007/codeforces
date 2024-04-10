import java.io.*;
import java.util.StringTokenizer;

public class PetyaExam832B {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        boolean[] isGood = new boolean[26];
        String good = in.nextLine();
        for (char c : good.toCharArray()) {
            isGood[(int) c - 97] = true;
        }
        
        char[] pattern = in.nextLine().toCharArray();
        boolean hasStar = false;
        for (char c : pattern) {
            if (c == '*') {
                hasStar = true;
            }
        }
        
        int n = in.nextInt();
        
        loop: for (int i = 0; i < n; i++) {
            char[] string = in.nextLine().toCharArray();
            if ((!hasStar && string.length != pattern.length) || pattern.length > string.length + 1) {
                System.out.println("NO");
                continue loop;
            }
            
            int offset = 0;
            for (int j = 0; j < pattern.length; j++) {
                if (pattern[j] >= 'a' && pattern[j] <= 'z') {
                    if (pattern[j] != string[j+offset]) {
                        System.out.println("NO");
                        continue loop;
                    }
                } else if (pattern[j] == '?') {
                    if (!isGood[(int) string[j+offset] - 97]) {
                        System.out.println("NO");
                        continue loop;
                    }
                } else {
                    offset = string.length - pattern.length;
                    for (int m = 0; m <= offset; m++) {
                        if (isGood[(int) string[j+m] - 97]) {
                            System.out.println("NO");
                            continue loop;
                        }
                    }
                }
            }
            System.out.println("YES");
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