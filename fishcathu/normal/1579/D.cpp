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
const int N=2E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
pii a[N];
queue<pii>q;
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]={read(),i};
    sort(a+1,a+1+n);
    for(int i=1;i<n;++i)
    {
        for(int j=a[i].fi;j--;)q.push({a[i].se,a[i+1].se});
        a[i+1].fi-=a[i].fi;
    }
    if(!q.empty())
    {
        for(int i=a[n].fi>>1;i--;)
        {
            auto [l,r]=q.front();
            if(r==a[n].se)break;
            q.pop();
            q.push({l,a[n].se});
            q.push({r,a[n].se});
        }
    }
    write(q.size(),'\n');
    while(!q.empty())
    {
        auto [l,r]=q.front();
        printf("%d %d\n",l,r);
        q.pop();
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}