#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1010;
const int inf=1<<30;
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int fa[N],a[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int m=read(),s=1;m--;)
    {
        int u=find(read()),v=find(read());
        if(u^v)fa[v]=u;
        else ++s;
        for(int i=1;i<=n;++i)a[i]=0;
        for(int i=1;i<=n;++i)++a[find(i)];
        sort(a+1,a+1+n,greater<>());
        int ans=-1;
        for(int i=1;i<=s;++i)ans+=a[i];
        write(ans,'\n');
    }
}