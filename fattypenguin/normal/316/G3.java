import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collection;
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
        char[] s = in.next().toCharArray();
        SuffixAutomaton automaton = new SuffixAutomaton(26);
        automaton.append(s);
        int[] low = new int[automaton.list.size()];
        int[] high = new int[automaton.list.size()];
        Arrays.fill(low, Integer.MIN_VALUE);
        Arrays.fill(high, Integer.MAX_VALUE);
        int m = in.nextInt();
        for (int iter = 0; iter < m; ++iter) {
            ArrayList occurance[] = new ArrayList[automaton.list.size()];
            for (int i = 0; i < automaton.list.size(); ++i) {
                occurance[i] = new ArrayList<Integer>();
                automaton.list.get(i).tag = 0;
            }
            SuffixAutomaton.SuffixAutomatonNode node = automaton.root;
            int length = 0;
            s = in.next().toCharArray();
            int l = in.nextInt(), r = in.nextInt();
            for (int i = 0; i < s.length; ++i) {
                int c = s[i] - 'a';
                while (node != automaton.root && node.ch[c] == null) {
                    node = node.suffixNode;
                    length = node.maximumLength;
                }

                if (node.ch[c] != null) {
                    ++length;
                    node = node.ch[c];
                    occurance[node.id].add(length);
                    ++node.tag;
                }

            }

            automaton.refresh();
            for (int i = 0; i < automaton.list.size(); ++i) {
                Integer[] arr = ((ArrayList<Integer>)occurance[i]).toArray(new Integer[occurance[i].size()]);
                Arrays.sort(arr, new Comparator<Integer>() {
                    @Override
                    public int compare(Integer a, Integer b) {
                        return b - a;
                    }
                });
                node = automaton.list.get(i);
                if (arr.length + node.sum < l) {
                    low[i] = 0;
                    high[i] = -1;
                } else if (l != 0) {
                    if (l <= node.sum) {
                        high[i] = Math.min(high[i], node.maximumLength);
                    } else {
                        high[i] = Math.min(high[i], arr[l - node.sum - 1]);
                    }
                }

                if (arr.length + node.sum > r) {
                    if (node.sum >= r + 1) {
                        low[i] = 0;
                        high[i] = -1;
                    } else {
                        low[i] = Math.max(low[i], arr[r - node.sum] + 1);
                    }
                }
            }

        }

        long ans = 0;
        for (int i = 1; i < automaton.list.size(); ++i) {
            low[i] = Math.max(low[i], automaton.list.get(i).suffixNode.maximumLength + 1);
            high[i] = Math.min(high[i], automaton.list.get(i).maximumLength);

            if (low[i] <= high[i]) {
                ans += high[i] - low[i] + 1;
            }
        }

        out.println(ans);
    }
}

class SuffixAutomaton {

    public final int ALPHA;
    public int totalNodes;

    class SuffixAutomatonNode{
        SuffixAutomatonNode suffixNode;
        SuffixAutomatonNode ch[];

        int tag, sum;
        int deg;
        int maximumLength;
        int positions;
        int id;
        SuffixAutomatonNode() {
            suffixNode = null;
            ch = new SuffixAutomatonNode[ALPHA];
            maximumLength = 0;
            positions = 0;
            tag = 0;
            deg = 0;
            id = list.size();

            list.add(this);
        }

    }

    SuffixAutomatonNode root;
    SuffixAutomatonNode lastNode;

    ArrayList<SuffixAutomatonNode> list;

    SuffixAutomaton(int ALPHA) {
        this.ALPHA = ALPHA;
        totalNodes = 0;
        list = new ArrayList<SuffixAutomatonNode>();
        root = new SuffixAutomatonNode();
        lastNode = root;
    }

    public void append(char[] s) {
        for (int i = 0; i < s.length; ++i) {
            this.extend(s[i] - 'a');
        }
    }

    SuffixAutomatonNode extend(int c, SuffixAutomatonNode rear) {
        SuffixAutomatonNode p = rear;
        SuffixAutomatonNode np = new SuffixAutomatonNode();
        np.maximumLength = p.maximumLength + 1;
        np.positions = 1;
        while (null != p && null == p.ch[c]) {
            p.ch[c] = np;
            p = p.suffixNode;
        }

        if (p == null) {
            np.suffixNode = root;
        } else {
            SuffixAutomatonNode q = p.ch[c];
            if (q.maximumLength == p.maximumLength + 1) {
                np.suffixNode = q;
            } else {
                SuffixAutomatonNode nq = new SuffixAutomatonNode();
                nq.ch = q.ch.clone();
                nq.maximumLength = p.maximumLength + 1;
                nq.suffixNode = q.suffixNode;
                q.suffixNode = nq;
                np.suffixNode = nq;

                while (null != p && p.ch[c] == q) {
                    p.ch[c] = nq;
                    p = p.suffixNode;
                }
            }
        }

        lastNode = np;
        return np;
    }

    SuffixAutomatonNode extend(int c) {
        return extend(c, lastNode);
    }

    void refresh() {
        Queue<SuffixAutomatonNode> q = new LinkedList<SuffixAutomatonNode>();

        for (SuffixAutomatonNode node : list) {
            if (node.suffixNode != null) {
                ++node.suffixNode.deg;
            }
            node.sum = 0;
        }

        for (SuffixAutomatonNode node : list) {
            if (node.deg == 0) {
                q.add(node);
            }
        }

        while (!q.isEmpty()) {
            SuffixAutomatonNode node = q.poll();
            if (node.suffixNode != null) {
                --node.suffixNode.deg;
                node.suffixNode.sum += node.sum + node.tag;
                if (0 == node.suffixNode.deg) {
                    q.offer(node.suffixNode);
                }
            }
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