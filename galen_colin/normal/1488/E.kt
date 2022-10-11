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
- remove question marks (?) from comparable stuff (ex: <Edge?> -> <Edge>)
*/
    @Throws(Exception::class)
    fun solve(tc: Int) {
        val n = `in`!!.nint()
        val a = IntArray(n)
        for (i in 0 until n) {
            a[i] = `in`!!.nint()
            --a[i]
        }
        val st = segtree(n)
        val other = IntArray(n)
        val pos = IntArray(n)
        for (i in 0 until n) {
            pos[i] = -1
            other[i] = -1
        }
        for (i in n - 1 downTo 0) {
            if (pos[a[i]] != -1) {
                other[a[i]] = pos[a[i]]
            } else {
                pos[a[i]] = i
            }
        }
        var ans: Long = 0
        for (i in 0 until n) {
            var single: Long = 0
            if (i < n - 1) single = st.query(i + 1, n - 1)
            ans = Math.max(ans, single + 1)
            if (other[a[i]] != -1 && other[a[i]] != i) {
                var doub: Long = 0
                if (other[a[i]] < n - 1) doub = st.query(other[a[i]] + 1, n - 1)
                ans = Math.max(ans, doub + 2)
                st.update(other[a[i]], doub + 2)
            }
        }
        out!!.println(ans)
    }

    @Throws(Exception::class)
    @JvmStatic
    fun main(_u_n_u_s_e_d_: Array<String>) {
        init_io("")
        var t = 1
        t = `in`!!.nint()
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

     class segtree(var n: Int) {
        var tree: LongArray
        private fun combine(a: Long, b: Long): Long {
            return Math.max(a, b)
        }

        private fun nullv(): Long {
            return Long.MIN_VALUE
        }

        fun init(arr: LongArray) {
            init(0, 0, n - 1, arr)
        }

        private fun init(i: Int, l: Int, r: Int, arr: LongArray): Long {
            if (l == r) return arr[l].also { tree[i] = it }
            val mid = (l + r) / 2
            val a = init(2 * i + 1, l, mid, arr)
            val b = init(2 * i + 2, mid + 1, r, arr)
            return combine(a, b).also { tree[i] = it }
        }

        fun update(loc: Int, `val`: Long) {
            update(0, 0, n - 1, loc, `val`)
        }

        private fun update(i: Int, l: Int, r: Int, loc: Int, `val`: Long): Long {
            if (loc < l || r < loc) return tree[i]
            if (l == r) return `val`.also { tree[i] = it }
            val mid = (l + r) / 2
            val a = update(2 * i + 1, l, mid, loc, `val`)
            val b = update(2 * i + 2, mid + 1, r, loc, `val`)
            return combine(a, b).also { tree[i] = it }
        }

        fun query(l: Int, r: Int): Long {
            return query(0, 0, n - 1, l, r)
        }

        private fun query(i: Int, tl: Int, tr: Int, ql: Int, qr: Int): Long {
            if (qr < tl || tr < ql || tl > tr) return nullv()
            if (ql <= tl && tr <= qr) return tree[i]
            val mid = (tl + tr) / 2
            val a = query(2 * i + 1, tl, mid, ql, qr)
            val b = query(2 * i + 2, mid + 1, tr, ql, qr)
            return combine(a, b)
        }

        init {
            tree = LongArray(4 * n)
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