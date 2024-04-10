import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
	char[][] pattern = {
		"aaab".toCharArray(), "aaba".toCharArray(), "abaa".toCharArray(), "baaa".toCharArray(), "aabb".toCharArray(),
		"abab".toCharArray(), "abba".toCharArray()
	};

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		int[] distances = IOUtils.readIntArray(in, 6);
		double[][] matrix = new double[6][8];
		for (int i = 0; i < 6; i++)
			matrix[i][7] = distances[i];
		matrix[2][0] = 1;
		matrix[4][0] = 1;
		matrix[5][0] = 1;
		matrix[1][1] = 1;
		matrix[3][1] = 1;
		matrix[5][1] = 1;
		matrix[0][2] = 1;
		matrix[3][2] = 1;
		matrix[4][2] = 1;
		matrix[0][3] = 1;
		matrix[1][3] = 1;
		matrix[2][3] = 1;
		matrix[1][4] = 1;
		matrix[2][4] = 1;
		matrix[3][4] = 1;
		matrix[4][4] = 1;
		matrix[0][5] = 1;
		matrix[2][5] = 1;
		matrix[3][5] = 1;
		matrix[5][5] = 1;
		matrix[0][6] = 1;
		matrix[1][6] = 1;
		matrix[4][6] = 1;
		matrix[5][6] = 1;
		for (int i = 0; i < 6; i++) {
			int row = i;
			for (int j = i + 1; j < 6; j++) {
				if (Math.abs(matrix[row][i]) < Math.abs(matrix[j][i]))
					row = j;
			}
			for (int j = i; j < 8; j++) {
				double temp = matrix[row][j];
				matrix[row][j] = matrix[i][j];
				matrix[i][j] = temp;
			}
			for (int j = 7; j >= i; j--)
				matrix[i][j] /= matrix[i][i];
			for (int j = 0; j < 6; j++) {
				if (i == j)
					continue;
				for (int k = 7; k >= i; k--)
					matrix[j][k] -= matrix[i][k] * matrix[j][i];
			}
		}
		double[] result = new double[7];
		for (int i = 0; i < 6; i++)
			result[i] = matrix[i][7];
		double min = Double.POSITIVE_INFINITY;
		for (int i = 0; i < 4; i++)
			min = Math.min(min, result[i]);
		for (int i = 0; i < 4; i++)
			result[i] -= min;
		for (int i = 4; i < 7; i++)
			result[i] += min;
		int[] answer = new int[7];
		for (int i = 0; i < 7; i++) {
			if (Math.abs(result[i] - Math.round(result[i])) > 1e-7) {
				out.printLine(-1);
				return;
			}
			answer[i] = (int) (result[i] + .5);
			if (answer[i] < 0) {
				out.printLine(-1);
				return;
			}
		}
		StringBuilder[] strings = new StringBuilder[4];
		for (int i = 0; i < 4; i++)
			strings[i] = new StringBuilder();
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < answer[i]; j++) {
				for (int k = 0; k < 4; k++)
					strings[k].append(pattern[i][k]);
			}
		}
		out.printLine(strings[0].length());
		for (StringBuilder builder : strings)
			out.printLine(builder);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class IOUtils {

	public static int[] readIntArray(InputReader in, int size) {
		int[] array = new int[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readInt();
		return array;
	}

	}