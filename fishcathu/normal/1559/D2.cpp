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
const int N=1E5+10;
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
int fa[N],_fa[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
int _find(int x){return _fa[x]^x?_fa[x]=_find(_fa[x]):x;}
vector<int>q,_q;
int main()
{
    int n=read(),y=read(),z=read();
    write(n-1-max(y,z),'\n');
    for(int i=1;i<=n;++i)fa[i]=_fa[i]=i;
    while(y--)
    {
        int u=find(read()),v=find(read());
        if(u>v)swap(u,v);
        fa[v]=u;
    }
    while(z--)
    {
        int u=_find(read()),v=_find(read());
        if(u>v)swap(u,v);
        _fa[v]=u;
    }
    for(int i=2;i<=n;++i)
    {
        int u=find(i),v=_find(i);
        if(u^1&&v^1)
        {
            fa[u]=_fa[v]=1;
            printf("%d 1\n",i);
        }
    }
    for(int i=2;i<=n;++i)
    {
        if(find(i)==i)q.pb(i);
        if(_find(i)==i)_q.pb(i);
    }
    for(int i=min(q.size(),_q.size());i--;)printf("%d %d\n",q[i],_q[i]);
}