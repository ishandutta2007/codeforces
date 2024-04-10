import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        String mask = in.next();
        int limit = in.nextInt();

        int intStr[] = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            intStr[i] = s.charAt(i);
        }

        int sa[] = SuffixArray.makeSA(intStr);
        int rank[] = SuffixArray.makeRank(sa);
        int height[] = SuffixArray.makeHeight(intStr, sa, rank);

        int radius[] = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            int badCount = 0;
            for (int j = i; badCount <= limit && j < s.length(); ++j) {
                if (mask.charAt(s.charAt(j) - 'a') == '0') {
                    ++badCount;
                }

                if (badCount <= limit) {
                    ++radius[i];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            int offer = radius[sa[i]];
            int cut = height[i];
            if (offer > cut) {
                ans += offer - cut;
            }
        }

        out.println(ans);
    }
}

class SuffixArray {

    static boolean cmp(int[] r, int a, int b, int l, int n) {
        int la = r[a], lb = r[b], ra, rb;
        ra = a + l < n ? r[a + l] : -1;
        rb = b + l < n ? r[b + l] : -1;
        return la == lb && ra == rb;
    }

    static int[] makeSA(int s[]) {
        int n = s.length;
        int alphaSize = 1;
        for (int i = 0; i < n; ++i) {
            alphaSize = Math.max(alphaSize, s[i] + 1);
        }

        int[] wa = new int[Math.max(n, alphaSize) + 10];
        int[] wb = new int[Math.max(n, alphaSize) + 10];
        int[] wc = new int[Math.max(n, alphaSize) + 10];
        int[] wd = new int[Math.max(n, alphaSize) + 10];
        int[] sa = new int[n];

        int[] x = wa, y = wb;
        for (int i = 0; i < n; ++i)
            ++wc[x[i] = s[i]];
        for (int i = 1; i < alphaSize; ++i)
            wc[i] += wc[i - 1];
        for (int i = n - 1; i >= 0; --i)
            sa[--wc[x[i]]] = i;
        for (int tot = 0, p = 1; tot + 1 < n; p <<= 1, alphaSize = tot + 1) {
            tot = 0;
            for (int i = n - p; i < n; ++i)
                y[tot++] = i;
            for (int i = 0; i < n; ++i) {
                if (sa[i] >= p) {
                    y[tot++] = sa[i] - p;
                }
            }
            for (int i = 0; i < n; ++i)
                wd[i] = x[y[i]];
            for (int i = 0; i < alphaSize; ++i)
                wc[i] = 0;
            for (int i = 0; i < n; ++i)
                ++wc[wd[i]];
            for (int i = 1; i < alphaSize; ++i)
                wc[i] += wc[i - 1];
            for (int i = n - 1; i >= 0; --i)
                sa[--wc[wd[i]]] = y[i];
            int[] t = x; x = y; y = t;
            x[sa[0]] = tot = 0;
            for (int i = 1; i < n; ++i)
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], p, n) ? tot : ++tot;
        }

        return sa;
    }

    static int[] makeRank(int sa[]) {
        int rank[] = new int[sa.length];
        for (int i = 0; i < sa.length; ++i) {
            rank[sa[i]] = i;
        }

        return rank;
    }

    static int[] makeHeight(int s[], int sa[], int rank[]) {
        int n = s.length;
        int height[] = new int[n];
        for (int i = 0; i < n; ++i) {

            if (0 == rank[i]) {
                continue;
            }

            if (i > 0) {
                height[rank[i]] = Math.max(0, height[rank[i - 1]] - 1);
            }

            for (; i + height[rank[i]] < s.length && sa[rank[i] - 1] + height[rank[i]] < s.length && s[i + height[rank[i]]] == s[sa[rank[i] - 1] + height[rank[i]]]; ++ height[rank[i]]);
        }

        return height;
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