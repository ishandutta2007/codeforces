import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		A solver = new A();
		solver.solve(1, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        int a = in.readInt();
        int b = in.readInt();
        int[] hs = new int[n];
        for (int i=0;i<n;i++){
            hs[i]=in.readInt();
        }
        Arrays.sort(hs);
        out.println(hs[b]-hs[b-1]);
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

    }