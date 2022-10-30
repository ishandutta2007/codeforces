fun main(args: Array<String>) {
    val a1 = readLine()!!.split(' ').map(String::toInt)
    val a2 = readLine()!!.split(' ').map(String::toInt)
    val al: MutableList<Int> = mutableListOf()
    var ans: Int = 0
    for( i in -1000..1000 ){
      var cnt: Int = 0
      for ((index, value) in a1.withIndex()) {
        if( index != 0 && value == i ){
          cnt += 1
          break
        }
      }
      for ((index, value) in a2.withIndex()) {
        if( index != 0 && value == i ){
          cnt += 1
          break
        }
      }
      if( cnt == 1 ) ans += 1
    }
    al.add( ans )
    for( i in -1000..1000 ){
      var cnt: Int = 0
      for ((index, value) in a1.withIndex()) {
        if( index != 0 && value == i ){
          cnt += 1
          break
        }
      }
      for ((index, value) in a2.withIndex()) {
        if( index != 0 && value == i ){
          cnt += 1
          break
        }
      }
      if( cnt == 1 ) al.add( i )
    }
    for( i in al ){
        print( i )
        print( " " )
    }
    //println( al )
}