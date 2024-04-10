import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Main implements Runnable {
    private String gao(int i,int j,String s)
    {
        char[] res = new char[j-i+1];
        for (int x = i;x <= j;++x)
            res[x-i] = s.charAt(x);
        int l = j-i+1;
        for (int x = l-1; (l-x)*2 <= l;--x)
            res[x] = res[l-x-1];
        return new String(res);
    }
        
    private void solve() throws IOException {
        String s = nextToken();
        int k = nextInt(),n = s.length();
        int p[][] = new int[n+1][n+1];
        p[0][0] = 0;
        for (int i = n-1;i >= 0;--i) 
            for (int j = i;j < n;++j)
            {
                if (i == j)
                {
                    p[i][j] = 0;
                    continue;
                }
                if (i+1 == j)
                {
                    if (s.charAt(i)==s.charAt(j)) p[i][j] = 0; else p[i][j] = 1;
                    continue;
                }
                p[i][j] = p[i+1][j-1];
                if (s.charAt(i)!=s.charAt(j)) ++p[i][j];
            }
        int f[][],prev[][];
        f = new int[k+1][n+1];
        prev = new int[k+1][n+1];
        Arrays.fill(f[0],0x7f7f7f7f);
        f[0][0] = 0; prev[0][0] = -1;
        int bn = 0;
        for (int t = 1;t <= k;++t)
        {
            Arrays.fill(f[t],0x7f7f7f7f);
            for (int i = 1;i <= n;++i)
            {
                for (int j = 0;j < i;++j)
                    if (f[t-1][j] + p[j][i-1] < f[t][i])
                    {
                        f[t][i] = f[t-1][j] + p[j][i-1];
                        prev[t][i] = j;
                    }
            }
            if (f[t][n] < f[bn][n]) bn = t;
        }
        ArrayList<String> o = new ArrayList<String>();
        //writer.println(p[0][n-1]);
        writer.println(f[bn][n]);
        for (int i = bn,j = n;i > 0;--i)
        {
            String t = gao(prev[i][j],j-1,s);
            o.add(t);
            j = prev[i][j];
        }
        for (int i = o.size()-1;i >= 0;--i)
        {
            writer.print(o.get(i));
            if (i != 0) writer.print("+");
        }
        writer.println();
    }

    public static void main(String[] args) {
        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}