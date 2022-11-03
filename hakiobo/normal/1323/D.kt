
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val numNums = br.readLine().toInt()
    val nums = br.readLine().split(' ').map(String::toInt)
    val oneBits = IntArray(25)
    val fenwickTrees = Array(25) {
        IntArray(2 shl it)
    }
    nums.forEach() {
        for (digit in oneBits.indices) {
            val mask = (2 shl digit) - 1
            val moddedNum = it and mask
            val inv = mask - moddedNum
            val inv2 = inv xor (1 shl digit)
            if (inv2 < inv) {
                oneBits[digit] += get(inv2 + 2, inv + 1, fenwickTrees[digit]) and 1
            } else {
                oneBits[digit] += (get(inv + 1, fenwickTrees[digit]) + get(inv2 + 2, mask + 1, fenwickTrees[digit])) and 1
            }
            update(moddedNum + 1, 1, fenwickTrees[digit])
        }
    }


    var output = 0
    var pow = 1
    for (x in oneBits) {
        if (x and 1 == 1) {
            output = output or pow
        }
        pow = pow shl 1
    }
    print(output)
}


private fun update(index: Int, updateVal: Int, fenwickTree: IntArray) {
    var id = index
    while (id <= fenwickTree.size) {
        fenwickTree[id - 1] += updateVal
        id += id and -id
    }
}

private fun get(index1: Int, index2: Int, fenwickTree: IntArray): Int {
    if (index1 > index2) {
        return 0
    }
    return get(index2, fenwickTree) - get(index1 - 1, fenwickTree)
}

private fun get(index: Int, fenwickTree: IntArray): Int {
    var id = index
    var sum = 0
    while (id > 0) {
        sum += fenwickTree[id - 1]
        id -= id and -id
    }
    return sum
}