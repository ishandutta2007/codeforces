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
    int n;
    int ys,yb,xs,xb;
    int[] x1,x2,y1,y2;

    boolean inside(int x, int y, int x1, int x2, int y1, int y2) {
        return (x1 <= x && x <= x2 && y1 <= y && y <= y2);
    }

    boolean testX(int y) {
        boolean ok = true;
        for (int x = xs; x <= xb; x++) {
            boolean f = false;
            for (int j = 0; j < n; j++) {
                if (inside(x,y,x1[j],x2[j], y1[j], y2[j])) {
                    f = true;
                    break;
                }
            }

            if (!f) ok = false;
        }
        return ok;
    }

    boolean testY(int x) {
        boolean ok = true;
        for (int y = ys; y <= yb; y++) {
            boolean f = false;
            for (int j = 0; j < n; j++) {
                if (inside(x,y,x1[j],x2[j], y1[j], y2[j])) {
                    f = true;
                    break;
                }
            }

            if (!f) ok = false;
        }
        return ok;
    }

    public void solve(int testNumber, Parser in, PrintWriter out) {
        n = in.nextInt();

        x1 = new int[5];
        y1 = new int[5];
        x2 = new int[5];
        y2 = new int[5];

        xs = 62800; xb = 0;
        ys = 62800; yb = 0;

        for (int i = 0; i < n; i++) {
            x1[i] = 2*in.nextInt();
            y1[i] = 2*in.nextInt();
            x2[i] = 2*in.nextInt();
            y2[i] = 2*in.nextInt();

            xs = Math.min(xs, x1[i]);
            ys = Math.min(ys, y1[i]);
            xb = Math.max(xb, x2[i]);
            yb = Math.max(yb, y2[i]);
        }

        if ((xb-xs) != (yb-ys)) {
            out.println("NO");
            return;
        }

        boolean ok = true;
        for (int i = 0; i < n; i++) {
            if (!testY(x1[i])) ok = false;
            if (x1[i]-1 >= xs && !testY(x1[i]-1)) ok = false;
            if (!testY(x2[i])) ok = false;
            if (x2[i]+1 <= xb && !testY(x2[i]+1)) ok = false;
        }

        for (int i = 0; i < n; i++) {
            if (!testX(y1[i])) ok = false;
            if (y1[i]-1 >= ys && !testX(y1[i]-1)) ok = false;
            if (!testX(y2[i])) ok = false;
            if (y2[i]+1 <= yb && !testX(y2[i]+1)) ok = false;
        }

        if (ok) out.println("YES");
        else out.println("NO");
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