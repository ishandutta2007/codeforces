fun main(args: Array<String>) {
  val s = readLine()!!
  var first: Int = 0
  var pp: Int = 0
  var iter: Int = 0
  var len: Int = s.length
  var pw: Int = 0
  var start: Int = 1
  while( iter < len ){
    if( s[ iter ] != ' ' ){
      if( s[ iter ] == ',' || s[ iter ] == '.' ){
        pp = 1
        print( s[ iter ] )
        if( s[ iter ] == '.' )
          first = 1
      }else{
        if( start == 1 ){
          print( s[ iter ].toUpperCase() )
          start = 0
        }else{
          if( pw == 1 || pp == 1 )
            print( " " )
          if( first == 1 ){
            print( s[ iter ].toUpperCase() )
            first = 0
          }else{
            print( s[ iter ].toLowerCase() )
          }
        }
        pp = 0
      }
      pw = 0
    }else{
      pw = 1
    }
    iter ++
  }
}