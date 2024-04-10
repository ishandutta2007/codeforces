
fun main(args: Array<String>) {

    var a = readLine()!!.split(' ').map(String::toInt)
   	var b = readLine()!!.split(' ').map(String::toInt)
    var n = a[0]
    var m = b[0]
    var ans = arrayListOf<Int>()
    var c = arrayListOf<Int>()
    var d = arrayListOf<Int>()
    for (i in 1..n)
    {
        c.add(a[i])
    }
    for (i in 1..m)
    {
        d.add(b[i])
    }
    for (i in 1..n)
    {
        if (!(a[i] in d))
        {
            ans.add(a[i])
        }
    }
    for (i in 1..m)
    {
        if (!(b[i] in c))
        {
            ans.add(b[i])
        }
    }
    print(ans.size)
    ans.sort()
    for (x in ans)
    {
        print(" ${x}")
    }
}