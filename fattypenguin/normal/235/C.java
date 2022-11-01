import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;
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
		CyclicalQuest solver = new CyclicalQuest();
		solver.solve(1, in, out);
		out.close();
	}
}

class SuffixAutomaton {

    public final int ALPHA;
    public int totalNodes;

    class SuffixAutomatonNode{
        SuffixAutomatonNode suffixNode;
        SuffixAutomatonNode ch[];

        int tag;
        int deg;
        int maximumLength;
        int positions;
        SuffixAutomatonNode() {
            suffixNode = null;
            ch = new SuffixAutomatonNode[ALPHA];
            maximumLength = 0;
            positions = 0;
            tag = 0;
            deg = 0;

            list.add(this);
        }
        SuffixAutomatonNode(SuffixAutomatonNode ch[]) {
            suffixNode = null;
            this.ch = ch;
            maximumLength = 0;
            positions = 0;
            tag = 0;
            deg = 0;

            list.add(this);
        }

    }

    SuffixAutomatonNode root;
    SuffixAutomatonNode lastNode;

    LinkedList<SuffixAutomatonNode> list;

    SuffixAutomaton(int ALPHA) {
        this.ALPHA = ALPHA;
        totalNodes = 0;
        list = new LinkedList<SuffixAutomatonNode>();
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
                SuffixAutomatonNode nq = new SuffixAutomatonNode(q.ch.clone());
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


    void calcPositions() {
        Queue<SuffixAutomatonNode> q = new LinkedList<SuffixAutomatonNode>();

        for (SuffixAutomatonNode node : list) {
            if (node.suffixNode != null) {
                ++node.suffixNode.deg;
            }
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
                node.suffixNode.positions += node.positions;
                if (0 == node.suffixNode.deg) {
                    q.offer(node.suffixNode);
                }
            }
        }
    }
}

class CyclicalQuest {

    int JIECAO(char[] s) {
        int n = s.length;
        int[] nxt = new int[n + 1];
        nxt[0] = -1;
        for (int i = 1; i <= n; i++) {
            int j = nxt[i - 1];
            while (j >= 0 && s[j] != s[i - 1])
                j = nxt[j];
            nxt[i] = j + 1;
        }
        int a = n - nxt[n];
        if (n % a == 0)
            return a;
        return n;
    }

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        String s = in.next();
        SuffixAutomaton sa = new SuffixAutomaton(26);
        sa.append(s.toCharArray());
        sa.calcPositions();
        int n = in.nextInt();
        for (; n != 0; --n) {
            char str[] = in.next().toCharArray();
            int length = str.length;
            if (length > s.length()) {
                out.println(0);
                continue;
            }
            int ans = 0;
            SuffixAutomaton.SuffixAutomatonNode node = sa.root;
            int match = 0;
            int maxLength = JIECAO(str) + str.length;
            for (int i = 0; i < maxLength; ++i) {
                int c = str[(i >= length ? i - length : i)] - 'a';
                if (match + 2 * length - i + 10 < length) {
                    break;
                }
                while (node != null && node.ch[c] == null) {
                    node = node.suffixNode;
                    if (node != null) {
                        match = node.maximumLength;
                    }
                }
                if (node == null) {
                    node = sa.root;
                } else {
                    ++match;
                    node = node.ch[c];
                    if (match >= length) {
                        if (n + 1 != node.tag) {
                            node.tag = n + 1;
                            ans += node.positions;
                        }

                        if (node.suffixNode.maximumLength >= length - 1) {
                            node = node.suffixNode;
                            match = node.maximumLength;
                        } else {
                            --match;
                        }
                    }
                }
            }

            out.println(ans);
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
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }