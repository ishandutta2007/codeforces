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
		Codeforces1C solver = new Codeforces1C();
		solver.solve(1, in, out);
		out.close();
	}
}

class Codeforces1C {
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        double x1,y1;
        double x2,y2;
        double x3,y3;
        double a1;
        double a2;
        double a3;
        double angle;
        double R;
        double d1,d2,d3;
        double area;
        double eps;
        try{
            x1 = in.readDouble();
            y1 = in.readDouble();
            x2 = in.readDouble();
            y2 = in.readDouble();
            x3 = in.readDouble();
            y3 = in.readDouble();
            a1 = Math.atan2(y2-y1,x2-x1);
            a2 = Math.atan2(y3-y1,x3-x1);
            a3 = Math.atan2(y3-y2,x3-x2);
            a1 -= a3;
            a2 -= a3;
            d1 = Math.hypot(x2-x1,y2-y1);
            d2 = Math.hypot(x3-x2,y3-y2);
            d3 = Math.hypot(x3-x1,y3-y1);
            R = d1 * d2 * d3/ (2*Math.abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)));
            eps = 5e-6/Math.min(Math.min(d1,d2),d3);
            for (int i=3;i<=100;i++){
                angle = Math.PI/i;
                if (Math.abs(Math.round(a1/angle)-a1/angle)>eps/angle) {
                    continue;
                }
                if (Math.abs(Math.round(a2/angle)-a2/angle)>eps/angle){
                    continue;
                }
                area = R*R*Math.sin(2*angle)*i/2.0;
                out.println(area);
                return;
            }
        }catch(IOException e){

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

    double readDouble() throws IOException {
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