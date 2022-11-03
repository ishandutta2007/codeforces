import java.io.BufferedReader
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val times = br.readInt()
    repeat(times) {
        val length = br.readInt()
        val doorLen = br.readInt()
        val pastTwo = IntArray(2) { br.readInt() }
        val peaks = IntArray(doorLen)
        var arrPos = 0
        var peakCount = 0
        var maxCnt = 0
        var maxIdx = 0
        repeat(length - 2) {
            val new = br.readInt()
            if (pastTwo[0] < pastTwo[1] && pastTwo[1] > new) {
                peaks[arrPos] = 1
                ++peakCount
            } else {
                peaks[arrPos] = 0
            }
            pastTwo[0] = pastTwo[1]
            pastTwo[1] = new
            if (++arrPos == peaks.size) {
                arrPos = 0
            }
            if (peaks[(arrPos + 1) % doorLen] == 1) {
                --peakCount
            }
            if (peakCount > maxCnt) {
                maxCnt = peakCount
                maxIdx = (it + 4 - doorLen).coerceAtLeast(1)
            }
        }
        bw.append("${maxCnt + 1} ${maxIdx.coerceAtLeast(1)}")
        bw.newLine()
    }
    bw.close()
}
private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()
@Suppress("DuplicatedCode")
private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) { // really simple whitespace check
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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}