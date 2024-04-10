var ft = Array(240000){0}
var st = Array(240000){0}
fun addf(x : Int){
    var xx = x
    while(xx < 240000){
        ft[xx] += 1
        xx += (xx and -xx)
    }
}
fun sumf(x : Int) : Int{
    var xx = x
    var res = 0
    while(xx > 0){
        res += ft[xx]
        xx -= (xx and -xx)
    }
    return res
}
fun adds(x : Int){
    var xx = x
    while(xx < 240000){
        st[xx] += 1
        xx += (xx and -xx)
    }
}
fun sums(x : Int) : Int{
    var xx = x
    var res = 0
    while(xx > 0){
        res += st[xx]
        xx -= (xx and -xx)
    }
    return res
}
fun main() {
    var n = readLine()!!.toInt()
    var s = readLine()!!.split(' ').map{it.toInt()}
    var fi = Array(240000){0}
    var se = Array(240000){0}
    var ans = Array(240000){'B'}
    for(i in 0 until n){
        if(fi[s[i]] == -1) continue
        if(fi[s[i]] == 0){
            fi[s[i]] = i + 1
        }
        else if(se[s[i]] == 0){
            se[s[i]] = i + 1
        }
        else fi[s[i]] = -1
    }
    for(i in 1..n){
        var ok = false
        if((fi[i] != -1) and (se[i] != 0)){
            var fp = fi[i]
            var sp = se[i]
            var RL = fp + 1
            var RR = n + 1
            while(RL < RR) {
                var RM = (RL + RR) / 2
                var s = sumf(RM) - sumf(fp)
                if (s > 0) RR = RM
                else RL = RM + 1
            }
            var fR = RR
            RL = sp + 1
            RR = n + 1
            while(RL < RR){
                var RM = (RL + RR) / 2
                var s = sums(RM) - sums(sp)
                if(s > 0) RR = RM
                else RL = RM + 1
            }
            var sR = RR
            //println("$fR $sR")
            if((fR == n + 1) and (sR  != n + 1)) break
            if((fR != n + 1) and (sR  == n + 1)) break
            if((fR != n + 1) and (sR  != n + 1))
                if((s[fR - 1] != s[sR - 1])) break

            RL = 0
            RR = fp - 1
            while(RL < RR) {
                var RM = (RL + RR + 1) / 2
                var s = sumf(fp - 1) - sumf(RM - 1)
                if (s > 0) RL = RM
                else RR = RM - 1
            }
            var fL = RR
            RL = 0
            RR = sp - 1
            while(RL < RR) {
                var RM = (RL + RR + 1) / 2
                var s = sums(sp - 1) - sums(RM - 1)
                if (s > 0) RL = RM
                else RR = RM - 1
            }
            var sL = RR
            //println("$fL $sL")
            if((fL == 0) and (sL  != 0)) break
            if((fL != 0) and (sL  == 0)) break
            if((fL != 0) and (sL  != 0))
                if((s[fL - 1] != s[sL - 1])) break

            ans[fp] = 'R'
            ans[sp] = 'G'
            addf(fp)
            adds(sp)
            ok = true
        }
        if(!ok) break
    }
    for(i in 1..n){
        print(ans[i])
    }
}