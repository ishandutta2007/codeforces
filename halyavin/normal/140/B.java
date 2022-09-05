import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Codeforces100B solver = new Codeforces100B();
		solver.solve(1, in, out);
		out.close();
	}
}

class Codeforces100B {
    int[][] friendsOrder;
    int[] mainOrder;
    int[][] friendsOrderReverse;
    int[] mainOrderReverse;
    int n;
    public int[] reverse(int[] order){
        int[] result = new int[n];
        for (int i=0;i<n;i++){
            result[order[i]]=i;
        }
        return result;
    }
	public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.readInt();
        friendsOrder = new int[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                friendsOrder[i][j]=in.readInt()-1;
            }
        }
        mainOrder = new int[n];
        for (int i=0;i<n;i++){
            mainOrder[i]=in.readInt()-1;
        }
        friendsOrderReverse = new int[n][];
        for (int i=0;i<n;i++){
            friendsOrderReverse[i] = reverse(friendsOrder[i]);
        }
        mainOrderReverse = reverse(mainOrder);
        int[] bestMoment = new int[n];
        int[] bestPosition = new int[n];
        Arrays.fill(bestPosition,n);
        int best = -1;
        int best2 = -1;
        for (int i=0;i<n;i++){
            if (best<0){
                best = i;
            } else {
                int cur = i;
                if (mainOrderReverse[cur]<mainOrderReverse[best]){
                    int tmp = cur;
                    cur = best;
                    best = tmp;
                }
                if (best2<0){
                    best2 = cur;
                }else {
                    if (mainOrderReverse[cur]<mainOrderReverse[best2]){
                        best2 = cur;
                    }
                }
            }
            for (int j=0;j<n;j++){
                int cur=best;
                if (cur==j){
                    cur = best2;
                }
                if (cur<0){
                    continue;
                }
                if (friendsOrderReverse[j][cur]<bestPosition[j]){
                    bestPosition[j]=friendsOrderReverse[j][cur];
                    bestMoment[j]=i+1;
                }
            }
        }
        for (int i=0;i<n;i++){
            out.print(bestMoment[i]);
            out.print(" ");
        }
        out.println();
	}
}

class InputReader {
    BufferedReader in;

    public InputReader(InputStream stream) {
        in = new BufferedReader(new InputStreamReader(stream));
    }

    public int skipSpace() {
        int c;
        try {
            while (true) {
                c = in.read();
                if (c < 0) {
                    throw new InputMismatchException();
                }
                if (c > 32) {
                    break;
                }
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return c;
    }

    public int readInt() {
        int res = 0;
        boolean sign = false;
        int c = skipSpace();
        try {
            if (c == '-') {
                sign = true;
                c = in.read();
            }
            while (true) {
                if (c >= '0' && c <= '9') {
                    res = res * 10 + c - '0';
                } else {
                    throw new InputMismatchException();
                }
                c = in.read();
                if (c <= 32) {
                    break;
                }
            }
            if (sign) {
                res = -res;
            }
            return res;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    }