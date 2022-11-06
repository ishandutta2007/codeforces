#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
char s[N];
int sa[N],rk[N],id[N],b[N];
void _sort(int n,int m)
{
    for(int i=1;i<=m;i++) b[i]=0;
    for(int i=1;i<=n;i++) b[rk[i]]++;
    for(int i=1;i<=m;i++) b[i]+=b[i-1];
    for(int i=n;i;i--) sa[b[rk[id[i]]]--]=id[i];
}
void _sa(int n)
{
    for(int i=1;i<=n;i++) rk[i]=s[i]-'a'+1,id[i]=i;
    int m=26;
    _sort(n,m);
    for(int p=1,t=0;p<n;m=t,t=0,p<<=1)
    {
        for(int i=1;i<=p;i++) id[++t]=n-p+i;
        for(int i=1;i<=n;i++)
        if(sa[i]>p) id[++t]=sa[i]-p;
        _sort(n,m);swap(id,rk);
        rk[sa[1]]=t=1;
        for(int i=2;i<=n;i++)
        rk[sa[i]]=(t+=id[sa[i-1]]!=id[sa[i]] || id[sa[i-1]+p]!=id[sa[i]+p]);
    }
}
int ht[N];
void get_ht(int n)
{
    for(int i=1,p=0;i<=n;ht[rk[i]]=p,i++)
    if(rk[i]!=1) for(p=p-!!p;sa[rk[i]-1]+p<=n && i+p<=n && s[i+p]==s[sa[rk[i]-1]+p];p++);
    else p=0;
}
int sv[N],sc[N],st;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);
        _sa(n);
        get_ht(n);
        st=0;
        long long ans=1ll*n*(n+1)/2,tot=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=1;
            for(;st && ht[i]<=sv[st];st--) cnt+=sc[st],tot-=1ll*sv[st]*sc[st];
            sv[++st]=ht[i],sc[st]=cnt;
            tot+=1ll*ht[i]*cnt;
            ans+=2*tot;
        }
        printf("%lld\n",ans);
    }
    return 0;
}