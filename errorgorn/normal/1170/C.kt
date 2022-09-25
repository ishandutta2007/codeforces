fun main(){
    var TC=readLine()!!.toInt()
    repeat(TC){
        var str1=readLine()!!
        var str2=readLine()!!
        var it1=0
        var it2=0
        while (it2<str2.length) {
            if (it1>=str1.length) break;
            if (str1[it1]==str2[it2]){
                it1++
                it2++
            }
            else if (it1<str1.length-1 && str2[it2]=='+' && str1[it1]=='-' && str1[it1+1]=='-'){
                it1+=2
                it2++
            }
            else break;
        }
        if (it1==str1.length && it2==str2.length) print("YES\n");
        else print("NO\n");
    }
}