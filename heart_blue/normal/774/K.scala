object compute {
    def check( a:Int, c:Char ) : Unit = {
        if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y')
        {
            if(a == 2 && (c == 'e' || c == 'o'))
            {
                print(c);
                print(c);
                return;
            }
            else
            {
                print(c);
            }
        }
        else
        {
            var cnt = a;
            while(cnt > 0)
            {
                print(c);
                cnt = cnt - 1;
            }
        }
    }
    def main(args: Array[String]): Unit = {
    import  scala.io.StdIn
    //  Scala
 
    val n = StdIn.readInt();
    var str = StdIn.readLine();
    var pre = str.charAt(0);
    var cnt = 0;
    for (c <- str){
        if(c != pre) {
            check(cnt, pre);
            cnt = 1;
            pre = c;
        }
        else
        {
            cnt = cnt + 1;
        }
    }
    check(cnt, pre);
    }
}