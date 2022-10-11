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
        val a = LongArray(n)
        for (i in 0 until n) {
            a[i] = `in`!!.nlong()
        }
        val q = `in`!!.nint()
        val res = LongArray(q)
        val qv = arrayOfNulls<query>(q)
        for (i in 0 until q) {
            var l = `in`!!.nint()
            var r = `in`!!.nint()
            --l
            --r
            qv[i] = query(l, r, i)
        }
        Arrays.sort(qv)
        val stack = IntArray(n)
        var spt = 0
        var qpt = 0
        val st = segtree_sum(n)
        for (r in 0 until n) {
            st.update(r, r, a[r])
            var last = r - 1
            while (spt > 0) {
                val v = stack[spt - 1]
                if (a[r] > a[v]) {
                    --spt
                    var pos = 0
                    if (spt > 0) pos = stack[spt - 1] + 1
                    st.update(pos, last, a[r] - a[v])
                    last = pos - 1
                } else {
                    break
                }
            }
            stack[spt++] = r
            while (qpt < q && qv[qpt]!!.r == r) {
                res[qv[qpt]!!.i] = st.query(qv[qpt]!!.l, qv[qpt]!!.r)
                ++qpt
            }
        }
        for (i in 0 until q) out!!.print(res[i].toString() + " ")
        out!!.println()
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

     class query(var l: Int, var r: Int, var i: Int) : Comparable<query> {
        override operator fun compareTo(other: query): Int {
            return r - other.r
        }

    }

     abstract class segtree(var n: Int) {
        var tree: LongArray
        var lazy: LongArray
        protected abstract fun combine(a: Long, b: Long): Long
        protected abstract fun nullv(): Long
        protected abstract fun lazy_func(l: Int, r: Int, v: Long): Long
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

        fun update(l: Int, r: Int, `val`: Long) {
            update(0, 0, n - 1, l, r, `val`)
        }

        private fun update(i: Int, tl: Int, tr: Int, ql: Int, qr: Int, `val`: Long): Long {
            if (tr < ql || qr < tl || tl > tr) {
                push_lazy(i, tl, tr)
                return tree[i]
            }
            if (ql <= tl && tr <= qr) {
                lazy[i] += `val`
                push_lazy(i, tl, tr)
                return tree[i]
            }
            push_lazy(i, tl, tr)
            val mid = (tl + tr) / 2
            val a = update(2 * i + 1, tl, mid, ql, qr, `val`)
            val b = update(2 * i + 2, mid + 1, tr, ql, qr, `val`)
            return combine(a, b).also { tree[i] = it }
        }

        fun query(l: Int, r: Int): Long {
            return query(0, 0, n - 1, l, r)
        }

        private fun query(i: Int, tl: Int, tr: Int, ql: Int, qr: Int): Long {
            if (qr < tl || tr < ql || tl > tr) return nullv()
            push_lazy(i, tl, tr)
            if (ql <= tl && tr <= qr) return tree[i]
            val mid = (tl + tr) / 2
            val a = query(2 * i + 1, tl, mid, ql, qr)
            val b = query(2 * i + 2, mid + 1, tr, ql, qr)
            return combine(a, b)
        }

        private fun push_lazy(i: Int, l: Int, r: Int) {
            val upd = lazy_func(l, r, lazy[i])
            tree[i] += upd
            if (l != r) {
                lazy[2 * i + 1] += lazy[i]
                lazy[2 * i + 2] += lazy[i]
            }
            lazy[i] = 0
        }

        init {
            tree = LongArray(4 * n)
            lazy = LongArray(4 * n)
        }
    }

     class segtree_sum(_n: Int) : segtree(_n) {
        override fun combine(a: Long, b: Long): Long {
            return a + b
        }

        override fun nullv(): Long {
            return 0
        }

        override fun lazy_func(l: Int, r: Int, v: Long): Long {
            return v * (r - l + 1)
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