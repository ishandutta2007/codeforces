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
const int N=3E6+10;
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
int inv[N],ans[N][3];
int main()
{
    const int p=1E9+7;
    int n=(ans[0][0]=ans[0][1]=ans[0][2]=read())*3+1;
    inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=1,s=n;i<n;++i)
    {
        s=s*1LL*(n-i)%p*inv[i+1]%p;
        ans[i][0]=((s-ans[i-1][0]*2LL-ans[i-1][1])*inv[3]%p+p)%p;
        ans[i][1]=(ans[i][0]+ans[i-1][0])%p;
        ans[i][2]=(ans[i][1]+ans[i-1][1])%p;
    }
    for(int i=read();i--;)write(ans[read()][2],'\n');
}