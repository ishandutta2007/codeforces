#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
#define MAXN 200005
#define MAXB 455
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,m,size;
ll ans=0;
int c[MAXB][MAXN],s[MAXN],block[MAXN];

void renew(int num,int x,int ad)
{
    for(;x<=n;x+=x&(-x))
        c[num][x]+=ad;
}

int query(int num,int x)
{
    int sum=0;
    for(;x;x-=x&(-x))
        sum+=c[num][x];
    return sum;
}

ll solve(int l,int r,int num)
{
    if(l>r)return 0;
    int sum=0;
    if(block[l]==block[r])
    {
        for(register int i=l;i<=r;i++)sum+=(s[i]<num);
        return(ll)sum;
    }
    for(register int i=block[l]+1;i<block[r];i++)
        sum+=query(i,num);
    if(block[l-1]!=block[l])sum+=query(block[l],num);
    else for(register int i=l;block[i]==block[l]&&i<=r;i++)sum+=(s[i]<num);
    if(block[l]==block[r]) return (ll)sum;
    if(block[r+1]!=block[r])sum+=query(block[r],num);
    else for(register int i=r;block[i]==block[r]&&i>=l;i--)sum+=(s[i]<num);
    return(ll)sum;
}

int main()
{
    n=read();m=read();size=sqrt(n);
    for(int i=1;i<=n;i++)block[i]=(i-1)/size+1;
    for(int i=1;i<=n;i++)s[i]=i,renew(block[i],i,1);
    for(register int i=1;i<=m;i++)
    {
        int u=read(),v=read();if(u>v)swap(u,v);
        if(u==v){printf("%lld\n",ans);continue;}
        if(u!=v-1)
        {
            ans+=2*solve(u+1,v-1,s[v]);
            ans-=2*solve(u+1,v-1,s[u]);
        }
        renew(block[u],s[u],-1);renew(block[u],s[v],1);
        renew(block[v],s[v],-1);renew(block[v],s[u],1);
        swap(s[u],s[v]);
       // cout<<ans;
        if(s[u]>s[v])ans++;else ans--;
        printf("%lld\n",ans);
    }
    return 0;
}