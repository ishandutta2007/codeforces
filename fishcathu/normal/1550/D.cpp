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
const int N=2E5+1;
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
const int p=1E9+7;
int fac[N],inv[N];
int main()
{
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<N;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<N;++i)
    {
        fac[i]=fac[i-1]*1LL*i%p;
        inv[i]=inv[i-1]*1LL*inv[i]%p;
    }
    for(int x=read();x--;)
    {
        int n=read(),l=read(),r=read(),a=min(1-l,r-n),b=a+n-1;
        static function<int(int,int)>solve=[&](int u,int v)
        {
            int res=0;
            for(int i=b,las=0;i>=a;--i)
            {
                int y=u-max(l+i-1,0),z=v-max(n-r+i,0),now=0;
                if(y>=0&&z>=0)now=(fac[y+z]*1LL*inv[y]%p*inv[z]%p);
                res=(res+(now-las+p)*1LL*i)%p;
                las=now;
            }
            return res;
        };
        int m=n>>1;
        if(n&1)write((solve(m,n-m)+solve(n-m,m))%p,'\n');
        else write(solve(m,m),'\n');
    }
}