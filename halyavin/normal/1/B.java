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
		Codeforces1B solver = new Codeforces1B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Codeforces1B {

    int getRow(String s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result = result * 26 + s.charAt(i) - 'A' + 1;
        }
        return result;
    }

    String getString(int row) {
        StringBuilder b = new StringBuilder();
        while (row > 0) {
            b.append((char)((row - 1) % 26 + 'A'));
            row = (row - 1) / 26;
        }
        b.reverse();
        return b.toString();
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        try {
            String s = in.readString();
            int i = 0;
            while (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                i++;
            }
            int row = getRow(s.substring(0, i));
            int previ = i;
            while (i < s.length() && Character.isDigit(s.charAt(i))) {
                i++;
            }
            int column = Integer.parseInt(s.substring(previ, i));
            if (i == s.length()) {
                out.println("R" + column + "C" + row);
                return;
            }
            row = column;
            i++;
            column = Integer.parseInt(s.substring(i));
            out.println(getString(column) + row);
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

    String readString() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        while (true) {
            c = in.read();
            if (c < 0) {
                return "";
            }
            if (c > 32) {
                break;
            }
        }
        while (true) {
            b.append((char) c);
            c = in.read();
            if (c <= 32) {
                break;
            }
        }
        return b.toString();
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