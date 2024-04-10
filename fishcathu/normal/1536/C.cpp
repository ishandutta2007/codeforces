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
const int N=5E5+10;
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
char c[N];
pii a[N],b[N];
int ans[N];
void solve()
{
    int n=read();
    scanf("%s",c+1);
    for(int i=1,j=0;i<=n;++i)
    {
        j+=c[i]&1;
        int t=__gcd(i,j);
        a[i]=b[i]=mp(i/t,j/t);
    }
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    memset(ans+1,0,m<<2);
    for(int i=1;i<=n;++i)write(++ans[lower_bound(b+1,b+1+m,a[i])-b],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}