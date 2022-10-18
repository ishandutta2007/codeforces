fun printNormal(s : String) {
	for (c in s) print(c.toLowerCase())
}

fun printCap(s : String) {
	print(s[0].toUpperCase())
	for (i in 1..(s.length - 1))
	print(s[i].toLowerCase())
}


fun main(args : Array<String>) {
	val s = readLine() + " "

	var i = 0
	val l : MutableList<String> = mutableListOf()
	var z = ""

	while (i < s!!.length) {
		if (s[i].isLetter()) {
			z = z + s[i];
		} else if (s[i].isWhitespace()) {
			if (z.length > 0) {
				l.add(z)
				z = ""
			}
		}
		else {
			if (z.length > 0) {
				l.add(z)
				z = ""
			}
			l.add("" + s[i])
		}
		i += 1
	}

	var startstart = true
	var start = true

	for (x in l) {
		if (x[0].isLetter()) {
			if (!startstart) print(" ");
			if (!start) printNormal(x) 
			else printCap(x)
			startstart = false
			start = false
		} else {
			print(x)
			if (x == ".") start = true
		}
	}
	print("\n")
}