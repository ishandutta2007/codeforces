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
		Codeforces100D solver = new Codeforces100D();
		solver.solve(1, in, out);
		out.close();
	}
}

class Codeforces100D {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        int[] times = new int[n];
        for (int i=0;i<n;i++){
            times[i] = in.readInt();
        }
        Arrays.sort(times);
        int rest = 350;
        int problems = 0;
        int fine = 0;
        int time = 360;
        for (int i=0;i<n;i++){
           if (rest>=times[i]){
               problems++;
               rest-=times[i];
               continue;
           }
           times[i]-=rest;
           rest = 0;
           if (time>=times[i]){
               problems++;
               time-=times[i];
               fine += (360-time);
           }
        }
        out.println(problems+" "+fine);
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