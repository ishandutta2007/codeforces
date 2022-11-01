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
int b[N];
vector<int>a[N];
ll pre[N],ans[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        b[i]=read();
        a[i].clear();
        a[i].pb(0);
        ans[i]=0;
    }
    for(int i=1;i<=n;++i)a[b[i]].pb(read());
    for(int i=1;i<=n;++i)
    {
        int m=a[i].size()-1;
        sort(a[i].begin()+1,a[i].end(),greater<int>());
        for(int j=1;j<=m;++j)pre[j]=pre[j-1]+a[i][j];
        for(int j=1;j<=m;++j)ans[j]+=pre[m-m%j];
    }
    for(int i=1;i<=n;++i)write(ans[i],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}