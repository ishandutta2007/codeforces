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
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
          a[i] = in.nextInt();
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
          for(int j=0; j<i; j++) {
            int s = a[i] + a[j];
            int cur = 0;
            int[] cnt = new int[s+1];
            for(int k=0; k<n; k++) {
              if(a[k] >= s) continue;
              if(cnt[s-a[k]] > 0) {
                cnt[s-a[k]]--;
                cur++;
              } else {
                cnt[a[k]]++;
              }
            }
            ans = Math.max(ans, cur);
          }
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