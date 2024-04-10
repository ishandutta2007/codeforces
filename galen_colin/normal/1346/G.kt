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
    @Throws(Exception::class)
    fun solve(tc: Int) {
        val k = `in`!!.nint()
        val n = `in`!!.nint()
        val pd = IntArray(k)
        for (i in 0 until k) pd[i] = `in`!!.nint()
        val a = IntArray(n)
        for (i in 0 until n) a[i] = `in`!!.nint()
        val mx = 1000007
        val can = IntArray(mx)
        for (i in 0 until k) {
            var j = pd[i]
            while (j < mx) {
                if (can[j] == 0) can[j] = pd[i]
                j += pd[i]
            }
        }
        val pts = BooleanArray(mx)
        for (i in 0 until n) pts[a[i]] = true
        val st = segtree(mx)
        st.init(pts)
        if (pd[0] <= 2) {
            out!!.println("YES")
            out!!.println("1 " + pd[0])
            out!!.println("2 " + pd[0])
            return
        }
        val stop = a[n - 1]
        for (i in 0 until k) {
            if (can[pd[i]] < pd[i]) continue
            val pt = 0
            var last = -1
            var first = -1
            var cur = -1
            var loc = a[0]
            while (loc <= stop) {
                val v = st.query(loc + 1, loc + pd[i] - 1)
                if (v.s != -1) {
                    cur = if (cur == -1) v.f else gcd(cur, v.f)
                    if (last == -1) last = v.s else {
                        cur = gcd(cur, Math.abs(v.s - last))
                        last = v.s
                    }
                }
                if (first == -1) first = v.s
                if (cur > 0 && can[cur] == 0) break
                loc += pd[i]
            }
            if (cur > 0 && can[cur] > 0) {
                out!!.println("YES")
                out!!.println(a[0].toString() + " " + pd[i])
                while (first - can[cur] > 0) first -= can[cur]
                out!!.println(first.toString() + " " + can[cur])
                return
            } else if (cur <= 0) {
                out!!.println("YES")
                out!!.println(a[0].toString() + " " + pd[i])
                if (first == -1) first = 1
                out!!.println(first.toString() + " " + pd[0])
                return
            }
        }
        out!!.println("NO")
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

    internal class segtree(var n: Int) {
        var tree: IntArray
        var pt: IntArray
        fun init(arr: BooleanArray) {
            init(0, 0, n - 1, arr)
        }

        private fun init(i: Int, l: Int, r: Int, arr: BooleanArray) {
            if (l == r) {
                tree[i] = 0
                if (arr[l]) {
                    pt[i] = l
                } else {
                    pt[i] = -1
                }
                return
            }
            val mid = (l + r) / 2
            init(2 * i + 1, l, mid, arr)
            init(2 * i + 2, mid + 1, r, arr)
            tree[i] = gcd(tree[2 * i + 1], tree[2 * i + 2])
            if (pt[2 * i + 1] != -1 && pt[2 * i + 2] != -1) {
                tree[i] = gcd(tree[i], Math.abs(pt[2 * i + 2] - pt[2 * i + 1]))
            }
            pt[i] = -1
            if (pt[2 * i + 1] != -1) pt[i] = pt[2 * i + 1] else if (pt[2 * i + 2] != -1) pt[i] = pt[2 * i + 2]
            return
        }

        fun query(l: Int, r: Int): Pair<Int, Int> {
            return query(0, 0, n - 1, l, r)
        }

        private fun query(i: Int, tl: Int, tr: Int, ql: Int, qr: Int): Pair<Int, Int> {
            if (qr < tl || tr < ql || tl > tr) return Pair(0, -1)
            if (ql <= tl && tr <= qr) return Pair(tree[i], pt[i])
            val mid = (tl + tr) / 2
            val a = query(2 * i + 1, tl, mid, ql, qr)
            val b = query(2 * i + 2, mid + 1, tr, ql, qr)
            val x = Pair(0, -1)
            x.f = gcd(a.f, b.f)
            if (a.s != -1 && b.s != -1) {
                x.f = gcd(x.f, Math.abs(b.s - a.s))
            }
            if (a.s != -1) x.s = a.s
            if (b.s != -1) x.s = b.s
            return x
        }

        init {
            tree = IntArray(4 * n)
            pt = IntArray(4 * n)
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
    }

    internal class Pair<A : Comparable<A>?, B : Comparable<B>?>(var f: A, var s: B) : Comparable<Pair<A, B>> {
        override fun compareTo(other: Pair<A, B>): Int {
            val v = f!!.compareTo(other.f)
            return if (v != 0) v else s!!.compareTo(other.s)
        }

        override fun toString(): String {
            return "(" + f.toString() + ", " + s.toString() + ")"
        }

    }
}

fun main(args: Array<String>) {
    Main.main(args);
}