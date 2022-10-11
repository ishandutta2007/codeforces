import java.io.*
import java.util.*

object Main {
    var `in`: IO? = null
    var out: PrintWriter? = null

    @Throws(Exception::class)
    fun init_io(filename: String) {
        if (filename == "") {
            `in` = IO(System.`in`)
            out = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)), true)
        } else {
            `in` = IO(FileInputStream("$filename.in"))
            out = PrintWriter(BufferedWriter(FileWriter("$filename.out")), true)
        }
    }

    const val mod: Long = 1000000007

    /*
fun main(args: Array<String>) {
    Main.main(args);
}
*/
    /* todo list
- stick main snippet at bottom
- remove "internal" from IO class (and all static classes)
*/
    @Throws(Exception::class)
    fun solve(tc: Int) {
        val alist = ArrayList<Edge>()
        val n = `in`!!.nint()
        val m = `in`!!.nint()
        val a = LongArray(n)
        var mindex = 0
        for (i in 0 until n) {
            a[i] = `in`!!.nlong()
            if (a[i] < a[mindex]) mindex = i
        }
        for (i in 0 until n) {
            alist.add(Edge(a[i] + a[mindex], mindex.toLong(), i.toLong()))
        }
        for (i in 0 until m) {
            var u = `in`!!.nlong()
            var v = `in`!!.nlong()
            val w = `in`!!.nlong()
            --u
            --v
            alist.add(Edge(w, u, v))
        }
        Collections.sort(alist)
        val d = DSU(n)
        var ans: Long = 0
        for (e in alist) {
            if (!d.con(e.from.toInt(), e.to.toInt())) {
                d.merge(e.from.toInt(), e.to.toInt())
                ans += e.weight
            }
        }
        out!!.println(ans)
    }

    @Throws(Exception::class)
    @JvmStatic
    fun main(_u_n_u_s_e_d_: Array<String>) {
        init_io("")
        val t = 1
        // t = in.nint();
        for (tc in 0 until t) {
            solve(tc)
        }
    }

    fun minv(v: Long): Long {
        return mpow(v, mod - 2)
    }

    fun mpow(base: Long, exp: Long): Long {
        var base = base
        var exp = exp
        var res: Long = 1
        while (exp > 0) {
            if (exp and 1 == 1L) {
                res = res * base % mod
            }
            base = base * base % mod
            exp = exp shr 1
        }
        return res
    }

    fun gcd(x: Int, y: Int): Int {
        if (x == 0) return y
        return if (y == 0) x else gcd(y % x, x)
    }

    fun rsort(arr: LongArray) {
        val r = Random()
        for (i in arr.indices) {
            val j = i + r.nextInt(arr.size - i)
            val t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        }
        Arrays.sort(arr)
    }

    fun rsort(arr: IntArray) {
        val r = Random()
        for (i in arr.indices) {
            val j = i + r.nextInt(arr.size - i)
            val t = arr[i]
            arr[i] = arr[j]
            arr[j] = t
        }
        Arrays.sort(arr)
    }

    /* static void qsort(long[] arr) {
    Long[] oarr = new Long[arr.length];
    for (int i = 0; i < arr.length; i++) {
      oarr[i] = arr[i];
    }

    ArrayList<Long> alist = new ArrayList<Long>(Arrays.asList(oarr));
    Collections.sort(alist);

    for (int i = 0; i < arr.length; i++) {
      arr[i] = (long)alist.get(i);
    }
  } */
    fun reverse(arr: LongArray) {
        for (i in 0 until arr.size / 2) {
            val temp = arr[i]
            arr[i] = arr[arr.size - 1 - i]
            arr[arr.size - 1 - i] = temp
        }
    }

    fun atos(arr: LongArray?): String {
        var s = Arrays.toString(arr)
        s = s.substring(1, s.length - 1)
        return s.replace(",", "")
    }

     class DSU(n: Int) {
        var parent: IntArray
        fun merge(a: Int, b: Int) {
            parent[find(b)] = find(a)
        }

        fun find(a: Int): Int {
            return if (a == parent[a]) a else find(parent[a]).also { parent[a] = it }
        }

        fun con(a: Int, b: Int): Boolean {
            return find(a) == find(b)
        }

        init {
            parent = IntArray(n)
            for (i in 0 until n) parent[i] = i
        }
    }

     class Edge : Comparable<Edge> {
        var weight: Long = 0
        var from: Long = 0
        var to: Long = 0

        constructor() {}
        constructor(w: Long, f: Long, t: Long) {
            weight = w
            from = f
            to = t
        }

        override operator fun compareTo(other: Edge): Int {
            return if (weight < other.weight) -1 else if (weight > other.weight) 1 else 0
        }
    }

     class IO(x: InputStream?) {
        var `in`: BufferedReader
        var tokens: StringTokenizer

        @Throws(Exception::class)
        fun nint(): Int {
            return nstr().toInt()
        }

        @Throws(Exception::class)
        fun nlong(): Long {
            return nstr().toLong()
        }

        @Throws(Exception::class)
        fun ndouble(): Double {
            return nstr().toDouble()
        }

        @Throws(Exception::class)
        fun nstr(): String {
            if (!tokens.hasMoreTokens()) tokens = StringTokenizer(`in`.readLine())
            return tokens.nextToken()
        }

        @Throws(Exception::class)
        fun nla(n: Int): LongArray {
            val arr = LongArray(n)
            for (i in 0 until n) {
                arr[i] = nlong()
            }
            return arr
        }

        init {
            `in` = BufferedReader(InputStreamReader(x))
            tokens = StringTokenizer(`in`.readLine())
        }
    } // static class Pair<A extends Comparable<A>, B extends Comparable<B>> implements Comparable<Pair<A, B>> {
    // public A f;
    // public B s;
    // public Pair(A a, B b) {
    // f = a;
    // s = b;
    // }
    // public int compareTo(Pair<A, B> other) {
    // int v = f.compareTo(other.f);
    // if (v != 0) return v;
    // return s.compareTo(other.s);
    // }
    // public String toString() {
    // return "(" + f.toString() + ", " + s.toString() + ")";
    // }
    // }
}

fun main(args: Array<String>) {
    Main.main(args);
}