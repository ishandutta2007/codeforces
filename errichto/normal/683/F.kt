fun main(args: Array<String>) {
    var (s) = readLine()!!.split('#')
    var ans = ""
    
    for(i in 0..(s.length-1)) {
        if(s[i] == ' ') {
            if(ans.length >= 1)
                if(ans[ans.length-1] != ' ') ans += s[i]
        }
        else {
            var hack = 0
            if((s[i] == '.') or (s[i] == ','))
                if(ans.length != 0)
                    if(ans[ans.length-1] == ' ') {
                        hack = 1
                        ans = ans.dropLast(1)
                        ans += s[i]
                    }
            if(hack == 0)
                ans += s[i]
            if((s[i] == '.') or (s[i] == ','))
                ans += " "
        }
    }
    if(ans[ans.length-1] == ' ') {
        var tmp = ""
        for(i in 0..(ans.length-2))
            tmp = tmp + ans[i]
        ans = tmp
    }
    var ple = ""
    for(i in 0..(ans.length-1)) {
        if((ans[i] == ' ') or (ans[i] == ',') or (ans[i] == '.'))
            ple += ans[i]
        else {
            var big = 0
            if(i == 0) big = 1
            else if(i == 1) big = 0
            else if(ans[i-2] == '.') big = 1
            if((big == 1) and ('a' <= ans[i]) and (ans[i] <= 'z'))
                ple += (ans[i].toInt() + ('A').toInt() - ('a').toInt()).toChar()
            else if((big == 0) and ('A' <= ans[i]) and (ans[i] <= 'Z'))
                ple += (ans[i].toInt() + ('a').toInt() - ('A').toInt()).toChar()
            else ple += ans[i]
        }
    }
    println(ple)
}