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
const int N=2010;
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
int dis[N][N],n;
vector<pii>ans;
void ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    for(int i=1;i<=n;++i)dis[x][i]=read();
}
int main()
{
    n=read();
    ask(1);
    int m=0;
    for(int i=2;i<=n;++i)
    {
        if(dis[1][i]&1)
        {
            ++m;
        }
    }
    m=m*2>n-1;
    if(m)
    {
        for(int i=1;i<=n;++i)
        {
            if(dis[1][i]==1)
            {
                ans.pb(mp(1,i));
            }
        }
    }
    for(int i=2;i<=n;++i)
    {
        if(dis[1][i]+m&1)
        {
            ask(i);
            for(int j=1;j<=n;++j)
            {
                if(dis[i][j]==1)
                {
                    ans.pb(mp(i,j));
                }
            }
        }
    }
    puts("!");
    for(pii x:ans)printf("%d %d\n",x.fi,x.se);
}