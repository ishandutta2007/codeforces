fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    class Stu(val name: String, var h: Int)
    //val a1 = readLine()!!.split(' ').map(String::toInt)
    val al: MutableList<Stu> = mutableListOf()
    var x: Int = 0
    while( x < n ){
      val (nm,hei) = readLine()!!.split(' ')
      al.add( Stu( nm , hei.toInt() ) )
      x ++
    }
    for( i in 100..300 ){
      for( who in al ){
        if( who.h == i ){
          println( who.name );
        }
      }
    }
}