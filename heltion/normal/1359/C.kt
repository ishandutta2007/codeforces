fun main(){
    fun readInt() = readLine()!!.toInt()
    fun readInts() = readLine()!!.split(' ').map(String::toInt)
    repeat(readInt()){
        val (h, c, t) = readInts()
        if(h + c - 2 * t >= 0) println(2)
        else{
            val n = (- t + h) / (- h - c + 2 * t)
            val m = n + 1
            val pn = 1L * (n + 1) * h + 1L * n * c - 1L * (2 * n + 1) * t
            val qn = 2 * n + 1
            val pm = - 1L * (m + 1) * h - 1L * m * c + 1L * (2 * m + 1) * t
            val qm = 2 * m + 1
            if(pn * qm <= pm * qn) println(qn)
            else println(qm)
        }
    }
}
//((n + 1)h + nc) / (2n + 1) = t
//(n + 1)h + nc = (2n + 1)t
//n(2t - h + c)= h - t