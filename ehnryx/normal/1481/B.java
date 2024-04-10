import java.io.*;
import java.util.*;
import java.math.*;

public class B {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    // new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    Solver solver = new Solver();
    solver.run_solver(in, out);
    out.close();
  }

  static class Solver {
    public void run_solver(InputReader in, PrintWriter out) {
      int T = in.nextInt();
      while(T-- > 0) {
        solve_case(in, out);
      }
    }

    void solve_case(InputReader in, PrintWriter out) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] h = new int[n];
      for(int i=0; i<n; i++) {
        h[i] = in.nextInt();
      }

      int last = 0;
      for(int t=0; t<k; t++) {
        boolean stop = false;
        for(int i=0; i+1<n; i++) {
          if(h[i] < h[i+1]) {
            h[i] += 1;
            last = i + 1;
            stop = true;
            break;
          }
        }
        if(!stop) {
          last = -1;
          break;
        }
      }
      out.println(last);
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