#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3E5+10;
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
int a[N];
vector<pii>to[100010];
map<int,int>f;
int main()
{
    read();
    for(int m=read();m--;){pii x={read(),read()};to[read()].pb(x);}
    for(vector<pii>x:to)
    {
        f.clear();
        for(auto [u,v]:x)f[v]=max(f[v],a[u]);
        for(auto [u,v]:f)a[u]=max(a[u],v+1);
    }
    write(*max_element(a,a+N),'\n');
}