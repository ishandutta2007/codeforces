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
        val n = `in`!!.nint()
        val m = `in`!!.nint()
        val q = `in`!!.nint()
        val a = Array(n) { LongArray(m) }
        for (i in 0 until n) {
            for (j in 0 until m) {
                a[i][j] = `in`!!.nlong()
            }
        }
        val rc = LongArray(n)
        val cc = LongArray(m)
        val rs = LongArray(n)
        val cs = LongArray(m)
        for (i in 0 until n) {
            for (j in 0 until m) {
                rs[i] += a[i][j]
                cs[j] += a[i][j]
            }
        }
        var mr = mod * mod
        var mc = mod * mod
        for (i in 0 until n) {
            var v: Long = 0
            for (j in 0 until n) {
                v += Math.abs(j - i) * rs[j]
            }
            rc[i] = v
            mr = Math.min(mr, rc[i])
        }
        for (i in 0 until m) {
            var v: Long = 0
            for (j in 0 until m) {
                v += Math.abs(j - i) * cs[j]
            }
            cc[i] = v
            mc = Math.min(mc, cc[i])
        }
        out!!.print(mr + mc)
        for (qq in 0 until q) {
            mr = mod * mod
            mc = mod * mod
            val r = `in`!!.nint() - 1
            val c = `in`!!.nint() - 1
            val v = `in`!!.nlong()
            val dif = v - a[r][c]
            a[r][c] = v
            for (i in 0 until n) {
                rc[i] += Math.abs(i - r) * dif
                mr = Math.min(mr, rc[i])
            }
            for (i in 0 until m) {
                cc[i] += Math.abs(i - c) * dif
                mc = Math.min(mc, cc[i])
            }
            out!!.print(" " + (mr + mc))
        }
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

    fun gcd(x: Long, y: Long): Long {
        return if (x == 0L) y else gcd(y % x, x)
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