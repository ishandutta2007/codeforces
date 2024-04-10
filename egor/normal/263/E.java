import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    int rowCount, columnCount;
    long[][] rows;
    long[][] columns;
    long[][] weightedRows;
    long[][] weightedColumns;
    long[][] diagonals;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        rowCount = in.readInt();
        columnCount = in.readInt();
        rows = new long[rowCount][columnCount];
        columns = new long[rowCount][columnCount];
        weightedRows = new long[rowCount][columnCount];
        weightedColumns = new long[rowCount][columnCount];
        diagonals = new long[rowCount][columnCount];
        int size = in.readInt();
        long[][] matrix = IOUtils.readLongTable(in, rowCount, columnCount);
//        long[][] sums = new long[rowCount + 1][columnCount + 1];
//        for (int i = 0; i < rowCount; i++) {
//            long column = 0;
//            for (int j = 0; j < columnCount; j++) {
//                column += matrix[i][j];
//                sums[i + 1][j + 1] = sums[i + 1][j] + column;
//            }
//        }
        if (size == 1) {
            int row = -1;
            int column = -1;
            long mx = -1;
            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < columnCount; j++) {
                    if (matrix[i][j] > mx) {
                        mx = matrix[i][j];
                        row = i + 1;
                        column = j + 1;
                    }
                }
            }
            out.printLine(row, column);
            return;
        }
        long[][] direct = calculate(matrix, size);
        reverseRows(matrix);
        long[][] reverseRows = calculate(matrix, size - 1);
        reverseRows(reverseRows);
        reverseColumns(matrix);
        long[][] reverse = calculate(matrix, size - 2);
        reverseRows(reverse);
        reverseColumns(reverse);
        reverseRows(matrix);
        long[][] reverseColumn = calculate(matrix, size - 1);
        reverseColumns(reverseColumn);
        int row = -1;
        int column = -1;
        long mx = -1;
        for (int i = size - 1; i <= rowCount - size; i++) {
            for (int j = size - 1; j <= columnCount - size; j++) {
                long value = direct[i][j] + reverseRows[i + 1][j] + reverseColumn[i][j + 1] + reverse[i + 1][j + 1];
                if (value > mx) {
                    mx = value;
                    row = i + 1;
                    column = j + 1;
                }
            }
        }
        out.printLine(row, column);
    }

    private long[][] calculate(long[][] matrix, int size) {
        if (size == 0)
            return new long[rowCount][columnCount];
        for (int i = 0; i < rowCount; i++) {
            long current = 0;
            long weighted = 0;
            for (int j = 0; j < size; j++) {
                current += matrix[i][j];
                weighted += (j + 1) * matrix[i][j];
                rows[i][j] = 0;
            }
            rows[i][size - 1] = current;
            weightedRows[i][size - 1] = weighted;
            for (int j = size; j < columnCount; j++) {
                weighted -= current;
                current -= matrix[i][j - size];
                current += matrix[i][j];
                weighted += matrix[i][j] * size;
                rows[i][j] = current;
                weightedRows[i][j] = weighted;
            }
        }
        for (int i = 0; i < columnCount; i++) {
            long current = 0;
            long weighted = 0;
            for (int j = 0; j < size; j++) {
                current += matrix[j][i];
                weighted += (j + 1) * matrix[j][i];
                columns[j][i] = 0;
            }
            columns[size - 1][i] = current;
            weightedColumns[size - 1][i] = weighted;
            for (int j = size; j < rowCount; j++) {
                weighted -= current;
                current -= matrix[j - size][i];
                current += matrix[j][i];
                weighted += matrix[j][i] * size;
                columns[j][i] = current;
                weightedColumns[j][i] = weighted;
            }
        }
        for (int i = size - 1; i < rowCount; i++) {
            long current = 0;
            for (int j = 0; j < size; j++)
                current += matrix[i - j][j];
            diagonals[i][size - 1] = current;
            for (int j = size; j < columnCount && j <= i; j++) {
                current -= matrix[i - j + size][j - size];
                current += matrix[i - j][j];
                diagonals[i - j + size - 1][j] = current;
            }
        }
        for (int i = 0; i <= columnCount - size; i++) {
            long current = 0;
            for (int j = 0; j < size; j++)
                current += matrix[rowCount - 1 - j][i + j];
            diagonals[rowCount - 1][i + size - 1] = current;
            for (int j = size; j < rowCount && i + j < columnCount; j++) {
                current -= matrix[rowCount - 1 - j + size][i + j - size];
                current += matrix[rowCount - 1 - j][i + j];
                diagonals[rowCount - 1 - j + size - 1][i + j] = current;
            }
        }
        long startTotal = 0;
        long startTriangle = 0;
        for (int i = 0; i < size; i++) {
            for (int j = size - i - 1; j < size; j++) {
                startTotal += matrix[i][j] * (size - (size - 1 - i + size - 1 - j));
                startTriangle += matrix[i][j];
            }
        }
        long[][] result = new long[rowCount][columnCount];
        for (int i = size - 1; i < rowCount; i++) {
            if (i != size - 1) {
                startTotal -= startTriangle;
                startTotal += weightedRows[i][size - 1];
                startTriangle -= diagonals[i - 1][size - 1];
                startTriangle += rows[i][size - 1];
            }
            result[i][size - 1] = startTotal;
            long total = startTotal;
            long triangle = startTriangle;
            for (int j = size; j < columnCount; j++) {
                total -= triangle;
                total += weightedColumns[i][j];
                triangle -= diagonals[i][j - 1];
                triangle += columns[i][j];
                result[i][j] = total;
            }
        }
        return result;
    }

    private void reverseColumns(long[][] matrix) {
        for (int i = 0, j = columnCount - 1; i < j; i++, j--) {
            for (int k = 0; k < rowCount; k++) {
                long temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
            }
        }
    }

    private void reverseRows(long[][] matrix) {
        for (int i = 0, j = rowCount - 1; i < j; i++, j--) {
            for (int k = 0; k < columnCount; k++) {
                long temp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = temp;
            }
        }
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
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

	public static long[] readLongArray(InputReader in, int size) {
		long[] array = new long[size];
		for (int i = 0; i < size; i++)
			array[i] = in.readLong();
		return array;
	}

	public static long[][] readLongTable(InputReader in, int rowCount, int columnCount) {
		long[][] table = new long[rowCount][];
		for (int i = 0; i < rowCount; i++)
			table[i] = readLongArray(in, columnCount);
		return table;
	}

	}