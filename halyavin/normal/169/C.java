import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.InputMismatchException;
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
		C solver = new C();
		solver.solve(1, in, out);
		out.close();
	}
}

class C {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.readString();
        String t = in.readString();
        int[][] data = new int[s.length()][t.length()];
        int mod = 1000000007;
        for (int i=0;i<s.length();i++){
            int sum = 1;
            for (int j=0;j<t.length();j++){
                if (s.charAt(i) == t.charAt(j)){
                    data[i][j] = sum;
                }
                if (i>0) {
                    sum += data[i-1][j];
                    if (sum>=mod){
                        sum-=mod;
                    }
                }
            }
        }
        int result = 0;
        for (int i=0;i<data.length;i++){
            for (int j=0;j<data[i].length;j++){
                result += data[i][j];
                if (result>=mod) {
                    result -= mod;
                }
            }
        }
        out.println(result);
	}
}

class InputReader {
    BufferedReader in;

    public InputReader(InputStream stream) {
        in = new BufferedReader(new InputStreamReader(stream));
    }

    public String readString() {
        try {
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
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    }