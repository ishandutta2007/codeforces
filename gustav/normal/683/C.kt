fun main(args : Array<String>) {
	val a = readLine()!!.split(' ').map(String::toInt).toTypedArray()
	val b = readLine()!!.split(' ').map(String::toInt).toTypedArray()
	var i = 1
	var j = 1

	a.sort(1)
	b.sort(1)
	
	val results : MutableList< Int > = mutableListOf()

	while (i < a.size && j < b.size) {
		if (a[i] == b[j]) {
			i += 1
			j += 1
		}
		else if (a[i] < b[j]) {
			results.add(a[i])
			i += 1
		}
		else {
			results.add(b[j])
			j += 1
		}
	}

	while (i < a.size) {
		results.add(a[i])
		i += 1
	}

	while (j < b.size) {
		results.add(b[j])
		j += 1
	}

	print(results.size)
	print(' ')

	for (x in results) {
		print(x)
		print(' ')
	}
	print('\n')
}