fun main(args : Array<String>) {
	val q = readLine()!!.toInt()
	for (i in 1..q) {
		var ok = false
		val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
		for (a in 1..n) {
			val k : Int = p / a
			if (k * a == p && 1 <= k && k <= m)
			ok = true
		}
		if (ok)
		println("Yes")
		else
		println("No")
	}

}