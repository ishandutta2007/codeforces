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
		B solver = new B();
		solver.solve(1, in, out);
		out.close();
	}
}

class B {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        String a = in.readString();
        String s = in.readString();
        int[] data = new int[10];
        for (int i=0;i<s.length();i++){
            data[s.charAt(i)-'0']++;
        }
        char[] result = new char[a.length()];
        int max = 9;
        for (int i=0;i<result.length;i++){
            result[i] = a.charAt(i);
            int d = a.charAt(i)-'0';
            while (data[max] == 0 && max > d) {
                max--;
            }
            if (max>d){
                data[max]--;
                result[i]=(char)('0' + max);
            }
        }
        String str = new String(result);
        out.println(str);
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