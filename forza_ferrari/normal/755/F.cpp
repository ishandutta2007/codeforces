#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m,bin[1000001],s[1000001],ans,cnt,val[1000001],sum,res,a[1000001],p;
bitset<1000001> dp;
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
    {
        bin[y]=x;
        s[x]+=s[y];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i)
        s[i]=1;
    for(register int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        link(i,x);
    }
    for(register int i=1;i<=n;++i)
        if(anc(i)==i)
            val[++cnt]=s[i];
    sort(val+1,val+cnt+1);
    int tmp=1;
    for(register int i=2;i<=cnt;++i)
        if(val[i]==val[i-1])
            ++tmp;
        else
        {
            for(register int j=0;1<<j<=tmp;++j)
            {
                a[++p]=val[i-1]*(1<<j);
                tmp-=1<<j;
            }
            if(tmp)
                a[++p]=val[i-1]*tmp;
            tmp=1;
        }
    for(register int i=0;1<<i<=tmp;++i)
    {
        a[++p]=val[cnt]*(1<<i);
        tmp-=1<<i;
    }
    if(tmp)
        a[++p]=val[cnt]*tmp;
    dp.set(0);
    for(register int i=1;i<=p;++i)
    {
        dp|=dp<<a[i];
        //for(register int i=0;i<=m;++i)
            //cout<<dp.test(i)<<endl;
    }
    if(dp.test(m))
        printf("%d ",m);
    else
        printf("%d ",m+1);
    ans=sum=0;
    for(register int i=1;i<=cnt;++i)
        sum+=val[i]>>1;
    if(sum>m)
        ans=m<<1;
    else
        ans=min(m+sum,n);
    printf("%d\n",ans);
    return 0;
}