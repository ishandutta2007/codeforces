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
const int N=3010;
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
int a[N],pre[N],pos[N],f[N][N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)pos[a[i]=read()]=0;
    for(int i=1;i<=n;++i)
    {
        pre[i]=pos[a[i]];
        pos[a[i]]=i;
        for(int j=i;--j;)
        {
            f[j][i]=f[j][i-1]+1;
            for(int k=pre[i];k>=j;k=pre[k])f[j][i]=min(f[j][i],f[j][k]+f[k+1][i]);
        }
    }
    write(f[1][n],'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}