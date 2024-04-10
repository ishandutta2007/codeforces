import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Codeforces100A solver = new Codeforces100A();
		solver.solve(1, in, out);
		out.close();
	}
}

class Codeforces100A {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        double R = in.readDouble();
        double r = in.readDouble();
        if (r>R+0.5) {
            out.println("NO");
            return;
        }
        if (n==1){
            if (r<R+0.5){
                out.println("YES");
            }else{
                out.println("NO");
            }
            return;
        }
        if (n==2){
            if (2*r<R+0.5){
                out.println("YES");
            }else{
                out.println("NO");
            }
            return;
        }
        if (2*r>R+0.5){
            out.println("NO");
            return;
        }
        double alpha = Math.asin(r/(R-r));
        if (alpha*n<Math.PI+1e-8){
            out.println("YES");
        }else{
            out.println("NO");
        }
	}
}

class InputReader {
    BufferedReader in;

    public InputReader(InputStream stream) {
        in = new BufferedReader(new InputStreamReader(stream));
    }

    public int skipSpace() {
        int c;
        try {
            while (true) {
                c = in.read();
                if (c < 0) {
                    throw new InputMismatchException();
                }
                if (c > 32) {
                    break;
                }
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return c;
    }

    public int readInt() {
        int res = 0;
        boolean sign = false;
        int c = skipSpace();
        try {
            if (c == '-') {
                sign = true;
                c = in.read();
            }
            while (true) {
                if (c >= '0' && c <= '9') {
                    res = res * 10 + c - '0';
                } else {
                    throw new InputMismatchException();
                }
                c = in.read();
                if (c <= 32) {
                    break;
                }
            }
            if (sign) {
                res = -res;
            }
            return res;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public double readDouble() {
        return Double.parseDouble(next());
    }

    public String next() {
        StringBuilder b = new StringBuilder();
        int c = skipSpace();
        try {
            while (true) {
                b.append((char) c);
                c = in.read();
                if (c <= 32) {
                    break;
                }
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return b.toString();
    }
}