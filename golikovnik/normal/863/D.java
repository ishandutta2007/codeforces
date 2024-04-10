import java.io.*;
import java.util.*;

public class D863 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    Random rnd = new Random(566);
    
    class Treap {
    	int val;
    	long prior;
    	Treap left;
    	Treap right;
    	int size;
    	boolean reversed;
    	
    	Treap(int x) {
    		this.val = x;
    		this.prior = rnd.nextLong();
    		this.size = 1;
    		this.reversed = false;
    	}
    	
    	void update() {
    		this.size = 1 + getSize(left) + getSize(right);
    	}
    	
    }
    
    int getSize(Treap t) {
    	return t == null ? 0 : t.size;
    }
    
    class TreapPair {
    	Treap left;
    	Treap right;
    	
    	TreapPair(Treap left, Treap right) {
    		this.left = left;
    		this.right = right;
    	}
    	
    }
    
    void push(Treap t) {
    	if (t == null) return;
    	if (!t.reversed) return;
    	Treap tmp = t.left;
    	t.left = t.right;
    	t.right = tmp;
    	t.reversed = false;
    	if (t.left != null) t.left.reversed ^= true;
    	if (t.right != null) t.right.reversed ^= true;
    }
    
    TreapPair split(Treap t, int x) {
    	push(t);
    	if (t == null) return new TreapPair(null, null);
    	int sz = 1 + getSize(t.left);
    	if (x >= sz) {
    		TreapPair res = split(t.right, x - sz);
    		t.right = res.left;
    		t.update();
    		res.left = t;
    		return res;
    	} else {
    		TreapPair res = split(t.left, x);
    		t.left = res.right;
    		t.update();
    		res.right = t;
    		return res;
    	}
    }
    
    Treap merge(Treap left, Treap right) {
    	push(left);
    	push(right);
    	if (left == null) return right;
    	if (right == null) return left;
    	if (left.prior > right.prior) {
    		left.right = merge(left.right, right);
    		left.update();
    		return left;
    	} else {
    		right.left = merge(left, right.left);
    		right.update();
    		return right;
    	}
    }
    
    Treap insert(Treap t, int pos, int x) {
    	TreapPair res = split(t, pos);
    	return merge(merge(res.left, new Treap(x)), res.right);
    }
    
    Treap reverse(Treap t, int L, int R) {
    	TreapPair fi = split(t, R);
    	TreapPair se = split(fi.left, L - 1);
    	se.right.reversed ^= true;
    	return merge(merge(se.left, se.right), fi.right);
    }
    
    Treap shift(Treap t, int L, int R) {
    	TreapPair fi = split(t, R);
    	TreapPair se = split(fi.left, L - 1);
    	TreapPair th = split(se.right, R - L);
    	Treap seg = merge(th.right, th.left);
    	return merge(merge(se.left, seg), fi.right);
    }
    
	void print(Treap t, List<Integer> to) {
		push(t);
    	if (t.left != null) print(t.left, to);
    	to.add(t.val);
    	if (t.right != null) print(t.right, to);
    }
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int q = in.nextInt();
    	int m = in.nextInt();
    	Treap t = null;
    	for (int i = 0; i < n; ++i) {
    		t = insert(t, i, in.nextInt());
    	}
    	for (int i = 0; i < q; ++i) {
    		int type = in.nextInt();
    		int L = in.nextInt();
    		int R = in.nextInt();
    		if (type == 1) {
    			t = shift(t, L, R);
    		} else t = reverse(t, L, R);
    	}
    	List<Integer> res = new ArrayList<>();
    	print(t, res);
    	for (int i = 0; i < m; ++i) {
    		int id = in.nextInt();
    		out.print(res.get(id - 1) + " ");
    	}
    }
 
    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("input.txt"));
                out = new PrintWriter(new File("output.txt"));
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
        new D863().run();
    }
}