fun main(){
    var s = readLine()!!.split(' ').map{it.toLong()}
    var (N, M, K, L) = s
    if(L + K > N) print(-1)
    else if((L + K + M - 1) / M * M > N) print(-1)
    else print((L + K + M - 1) / M)
}