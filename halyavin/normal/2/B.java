import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.stream.IntStream;

public class Problem2B {
	int n;
	int[][] matrix;
	int[][] opt2;
	int[][] prev2;
	int[][] opt5;
	int[][] prev5;

	public void calc(int[][] opt, int[][] prev, int div) {
		for (int i = matrix.length - 1; i >= 0; i--) {
			for (int j = matrix.length - 1; j >= 0; j--) {
				int value = matrix[i][j];
				if (value == 0) {
					opt[i][j] = Integer.MAX_VALUE;
					prev[i][j] = 0;
					continue;
				}
				int cur = 0;
				while (value % div == 0) {
					value /= div;
					cur++;
				}
				int min = Integer.MAX_VALUE;
				int min_prev = 0;
				if (i < matrix.length - 1 && opt[i + 1][j] < min) {
					min = opt[i + 1][j];
					min_prev = 1;
				}
				if (j < matrix.length - 1 && opt[i][j + 1] < min) {
					min = opt[i][j + 1];
					min_prev = 2;
				}
				if (min_prev != 0) {
					cur += min;
				}
				opt[i][j] = cur;
				prev[i][j] = min_prev;
			}
		}
	}

	public void run(BufferedReader in, PrintWriter out) throws IOException {
		int n = Integer.parseInt(readWord(in));
		matrix = new int[n][n];
		boolean hasZero = false;
		int zeroX = 0;
		int zeroY = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = Integer.parseInt(readWord(in));
				if (matrix[i][j] == 0) {
					hasZero = true;
					zeroX = i;
					zeroY = j;
				}
			}
		}
		opt2 = new int[n][n];
		prev2 = new int[n][n];
		opt5 = new int[n][n];
		prev5 = new int[n][n];
		calc(opt2, prev2, 2);
		calc(opt5, prev5, 5);
		int[][] optPrev;
		int min = Math.min(opt2[0][0], opt5[0][0]);
		if (opt2[0][0] < opt5[0][0]) {
			optPrev = prev2;
		} else {
			optPrev = prev5;
		}
		if (min > 0 && hasZero) {
			out.println("1");
			IntStream.range(0, zeroX).forEach(i -> out.write('D'));
			IntStream.range(0, zeroY).forEach(i -> out.write('R'));
			IntStream.range(zeroX, n - 1).forEach(i -> out.write('D'));
			IntStream.range(zeroY, n - 1).forEach(i -> out.write('R'));
			out.println();
			return;
		}
		out.println(min);
		int curX = 0;
		int curY = 0;
		while (optPrev[curX][curY] != 0) {
			if (optPrev[curX][curY] == 1) {
				out.write('D');
				curX++;
			} else {
				out.write('R');
				curY++;
			}
		}
		out.println();
	}

	public static void main(String[] args) {
		try (BufferedReader in = new BufferedReader(new InputStreamReader(
				System.in));
				PrintWriter out = new PrintWriter(new OutputStreamWriter(
						System.out))) {
			new Problem2B().run(in, out);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	String readWord(BufferedReader in) throws IOException {
		StringBuilder b = new StringBuilder();
		int c = 0;
		while (true) {
			c = in.read();
			if (c < 0) {
				return "";
			}
			if (c > ' ') {
				break;
			}
		}
		while (true) {
			b.append((char) c);
			c = in.read();
			if (c <= ' ') {
				break;
			}
		}
		return b.toString();
	}
}