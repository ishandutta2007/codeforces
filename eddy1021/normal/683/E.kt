fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val c = readLine()!!.split(' ').map(String::toInt)
    var ans: MutableList<Int> = mutableListOf()
    var x: Int = 0
    while( x < n ){
      ans.add( 0 )
      x ++
    }
    x = 0
    while( x < n ){
      var pre: Int = 0
      var y: Int = 0
      while( y < n ){
        if( ans[ y ] == 0 ){
          if( pre == c[ x ] ){
            ans[ y ] = x + 1
            break
          }
          pre ++
        }
        y ++
      }
      x ++
    }
    for( i in ans ){
      print( i )
      print( " " )
    }
}