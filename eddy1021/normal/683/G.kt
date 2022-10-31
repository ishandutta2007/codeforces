fun gcd(a : Long, b : Long) : Long{
  var ta: Long = a
  var tb: Long = b
  var c : Long = 0
  while( tb != 0L ){
    c = ta % tb
    ta = tb
    tb = c
  }
  return ta
}
fun main(args: Array<String>) {
  val s = readLine()!!
  var n : Long = 0
  var p : Long = 0
  var len: Int = s.length
  var iter: Int = 0
  var st: Int = 0
  var cnt: Int = 0
  var cnt2: Int = 0
  while( iter < len ){
    if( s[ iter ] == '.' ){
      st = 1
    }else if( s[ iter ] == '(' ){
      st = 2
    }else if( s[ iter ] == ')' ){
      st = 3
    }else if( st == 1 ){
      cnt += 1
      n = n * 10 + ( s[ iter ].toLong() - 48 )
    }else if( st == 2 ){
      cnt2 += 1
      p = p * 10 + ( s[ iter ].toLong() - 48 )
    }
    iter ++
  }
  var au : Long = n
  var ad : Long = 1
  var bu : Long = p
  var bd : Long = 9
  var tmp: Int = 1
  while( tmp < cnt2 ){
    bd = bd * 10 + 9
    tmp ++
  }
  tmp = 0
  while( tmp < cnt ){
    ad *= 10
    bd *= 10
    tmp ++
  }
  var ag = gcd( au , ad )
  au /= ag
  ad /= ag
  var bg = gcd( bu , bd )
  bu /= bg
  bd /= bg
  var ansu = au * bd + bu * ad
  var ansd = ad * bd
  var ansg = gcd( ansu , ansd )
  ansu /= ansg
  ansd /= ansg
  print( ansu )
  print( "/" )
  print( ansd )
}