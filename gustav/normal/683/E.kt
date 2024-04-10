fun main(args : Array<String>) {
	val n = readLine()!!.toInt()
	val a = readLine()!!.split(' ').map(String::toInt).toTypedArray()
	for (i in 1..n) {
		var j = 0
		while (a[j] != 0) j += 1
		for (k in 0..j) a[k] -= 1
		print(j + 1)
		print(' ')
	}
}