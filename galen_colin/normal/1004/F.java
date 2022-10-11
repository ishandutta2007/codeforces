import java.io.*;
import java.util.*;

public class Main {
  static BufferedReader reader;
  static StringTokenizer stoken;
  static PrintWriter out;

  static int ni() throws Exception {
    return Integer.parseInt(ns());
  }

  static long nl() throws Exception {
    return Long.parseLong(ns());
  }

  static double nd() throws Exception {
    return Double.parseDouble(ns());
  }

  static String ns() throws Exception {
    if (stoken == null || !stoken.hasMoreTokens()) stoken = new StringTokenizer(reader.readLine());
    return stoken.nextToken();
  }

  static segtree_sum ss;
  static segtree_or so;

  static int n, x;
  static int INDEX = -1;
  static long DON = -1;
  static int POS;
  static long[] reach;
  static long[] QV;
  static int qc;
  static int[] qrun;

  public static void main(String[] args) throws Exception {
    reader = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);

    n = ni();
    int q = ni();
    x = ni();
    long[] a = new long[n];
    for (int i = 0; i < n; i++) a[i] = nl();
    QV = new long[200007];
    qrun = new int[200009];
    for (int i = 0; i < 200007; i++) QV[i] = -1;

    reach = new long[n];
    int pt = -1;

    int count[] = new int[20];
    int cor = 0;
    for (int i = 0; i < n; i++) {
      while (pt < n - 1 && (cor < x || pt < i)) {
        ++pt;
        for (int j = 0; j < 20; j++) {
          if ((a[pt] & (1 << j)) > 0) ++count[j];
        }
        cor = 0;
        for (int j = 0; j < 20; j++) {
          if (count[j] > 0) cor += (1 << j);
        }
      }

      reach[i] = pt;
      if (cor < x) reach[i] = n;
      for (int j = 0; j < 20; j++) {
        if ((a[i] & (1 << j)) > 0) --count[j];
      }
      cor = 0;
      for (int j = 0; j < 20; j++) {
        if (count[j] > 0) cor += (1 << j);
      }
    }

    ss = new segtree_sum(n);
    so = new segtree_or(n);
    ss.init(reach);
    so.init(a);

    // for (int i = 0; i < n; i++) out.print(reach[i] + " ");
    // out.println();

    for (int Q = 0; Q < q; Q++) {
      int type = ni();
      if (type == 1) {
        int ind = ni() - 1, val = ni();
        so.update(ind, val);

        int cind = ind;
        cor = val;
        POS = ind;
        int ll = 0, rr = n;
        while (ll < rr) {
          int m = (ll + rr) / 2;

          long v = ss.query(m, m);
          if (v < ind) ll = m + 1;
          else rr = m;
        }
        while (cind >= 0 && (cind == ind || ss.query(cind, cind) >= ind)) {
          INDEX = cind;
          DON = cor;
          qc = 0;
          so.query_left(0, 0, n - 1, cind, cor);
          for (int i = 0; i < qc; i++) QV[qrun[i]] = -1;
          INDEX = Math.max(INDEX, ll);
          
          int stor = INDEX;
          INDEX = ind - 1;
          qc = 0;
          so.query_right(0, 0, n - 1, ind, cor);
          for (int i = 0; i < qc; i++) QV[qrun[i]] = -1;
          int v = INDEX + 1;
          ss.update(stor, cind, v);

          // out.println("stor " + stor + " " + cind + " " + (INDEX + 1));

          cor = (int)so.query(stor, ind);
          if (stor != 0) cor |= so.query(stor - 1, stor - 1);
          cind = stor - 1;
        }

        // for (int i = 0; i < n; i++) out.print(so.query(i, i) + " ");
        // out.println();
        // for (int i = 0; i < n; i++) out.print(ss.query(i, i) + " ");
        // out.println();
      } else {
        long l = ni() - 1, r = ni() - 1;
        if (l == r) {
          if (so.query((int)l, (int)l) < x) out.println(0);
          else out.println(1);
          continue;
        }

        long ll = l, rr = r + 1;
        while (ll < rr) {
          int m = (int)((ll + rr) / 2);

          long v = ss.query(m, m);
          if (v <= r) ll = m + 1;
          else rr = m;
        }

        long base = ff(r - l + 1) + (ff(r) - ff(l - 1));
        // out.println("base " + base);

        base -= (r - ll + 1) * (r + 1);
        // out.println("base " + base + " " + ll);
        if (ll != l) {
          base -= ss.query((int)l, (int)(ll - 1));
        }
        out.println(base);
      }
    }
  }

  static long ff(long x) {
    if (x < 0) return 0;
    return x * (x + 1) / 2;
  }

  static Point max(Point a, Point b) {
    if (a.x == b.x) {
      if (a.y < b.y) return new Point(b.x, b.y);
      return new Point(a.x, a.y);
    }
    if (a.x < b.x) return new Point(b.x, b.y);
    return new Point(a.x, a.y);
  }

  static class Point implements Comparable<Point> {
    public int x;
    public int y;

    Point() {}
    Point(int a, int b) {x = a; y = b;}

    public int compareTo(Point other) {
      if (x == other.x) return y - other.y;
      return x - other.x;
    }

    public String toString() {
      return "(" + x + ", " + y + ")";
    }
  }

  static abstract class segtree {
    public int n;
    public long[] tree, lazy;

    public segtree(int _n) {
      n = _n;
      tree = new long[4 * _n];
      lazy = new long[4 * _n];
      for (int i = 0; i < 4 * _n; i++) lazy[i] = -1;
    }

    protected abstract long combine(long a, long b);

    protected abstract long nullv();

    protected abstract long lazy_func(int l, int r, long v);

    public void init(long[] arr) {
      init(0, 0, n - 1, arr);
    }

    private long init(int i, int l, int r, long[] arr) {
      if (l == r) return tree[i] = arr[l];

      int mid = (l + r) / 2;
      long a = init(2 * i + 1, l, mid, arr);
      long b = init(2 * i + 2, mid + 1, r, arr);

      return tree[i] = combine(a, b);
    }

    public void update(int l, int r, long val) {
      update(0, 0, n - 1, l, r, val);
    }

    private long update(int i, int tl, int tr, int ql, int qr, long val) {
      if (tr < ql || qr < tl || tl > tr) {
        push_lazy(i, tl, tr);
        return tree[i];
      }
      if (ql <= tl && tr <= qr) {
        lazy[i] = val;
        push_lazy(i, tl, tr);
        return tree[i];
      }

      push_lazy(i, tl, tr);

      int mid = (tl + tr) / 2;
      long a = update(2 * i + 1, tl, mid, ql, qr, val);
      long b = update(2 * i + 2, mid + 1, tr, ql, qr, val);

      return tree[i] = combine(a, b);
    }

    public long query(int l, int r) {
      return query(0, 0, n - 1, l, r);
    }

    private long query(int i, int tl, int tr, int ql, int qr) {
      if (qr < tl || tr < ql || tl > tr) return nullv();

      push_lazy(i, tl, tr);
      if (ql <= tl && tr <= qr) return tree[i];

      int mid = (tl + tr) / 2;
      long a = query(2 * i + 1, tl, mid, ql, qr);
      long b = query(2 * i + 2, mid + 1, tr, ql, qr);

      return combine(a, b);
    }

    private void push_lazy(int i, int l, int r) {
      if (lazy[i] == -1) return;
      tree[i] = (r - l + 1) * lazy[i];

      if (l != r) {
        lazy[2 * i + 1] = lazy[i];
        lazy[2 * i + 2] = lazy[i];
      }

      lazy[i] = -1;
    }
  }

  static class segtree_sum extends segtree {
    public segtree_sum(int _n) {
      super(_n);
    }

    protected long combine(long a, long b) {
      return a + b;
    }

    protected long nullv() {
      return 0;
    }

    protected long lazy_func(int l, int r, long v) {
      return v;
    }
  }

  static class segtree_or {
    public int n;
    public long[] tree;

    public segtree_or(int _n) {
      n = _n;
      tree = new long[4 * _n];
    }

    private long combine(long a, long b) {
      return a | b;
    }

    private long nullv() {
      return 0;
    }

    public void init(long[] arr) {
      init(0, 0, n - 1, arr);
    }

    private long init(int i, int l, int r, long[] arr) {
      if (l == r) return tree[i] = arr[l];

      int mid = (l + r) / 2;
      long a = init(2 * i + 1, l, mid, arr);
      long b = init(2 * i + 2, mid + 1, r, arr);

      return tree[i] = combine(a, b);
    }

    public void update(int loc, long val) {
      update(0, 0, n - 1, loc, val);
    }

    private long update(int i, int l, int r, int loc, long val) {
      if (loc < l || r < loc) return tree[i];
      if (l == r) return tree[i] = val;

      int mid = (l + r) / 2;
      long a = update(2 * i + 1, l, mid, loc, val);
      long b = update(2 * i + 2, mid + 1, r, loc, val);

      return tree[i] = combine(a, b);
    }

    public long query(int l, int r) {
      return query(0, 0, n - 1, l, r);
    }

    private long query(int i, int tl, int tr, int ql, int qr) {
      if (qr < tl || tr < ql || tl > tr || ql > qr) return nullv();
      if (ql <= tl && tr <= qr) return tree[i];

      int mid = (tl + tr) / 2;
      long a = query(2 * i + 1, tl, mid, ql, qr);
      long b = query(2 * i + 2, mid + 1, tr, ql, qr);

      return combine(a, b);
    }

    private long query_left(int i, int tl, int tr, int qr, long ror) {
      if (qr < tl) return 0;
      if (tr <= qr) {
        if ((tree[i] | ror) == DON) {
          INDEX = Math.min(INDEX, tl);
          return tree[i] | ror;
        }
      }
      if (tl == tr) {
        if ((tree[i] | ror) == DON) INDEX = Math.min(INDEX, tl);
        return tree[i] | ror;
      }

      int mid = (tl + tr) / 2;
      if (qr <= mid) return query_left(2 * i + 1, tl, mid, qr, ror);
      long a = query_left(2 * i + 2, mid + 1, tr, qr, ror);
      long b = ror | a;
      if (b == DON) b = query_left(2 * i + 1, tl, mid, qr, b);
      if (tr <= qr) b |= tree[i];
      return b;
    }

    private long query_right(int i, int tl, int tr, int ql, long ror) {
      if (tr < ql) return 0;
      if (ql <= tl) {
        if ((ror | tree[i]) < x) {
          INDEX = Math.max(INDEX, tr);
          return ror | tree[i];
        }
      }
      if (tl == tr) {
        if ((tree[i] | ror) < x) INDEX = Math.max(INDEX, tl);
        return tree[i] | ror;
      }

      int mid = (tl + tr) / 2;
      if (ql > mid) return query_right(2 * i + 2, mid + 1, tr, ql, ror);
      long a = query_right(2 * i + 1, tl, mid, ql, ror);
      long b = ror | a;
      if (b < x) {
        INDEX = Math.max(INDEX, mid);
        b |= query_right(2 * i + 2, mid + 1, tr, ql, b);
      }
      if (ql <= tl) b |= tree[i];
      return b;
    }
  }
}