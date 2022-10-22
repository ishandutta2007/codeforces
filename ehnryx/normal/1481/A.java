import java.io.*;
import java.util.*;
import java.math.*;

public class A {
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
      for(int tt=1; tt<=T; tt++) {
        solve_case(in, out);
      }
    }

    void solve_case(InputReader in, PrintWriter out) {
      int x = in.nextInt();
      int y = in.nextInt();
      String s = in.next();
      int topx = 0;
      int topy = 0;
      int botx = 0;
      int boty = 0;
      for(int i=0; i<s.length(); i++) {
        if(s.charAt(i) == 'R') {
          topx++;
        } else if(s.charAt(i) == 'L') {
          botx--;
        } else if(s.charAt(i) == 'U') {
          topy++;
        } else if(s.charAt(i) == 'D') {
          boty--;
        }
      }
      if(botx <= x && x <= topx && boty <= y && y <= topy) {
        out.println("YES");
      } else {
        out.println("NO");
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