import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
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

	public double nextDouble() {
		return Double.parseDouble(next());
	}

}

class Gauss {
	public static double[][] inverse(double[][] A) {
		int n = A.length;
		double[][] B = new double[n][n];
		for (int i = 0; i < n; i++)
			B[i][i] = 1.0;
		for (int i = 0; i < n; i++) {
			int c = i;
			for (int j = i; j < n; j++)
				if (Math.abs(A[j][i]) > Math.abs(A[c][i]))
					c = j;
			double[] temp;
			temp = A[c];
			A[c] = A[i];
			A[i] = temp;
			temp = B[c];
			B[c] = B[i];
			B[i] = temp;
			for (int j = i + 1; j < n; j++) {
				double lambda = A[j][i] / A[i][i];
				for (int k = 0; k < n; ++k) {
					A[j][k] -= A[i][k] * lambda;
					B[j][k] -= B[i][k] * lambda;
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			double lambda = A[i][i];
			for (int k = 0; k < n; k++) {
				A[i][k] /= lambda;
				B[i][k] /= lambda;
			}
			for (int j = i - 1; j >= 0; j--) {
				lambda = A[j][i];
				for (int k = 0; k < n; ++k) {
					A[j][k] -= A[i][k] * lambda;
					B[j][k] -= B[i][k] * lambda;
				}
			}
		}
		return B;
	}
}

class Matrix {
	public static double[][] multiply(double[][] A, double[][] B) {
		double[][] C = new double[A.length][B[0].length];
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j < A[i].length; j++) {
				for (int k = 0; k < B.length; k++) {
					C[i][k] += A[i][j] * B[j][k];
				}
			}
		}
		return C;
	}

	public static double[][] power(double[][] A, int n) {
		double[][] C = new double[A.length][A[0].length];
		for (int i = 0; i < C.length; i++) {
			C[i][i] = 1.0;
		}
		for (; n > 0; n /= 2, A = multiply(A, A))
			if (n % 2 == 1)
				C = multiply(C, A);
		return C;
	}
}

class Solver {
	// p[i][j]: Pr[start from i and trap in j]
	double[][] computeP(int n, int m, int[][] g, int[] id) {
		double[][] p = new double[n][m];
		double[][] A = new double[n][n];
		for (int i = 0; i < n; i++) {
			A[i][i] = 1.0;
			if (id[i] < 0) {
				int degree = 0;
				for (int j = 0; j < n; j++)
					degree += g[i][j];
				for (int j = 0; j < n; j++)
					if (g[i][j] != 0)
						A[i][j] = -(double) g[i][j] / (double) degree;
			}
		}
//		for (int i = 0; i < id.length; i++)
//			System.out.println("id[" + i + "]=" + id[i]);
//		for (int i = 0; i < A.length; i++) {
//			for (int j = 0; j < A[i].length; j++) {
//				System.out.print(A[i][j] + " ");
//			}
//			System.out.println();
//		}
		double[][] B = Gauss.inverse(A);
		// for (int i = 0; i < B.length; i++) {
		// for (int j = 0; j < B[i].length; j++) {
		// System.out.print(B[i][j] + " ");
		// }
		// System.out.println();
		// }
		for (int i = 0; i < n; i++)
			if (id[i] >= 0) {
				for (int j = 0; j < n; ++j)
					p[j][id[i]] = B[j][i];
			}
		return p;
	}

	public void solve(InputReader in, PrintWriter out) {
		// int n = in.nextInt();
		// double[][] p = new double[n][n];
		// for (int i = 0; i < n; i++)
		// for (int j = 0; j < n; j++)
		// p[i][j] = in.nextDouble();
		// double[][] t = Gauss.inverse(p);
		// for (int i = 0; i < n; i++) {
		// for (int j = 0; j < n; j++)
		// System.out.print(t[i][j] + " ");
		// System.out.println();
		// }
		int n = in.nextInt();
		int numEdge = in.nextInt();
		int numStep = in.nextInt();
		int[] id = new int[n];
		int m = 0;
		for (int i = 0; i < id.length; i++) {
			id[i] = in.nextInt();
			if (id[i] == 1)
				id[i] = m++;
			else
				id[i] = -1;
		}
		int[][] g = new int[n][n];
		for (int t = 0; t < numEdge; t++) {
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u][v]++;
			g[v][u]++;
		}

		double[][] p = computeP(n, m, g, id);
		// for (int i = 0; i < p.length; i++) {
		// for (int j = 0; j < p[i].length; j++) {
		// out.print(p[i][j] + " ");
		// }
		// out.println();
		// }

		double[][] T = new double[m][m];
		double[] b = p[0].clone();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (id[i] >= 0 && id[j] >= 0) {
					int degree = 0;
					for (int k = 0; k < n; k++)
						degree += g[j][k];
					double cur = 0;
					for (int k = 0; k < n; k++)
						cur += p[k][id[i]] * (double) g[j][k];
					T[id[i]][id[j]] = cur / (double) degree;
				}

		T = Matrix.power(T, numStep - 2);
		double ans = 0.0;
		for (int i = 0; i < m; i++)
			ans += T[m - 1][i] * b[i];
		out.print(ans);
	}
}