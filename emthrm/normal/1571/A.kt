fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        val gl = s.filter { it != '=' }
        println(
            when {
                gl.isEmpty() -> '='
                gl.all { it == '<' } -> '<'
                gl.all { it == '>' } -> '>'
                else -> '?'
            }
        )
    }
}