import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map;
import java.io.BufferedReader;
import java.io.InputStream;

public class b {
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
    static int INF = (int)1e9 + 9;
    public void solve(InputReader in, PrintWriter out) {
      int T = in.nextInt();
      while(T-- > 0) {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int mina = INF;
        int minb = INF;
        for(int i=0; i<n; i++) {
          a[i] = in.nextInt();
          mina = Math.min(mina, a[i]);
        }
        for(int i=0; i<n; i++) {
          b[i] = in.nextInt();
          minb = Math.min(minb, b[i]);
        }

        long ans = 0;
        for(int i=0; i<n; i++) {
          ans += Math.max(a[i] - mina, b[i] - minb);
        }
        out.println(ans);
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