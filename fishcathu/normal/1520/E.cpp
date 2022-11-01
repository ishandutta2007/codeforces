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
typedef pair<ll,ll> pll;
const int N=1E6+10;
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
char a[N];
int b[N];
void solve()
{
    int n=read();
    scanf("%s",a);
    int s=0;
    for(int i=0,j=0;a[i];++i)
    {
        if(a[i]=='*')b[++s]=i-j++;
    }
    ll ans=0;
    for(int i=2;i<=s;++i)ans+=b[i]-b[1];
    for(ll i=2,j=ans;i<=s;++i)
    {
        j+=(2*i-2-s)*1LL*(b[i]-b[i-1]);
        ans=min(ans,j);
    }
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}