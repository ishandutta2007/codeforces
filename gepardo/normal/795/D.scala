object D {
    def shuffle[T](array: Array[T]): Array[T] = {
        val rnd = new java.util.Random
        for (n <- Iterator.range(array.length - 1, 0, -1)) {
            val k = rnd.nextInt(n + 1)
            val t = array(k); array(k) = array(n); array(n) = t
        }
        return array
    }
    
	def main(args: Array[String]) = {
		val scanner = new java.util.Scanner(System.in)
		val n, l, r = scanner.nextInt()
		var a, b = new Array[Int](n)
		for (i <- 0 to n-1) {
			a(i) = scanner.nextInt()
		}
		for (i <- 0 to n-1) {
			b(i) = scanner.nextInt()
		}
		var i = 0
		var lie = false
		for (i <- 1 to n) {
			if (a(i-1) != b(i-1) && (i < l || r < i)) {
				lie = true
			}
		}
		shuffle(a)
		scala.util.Sorting.quickSort(a)
		shuffle(b)
		scala.util.Sorting.quickSort(b)
		for (i <- 1 to n) {
			if (a(i-1) != b(i-1)) {
				lie = true
			}
		}
		if (lie) {
			println("LIE")
		} else {
			println("TRUTH")
		}
	}
}