import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskE implements Runnable {
	
	// 1 + 2 + 3 + .. + n = (1 + n) * n / 2
	private BigInteger sum1(int x) {
		return (BigInteger.valueOf((long)(1 + x) * x / 2));
	}
	
	// 1^2 + 2^2 + 3^2 + .. + n^2 = n * (n + 1) * (2n + 1) / 6
	private BigInteger sum2(int x) {
		BigInteger ret = BigInteger.valueOf(x).multiply(BigInteger.valueOf(x + 1)).multiply(BigInteger.valueOf(2 * x + 1));
		ret = ret.divide(BigInteger.valueOf(6));
		
		return ret;
	}
	
	// 1^3 + 2^3 + .. + n^3 = ( (1 + n) * n / 2)^2
	private BigInteger sum3(int x) {
		BigInteger ret = sum1(x);
		
		return ret.multiply(ret);
	}
	
	private BigInteger solveSquare(int x) {
		
		--x;
		
		BigInteger  a3 = sum3(x).multiply(BigInteger.valueOf(2)),
					a2 = sum2(x).multiply(BigInteger.valueOf(3)),
					a1 = sum1(x).multiply(BigInteger.valueOf(3)),
					a0 = BigInteger.valueOf(x + 1);
		
		return a0.add(a1).add(a2).add(a3);
	}
	
	//1 + (1 + d) + (1 + d + (d + 2)) + ...
	//1 * n + d * (n - 1) + (d + 2) * (n - 2) + ...
	//1 * n + n * (d + (d + 2) + (d + 4) + ...) - d - 2 * (d + 2) - 3 * (d + 4)
	private BigInteger sumLine(long n, long d) {
		if (n <= 1) {
			return BigInteger.valueOf(n);
		}
		
		BigInteger ret = BigInteger.valueOf(n);
		BigInteger sum = BigInteger.valueOf(d + (n - 2)).multiply(BigInteger.valueOf(n - 1));
		ret = ret.add(BigInteger.valueOf(n).multiply(sum));
		ret = ret.subtract(sum1((int)n - 1).multiply(BigInteger.valueOf(d)));
		ret = ret.subtract(sumSeq((int)n - 1));
		
		return ret;
	}
	
	// a0 + (a0 + d) + (a0 + d + d) + ...
	private BigInteger sumAri(BigInteger a0, long d, long n) {
		BigInteger bd = BigInteger.valueOf(d);
		BigInteger bn = BigInteger.valueOf(n);
		
		//System.out.println("bn = " + a0.add( a0.add( bn.subtract(BigInteger.ONE).multiply(bd) ) ).multiply(bn) );
		
		return (a0.add( a0.add( bn.subtract(BigInteger.ONE).multiply(bd) ) ).multiply(bn).shiftRight(1) );
	}
	
	//sum{x * 2 * (x - 1) | 1 <= x <= n}
	private BigInteger sumSeq(int x) {
		
		BigInteger ret = sum2(x).subtract(sum1(x));
		
		return ret.multiply(BigInteger.valueOf(2));
	}
	
	private BigInteger solve(int x, int y) {
		
		if (x == 0 || y == 0) {
			return BigInteger.ZERO;
		}
		
		BigInteger ret = solveSquare(Math.min(x,  y));
		if (x > y) {
			BigInteger firstRow = sumLine(x, 3).subtract(sumLine(y, 3));
			ret = ret.add(sumAri(firstRow, y - x, y));
		} else if (y > x){
			BigInteger firstColumn = sumLine(y, 1).subtract(sumLine(x, 1));
			ret = ret.add(sumAri(firstColumn, y - x, x));
		}
		
		return ret;
	}
	
	private void solve(int x1, int y1, int x2, int y2) {
		
		BigInteger ans = solve(x2, y2).subtract(solve(x1 - 1, y2)).subtract(solve(x2, y1 - 1)).add(solve(x1 - 1, y1 - 1));
		
		if (ans.compareTo(BigInteger.valueOf(10000000000l)) < 0) {
			writer.println(ans);
		} else {
			ans = ans.mod(BigInteger.valueOf(10000000000l));
			String str = ans.toString();
			while (str.length() < 10) {
				str = "0" + str;
			}
			
			writer.println("..." + str);
		}
	}

    private void solve() throws IOException {
    	
		//System.out.println("firstColumn = " + sumLine(6, 3));
    	
    	int n = nextInt();
    	for (int i = 0; i < n; ++i) {
    		int x1 = nextInt(),
    			y1 = nextInt(),
    			x2 = nextInt(),
    			y2 = nextInt();
    		
    		solve(x1, y1, x2, y2);
    	}
    }

    public static void main(String[] args) {
        new TaskE().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();//
    }
}