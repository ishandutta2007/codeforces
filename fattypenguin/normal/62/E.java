import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

import javax.swing.Box.Filler;

import org.omg.CORBA.TRANSACTION_MODE;

public class Main implements Runnable {
    
    long f[][],tmp[],sum[];
    long h[][],v[][];
    int stand[],tran[][];
    int n,m;
    
    private void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        h = new long[m][n];
        v = new long[m][n];
        tmp = new long[1<<n];
        sum = new long[1<<n];
        f = new long[m+1][1<<n];
        tran = new int[1<<n][1<<n];
        stand = new int[1<<n];
        for (int i = 0;i < n;++i)
            stand[1<<i] = i;
        for (int j = 0;j < n;++j)
            h[0][j] = 1l << 50;
        for (int i = 1;i < m;++i)
            for (int j = 0;j < n;++j)
                h[i][j] = nextLong();
        for (int i = 0;i < m;++i)
            for (int j = 0;j < n;++j)
                v[i][j] = nextLong();
        for (int i = 0;i < (1 << n);++i)
            for (int j = 0;j < (1 << n);++j)
            {
                int t = i;
                while (true)
                {
                    int s = t | ((t&j) << 1) | ((t & (j<<1)) >> 1);
                    s = s & ((1 << n)-1);
                    if ((j & (1 << (n-1)))!= 0)
                        if (((i&1)!=0) || (i&(1<<(n-1)))!=0)
                            s |= 1 | (1<<(n-1));
                    if (s == t)  break;
                    t = s;
                }
                tran[i][j] = t;
            }
        Arrays.fill(f[0], 1l << 60);
        f[0][(1 << n) - 1] = 0;
        for (int i = 0;i < m;++i)
        {
            Arrays.fill(tmp, 1l << 60);
            Arrays.fill(f[i+1], 1l << 60);
            sum[0] = 0;
            for (int k = 1;k < (1<<n);++k)
                sum[k] = sum[k-(k&(-k))] + h[i][stand[k&-k]];
            for (int j = 0;j < (1<<n);++j)
            {
                for (int k = j;;k = (k-1)&j)
                {
                    int block = k^j;
                    tmp[k] = Math.min(tmp[k],sum[block]+f[i][j]);
                    if (0 == k) break;
                }
            }
            sum[0] = 0;
            for (int k = 1;k < (1<<n);++k)
                sum[k] = sum[k-(k&(-k))] + v[i][stand[k&-k]];
            for (int j = 0;j < (1<<n);++j)
            {
                for (int k = 0;k < (1<<n);++k)
                {
                    int s = tran[j][k];
                    int rest = (k) ^ ((1 << n) - 1);
                    f[i+1][s] = Math.min(f[i+1][s],tmp[j] + sum[rest]);
                }
            }
        }
   //   System.out.println(h[0][0]);
        System.out.println(f[m][0]);
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