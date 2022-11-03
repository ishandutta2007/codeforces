import java.io.BufferedReader

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val t = br.readInt()
    repeat(t){
        val n = br.readInt()
        val k = br.readInt()
        val s = br.readLine()
        val v = Array<Boolean?>(k){null}
        var bad = false
        for(x in s.indices){
            val c = s[x]
            if(c == '1'){
                if(v[x%k] == false){
                    bad = true
                } else {
                    v[x%k] = true
                }
            } else if(c == '0'){
                if(v[x%k] == true){
                    bad = true
                } else {
                    v[x%k] = false
                }
            }
        }
        var oCount = 0
        var zCount = 0
        var nCount = 0
        for(x in v){
            when(x){
                true -> oCount++
                false -> zCount++
                null -> nCount++
            }
        }
        if(oCount + nCount < zCount || zCount + nCount < oCount){
            bad = true
        }
        if(bad){
            sb.append("NO\n")
        } else {
            sb.append("YES\n")
        }
    }

    print(sb)
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