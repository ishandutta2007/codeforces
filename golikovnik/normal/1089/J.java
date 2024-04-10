import java.io.*;
import java.util.*;
import java.util.function.*;

public class JS_Minification {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    class Trie {
        Map<Character, Trie> next;
        boolean terminal;

        Trie() {
            next = new HashMap<>();
            terminal = false;
        }

        void add(String s) {
            Trie cur = this;
            for (int i = 0; i < s.length(); ++i) {
                char ch = s.charAt(i);
                cur = cur.next.computeIfAbsent(ch, x -> new Trie());
            }
            cur.terminal = true;
        }

        Trie get(String s) {
            Trie cur = this;
            for (int i = 0; cur != null && i < s.length(); ++i) {
                char ch = s.charAt(i);
                cur = cur.next.get(ch);
            }
            return cur;
        }
    }

    boolean isWord(char ch) {
        return Character.isLetterOrDigit(ch) || ch == '_' || ch == '$';
    }

    enum Type {
        RESERVED, NUMBER, WORD
    }

    class Token {
        String name;
        Type type;
        boolean canBeDigit;
        boolean canBeWord;

        public Token(String name, Type type, boolean canBeDigit, boolean canBeWord) {
            this.name = name;
            this.type = type;
            this.canBeDigit = canBeDigit;
            this.canBeWord = canBeWord;
        }
    }

    class Segment {
        int left;
        int right;

        public Segment(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public void solve() throws IOException {
        int nreserved = in.nextInt();
        Trie reserved = new Trie();
        TreeSet<String> canUse = new TreeSet<>(Comparator.comparing(String::length).thenComparing(Function.identity()));
        for (char x = 'a'; x <= 'z'; ++x) {
            canUse.add(x + "");
            for (char y = 'a'; y <= 'z'; ++y) {
                canUse.add("" + x + y);
                for (char z = 'a'; z <= 'z'; ++z) {
                    canUse.add("" + x + y + z);
                }
            }
        }
        for (int i = 0; i < nreserved; ++i) {
            String tk = in.next();
            reserved.add(tk);
            canUse.remove(tk);
        }
        List<Token> tokens = new ArrayList<>();
        StringBuilder wholeSb = new StringBuilder();
        int nlines = in.nextInt();
        for (int i = 0; i < nlines; ++i) {
            String line = in.nextLine();
            int pos = line.indexOf('#');
            wholeSb.append(line, 0, pos == -1 ? line.length() : pos);
            wholeSb.append(' ');
        }
        String whole = wholeSb.toString();
        int len = whole.length();
        {
            int i = 0;
            while (i < len) {
                char ch = whole.charAt(i);
                if (Character.isWhitespace(ch)) {
                    ++i;
                    continue;
                }
                Trie prefix = reserved;
                int resMax = i;
                int resCur = i;
                while (prefix != null && resCur < len) {
                    if (prefix.terminal) {
                        resMax = resCur;
                    }
                    char curCh = whole.charAt(resCur++);
                    prefix = prefix.next.get(curCh);
                }
                boolean canBeDigit = Character.isDigit(ch);
                boolean canBeWord = !canBeDigit && isWord(ch);
                for (int j = i + 1; j < resMax; ++j) {
                    canBeDigit &= Character.isDigit(whole.charAt(j));
                    canBeWord &= isWord(whole.charAt(j));
                }
                if (canBeDigit) {
                    int r = resMax;
                    while (r < len && Character.isDigit(whole.charAt(r))) {
                        ++r;
                    }
                    if (r != resMax) {
                        tokens.add(new Token(whole.substring(i, r), Type.NUMBER, canBeDigit, canBeWord));
                        i = r;
                        continue;
                    }
                }
                if (canBeWord) {
                    int r = resMax;
                    while (r < len && isWord(whole.charAt(r))) {
                        ++r;
                    }
                    if (r != resMax) {
                        tokens.add(new Token(whole.substring(i, r), Type.WORD, canBeDigit, canBeWord));
                        i = r;
                        continue;
                    }
                }
                tokens.add(new Token(whole.substring(i, resMax), Type.RESERVED, canBeDigit, canBeWord));
                i = resMax;
            }
        }
        int ntokens = tokens.size();
        {
            Map<String, String> rename = new HashMap<>();
            for (Token tk : tokens) {
                if (tk.type != Type.WORD) {
                    continue;
                }
                tk.name = rename.computeIfAbsent(tk.name, x -> canUse.pollFirst());
            }
        }
        List<List<Token>> blocks = new ArrayList<>();
        for (int i = 0; i < ntokens; ++i) {
            Token cur = tokens.get(i);
            if (i != 0) {
                Token prev = tokens.get(i - 1);
                char first = cur.name.charAt(0);
                if (prev.canBeDigit && Character.isDigit(first)) {
                    blocks.add(new ArrayList<>());
                } else if (prev.canBeWord && isWord(first)) {
                    blocks.add(new ArrayList<>());
                }
            } else {
                blocks.add(new ArrayList<>());
            }
            blocks.get(blocks.size() - 1).add(cur);
        }
        int blockS = blocks.size();
        for (int i = 0; i < blockS; ++i) {
            if (i != 0) {
                out.print(' ');
            }
            List<Segment> segs = new ArrayList<>();
            List<Token> block = blocks.get(i);
            int blockSize = block.size();
            outer: for (int tk = 0; tk < blockSize; ++tk) {
                Token t = block.get(tk);
                Trie cur = reserved.get(t.name);
                for (int ed = tk + 1; cur != null && ed < blockSize; ++ed) {
                    String s = block.get(ed).name;
                    for (int c = 0; cur != null && c < s.length(); ++c) {
                        cur = cur.next.get(s.charAt(c));
                        if (cur != null && cur.terminal) {
                            segs.add(new Segment(tk + 1, ed));
                            continue outer;
                        }
                    }
                }
            }
            boolean[] putSpace = new boolean[blockSize];
            segs.sort(Comparator.comparingInt(x -> x.right));
            outer: for (Segment seg : segs) {
                for (int pos = seg.left; pos <= seg.right; ++pos) {
                    if (putSpace[pos]) {
                        continue outer;
                    }
                }
                putSpace[seg.right] = true;
            }
            for (int tk = 0; tk < blockSize; ++tk) {
                if (putSpace[tk]) {
                    out.print(' ');
                }
                out.print(block.get(tk).name);
            }
        }
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("input.txt"));
//                out = new PrintWriter(new File("output.txt"));
                out = new PrintWriter(System.out);
            }
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

    }

    public static void main(String[] arg) {
        new JS_Minification().run();
    }
}