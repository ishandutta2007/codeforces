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
const int N=60;
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
char a[N][N];
void solve()
{
    int n=read(),m=read();
    bool b=0,c=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",a[i]+1);
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]!='.')
            {
                (a[i][j]+i+j&1?b:c)=1;
            }
        }
    }
    if(b&&c)puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)putchar(i+j+b&1?'W':'R');
            putchar('\n');
        }
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}