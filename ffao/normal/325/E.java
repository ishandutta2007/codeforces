import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.Vector;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    boolean[] visited = new boolean[100000];
    Stack<Integer> st= new Stack<Integer>();
    int n;

    void dfs(int v) {
        visited[v] = true;
        st.add(v);
        int k = (v+n)/2;
        if (!visited[k]) {
            dfs(k);
        }
        else if (!visited[k - n/2]){
            dfs(k - n/2);
        }

    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        n = in.nextInt();
        if (n % 2 == 1) {
            out.println(-1);
            return;
        }

        out.print("0");

        dfs(0);
        while (!st.empty()) {
            out.print(" " + st.pop());
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