import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger N = new BigInteger(br.readLine());
        Random r = new Random();
        ArrayList<BigInteger> factors = new ArrayList<BigInteger>();
        factors.add(N);
        for (int z = 0; factors.size() < 10 && z < 99; z++) {
            BigInteger x;
            do {
                x = new BigInteger(N.bitLength(), r);
            } while (x.compareTo(N) >= 0);

            BigInteger sq = x.multiply(x).remainder(N);
            System.out.println("sqrt " + sq);
            System.out.flush();
            BigInteger y = new BigInteger(br.readLine());

            assert y.signum() >= 0;

            BigInteger sum = x.add(y).remainder(N);
            if (sum.equals(BigInteger.ZERO)) {
                continue;
            }
            assert sum.signum() > 0;

            ArrayList<BigInteger> newFactors = new ArrayList<BigInteger>();
            for (BigInteger fac : factors) {
                BigInteger newFac = fac.gcd(sum);
                if (newFac.equals(BigInteger.ONE) || newFac.equals(fac)) {
                    newFactors.add(fac);
                } else {
                    newFactors.add(newFac);
                    newFactors.add(fac.divide(newFac));
                }
            }
            factors = newFactors;
        }
        String result = "! " + factors.size();
        for (BigInteger fac : factors) {
            result += " " + fac;
        }
        System.out.println(result);
        System.out.flush();
    }
}