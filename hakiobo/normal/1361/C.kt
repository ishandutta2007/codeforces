import java.io.BufferedReader
// Note: this code is derivative of submission 82571471 by elizarov

fun main(){
    val br = System.`in`.bufferedReader()
    val n = br.readInt()
    val pieces = IntArray(2 * n)
    repeat(n) { i ->
        pieces[2 * i] = br.readInt()
        pieces[2 * i + 1] = br.readInt()
    }
    var output = ""
    val maxMask = 1 shl 20
    val topOfMaskedNode = IntArray(maxMask)
    val gOdd = BooleanArray(maxMask)
    val pieceBeneathOnSameMaskedNode = IntArray(2 * n)
    val stack = IntArray(2 * n)
    val path = IntArray(2 * n)
    val visited = BooleanArray(n)
    fun isValid(b: Int):Boolean{
        val mask = (1 shl b) - 1
        var numOdds = 0
        topOfMaskedNode.fill(-1, 0, mask + 1)
        gOdd.fill(false, 0, mask + 1)
        for ((index, piece) in pieces.withIndex()) {
            val maskedPiece = piece and mask
            gOdd[maskedPiece] = !gOdd[maskedPiece]
            numOdds += if(gOdd[maskedPiece]) 1 else -1
            pieceBeneathOnSameMaskedNode[index] = topOfMaskedNode[maskedPiece]
            topOfMaskedNode[maskedPiece] = index
        }
        if(numOdds != 0) return false

        visited.fill(false)
        var numVisited = 0
        var stackPointer = 2
        stack[0] = 0
        stack[1] = 1
        visited[0] = true
        while (stackPointer > 0) {
            val i = stack[stackPointer - 1]
            val u = pieces[i] and mask
            val nextPiece = topOfMaskedNode[u]
            if (nextPiece >= 0) {
                if (!visited[nextPiece shr 1]) {
                    stack[stackPointer++] = nextPiece
                    stack[stackPointer++] = nextPiece xor 1
                    visited[nextPiece shr 1] = true
                }
                topOfMaskedNode[u] = pieceBeneathOnSameMaskedNode[nextPiece]
            } else {
                path[numVisited++] = stack[--stackPointer] + 1
                path[numVisited++] = stack[--stackPointer] + 1
            }
        }
        return if(numVisited == n shl 1) {
            output = path.joinToString(" ")
            true
        } else {
            false
        }
    }

    var high = 21
    var low = 0
    var mid = (low + high) shr 1
    while (low != high){
        if(isValid(mid)){
            low = mid + 1
        } else {
            high = mid
        }
        mid = (high + low) shr 1
    }
    println(mid - 1)
    print(output)
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