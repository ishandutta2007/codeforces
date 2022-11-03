import java.lang.StringBuilder
import java.lang.System.`in`

fun main() {
    val br = `in`.bufferedReader()
    val sb = StringBuilder()
    val (rows, cols, chips) = br.readLine().split(" ").map(String::toInt)
    repeat(2 * chips){
        br.readLine()
    }

    sb.append(rows * cols - 3 + rows + cols)
    sb.append('\n')
    repeat(rows - 1) {
        sb.append('U')
    }
    repeat(cols - 1) {
        sb.append('L')
    }
    repeat(rows) { row ->
        repeat(cols - 1) {
            if (row and 1 == 0) {
                sb.append('R')
            } else {
                sb.append('L')
            }
        }
        if(row != rows - 1){
            sb.append('D')
        }
    }
    print(sb)
}