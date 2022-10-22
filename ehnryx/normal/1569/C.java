// package Codeforces.Div2Sep8;

import java.util.*;
import java.io.*;

public class C {
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int t = sc.nextInt();
        for(int a=0;a<t;a++) {
            int m = sc.nextInt();
//            sc.nextLine();
            int mod = 998244353;
//            String[] inp = sc.nextLine().split(" ");
            int[] tasks = new int[m];
            for(int i=0;i<m;i++){
                tasks[i] = sc.nextInt();
            }
            List<Integer> arr = new ArrayList<>();
            for (int i = 0; i < m; i++) {
              arr.add(tasks[i]);
            }
            Collections.sort(arr);
            for (int i = 0; i < m; i++) {
              tasks[i] = arr.get(i);
            }
            //Collections.shuffle(Arrays.asList(tasks));

            //Arrays.sort(tasks);
            if(tasks[m-1]-tasks[m-2]>1){
                System.out.println(0);
            } else if (tasks[m-1]-tasks[m-2]==1) {
                int idx = m-2;
                int cnt=0;
                while( idx>=0 &&tasks[idx]==tasks[m-2]) {
                    cnt++; idx--;
                }
                long res = 1;
                for (int i = 1; i <= m; i++) {
                    if(i==(cnt+1)) continue;
                    res = (res * i) % mod;
                }
//                int res = modFact((m),mod);
//                double last = ((cnt/(cnt+1)));
//                System.out.println(last);
                res = (res * cnt) % mod;

                System.out.println(res);
            } else {
                System.out.println(modFact(m,mod));
            }
        }
    }

    static int modFact(int n, int p)
    {
        long result = 1;
        for (int i = 1; i <= n; i++)
            result = (result * i) % p;

        return (int) result;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next()
        {
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

        int nextInt() { return Integer.parseInt(next()); }

        long nextLong() { return Long.parseLong(next()); }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
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
}