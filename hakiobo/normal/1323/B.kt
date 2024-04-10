
import java.lang.System.`in`
import kotlin.math.sqrt

fun main() {
    val br = `in`.bufferedReader()
    val (n, m, k) = br.readLine().split(' ').map(String::toInt)
    val factorList = getFactors(k)
    val nFenwick = LongArray(n)
    val mFenwick = LongArray(m)
    var curStreak = 0
    br.readLine().split(' ').map(String::toInt).forEach {
        if (it == 1) {
            curStreak++
            update(curStreak, 1, nFenwick)
        } else {
            curStreak = 0
        }
    }
    curStreak = 0
    br.readLine().split(' ').map(String::toInt).forEach {
        if (it == 1) {
            curStreak++
            update(curStreak, 1, mFenwick)
        } else {
            curStreak = 0
        }
    }
    var rectCount = 0L
    for (factor in factorList) {
        val f2 = k / factor
        rectCount += get(factor, n, nFenwick) * get(f2, m, mFenwick)
        if (factor != f2) {
            rectCount += get(f2, n, nFenwick) * get(factor, m, mFenwick)
        }
    }
    print(rectCount)
}

private fun update(index: Int, updateVal: Long, fenwickTree: LongArray) {
    var id = index
    while (id <= fenwickTree.size) {
        fenwickTree[id - 1] += updateVal
        id += id and -id
    }
}

private fun get(index1: Int, index2: Int, fenwickTree: LongArray): Long {
    if (index1 > index2) {
        return 0L
    }
    return get(index2, fenwickTree) - get(index1 - 1, fenwickTree)
}

private fun get(index: Int, fenwickTree: LongArray): Long {
    var id = index
    var sum = 0L
    while (id > 0) {
        sum += fenwickTree[id - 1]
        id -= id and -id
    }
    return sum
}

private fun getFactors(num: Int): List<Int> {
    val factorList = emptyList<Int>().toMutableList()
    for (i in 1..(sqrt(num.toDouble()).toInt())) {
        if (num % i == 0) {
            factorList.add(i)
        }
    }
    return factorList
}