import java.io.*;
import java.util.*;

public class d {
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

        int minv = 2*n;
        int maxv = 1;
        List<Integer> zero = new ArrayList<>();
        List<Integer> one = new ArrayList<>();
        for(int i=1; i<=n; i++) {
          zero.add(i);
        }
        for(int i=0; i<n; i++) {
          one.add(2*n - i);
        }

        int[] ans = new int[n];
        for(int i=0; i<n; i++) {
          int ref;
          if(s.charAt(i) == '0') {
            ref = zero.remove(zero.size() - 1);
            one.add(ref);
          } else {
            ref = one.remove(one.size() - 1);
            zero.add(ref);
          }
          minv = Math.min(minv, ref);
          maxv = Math.max(maxv, ref);
          ans[i] = ref;
        }

        out.println(maxv - minv + 1);
        for(int i=0; i<n; i++) {
          out.print(ans[i] - minv + 1);
          out.print(' ');
        }
        out.print('\n');
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