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
const int N=101,M=1E4+1;
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
typedef bitset<M> bt;
bt vis[N][N];
void init()
{
    vis[1][1][0]=1;
    for(int i=1;i<N;++i)
    {
        for(int j=1;j<N;++j)
        {
            for(int k=1;k<M;++k)
            {
                if(k>=j&&vis[i-1][j][k-j]||k>=i&&vis[i][j-1][k-i])
                {
                    vis[i][j][k]=1;
                }
            }
        }
    }
}
void solve()
{
    int a=read(),b=read(),c=read();
    puts(vis[a][b][c]?"YES":"NO");
}
int main()
{
    init();
    for(int x=read();x--;)
    {
        solve();
    }
}