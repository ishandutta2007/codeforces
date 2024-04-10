import java.io.*;
import java.util.*;

public class c {
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
        String s = in.next();

        int[] sum = new int[n+1];
        int[] cnt = new int[12*n+1];
        for(int i=0; i<n; i++) {
          sum[i+1] = sum[i] + s.charAt(i) - '0' - 1;
          cnt[sum[i+1]+n] += 1;
        }

        long ans = 0;
        for(int i=0; i<n; i++) {
          ans += cnt[sum[i]+n];
          cnt[sum[i+1]+n] -= 1;
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