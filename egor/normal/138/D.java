import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
                TaskD solver = new TaskD();
                solver.solve(1, in, out);
                out.close();
        }
}

class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
                int rowCount = in.readInt();
                int columnCount = in.readInt();
                char[][] table = IOUtils.readTable(in, rowCount, columnCount);
                char[][] first = new char[(rowCount + columnCount) / 2][(rowCount + 1) / 2 + (columnCount + 1) / 2 - 1];
                int start = (rowCount + 1) / 2;
                for (int i = 0; i < rowCount + columnCount - 1; i += 2) {
                        start--;
                        for (int j = 0; j < columnCount && j <= i; j++) {
                                if (i - j >= rowCount)
                                        continue;
                                first[i / 2][j + start] = table[i - j][j];
                        }
                }
                char[][] second = new char[(rowCount + columnCount - 1) / 2][rowCount / 2 + columnCount / 2];
                start = rowCount / 2;
                for (int i = 1; i < rowCount + columnCount - 1; i += 2) {
                        start--;
                        for (int j = 0; j < columnCount && j <= i; j++) {
                                if (i - j >= rowCount)
                                        continue;
                                second[i / 2][j + start] = table[i - j][j];
                        }
                }
                if ((solve(first) ^ solve(second)) == 0)
                        out.printLine("LOSE");
                else
                        out.printLine("WIN");
        }

        private int[][][][] result;
        private char[][] table;
        private int[][] sequences;
        private int index = -1;

        private int solve(char[][] table) {
               if (table.length == 0)
                   return 0;
                result = new int[table.length][table.length][table[0].length][table[0].length];
                ArrayUtils.fill(result, -1);
                this.table = table;
                sequences = new int[table.length + table[0].length + 5][table.length * table[0].length];
                return go(0, table.length - 1, 0, table[0].length - 1);
        }

        private int go(int fromRow, int toRow, int fromColumn, int toColumn) {
                if (fromRow > toRow || fromColumn > toColumn)
                        return 0;
                if (result[fromRow][toRow][fromColumn][toColumn] != -1)
                        return result[fromRow][toRow][fromColumn][toColumn];
                index++;
                int sequenceIndex = 0;
                for (int i = fromRow; i <= toRow; i++) {
                        for (int j = fromColumn; j <= toColumn; j++) {
                                if (table[i][j] == 'X')
                                        sequences[index][sequenceIndex++] = go(fromRow, i - 1, fromColumn, j - 1) ^ go(i + 1, toRow, fromColumn, j - 1) ^
                                                go(fromRow, i - 1, j + 1, toColumn) ^ go(i + 1, toRow, j + 1, toColumn);
                                else if (table[i][j] == 'L')
                                        sequences[index][sequenceIndex++] = go(fromRow, i - 1, fromColumn, toColumn) ^ go(i + 1, toRow, fromColumn, toColumn);
                                else if (table[i][j] == 'R')
                                        sequences[index][sequenceIndex++] = go(fromRow, toRow, fromColumn, j - 1) ^ go(fromRow, toRow, j + 1, toColumn);
                        }
                }
                Arrays.sort(sequences[index], 0, sequenceIndex);
                if (sequenceIndex == 0 || sequences[index][0] != 0) {
                        result[fromRow][toRow][fromColumn][toColumn] = 0;
                } else {
                        for (int i = 1; i < sequenceIndex; i++) {
                                if (sequences[index][i] > sequences[index][i - 1] + 1) {
                                        result[fromRow][toRow][fromColumn][toColumn] = sequences[index][i - 1] + 1;
                                        break;
                                }
                        }
                        if (result[fromRow][toRow][fromColumn][toColumn] == -1)
                                result[fromRow][toRow][fromColumn][toColumn] = sequences[index][sequenceIndex - 1] + 1;
                }
                index--;
                return result[fromRow][toRow][fromColumn][toColumn];
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

        public char readCharacter() {
                int c = read();
                while (isSpaceChar(c))
                        c = read();
                return (char) c;
        }

        }

class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
                writer = new PrintWriter(outputStream);
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

        public static char[] readCharArray(InputReader in, int size) {
                char[] array = new char[size];
                for (int i = 0; i < size; i++)
                        array[i] = in.readCharacter();
                return array;
        }

        public static char[][] readTable(InputReader in, int rowCount, int columnCount) {
                char[][] table = new char[rowCount][];
                for (int i = 0; i < rowCount; i++)
                        table[i] = readCharArray(in, columnCount);
                return table;
        }

        }

class ArrayUtils {

        public static void fill(int[][] array, int value) {
                for (int[] row : array)
                        Arrays.fill(row, value);
        }

        public static void fill(int[][][] array, int value) {
                for (int[][] subArray : array)
                        fill(subArray, value);
        }

        public static void fill(int[][][][] array, int value) {
                for (int[][][] subArray : array)
                        fill(subArray, value);
        }

        }