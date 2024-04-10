import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	
	static class Request {
		final int pin1, left1, right1, pin2, left2, right2;
		
		static final Map<Request, Integer> cache = new HashMap<Request, Integer>();

		Request(int pin1, int left1, int right1, int pin2, int left2,
				int right2) {
			if (pin1 < pin2) {
				int t = pin1;
				pin1 = pin2;
				pin2 = t;
				t = left1;
				left1 = left2;
				left2 = t;
				t = right1;
				right1 = right2;
				right2 = t;
			}
			this.pin1 = pin1;
			this.left1 = left1;
			this.right1 = right1;
			this.pin2 = pin2;
			this.left2 = left2;
			this.right2 = right2;
		}
		
		Request(int l1, int r1, int l2, int r2) {
			this(pin(l1, r1), left(l1, r1), right(l1, r1), pin(l2, r2), left(l2, r2), right(l2, r2));
		}
		
		static int pin(int l, int r) {
			int pin = -1;
			while (l <= r) {
				pin = Integer.numberOfTrailingZeros(l);
				l = (l | (l - 1)) + 1;
			}
			return pin;
		}
		
		static int left(int l, int r) {
			int pin = pin(l, r);
			int pinMask = (1 << pin) - 1;
			int pinPos = (l + pinMask) & ~pinMask;
			return pinPos - l;
		}

		static int right(int l, int r) {
			int pin = pin(l, r);
			int pinMask = (1 << pin) - 1;
			int pinPos = (l + pinMask) & ~pinMask;
			return r - pinPos;
		}
		
		int getAns() {
			Integer ans = cache.get(this);
			if (ans != null) {
				return ans;
			}
			ans = doGetAns();
			cache.put(this, ans);
			return ans;
		}
		
		int doGetAns() {
			int cans = 0;
			if (pin1 == pin2) {
				cans = 1 + min(left1, left2) + min(right1, right2);
			}
			if (left1 > 0) {
				cans = max(cans, new Request(-left1, -1, (1 << pin2) - left2, (1 << pin2) + right2).getAns());
			}
			if (right1 > 0) {
				cans = max(cans, new Request(1, right1, (1 << pin2) - left2, (1 << pin2) + right2).getAns());
			}
			return cans;
		}

		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + left1;
			result = prime * result + left2;
			result = prime * result + pin1;
			result = prime * result + pin2;
			result = prime * result + right1;
			result = prime * result + right2;
			return result;
		}

		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Request other = (Request) obj;
			if (left1 != other.left1)
				return false;
			if (left2 != other.left2)
				return false;
			if (pin1 != other.pin1)
				return false;
			if (pin2 != other.pin2)
				return false;
			if (right1 != other.right1)
				return false;
			if (right2 != other.right2)
				return false;
			return true;
		}
	}
	
	static void solve() throws Exception {
		out.print(new Request(nextInt(), nextInt(), nextInt(), nextInt()).getAns());
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			solve();
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}