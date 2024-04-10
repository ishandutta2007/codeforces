import java.io.*;
import java.util.*;

public class P526C {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long maxWeight = Long.parseLong(st.nextToken());
		long joyR = Long.parseLong(st.nextToken());
		long joyB = Long.parseLong(st.nextToken());
		long weightR = Long.parseLong(st.nextToken());
		long weightB = Long.parseLong(st.nextToken());
		// reduce the problem by gcd
		long div = gcd(weightR, weightB);
		weightR /= div;
		weightB /= div;
		maxWeight /= div;
		// compare "candy density" and make red be more dense if necessary
		if (1.0 * joyR / weightR  < 1.0 * joyB / weightB) {
			long temp = joyR;
			joyR = joyB;
			joyB = temp;
			temp = weightR;
			weightR = weightB;
			weightB = temp;
		}
		// calculate ans to frobenius coin problem + 1
		long minMake = weightR * weightB - weightR - weightB + 1;
		long initR = (maxWeight - minMake) / weightR;
		if (initR < 0) {
			initR = 0;
		}
		long remainWeight = maxWeight - initR * weightR;
		long maxOther = 0;
		if (weightB > weightR) {
			for (long otherB = 0; otherB * weightB <= remainWeight; otherB++) {
				long otherR = (remainWeight - otherB * weightB) / weightR;
				long currOther = otherR * joyR + otherB * joyB;
				if (currOther > maxOther) {
					maxOther = currOther;
				}
			}
		}
		else {
			for (long otherR = 0; otherR * weightR <= remainWeight; otherR++) {
				long otherB = (remainWeight - otherR * weightR) / weightB;
				long currOther = otherB * joyB + otherR * joyR;
				if (currOther > maxOther) {
					maxOther = currOther;
				}
			}
		}
		out.println(initR * joyR + maxOther);
		out.flush();
		System.exit(0);
	}
	
	static long gcd(long a, long b) {
		while (b != 0) {
			long remainder = a % b;
			a = b;
			b = remainder;
		}
		return a;
	}

}