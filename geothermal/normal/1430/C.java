    //package com.codeforces.EducationalRound96;
     
    import java.io.BufferedReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.util.StringTokenizer;
    import java.io.PrintWriter;
     
    public class Div2C {
     
        static class FastReader {
     
            BufferedReader  br;
            StringTokenizer st;
     
            public FastReader() {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
     
            String next() {
                while (st == null || !st.hasMoreElements()) {
                    try {
                        st = new StringTokenizer(br.readLine());
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }
     
            int nextInt() {
                return Integer.parseInt(next());
            }
     
            long nextLong() {
                return Long.parseLong(next());
            }
     
            double nextDouble() {
                return Double.parseDouble(next());
            }
     
            String nextLine() {
                String str = "";
                try {
                    str = br.readLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                return str;
            }
        }
     
        public static void main(String[] args) {
     
            FastReader s = new FastReader();
            PrintWriter out = new PrintWriter(System.out);
     
            long n;
     
            long curr;
     
            int T = s.nextInt();
     
            for (int i = 0; i < T; i++) {
     
                n = s.nextInt();
     
                out.printf("2\n");
     
                out.printf("%d %d\n", n, n - 1);
     
                curr = n;
     
                for (long j = n - 2; j >= 1; j--) {
                    out.printf("%d %d\n", curr, j);
                    curr =
                        ((curr + j) % 2) == 0 ?
                        ((curr + j) / 2) :
                        ((curr + j) / 2) + 1;
                }
            }
            out.flush();
            out.close();
        }
    }