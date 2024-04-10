fun gcd(a : Long, b : Long) : Long {
	if (b == 0L) return a
	return gcd(b, a % b)
}

fun main(args : Array<String>) {
	val s = readLine() + "."
	val (x, y, z) = s.split('.', '(', ')')

	var nines = 0L
	for (i in 1..z.length)
	nines = nines * 10L + 9L

	var tens = 1L
	for (i in 1..y.length)
	tens = tens * 10L

	if (y != "") {
		val a = x.toLong() * tens * nines + y.toLong() * nines + z.toLong()
		val b = tens * nines
		val g = gcd(a, b)
		print(a / g)
		print("/")
		print(b / g)
	} else {
		val a = x.toLong() * tens * nines + z.toLong()
		val b = tens * nines
		val g = gcd(a, b)
		print(a / g)
		print("/")
		print(b / g)
	}
}