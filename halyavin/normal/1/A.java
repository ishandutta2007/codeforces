import java.io.IOException;
import java.io.InputStreamReader;
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
		Codeforces1A solver = new Codeforces1A();
		solver.solve(1, in, out);
		out.close();
	}
}

class Codeforces1A {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            long n = in.readLong();
            long m = in.readLong();
            long a = in.readLong();
            n = (n + a - 1) / a;
            m = (m + a - 1) / a;
            out.println(n * m);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class InputReader {
    BufferedReader in;

    public InputReader(InputStream stream) {
        in = new BufferedReader(new InputStreamReader(stream));
    }

    int skipSpace() {
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

    long readLong() throws IOException {
        long res = 0;
        boolean sign = false;
        int c = skipSpace();
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
    }

    }