import java.io.BufferedReader

fun main() {
    fun gcd(p: Int, q: Int): Int {
        return if (p < 0) gcd(-p, q)
        else if (q < 0) gcd(p, -q)
        else if (p == 0) q
        else if (q == 0) p
        else if (p and 1 == 0 && q and 1 == 0) gcd(p shr 1, q shr 1) shl 1
        else if (p and 1 == 0) gcd(p shr 1, q)
        else if (q and 1 == 0) gcd(p, q shr 1)
        else if (p > q) gcd((p - q) shr 1, q)
        else gcd(p, (q - p) shr 1)
    }

    fun modPow(n: Long, k: Long, m: Long): Long {
        if (k == 0L) {
            return 1L
        }
        var half = modPow(n, k shr 1, m)
        half *= half
        if (k and 1L == 1L) {
            half %= m
            half *= n
        }
        return half % m
    }

    val mod = 998_244_353L
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val primesList = mutableListOf<Int>()
        val sieve = IntArray(n + 1) { -1 }
        for (x in 2..n) {
            if (sieve[x] == -1) {
                sieve[x] = primesList.size
                if (x < 1000) {
                    var y = x * x
                    while (y <= n) {
                        sieve[y] = primesList.size
                        y += x
                    }
                }
                primesList += x
            }
        }
        val factors = IntArray(primesList.size)
        val modInv = LongArray(n + 1) { idx ->
            modPow(idx.toLong(), mod - 2, mod)
        }

        val dests = IntArray((n - 1) shl 1)
        val cons = Array(n) { mutableListOf<Int>() }
        val weights = IntArray((n - 1) shl 1)
        for (idx in 0 until n - 1) {
            val ii = idx shl 1
            val ij = ii + 1
            val i = br.readInt() - 1
            val j = br.readInt() - 1
            val x = br.readInt()
            val y = br.readInt()
            val g = gcd(x, y)

            cons[i].add(ii)
            dests[ii] = j
            weights[ii] = x / g
            cons[j].add(ij)
            dests[ij] = i
            weights[ij] = y / g
        }

        var ans = 0L
        val visited = BooleanArray(n)
        fun r(node: Int, initMult: Long): Long {
            visited[node] = true
            var curMult = initMult
            ans += initMult
            if (ans >= mod) ans -= mod
            for (edge in cons[node]) {
                val adj = dests[edge]
                if (!visited[adj]) {
                    var curWeight = weights[edge]
                    var nextWeight = weights[edge xor 1]
                    while (curWeight != 1) {
                        val p = sieve[curWeight]
                        val prime = primesList[p]
                        if (factors[p] == 0) {
                            ans = (ans * prime) % mod
                        } else {
                            curMult = (curMult * modInv[prime]) % mod
                            factors[p]--
                        }
                        curWeight /= prime
                    }
                    curMult = (curMult * nextWeight) % mod
                    while (nextWeight != 1) {
                        val p = sieve[nextWeight]
                        val prime = primesList[p]
                        factors[p]++
                        nextWeight /= prime
                    }
                    curMult = r(adj, curMult)
                    curWeight = weights[edge]
                    nextWeight = weights[edge xor 1]
                    curMult = (curMult * curWeight) % mod
                    while (curWeight != 1) {
                        val p = sieve[curWeight]
                        val prime = primesList[p]
                        factors[p]++
                        curWeight /= prime
                    }
                    while (nextWeight != 1) {
                        val p = sieve[nextWeight]
                        val prime = primesList[p]
                        curMult = (curMult * modInv[prime]) % mod
                        factors[p]--
                        nextWeight /= prime
                    }
                }
            }
            return curMult
        }
        r(0, 1L)

        bw.append("$ans\n")
    }
    bw.flush()
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }

    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}