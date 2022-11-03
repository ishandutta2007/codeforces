
fun main(args: Array<String>) {

    val namearray = arrayListOf<String>()
    var heightarray = arrayListOf<Int>()
    var str = readLine()!!.split(' ').map(String::toString)
    var n = str[0].toInt()
    var i = 1
	while ( i <= n)
    {
        i++
        var (name, strheight) = readLine()!!.split(' ').map(String::toString)
        var height = strheight.toInt()
        namearray.add(name)
        heightarray.add(height)
    }
    i = 0
    while (i <= n-1)
    {
        var j = 0
        while (j <= n-2-i)
        {
            if(heightarray[j] > heightarray[j+1])
            {
                var t = heightarray[j];
                heightarray[j] = heightarray[j+1]
                heightarray[j+1] = t
                
                var tt = namearray[j]
                namearray[j] = namearray[j+1]
                namearray[j+1] = tt
            }
            j++
        }
        i++
    }
    for (x in namearray)
    {
        println(x)
    }
}