import java.io.*;
import java.awt.geom.*;
import java.text.*;
import java.math.*;
import java.util.*;

public class FD2 implements Runnable {

    final String filename = "";

    MathContext mc = new MathContext(50, RoundingMode.HALF_UP);

    BigDecimal[] sincos(BigDecimal x) {
        BigDecimal s = BigDecimal.valueOf(1, 2); // 0.01
        if (x.compareTo(s) > 0) {
            BigDecimal y = x.divide(BigDecimal.valueOf(2), mc);
            BigDecimal[] siny = sincos(y);
            return new BigDecimal[] { BigDecimal.valueOf(2).multiply(siny[0], mc).multiply(siny[1], mc),
                    siny[1].pow(2, mc).subtract(siny[0].pow(2, mc), mc) };
        }
        BigDecimal sin = BigDecimal.ZERO;
        BigDecimal cos = BigDecimal.ONE;
        BigDecimal mult = x;
        BigDecimal eps = BigDecimal.valueOf(1, mc.getPrecision());
        for (int i = 1; mult.compareTo(eps) > 0; i++) {
            if (i % 2 == 0) {
                if (i % 4 == 0) {
                    cos = cos.add(mult, mc);
                } else {
                    cos = cos.subtract(mult, mc);
                }
            } else {
                if (i % 4 == 1) {
                    sin = sin.add(mult, mc);
                } else {
                    sin = sin.subtract(mult, mc);
                }
            }
            mult = mult.multiply(x, mc).divide(BigDecimal.valueOf(i + 1), mc);
        }
        return new BigDecimal[] { sin, cos };
    }

    BigDecimal f1(BigDecimal a) {
        BigDecimal res = a;
        BigDecimal b = a.multiply(BigDecimal.valueOf(2), mc);
        BigDecimal sin = BigDecimal.ZERO;
        BigDecimal b2 = b.multiply(b, mc);
        BigDecimal mult = b;
        for (int i = 0; i < 20; i++) {
            sin = sin.add(mult, mc);
            mult = mult.multiply(b2, mc);
            mult = mult.divide(BigDecimal.valueOf((2 * i + 2) * (2 * i + 3)), mc).negate();
        }
        return res.subtract(sin.divide(BigDecimal.valueOf(2), mc), mc);
    }

    BigDecimal atan(BigDecimal x) {
        BigDecimal s = BigDecimal.valueOf(1, 1); // 0.1
        int t = 0;
        while (x.compareTo(s) > 0) {
            x = x.subtract(s, mc).divide(BigDecimal.ONE.add(x.multiply(s, mc), mc), mc);
            t++;
        }
        if (t > 0) {
            return atan(s).multiply(BigDecimal.valueOf(t), mc).add(atan(x), mc);
        }
        BigDecimal res = BigDecimal.ZERO;
        BigDecimal mult = x;
        BigDecimal x2 = x.multiply(x, mc);
        int i = 1;
        BigDecimal eps = BigDecimal.valueOf(1, mc.getPrecision());
        while (mult.abs().compareTo(eps) > 0) {
            res = res.add(mult.divide(BigDecimal.valueOf(i), mc), mc);
            mult = mult.multiply(x2, mc).negate();
            i += 2;
        }
        return res;
    }

    public BigDecimal getPi() {
        return BigDecimal.valueOf(4).multiply(atan(BigDecimal.ONE), mc);
    }

    public BigDecimal getPi2() {
        BigDecimal res = atan(BigDecimal.ONE);
        return res.add(res, mc);
    }

    public BigDecimal sqrt(BigDecimal x) {
        int xscale = x.scale();
        int bits = x.unscaledValue().bitLength() + (int) (Math.log(10) * xscale);
        BigDecimal y = new BigDecimal(BigInteger.ONE.shiftLeft(bits / 2), xscale);
        while (true) {
            BigDecimal ny = y.add(x.divide(y, mc), mc).divide(BigDecimal.valueOf(2), mc);
            if (ny.equals(y)) {
                break;
            }
            y = ny;
        }
        return y;
    }

    public BigDecimal atan2(BigDecimal y, BigDecimal x) {
        if (y.signum() > 0 && x.signum() <= 0) {
            return getPi2().add(atan2(x.negate(), y), mc);
        }
        if (y.signum() <= 0 && x.signum() <= 0) {
            return atan2(y.negate(), x).subtract(getPi2(), mc);
        }
        if (y.signum() < 0) {
            return atan2(y.negate(), x).negate();
        }
        if (y.compareTo(x) > 0) {
            return getPi2().subtract(atan2(x, y), mc);
        }
        return atan(y.divide(x, mc));
    }

    public void solve() throws Exception {
        long x1, y1, r1;
        long x2, y2, r2;
        x1 = iread();
        y1 = iread();
        r1 = iread();
        x2 = iread();
        y2 = iread();
        r2 = iread();
        long d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (d2 >= (r1 + r2) * (r1 + r2)) {
            out.write("0\n");
            return;
        }
        if (d2 <= (r1 - r2) * (r1 - r2)) {
            BigDecimal r = BigDecimal.valueOf(Math.min(r1, r2));
            BigDecimal res = r.multiply(r, mc).multiply(getPi(), mc);
            out.write(res + "\n");
            return;
        }
        BigDecimal r1sq = BigDecimal.valueOf(r1).pow(2, mc);
        BigDecimal r2sq = BigDecimal.valueOf(r2).pow(2, mc);
        BigDecimal dsq = BigDecimal.valueOf(d2);
        BigDecimal ix1 = r1sq.subtract(r2sq, mc).add(dsq, mc);
        BigDecimal iy2 = BigDecimal.valueOf(r1 + r2).pow(2, mc).subtract(dsq, mc)
                .multiply(dsq.subtract(BigDecimal.valueOf(r1 - r2).pow(2, mc), mc), mc);
        BigDecimal iy = sqrt(iy2);
        BigDecimal a1 = atan2(iy, ix1);
        BigDecimal res = r1sq.multiply(f1(a1), mc);
        BigDecimal ix2 = r2sq.subtract(r1sq, mc).add(dsq, mc);
        BigDecimal a2 = atan2(iy, ix2);
        res = res.add(r2sq.multiply(f1(a2), mc), mc);
        System.out.println(res);

    }

    DecimalFormat df = new DecimalFormat("0.000000");

    public void run() {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new BufferedWriter(new OutputStreamWriter(System.out));
            // in = new BufferedReader(new FileReader(filename+".in"));
            // out = new BufferedWriter(new FileWriter(filename+".out"));
            solve();
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public int iread() throws Exception {
        return Integer.parseInt(readWord());
    }

    public double dread() throws Exception {
        return Double.parseDouble(readWord());
    }

    public long lread() throws Exception {
        return Long.parseLong(readWord());
    }

    BufferedReader in;

    BufferedWriter out;

    public String readWord() throws IOException {
        StringBuilder b = new StringBuilder();
        int c;
        c = in.read();
        while (c >= 0 && c <= ' ')
            c = in.read();
        if (c < 0)
            return "";
        while (c > ' ') {
            b.append((char) c);
            c = in.read();
        }
        return b.toString();
    }

    public static void main(String[] args) {
        try {
            Locale.setDefault(Locale.US);
        } catch (Exception e) {

        }
        // new Thread(new Main()).start();
        new Thread(null, new FD2(), "1", 1 << 25).start();
    }
}