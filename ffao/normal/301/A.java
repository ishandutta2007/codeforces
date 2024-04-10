import java.io.IOException;
import java.io.InputStreamReader;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, PrintWriter out) {
        int n = in.nextInt();
        int neg=0, sum=0, min = Constants.INF;

        int[] arr = new int[2*n-1];
        for (int i = 0; i < 2*n-1; i++) {
            arr[i] = in.nextInt();
            sum += Math.abs(arr[i]);
            min = Math.min(min, Math.abs(arr[i]));

            if (arr[i] < 0) neg++;
        }

        if (n % 2 == 0) {
            if (neg % 2 == 0) out.println(sum);
            else out.println(sum - 2*min);
        }
        else out.println(sum);

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

class Constants {
    public static int INF = 1000000010;
}