#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10,M=28;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int a[M];
int head[N],nex[N<<1],to[N<<1],cnt=1;
int size[N],l,m,k;
bitset<N<<1>b;
void add(int u,int v)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
void dfs(int x,int f)
{
    size[x]=1;
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        if(b[i]||t==f)continue;
        dfs(t,x);
        if(size[t]==a[k]||size[t]==a[k-1])
        {
            l=x;
            m=i;
        }
        size[x]+=size[t];
    }
}
bool check(int x,int w)
{
    if(w<=3)return 1;
    l=0;
    k=w;
    dfs(x,0);
    if(!l)return 0;
    b[m]=b[m^1]=1;
    int r=to[m];
    bool t=size[r]==a[w];
    --w;
    return check(l,w-t)&&check(r,w-!t);
}
int main()
{
    a[1]=1;
    for(int i=2;i<M;++i)a[i]=a[i-1]+a[i-2];
    int n=read();
    int t=lower_bound(a,a+M,n)-a;
    if(a[t]!=n)
    {
        puts("NO");
        return 0;
    }
    while(--n)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    puts(check(1,t-1)?"YES":"NO");
}