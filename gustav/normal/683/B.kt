fun main(args : Array<String>) {
	// val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	// if (0 < x && x < a && 0 < y && y < a)
	// println("0");
	// else if (0 <= x && x <= a && 0 <= y && y <= a)
	// println("1");
	// else
	// println("2");
	val n = readLine()
	var l = readLine()
	val p : MutableList< Pair< Int, String > > = mutableListOf()
	while (l != null) {
		val (name, sscore) = l!!.split(' ');
		val score = sscore.toInt();
		p.add(Pair(score, name));
		l = readLine()
	}
	val a = p.toTypedArray()
	a.sortBy({ pi -> pi.first })
	
	for (i in a)
	println(i.second)
}