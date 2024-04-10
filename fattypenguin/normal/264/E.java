import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
import java.util.ArrayList;
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
        int n = in.nextInt();
        int m = in.nextInt();

        IntervalTree tree = new IntervalTree(m + 100);
        IntervalTree index = new IntervalTree(n);

        TreeMap<Integer, Integer> active = new TreeMap<Integer, Integer>();

        ArrayList<Integer> smallIndex = new ArrayList<Integer>();
        ArrayList<Integer> smallHeight = new ArrayList<Integer>();
        ArrayList<Integer> smallLength = new ArrayList<Integer>();

        for (int i = 0; i <= m; ++i) {
            for (int j = smallHeight.size() - 1; j >= 0; --j) {
                int length = index.getMax(smallIndex.get(j)) + 1;

                for (int k = j + 1; k < smallHeight.size(); ++k) {
                    if (smallHeight.get(k) > smallHeight.get(j)) {
                        length = Math.max(length, smallLength.get(k) + 1);
                    }
                }

                tree.update(smallHeight.get(j), length);
                smallLength.set(j, length);

                if (smallHeight.get(j) >= 11 - i + m) {
                    index.update(smallIndex.get(j), length);
                    smallHeight.remove(j);
                    smallIndex.remove(j);
                    smallLength.remove(j);
                }
            }

            if (i > 0) out.println(tree.getMax(0));
            if (i == m) break;

            int type = in.nextInt();
            if (type == 1) {
                int pos = in.nextInt() - 1;
                int height = in.nextInt();

                height = height - i + m;

                active.put(pos, height);

                int idealPos = 0;
                for (int j = 0; j < smallIndex.size(); ++j) {
                    if (smallIndex.get(j) > pos) {
                        break;
                    }
                    ++idealPos;
                }

                smallIndex.add(idealPos, pos);
                smallHeight.add(idealPos, height);
                smallLength.add(idealPos, 0);

            } else {
                int k = in.nextInt();
                int pos[] = new int[k];
                int val[] = new int[k];

                Map.Entry<Integer, Integer> entry = active.firstEntry();
                for (int j = 0; j < k; ++j) {
                    pos[j] = entry.getKey();
                    val[j] = entry.getValue();

                    tree.update(val[j], 0);
                    entry = active.higherEntry(entry.getKey());
                }

                for (int j = 0; j < smallHeight.size(); ++j) {
                    if (pos[k - 1] == smallIndex.get(j)) {
                        smallHeight.remove(j);
                        smallIndex.remove(j);
                        smallLength.remove(j);
                        break;
                    }
                }

                index.update(pos[k - 1], 0);
                active.remove(pos[k - 1]);

                for (int j = k - 2; j >= 0; --j) {
                    int res = tree.getMax(val[j] + 1) + 1;
                    tree.update(val[j], res);
                    if (val[j] >= 11 - i + m) index.update(pos[j], res);
                }

            }
        }



    }
}

class IntervalTree {
    int max[];
    int length;

    IntervalTree(int size) {
        max = new int[size * 4 + 20];
        length = size;
    }

    void update(int aim, int v) {
        update(0, length - 1, aim, 1, v);
    }

    private void update(int left, int right, int aim, int x, int v) {
        if (left == right) {
            max[x] = v;
            return;
        }

        int mid = (left + right) >> 1;
        if (aim <= mid) update(left, mid, aim, x * 2, v);
        else update(mid + 1, right, aim, x * 2 + 1, v);

        max[x] = Math.max(max[x * 2], max[x * 2 + 1]);
    }

    int getMax(int l) {
        return getMax(0, length - 1, l, length - 1, 1);
    }

    private int getMax(int left, int right, int l, int r, int x) {
        if (l <= left && r >= right) {
            return max[x];
        }

        int mid = (left + right) >> 1, ret = 0;
        if (l <= mid) ret = getMax(left, mid, l, r, x * 2);
        if (r > mid) ret = Math.max(ret, getMax(mid + 1, right, l, r, x * 2 + 1));

        return ret;
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