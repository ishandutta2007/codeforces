import java.io.PrintWriter;
import java.util.Scanner;

public class C {

    int n, m;
    int[][] matrix;

    private boolean isGoodX(int x) {
        return x >= 0 && x < n;
    }

    private boolean isGoodY(int y) {
        return y >= 0 && y < m;
    }

    private boolean isGood(int x, int y) {
        return isGoodX(x) && isGoodY(y);
    }

    public boolean checkNormalSquareCells(int x, int y, int size, int value) {
        if (isGoodY(y)) {
            for (int i = 0; i < size; i++) {
                if (isGoodX(x + i) && matrix[x + i][y] != value) {
                    return false;
                }
            }
        }
        if (isGoodY(y + size - 1)) {
            for (int i = 0; i < size; i++) {
                if (isGoodX(x + i) && matrix[x + i][y + size - 1] != value) {
                    return false;
                }
            }
        }
        if (isGoodX(x)) {
            for (int i = 0; i < size; i++) {
                if (isGoodY(y + i) && matrix[x][y + i] != value) {
                    return false;
                }
            }
        }
        if (isGoodX(x + size - 1)) {
            for (int i = 0; i < size; i++) {
                if (isGoodY(y + i) && matrix[x + size - 1][y + i] != value) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean checkNormalSquare(int x, int y, int size) {
        if (size <= 1) return false;
        if (!isGood(x, y) || !isGood(x + size - 1, y + size - 1)) return false;
        if (!checkNormalSquareCells(x, y, size, 1)) return false;
        if (size > 2 && !checkNormalSquareCells(x + 1, y + 1, size - 2, 0)) return false;
        if (!checkNormalSquareCells(x - 1, y - 1, size + 2, 0)) return false;
        return true;
    }

    public boolean checkDiagonalSquareCells(int x, int y, int size, int value, boolean checkCorners) {
        int start = 0;
        int finish = size;
        if (!checkCorners) {
            start++;
            finish--;
        }
        for (int i = start; i < finish; i++) {
            if (isGood(x + i, y + i) && matrix[x + i][y + i] != value) return false;
            if (isGood(x - i, y + i) && matrix[x - i][y + i] != value) return false;
            if (isGood(x - size + 1 + i, y + size - 1 + i) &&
                    matrix[x - size + 1 + i][y + size - 1 + i] != value) return false;
            if (isGood(x + size - 1 - i, y + size - 1 + i) &&
                    matrix[x + size - 1 - i][y + size - 1 + i] != value) return false;
        }
        return true;
    }

    public boolean checkDiagonalSquare(int x, int y, int size) {
        if (size <= 1) return false;
        if (!isGood(x, y) || !isGood(x + size - 1, y + size - 1)) return false;
        if (!isGood(x, y + 2 * size - 2) || !isGood(x - size + 1, y + size - 1)) return false;
        if (!checkDiagonalSquareCells(x, y, size, 1, true)) return false;
        if (!checkDiagonalSquareCells(x, y + 1, size - 1, 0, true)) return false;
        if (size > 2 && !checkDiagonalSquareCells(x, y + 2, size - 2, 0, true)) return false;
        if (!checkDiagonalSquareCells(x, y - 1, size + 1, 0, true)) return false;
        if (!checkDiagonalSquareCells(x, y - 2, size + 2, 0, false)) return false;
        return true;
    }

    public int squares() {
        int res = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (matrix[x][y] == 0) continue;
                int size;
                for (size = 1; y + size < m && matrix[x][y + size] == 1; size++) {
                }
                if (checkNormalSquare(x, y, size)) res++;
                y += size;
            }
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (matrix[x][y] == 0) continue;
                if (isGood(x - 1, y - 1) && matrix[x - 1][y - 1] == 1) continue;
                if (isGood(x + 1, y - 1) && matrix[x + 1][y - 1] == 1) continue;
                int size;
                for (size = 1; x + size < n && y + size < m && matrix[x + size][y + size] == 1; size++) {
                }
                if (checkDiagonalSquare(x, y, size)) res++;
            }
        }
        return res;
    }

    public void run(Scanner in, PrintWriter out) {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            n = in.nextInt();
            m = in.nextInt();
            matrix = new int[n][m];
            for (int i = 0; i < n; i++) {
                String s = in.next();
                for (int j = 0; j < m; j++) {
                    matrix[i][j] = s.charAt(j) - '0';
                }
            }
            out.println(squares());
        }
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in);
             PrintWriter out = new PrintWriter(System.out)
        ) {
            new C().run(in, out);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}