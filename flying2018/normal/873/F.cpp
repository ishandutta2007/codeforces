#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
char s[N];
int sa[N],ht[N],id[N],rk[N],b[N];
void sa_sort(int n,int m)
{
    for(int i=1;i<=m;i++) b[i]=0;
    for(int i=1;i<=n;i++) b[rk[i]]++;
    for(int i=1;i<=m;i++) b[i]+=b[i-1];
    for(int i=n;i>=1;i--) sa[b[rk[id[i]]]--]=id[i];
}
void sa_(int n)
{
    int m=26;
    for(int i=1;i<=n;i++) rk[i]=s[i]-'a'+1,id[i]=i;
    sa_sort(n,m);
    for(int p=1,t=0;p<n;p<<=1,m=t,t=0)
    {
        for(int i=1;i<=p;i++) id[++t]=n-p+i;
        for(int i=1;i<=n;i++)
        if(sa[i]>p) id[++t]=sa[i]-p;
        sa_sort(n,m);
        swap(rk,id);rk[sa[1]]=t=1;
        for(int i=2;i<=n;i++)
        rk[sa[i]]=(t+=id[sa[i]]!=id[sa[i-1]] || id[sa[i]+p]!=id[sa[i-1]+p]);
    }
}
void get_ht(int n)
{
    for(int i=1,p=0;i<=n;ht[rk[i]]=p,i++)
    if(rk[i]!=1) for(p=p-!!p;i+p<=n && sa[rk[i]-1]+p<=n && s[i+p]==s[sa[rk[i]-1]+p];p++);
    else p=0;
}
char op[N];
int sc[N],sh[N],st;
int main()
{
    int n;
    scanf("%d%s%s",&n,s+1,op+1);
    reverse(s+1,s+n+1);reverse(op+1,op+n+1);
    sa_(n);
    get_ht(n);
    long long ans=0;
    // for(int i=1;i<=n;i++) printf("%d ",ht[i]);puts("");
    int mn=1e7;
    for(int i=1;i<=n;i++)
    {
        mn=min(mn,ht[i]);
        if(op[sa[i]]=='1') continue;
        int cnt=1;
        for(;st && sh[st]>=mn;st--)
        {
            cnt+=sc[st];
            ans=max(ans,1ll*sh[st]*cnt);
        }
        ans=max(ans,n-sa[i]+1ll);
        sc[++st]=cnt,sh[st]=mn;mn=1e7;
    }
    int cnt=0;
    for(;st;st--)
    {
        cnt+=sc[st];
        ans=max(ans,1ll*sh[st]*(cnt+1));
    }
    printf("%lld\n",ans);
    return 0;
}