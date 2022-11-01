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
const int N=3E5+10;
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
bool vis[N];
void solve()
{
    int n=read(),m=read();
    for(int i=0;i<n;++i)b[i]=0;
    for(int i=0;i<n;++i)
    {
        a[i]=(i-read()+1+n)%n;
        ++b[a[i]];
    }
    vct ans;
    for(int i=0;i<n;++i)
    {
        if(n-b[i]+1>>1>m)continue;
        int res=0;
        for(int j=0;j<n;++j)vis[j]=0;
        for(int j=0;j<n;++j)
        {
            if(vis[j])continue;
            for(int k=j;!vis[k];k=(k+i-a[k]+n)%n)
            {
                vis[k]=1;
                ++res;
            }
            --res;
        }
        if(res<=m)ans.pb(i);
    }
    write(ans.size(),' ');
    for(int x:ans)write(x,' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}