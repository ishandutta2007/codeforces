import java.io.*;
import java.util.*;

public class Main {
  public static IO in;
  public static PrintWriter out;

  static void init_io(String filename) throws Exception {
    if (filename.equals("")) {
      in = new IO(System.in);
      out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
    } else {
      in = new IO(new FileInputStream(filename + ".in"));
      out = new PrintWriter(new BufferedWriter(new FileWriter(filename + ".out")), true);
    }
  }

  public static void main(String[] _u_n_u_s_e_d_) throws Exception {
    init_io("");

    int n = in.nint(), m = in.nint();

    dijkstra d = new dijkstra(n);
    for (int i = 0; i < m; i++) {
      int a = in.nint(), b = in.nint();
      long c = in.nlong();

      --a; --b;

      if (a != b) d.edge(a, b, c);
    }

    d.run(0);

    ArrayList<Integer> path = new ArrayList<Integer>();

    int foc = n - 1;

    do {
      path.add(foc + 1);
      foc = d.par[foc];
    } while (foc != -1);

    long[] ap = new long[path.size()];
    for (int i = 0; i < path.size(); i++) {
      ap[i] = path.get(path.size() - i - 1);
    }

    if (ap[0] == 1) out.println(atos(ap));
    else out.println(-1);
  }

  static class dijkstra {
    public int n;
    final public static long inf = 3_000_000_000_000_000_000L;
    public long[] dists;
    public int[] par;
    public boolean[] vis;
    public ArrayList<ArrayList<Pair<Long, Integer>>> edges;
    
    public dijkstra(int s) {
      n = s;
      dists = new long[s];
      par = new int[s];
      vis = new boolean[s];
      edges = new ArrayList<ArrayList<Pair<Long, Integer>>>(n);
      for (int i = 0; i < n; i++) {
        edges.add(new ArrayList<Pair<Long, Integer>>());
      }
    }

    public void edge(int a, int b, long wt) {
      edges.get(a).add(new Pair(wt, b));
      edges.get(b).add(new Pair(wt, a));
    }

    public void run(int src) {
      for (int i = 0; i < n; i++) dists[i] = inf;
      for (int i = 0; i < n; i++) par[i] = -1;
      for (int i = 0; i < n; i++) vis[i] = false;

      PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<Pair<Long, Integer>>();
      dists[src] = 0;
      pq.add(new Pair(0L, src));
      while (pq.size() > 0) {
        Pair<Long, Integer> foc = pq.poll();
        foc.f = foc.f;

        if (vis[foc.s]) continue;
        vis[foc.s] = true;

        dists[foc.s] = Math.min(dists[foc.s], foc.f);
        for (Pair<Long, Integer> x: edges.get(foc.s)) {
          long d = dists[foc.s] + x.f;
          if (d < dists[x.s]) {
            dists[x.s] = d;
            par[x.s] = foc.s;
            pq.add(new Pair(d, x.s));
          }
        }
      }
    }
  }

  static int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }

  static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }

    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);

    for (int i = 0; i < arr.length; i++) {
      arr[i] = alist.get(i);
    }
  }

  static void reverse(long[] arr) {
    for (int i = 0; i < arr.length / 2; i++) {
      long temp = arr[i];
      arr[i] = arr[arr.length - 1 - i];
      arr[arr.length - 1 - i] = temp;
    }
  }

  static String atos(long[] arr) {
    String s = Arrays.toString(arr);
    s = s.substring(1, s.length() - 1);
    return s.replace(",", "");
  }

  static class IO {
    public BufferedReader in;
    public StringTokenizer tokens;

    public IO(InputStream x) throws Exception {
      in = new BufferedReader(new InputStreamReader(x));
      tokens = new StringTokenizer(in.readLine());
    }

    int nint() throws Exception {
      return Integer.parseInt(nstr());
    }

    long nlong() throws Exception {
      return Long.parseLong(nstr());
    }

    double ndouble() throws Exception {
      return Double.parseDouble(nstr());
    }

    String nstr() throws Exception {
      if (!tokens.hasMoreTokens()) tokens = new StringTokenizer(in.readLine());
      return tokens.nextToken();
    }
    
    long[] nla(int n) throws Exception {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = nlong();
      }
      return arr;
    }
  }

  static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    public A f;
    public B s;

    public Pair(A a, B b) {
      f = a;
      s = b;
    }

    public int compareTo(Pair<A, B> other) {
      int v = f.compareTo(other.f);
      if (v != 0) return v;
      return s.compareTo(other.s);
    }

    public String toString() {
      return "(" + f.toString() + ", " + s.toString() + ")";
    }
  }
}