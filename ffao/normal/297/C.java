import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class MyPair {
    int a, b;
    MyPair(int x, int y) {
        a=x; b=y;
    }
}

class TaskC {
    PrintWriter out;
    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i != 0) out.print(" ");
            out.print(a[i]);
        }
        out.println();
    }
    
    public void solve(int testNumber, Parser in, PrintWriter out) {
        this.out = out;
        
        int n = in.nextInt();
        MyPair[] p = new MyPair[n];
        for (int i = 0; i <n; i++) {
            p[i] = new MyPair(in.nextInt(), i);
        }
        Arrays.sort(p, new Comparator<MyPair>() {
            @Override
            public int compare(MyPair o1, MyPair o2) {
                return o1.a-o2.a;
            }
        });

        int[] a = new int[n];
        int[] b = new int[n];

        out.println("YES");
        int ot = (n+2)/3;
        for (int i = 0; i < n; i++) {
            if (i < ot) {
                a[p[i].b] = i;
                b[p[i].b] = p[i].a - i;
            }
            else if (i < 2*ot) {
                a[p[i].b] = p[i].a - i;
                b[p[i].b] = i;
            }
            else {
                a[p[i].b] = p[i].a - (n-i-1);
                b[p[i].b] = n-i-1;
            }
        }

        printArray(a);
        printArray(b);
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