import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class SuitableReplacementE25D {
    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner();
        String s = in.nextLine();
        String pattern = in.nextLine();

        HashMap<Character, Integer> pApps = new HashMap<>();
        for (int i = 0; i < pattern.length(); i++) {
            if (pApps.containsKey(pattern.charAt(i))) {
                pApps.put(pattern.charAt(i), pApps.get(pattern.charAt(i)) + 1);
            } else {
                pApps.put(pattern.charAt(i), 1);
            }
        }
        
        HashMap<Character, Integer> sApps = new HashMap<>();
        for (Character c : pApps.keySet()) {
            sApps.put(c, 0);
        }
        ArrayList<Integer> blankPositions = new ArrayList<>();
        int blankCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (sApps.containsKey(s.charAt(i))) {
                if (sApps.containsKey(s.charAt(i))) {
                    sApps.put(s.charAt(i), sApps.get(s.charAt(i)) + 1);
                } else {
                    sApps.put(s.charAt(i), 1);
                }
            } else if (s.charAt(i) == '?') {
                blankCount++;
                blankPositions.add(i);
            }
        }
        
        StringBuilder result = new StringBuilder(s);
        
        loop: for (int i = 1; true; i++) {
            for (Character c : pApps.keySet()) {
                while(pApps.get(c) * i > sApps.get(c) && blankCount > 0) {
                    blankCount--;
                    result.setCharAt(blankPositions.get(blankCount), c);
                    sApps.put(c, sApps.get(c) + 1);
                }
                if (blankCount == 0) break loop;
            }
        }
        
        System.out.println(result);
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