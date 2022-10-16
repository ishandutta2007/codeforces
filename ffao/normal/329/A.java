import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ffao
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    String[] board;
    int n;

    public void solve(int testNumber, Parser in, OutputWriter out) {
        n = in.nextInt();
        board = new String[n];
        for (int i = 0; i < n; i++) {
            board[i] = in.next();
        }

        boolean okC = true, okR = true;
        for (int i = 0; i < n; i++) {
            boolean found = false;

            for (int j = 0; j < n; j++) {
                if (board[i].charAt(j) != 'E') {
                    found = true;
                    break;
                }
            }

            if (!found) okC = false;
        }

        for (int i = 0; i < n; i++) {
            boolean found = false;

            for (int j = 0; j < n; j++) {
                if (board[j].charAt(i) != 'E') {
                    found = true;
                    break;
                }
            }

            if (!found) okR = false;
        }

        if (!okC && !okR) {
            out.println(-1);
            return;
        }

        if (okC) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i].charAt(j) != 'E') {
                        out.println((i+1) + " " + (j+1));
                        break;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[j].charAt(i) != 'E') {
                        out.println((j+1) + " " + (i+1));
                        break;
                    }
                }
            }
        }
    }
}

class Parser
{
    private BufferedReader din;
    private StringTokenizer tokenizer;

    public Parser(InputStream in)
    {
        din = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(din.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }