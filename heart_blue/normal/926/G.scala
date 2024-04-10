object compute {
    def min( a:Int, b:Int ) : Int = {
      if(a > b) return b;
      else return a;
   }
  def main(args: Array[String]): Unit = {
    import  scala.io.StdIn
    //  Scala

    val n = StdIn.readInt();
    var res = 0;
    var str = StdIn.readLine();
    var ar = str.split(' ');
    var cnt0 = 0;
    var cnt1 = 0;
    for( a <- ar){
         var x = a.charAt(a.length()-1);
         if(x%2 == 0) cnt0 += 1;
         else cnt1 += 1;
      }
      var o = min(cnt1,cnt0);
      cnt1 -= o;
      res = cnt1/3 + o;
      
  println(res);
  }
}