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
const int N=30;
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
char a[N][N];
int b[N][N];
void solve()
{
    memset(a,0,sizeof a);
    int n=read(),m=read(),y=read();
    for(int i=1;i<=n;++i)
    {
        scanf("%s",a[i]+1);
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]!='*')continue;
            b[i][j]=0;
            int t=1;
            while(a[i-t][j-t]=='*'&&a[i-t][j+t]=='*')++t;
            --t;
            for(int k=0;k<=t;++k)
            {
                b[i-k][j-k]=max(b[i-k][j-k],t);
                b[i-k][j+k]=max(b[i-k][j+k],t);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]=='*'&&b[i][j]<y)
            {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}