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
const int N=5E4+10,M=1E5+10;
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
struct node
{
    int x,y;
    bool operator<(const node m)const
    {
        return x<m.x&&y>m.y;
    }
};
int L[M],R[M];
vct to[N];
int ans[N],n;
set<node>q[N];
void add(int x,node y)
{
    while(x<=n)
    {
        set<node>::iterator it=q[x].lower_bound(y);
        if(it==q[x].end()||it->y<y.y)
        {
            q[x].erase(y);
            q[x].insert(y);
        }
        x+=x&-x;
    }
}
int solve(int l,int r)
{
    if(l>r)return 0;
    int t=0;
    for(int i=r;i>=l;i-=i&-i)
    {
        set<node>::iterator it=q[i].lower_bound({l,0});
        if(it!=q[i].end())t=max(t,it->y);
    }
    if(!t)return 0;
    return R[t]-L[t]+1+solve(l,L[t]-1)+solve(R[t]+1,r);
}
int main()
{
    n=read();
    for(int i=read();i>=1;--i)
    {
        L[i]=read(),R[i]=read();
        to[R[i]-L[i]+1].pb(i);
    }
    for(int i=n;i>=1;--i)
    {
        for(int x:to[i])add(R[x],{L[x],x});
        ans[i]=solve(1,n);
    }
    for(int i=1;i<=n;++i)write(ans[i],'\n');
}