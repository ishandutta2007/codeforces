import java.io.*;
import java.util.*;

public class f {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    // new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    Solver solver = new Solver();
    solver.solve(in, out);
    out.close();
  }

  static class Solver {
    public void solve(InputReader in, PrintWriter out) {
      int T = in.nextInt();
      while(T-- > 0) {
        int n = in.nextInt();
        List<Tuple> v = new ArrayList<>();
        for(int i=1; i<=n; i++) {
          int a = in.nextInt();
          int b = in.nextInt();
          v.add(new Tuple(a, -b, -i));
          v.add(new Tuple(b, -a, i));
        }
        Collections.sort(v);

        int[] left = new int[2*n+1];
        int[] match = new int[2*n];
        for(int i=0; i<2*n; i++) {
          if(v.get(i).i < 0) {
            left[-v.get(i).i] = i;
            match[i] = -1;
          } else {
            match[i] = left[v.get(i).i];
          }
        }

        int[][] dp = new int[2*n][2*n];
        for(int d=2; d<=2*n; d++) {
          for(int i=0; i<=2*n-d; i++) {
            int j = i + d - 1;
            int k = match[j];
            dp[i][j] = dp[i][j-1];
            if(k >= i) {
              int val = dp[k+1][j-1] + 1 + (k > i ? dp[i][k-1] : 0);
              dp[i][j] = Math.max(dp[i][j], val);
            }
          }
        }
        out.println(dp[0][2*n-1]);
      }
    }

    class Tuple implements Comparable<Tuple> {
      int a, b, i;
      Tuple(int a, int b, int i) {
        this.a = a;
        this.b = b;
        this.i = i;
      }
      public int compareTo(Tuple o) {
        if(this.a < o.a || (this.a <= o.a && this.b < o.b)) return -1;
        if(this.a <= o.a && this.b <= o.b && this.i < o.i) return -1;
        if(this.a == o.a && this.b == o.b && this.i == o.i) return 0;
        return 1;
      }
    }
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

  }

}