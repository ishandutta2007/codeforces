import java.util.Scanner
val read=Scanner(System.`in`)
val INF=0x3fffffffffffffff
var dp=Array<LongArray>(15,{_->LongArray(1 shl 15,{_->0})})
var n=read.nextInt()
var m=read.nextInt()
var q=read.nextInt()
var s=read.nextInt()-1
var dis=Array<LongArray>(15,{_->LongArray(15,{_->-1})})
var mat=Array<Array<LongArray> >(50,{_->Array<LongArray>(15,{_->LongArray(15,{_->INF})})})
var sum=LongArray(1 shl 15,{_->0.toLong()})
var rk=IntArray(1 shl 15,{i->i})
var to=Array<ArrayList<Int> >(15,{_->ArrayList<Int>()})
var pr=LongArray(q,{_->INF})
class queue
{
    var l=0;var r=0;var que=IntArray(15)
    fun push(value:Int)
    {
        if(l==r)
        {
            l=0
            r=0
        }
        que[r++]=value
    }
    fun front():Int{return que[l]}
    fun pop(){++l}
    fun empty():Boolean{return l==r}
}
var que=queue()
class pair(var value:Long,var dis:Long)
var len=IntArray(15,{_->0})
var g=Array<Array<pair> >(15,{_->Array<pair>((1 shl n)*n+1,{_->pair(0,0)})})
fun min(A:Long,B:Long):Long{return if(A<B) A else B }
fun lower_bound(i:Int,x:Long):Long
{
    var l=1;var r=len[i]
    while(l!=r)
    {
        var mid=(l+r) shr 1
        if(g[i][mid].value<x)
            l=mid+1
        else
            r=mid
    }
    return g[i][l].dis
}
fun sort(l:Int,r:Int)
{
    val mid=sum[rk[(l+r) shr 1]]
    var i=l;var j=r
    do
    {
        while(sum[rk[i]]<mid)++i
        while(sum[rk[j]]>mid)--j
        if(i<=j)
        {
            val tmp=rk[i];rk[i]=rk[j];rk[j]=tmp
            ++i;--j
        }
    }while(i<=j)
    if(l<j)sort(l,j)
    if(i<r)sort(i,r)
}
fun main()
{
    for(i in 0 until n)
        sum[1 shl i]=read.nextLong()
    for(i in 0 until (1 shl n))
        sum[i]=sum[i and (i-1)]+sum[i and -i]
    sort(0,(1 shl n)-1)
    for(i in 0 until m)
    {
        var a=read.nextInt()-1;var b=read.nextInt()-1
        to[a].add(b)
    }
    for(i in 0 until n)
    {
        dis[i][i]=0
        que.push(i)
        while(!que.empty())
        {
            var now=que.front()
            que.pop()
            for(j in to[now])
            {
                if(dis[i][j]==-1.toLong())
                {
                    dis[i][j]=dis[i][now]+1
                    que.push(j)
                }
            }
        }
    }
    for(l in 0 until n)
    {
        for(i in 0 until n)
            for(j in 0 until (1 shl n))
                dp[i][j]=INF
        dp[l][1 shl l]=0
        for(i in 0 until (1 shl n))
            for(j in 0 until n)
                for(k in 0 until n)
                    dp[k][i or (1 shl k)]=min(dp[k][i or (1 shl k)],dp[j][i]+dis[j][k])
        for(i in 0 until n)
            mat[0][l][i]=dp[i][(1 shl n)-1]
        for(i in 0 until (1 shl n))
        {
            var tmp=pair(sum[rk[i]],INF)
            for(j in 0 until n)
                tmp.dis=min(tmp.dis,dp[j][rk[i]])
            if(tmp.dis==INF)
                continue
            while(len[l]>0&&g[l][len[l]].dis>=tmp.dis)
                --len[l]
            g[l][++len[l]]=tmp
        }
    }
    for(i in 1 until 50)
        for(j in 0 until n)
            for(k in 0 until n)
                for(l in 0 until n)
                    mat[i][j][l]=min(mat[i][j][l],mat[i-1][j][k]+mat[i-1][k][l])
    for(case in 0 until q)
    {
        var x=read.nextLong()
        var y=x/sum[(1 shl n)-1]
        x%=sum[(1 shl n)-1]
        var ans=INF
        var res=LongArray(n,{_->INF})
        res[s]=0
        for(i in 49 downTo 0)
            if(y>=1.toLong() shl i)
            {
                y-=1.toLong() shl i
                var tmp=res.drop(0)
                for(j in 0 until n)
                    res[j]=INF
                for(j in 0 until n)
                    for(k in 0 until n)
                        res[k]=min(res[k],tmp[j]+mat[i][j][k])
            }
        for(i in 0 until n)
            ans=min(ans,res[i]+lower_bound(i,x))
        pr[case]=ans
    }
    println(pr.joinToString("\n"))
}