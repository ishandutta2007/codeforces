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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    private char[] s;
    private int[] sa, rank, height;
    private RMQ rmq;//
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        s = in.next().toCharArray();

        int[] length = new int[27];
        length[1] = 1;
        for (int i = 2; i <= 26; ++i) {
            length[i] = length[i - 1] * 2 + 1;
        }

        int n = s.length;
        int[] intS = new int[n];
        for (int i = 0; i < n; ++i) {
            intS[i] = s[i];
        }
        sa = SuffixArray.makeSA(intS);
        rank = SuffixArray.makeRank(sa);
        height = SuffixArray.makeHeight(intS, sa, rank);

        rmq = new STable(height);
        // same index.

        int[][] alphaSum = new int[26][n + 1];
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= n; ++j) {
                alphaSum[i][j] = alphaSum[i][j - 1];
                if (i + 'a' == s[j - 1]) {
                    ++alphaSum[i][j];
                }
            }
        }
        long[][] result = new long[n][26];
        boolean[][] isSymmetric = new boolean[n][27];

        long originalAnswer = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ++result[i][j];
            }
        }

        long[] delta = new long[n + 1];
        for (int radius = 1; radius <= 21; ++radius) {
            for (int i = 0; i < n; ++i) {
                if (radius == 1) {
                    isSymmetric[i][radius] = true;
                    ++delta[i];
                    --delta[i + 1];
                    ++originalAnswer;
                    continue;
                }
                int begin = i - length[radius - 1];
                int end = i + length[radius - 1];

                if (begin < 0 || end >= n) continue;
                long score = (end - begin + 1) * (long)(end - begin + 1);

                int leftCenter = i - 1 - length[radius - 2];
                int rightCenter = i + 1 + length[radius - 2];

                if (!isSymmetric[leftCenter][radius - 1] && !isSymmetric[rightCenter][radius - 1]) {
                    continue;
                }

                if (isSymmetric[leftCenter][radius - 1] && isSymmetric[rightCenter][radius - 1]) {
                    if (equalRange(begin, begin + length[radius - 1] - 1, i + 1, end)) {
                        for (int k = 0; k < 26; ++k) {
                            if (alphaSum[k][i] - alphaSum[k][begin] == 0) {
                                if (k + 'a' == s[i]) {
                                    // original
                                    originalAnswer += score;
                                    delta[begin] += score;
                                    delta[end + 1] -= score;
                                    isSymmetric[i][radius] = true;
                                } else {
                                    result[i][k] += score;
                                }
                            }
                        }
                    }
                }

                int len = getEqualLength(begin, begin + length[radius - 1] - 1, i + 1, end);
                int value = s[i] - 'a';
                if (isSymmetric[leftCenter][radius - 1] && alphaSum[value][i] - alphaSum[value][begin] == 0) {
                    if (len < length[radius - 1]) {
                        if (equalRange(begin + len + 1, i - 1, i + 1 + len + 1, end)) {
                            int shouldBe = s[begin + len] - 'a';
//                            System.out.println("i1 = " + i + " raidus = " + radius + " at = " + (i + 1 + len) + " should be = " + (char)(shouldBe + 'a'));
                            if (shouldBe != s[i] - 'a') {
                                result[i + 1 + len][shouldBe] += score;
                            }
                        }
                    }
                }

                if (isSymmetric[rightCenter][radius - 1] && alphaSum[value][end + 1] - alphaSum[value][i + 1] == 0) {
                    if (len < length[radius - 1]) {
                        if (equalRange(begin + len + 1, i - 1, i + 1 + len + 1, end)) {
                            int shouldBe = s[i + 1 + len] - 'a';
//                            System.out.println("i2 = " + i + " raidus = " + radius + " at = " + (begin + len) + " should be = " + (char)(shouldBe + 'a'));
                            if (shouldBe != s[i] - 'a') {
                                result[begin + len][shouldBe] += score;
                            }
                        }
                    }
                }
            }
        }

        long maxAnswer = originalAnswer;
        for (int i = 1; i < n; ++i) {
            delta[i] += delta[i - 1];
        }
//        System.out.println(Arrays.deepToString(result));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (j + 'a' != s[i]) {
                    maxAnswer = Math.max(maxAnswer, originalAnswer - delta[i] + result[i][j]);
                }
            }
        }

        out.println(maxAnswer);
    }

    private int getEqualLength(int l1, int r1, int l2, int r2) {
        if (r1 - l1 + 1 != r2 - l2 + 1) throw new IllegalArgumentException();
        int low = Math.min(rank[l1], rank[l2]);
        int high = rank[l1] + rank[l2] - low;
        return rmq.getMinValue(low + 1, high);
    }

    private boolean equalRange(int l1, int r1, int l2, int r2) {
        if (l1 > r1) return true;
        if (r1 - l1 + 1 != r2 - l2 + 1) throw new IllegalArgumentException();
        int low = Math.min(rank[l1], rank[l2]);
        int high = rank[l1] + rank[l2] - low;
        return rmq.getMinValue(low + 1, high) >= r2 - l2 + 1;
    }

    interface RMQ {
        abstract public int getMinValue(int left, int right);
    }

    static class STable implements RMQ {
        int min[][];
        int orig[];
        int log[];
        int size, maxPw;

        STable(int[] seq) {
            this.orig = seq;
            this.size = seq.length;
            construct();
        }

        void construct() {
            int power = 1;
            while ((1 << power) < size) {
                ++power;
            }
            maxPw = power + 1;
            min = new int[maxPw][size];
            log = new int[size + 1];
            log[0] = 0;
            for (int i = 1; i <= size; ++i) {
                log[i] = 0;
                while ((1 << (log[i] + 1)) < i) {
                    ++log[i];
                }
            }

            for (int i = 0; i < size; ++i) {
                min[0][i] = orig[i];
            }

            for (int i = 1; i < maxPw; ++i) {
                for (int j = 0; j < size; ++j) {
                    min[i][j] = min[i - 1][j];
                    if (j + (1 << (i - 1)) < size) {
                        min[i][j] = Math.min(min[i][j], min[i - 1][j + (1 << (i - 1))]);
                    }
                }
            }
        }

        public int getMinValue(int left, int right) {
            if (right < left) {
                return Integer.MAX_VALUE;
            }
            int step = log[right - left + 1];
            return Math.min(min[step][left], min[step][right - (1 << step) + 1]);
        }
    }
    static class SuffixArray {

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

                for (; i + height[rank[i]] < s.length && sa[rank[i] - 1] + height[rank[i]] < s.length
                        && s[i + height[rank[i]]] == s[sa[rank[i] - 1] + height[rank[i]]]; ++ height[rank[i]]);
            }

            return height;
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

    }