fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    //val a1 = readLine()!!.split(' ').map(String::toInt)
    //val al: MutableList<Stu> = mutableListOf()
    var x: Int = 0
    while( x < n ){
      val a = readLine()!!.split(' ').map(String::toInt)
      var ans: Int = 0
      var i: Int = 1
      while( i <= a[ 0 ] && ans == 0 ){
        if( ( a[ 2 ] % i == 0 ) && ( a[ 2 ] <= a[ 1 ] * i ) )
          ans = 1
        i ++
      }
      if( ans == 1 )
        println( "Yes" )
      else 
        println( "No" )
      x ++
    }
}