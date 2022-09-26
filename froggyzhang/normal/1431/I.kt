import java.util.Scanner
val read=Scanner(System.`in`)
val n=read.nextInt()
val m=read.nextInt()
val q=read.nextInt()
var s=Array<String>(q,{_->""})
var lst=IntArray(q)
var head=IntArray(m,{_->-1})
var cnt=0
var root=cnt++
var ans=IntArray(q,{_->-1})
var son=Array<IntArray>(500005,{_->IntArray(26,{_->-1})})
fun add(now:Int,str:String,pos:Int)
{
    if(pos==m)
        return
    if(son[now][str[pos]-'a']==-1)
        son[now][str[pos]-'a']=cnt++
    add(son[now][str[pos]-'a'],str,pos+1)
}
fun merge(A:Int,B:Int)
{
    for(i in 0 until 26)
        if(son[B][i]!=-1)
        {
            if(son[A][i]!=-1)
                merge(son[A][i],son[B][i])
            else
                son[A][i]=son[B][i]
        }
}
fun merge_son(now:Int):Int
{
    var x=0
    while(x!=26&&son[now][x]==-1)
        ++x
    for(i in (x+1) until 26)
        if(son[now][i]!=-1)
            merge(son[now][x],son[now][i])
    return son[now][x]
}
fun pd(now:Int,str:String,pos:Int):Int
{
    if(pos!=m&&son[now][str[pos]-'a']!=-1)
        return pd(son[now][str[pos]-'a'],str,pos+1)
    else
        return pos
}
fun main()
{
    for(i in 0 until n)
        add(root,read.next(),0)
    for(i in 0 until q)
    {
        s[i]=read.next()
        lst[i]=head[0]
        head[0]=i
    }
    for(i in 0 until m)
    {
        var j=head[i]
        while(j!=-1)
        {
            var nxt=lst[j]
            ++ans[j]
            var tmp=pd(root,s[j],i)
            if(tmp==i)
                ans[j]=-1
            else if(tmp!=m)
            {
                lst[j]=head[tmp]
                head[tmp]=j
            }
            j=nxt
        }
        root=merge_son(root)
    }
    print(ans.joinToString("\n"))
}