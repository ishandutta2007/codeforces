#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E6+10;
const int inf=1<<30;
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
int head[N],nex[N],to[N];
int fa[N],q[N];
int a[N],b[N];
void add(int u,int v)
{
    static int cnt=0;
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
int main()
{
    int n=read(),m=read();
    for(int i=2;i<=n;++i)add(fa[i]=read(),i);
    q[1]=1;
    for(int l=0,r=1;r<n;)
    {
        for(int i=head[q[++l]];i;i=nex[i])
        {
            q[++r]=to[i];
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!head[i])
        {
            a[i]=1;
            b[i]=m;
        }
    }
    for(int i=n;i>=1;--i)
    {
        int x=q[i];
        if(b[x])
        {
            int f=fa[x];
            a[f]+=a[x];
            a[x]=0;
            b[f]=max(b[f],b[x]-1);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int x=q[i];
        ans=max(ans,a[x]+=a[fa[x]]);
    }
    write(ans,'\n');
}