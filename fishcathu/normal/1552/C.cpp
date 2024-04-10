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
const int N=110;
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
int a[N],b[N];
bool vis[N<<1];
void solve()
{
    int n=read(),s=n<<1,cnt=read();
    for(int i=1;i<=cnt;++i)
    {
        a[i]=read();
        b[i]=read();
        vis[a[i]]=vis[b[i]]=1;
    }
    vct q;
    for(int i=1;i<=s;++i)
    {
        if(vis[i])vis[i]=0;
        else q.pb(i);
    }
    for(int i=0,t=q.size()>>1;i<t;++i)a[++cnt]=q[i],b[cnt]=q[i+t];
    int res=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>b[i])swap(a[i],b[i]);
        for(int j=1;j<i;++j)
        {
            if(a[j]>b[i]||b[j]<a[i])continue;
            if(a[j]<a[i]&&b[j]>b[i])continue;
            if(a[j]>a[i]&&b[j]<b[i])continue;
            ++res;
        }
    }
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}