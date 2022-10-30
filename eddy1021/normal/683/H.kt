fun main(args: Array<String>) {
  val (tn,k) = readLine()!!.split(' ').map(String::toLong)
  val n: Int = tn.toInt()
  val pp = readLine()!!.split(' ').map(String::toInt)
  var p = Array<Int>(n,{i -> 0})
  var ans = Array<Int>(n,{i -> i})
  var rans = Array<Int>(n,{i -> 0})
  for( iter in 0..n-1 )
    p[ pp[ iter ] - 1 ] = iter;
  var tk: Long = k
  while( tk > 0 ){
    if( tk % 2L == 1L ){
      for( iter2 in 0..n-1 )
        ans[ iter2 ] = p[ ans[ iter2 ] ]
    }
    for( iter2 in 0..n-1 )
      rans[ iter2 ] = p[ p[ iter2 ] ]
    val tmp = p
    p = rans
    rans = tmp
    tk /= 2L
  }
  for( i in 0..n-1 )
    ans[ i ] = ans[ i ] + 1
  println(ans.joinToString(" "))
}