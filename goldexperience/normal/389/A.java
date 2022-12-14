import java.util.*;
import java.io.*;
import java.math.*;



public class Main{

	class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int nextHex() {
			return Integer.parseInt(next(), 16);
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public BigInteger nextBigInteger(){
			return new BigInteger(next(), 10);
		}

	}

	int gcd(int x, int y){
		if (y == 0) return x; else return gcd(y, x % y);
	}

	void run(){
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int x = in.nextInt();
			ans = gcd(ans, x);
		}
		out.println(ans * n);
		out.close();
	}

	public static void main(String args[]){
		new Main().run();
	}
}