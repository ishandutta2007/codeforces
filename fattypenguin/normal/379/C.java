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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Pair[] contestants = new Pair[n];
        for (int i = 0; i < n; ++i) {
            contestants[i] = new Pair(in.nextInt(), i);
        }
        int[] res = new int[n];
        Arrays.sort(contestants);
        long result = 0;
        int currentRating = 0;
        for (Pair pair : contestants) {
            if (pair.rating > currentRating) {
                currentRating = pair.rating;
            }
            res[pair.id] = currentRating;
            result += currentRating++;
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) out.print(" ");
            out.print(res[i]);
        }
        out.println();
    }

    static class Pair implements Comparable<Pair> {
        int rating, id;
        Pair(int rating, int id) {
            this.rating = rating;
            this.id = id;
        }

        public int compareTo(Pair pair) {
            return rating - pair.rating;
        }
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }