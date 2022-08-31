import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.util.Collections;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, InputReader in, OutputWriter out) {
        int count = in.readInt();
        int[] computer = IOUtils.readIntArray(in, count);
        int[][] required = new int[count][];
        for (int i = 0; i < count; i++) {
            int requiredCount = in.readInt();
            required[i] = IOUtils.readIntArray(in, requiredCount);
        }
        MiscUtils.decreaseByOne(required);
        int answer = Integer.MAX_VALUE;
        for (int i = 1; i <= 3; i++)
            answer = Math.min(answer, go(computer, required, i));
        out.printLine(answer);
	}

    private int go(int[] computer, int[][] required, int current) {
        int count = computer.length;
        boolean[] processed = new boolean[count];
        int[] requirementsRemaining = new int[count];
        for (int i = 0; i < count; i++)
            requirementsRemaining[i] = required[i].length;
        int result = 0;
        int notCompleted = count;
        while (notCompleted != 0) {
            while (true) {
                boolean updated = false;
                for (int i = 0; i < count; i++) {
                    if (!processed[i] && computer[i] == current && requirementsRemaining[i] == 0) {
                        processed[i] = true;
                        result++;
                        for (int j = 0; j < count; j++) {
                            for (int k : required[j]) {
                                if (k == i)
                                    requirementsRemaining[j]--;
                            }
                        }
                        updated = true;
                        notCompleted--;
                    }
                }
                if (!updated)
                    break;
            }
            current = current % 3 + 1;
            result++;
        }
        return result - 1;
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

class MiscUtils {

	public static void decreaseByOne(int[]...arrays) {
		for (int[] array : arrays) {
			for (int i = 0; i < array.length; i++)
				array[i]--;
		}
	}

	}