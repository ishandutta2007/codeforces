import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        // [x y dx dy 1]
        long n = in.nextLong();

        long sx = ((in.nextLong() - 1) % n + n) % n;
        long sy = ((in.nextLong() - 1) % n + n) % n;
        long dx = (in.nextLong() % n + n) % n;
        long dy = (in.nextLong() % n + n) % n;

        long t = in.nextLong();

        Matrix move = Matrix.getUnitMatrix(6);
        long[][] mat = move.arr;
        mat[0][2] = 1;
        mat[1][2] = 1;
        mat[0][3] = 1;
        mat[1][3] = 1;

        mat[2][0] = 1;
        mat[3][1] = 1;

        mat[0][0] = 2;
        mat[1][0] = 1;
        mat[0][1] = 1;
        mat[1][1] = 2;

        mat[4][2] = 1;
        mat[4][3] = 1;
        mat[4][0] = 1;
        mat[4][1] = 1;

        mat[5][4] = 1;

        Matrix result = NumberUtils.powMod(move, t, n);

        // [sx sy dx dy 1]
        mat = result.arr;
        long x = (sx * mat[0][0] + sy * mat[1][0] + dx * mat[2][0] + dy * mat[3][0] + 2 * mat[4][0] + mat[5][0]) % n;
        long y = (sx * mat[0][1] + sy * mat[1][1] + dx * mat[2][1] + dy * mat[3][1] + 2 * mat[4][1] + mat[5][1]) % n;

        out.println((x + 1) + " " + (y + 1));
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    }

class Matrix {

    public long[][] arr;

    public Matrix(int size) {
        arr = new long[size][size];
    }

    public Matrix(long[][] arr) {
        if (arr.length != arr[0].length) {
            throw new IllegalArgumentException();
        }
        this.arr = new long[arr.length][arr.length];
        for (int i = 0; i < arr.length; ++i) {
            System.arraycopy(arr[i], 0, this.arr[i], 0, arr.length);
        }
    }

    public Matrix(int[][] arr) {
        if (arr.length != arr[0].length) {
            throw new IllegalArgumentException();
        }
        this.arr = new long[arr.length][arr.length];
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr.length; ++j) {
                this.arr[i][j] = arr[i][j];
            }
        }
    }


    public Matrix multiply(Matrix to, Long mod) {
        if (arr.length != to.arr.length) {
            throw new IllegalArgumentException();
        }

        Matrix res = new Matrix(arr.length);
        for (int k = 0; k < arr.length; ++k) {
            for (int i = 0; i < arr.length; ++i) {
                if (arr[i][k] == 0) continue;
                for (int j = 0; j < arr.length; ++j) {
                    res.arr[i][j] += arr[i][k] * to.arr[k][j];
                    if (mod != null && res.arr[i][j] >= mod) {
                        res.arr[i][j] %= mod;
                    }
                }
            }
        }

        return res;
    }

    public int size() {
        return arr.length;
    }

    public static Matrix getUnitMatrix(int size) {
        Matrix matrix = new Matrix(size);
        for (int i = 0; i < size; ++i) {
            matrix.arr[i][i] = 1;
        }
        return matrix;
    }

    public String toString() {
        return Arrays.deepToString(arr);
    }
}

class NumberUtils {

    public static Matrix powMod(Matrix mat, long p, long mod) {

        if (p == 0) {
            return Matrix.getUnitMatrix(mat.size());
        }

        if (p == 1) {
            return mat;
        }

        if (p % 2 == 0) {
            Matrix res = powMod(mat, p / 2, mod);
            return res.multiply(res, mod);
        }

        return powMod(mat, p - 1, mod).multiply(mat, mod);
    }

    }