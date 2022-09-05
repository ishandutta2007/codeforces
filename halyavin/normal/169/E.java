import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.math.BigInteger;
import java.text.DecimalFormat;
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
		E solver = new E();
		solver.solve(1, in, out);
		out.close();
	}
}

class E {
    static class End implements Comparable<End> {
        int sign;
        double pos;
        public End (int sign, double pos){
            this.sign = sign;
            this.pos = pos;
        }
        public int compareTo(End x){
            if (pos < x.pos-1e-10){
                return -1;
            }
            if (pos>x.pos+1e-10){
                return 1;
            }
            if (sign<x.sign){
                return -1;
            }
            if (sign>x.sign){
                return 1;
            }
            return 0;
        }
    }
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.readInt();
        long len = in.readLong();
        long v1 = in.readLong();
        long v2 = in.readLong();
        int dBig = (int)((len*v2)/(v1+v2));
        double dSmall = ((len*v2)%(v1+v2))/(double)(v1+v2);
        int[] as = new int[n];
        for (int i=0;i<n;i++){
            as[i] =in.readInt();
        }
        End[] ends = new End[2*n];
        int start = 0;
        for (int i=0;i<n;i++){
            ends[i] = new End(-1,as[i]);
            if (as[i]>dBig || as[i]==dBig && dSmall<1e-10){
                ends[i+n] = new End(1,as[i]-dBig-dSmall);
            } else {
                start++;
                ends[i+n] = new End(1,as[i]-dBig-dSmall+2*len);
            }
        }
        Arrays.sort(ends);
        double pos = 0;
        double[] res = new double[n+1];
        for (int i=0;i<ends.length;i++){
            double dt = ends[i].pos-pos;
            pos = ends[i].pos;
            res[start]+=dt/(2*len);
            start+=ends[i].sign;
        }
        res[start]+=(2*len-pos)/(2*len);
        DecimalFormat df = new DecimalFormat("0.##########");
        for (int i=0;i<res.length;i++){
            out.println(df.format(res[i]));
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

    public long readLong() {
        long res = 0;
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