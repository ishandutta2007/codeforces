import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val numCases = br.readInt()
    repeat(numCases){
        val rows = br.readInt()
        val cols = br.readInt()
        val claimedRows = BooleanArray(rows)
        val claimedCols = BooleanArray(cols)
        var openCols = cols
        var openRows = rows
        for(row in 0 until rows){
            for(col in 0 until cols){
                if(br.readInt() == 1){
                    if(!claimedCols[col]){
                        claimedCols[col] = true
                        openCols--
                    }
                    if(!claimedRows[row]){
                        claimedRows[row] = true
                        openRows--
                    }
                }
            }
        }
        val limit = openCols.coerceAtMost(openRows)
        if(limit and 1 == 0){
            sb.append("Vivek\n")
        } else {
            sb.append("Ashish\n")
        }
    }
    print(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val CR_INT = '\r'.toInt()
@Suppress("DuplicatedCode")
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
    if (read == CR_INT) {
        read()
    }
    return if (neg) -ret else ret
}