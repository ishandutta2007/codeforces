
import java.io.*;
import java.util.*;

public class TooEasyProblems913D {
    
    public static void main(String[] args) {
        FastScanner in = new FastScanner();
        
        //while (true) {
            int n = in.nextInt();
            int t = in.nextInt();
            Random r = new Random();
            /*int n = r.nextInt(10) + 1;
            int t = r.nextInt(100) + 1;*/
            //System.out.println(n + " " + t);
            ArrayList<Triple> problems = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                /*int a = r.nextInt(10) + 1;
                int b = r.nextInt(20) + 1;
                System.out.println(a + " " + b);*/
                problems.add(new Triple(b, a, i + 1));
            }
            Collections.sort(problems);
            int best = 0;
            int bestIndex = -1;
            int time = 0;
            TreeSet<Triple> set = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                Triple p = problems.get(i);
                Triple x = new Triple(-1 * p.b, p.a, p.c);
                set.add(x);
                time += x.b;
                while (set.size() > 0 && set.last().a > -1 * set.size()) {
                    Triple tr = set.pollLast();
                    time -= tr.b;
                }

                if (time > t) {
                    break;
                }

                if (set.size() > best) {
                    best = set.size();
                    bestIndex = i;
                }

            }

            TreeSet<Triple> answer = new TreeSet<>();
            for (int i = 0; i <= bestIndex; i++) {
                Triple p = problems.get(i);
                Triple x = new Triple(-1 * p.b, p.a, p.c);
                answer.add(x);

                while (answer.size() > 0 && answer.last().a > -1 * answer.size()) {
                    answer.pollLast();
                }
            }

            System.out.println(best);
            System.out.println(best);
            while (answer.size() > 0) {
                System.out.print(answer.pollLast().c + " ");
            }
            System.out.println();
            /*int stress = 0;
            for (int i = 0; i < 1024; i++) {
                int cur = i;
                int total = 0;
                int tTime = 0;
                int min = 1000;
                for (int j = 0; j < n; j++) {
                    if (cur % 2 == 1) {
                        total++;
                        tTime += problems.get(j).a;
                        min = Math.min(min, problems.get(j).b);
                    }
                    cur = cur / 2;
                }
                if (tTime <= t && total > stress && min >= total) stress = total;
            }
            if (best != answer.size() || best != stress) {
                System.out.println("BAD");
                System.out.println(best + " " + stress);
                break;
            } else {
                System.out.println("GOOD");
            }*/
        //}
        
    }
    
    public static class Triple implements Comparable<Triple> {
        int a, b, c;
        public Triple (int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        
        public int compareTo(Triple p) {
            if (a != p.a) {
                return new Integer(a).compareTo(p.a);
            }
            if (b != p.b) return new Integer(b).compareTo(p.b);
            return new Integer(c).compareTo(p.c);
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