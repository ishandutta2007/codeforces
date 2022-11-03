import java.io.BufferedReader

private const val LIMITED_FLAG = 0b1000
private const val C_FLAG = 0b0100
private const val B_FLAG = 0b0010
private const val A_FLAG = 0b0001

fun main() {

    val mod = 998_244_353L
    val br = System.`in`.bufferedReader()
    val digits = br.readLine().toCharArray()
    val n = digits.size
    val dp = Array(n + 1) { LongArray(16) }
    dp[0][0] = 6L
    for (i in 0 until n) {
        for (state in 0 until 16) {
            if (dp[i][state] == 0L) continue
            val aDif = A_FLAG and state != 0
            val bDif = B_FLAG and state != 0
            val cDif = C_FLAG and state != 0
            val cLimited = LIMITED_FLAG and state == 0

            val abDif = aDif || bDif
            val bcDif = bDif || cDif
            val baseNew = if (digits[i] == '1') state or LIMITED_FLAG else state

            // 000
            var newState = baseNew
            dp[i + 1][newState] += dp[i][state]
            if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod


            // 001
            if (bcDif) {
                newState = baseNew or C_FLAG
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod
            }


            // 010
            if (abDif) {
                newState = baseNew or B_FLAG
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod


                // 011
                newState = baseNew or A_FLAG
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod
            }


            if (!cLimited || digits[i] == '1') {
                // 100
                newState = state or A_FLAG
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod

                // 101
                if (bcDif) {
                    newState = state or B_FLAG
                    dp[i + 1][newState] += dp[i][state]
                    if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod
                }


                // 110
                newState = state or C_FLAG
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod

                // 111
                newState = state
                dp[i + 1][newState] += dp[i][state]
                if (dp[i + 1][newState] >= mod) dp[i + 1][newState] -= mod
            }
        }
    }
    val ans = dp.last()[0b1111] + dp.last()[0b0111]
    println(ans - if (ans >= mod) mod else 0)
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