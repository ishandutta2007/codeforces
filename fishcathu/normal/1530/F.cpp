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
const int N=2E5+10;
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
int a[21][1<<21];
int main()
{
    const int p=31607;
    int n=read(),s=(1<<n)-1;
    for(int i=0;i<n;++i)
    {
        a[i][0]=1;
        for(int j=0,k=3973;j<n;++j)a[i][1<<j]=read()*k%p;
        for(int j=0;j<=s;++j)
        {
            int k=j&-j;
            a[i][j]=a[i][j^k]*a[i][k]%p;
        }
        for(int j=0;j<=s;++j)a[i][j]=(a[i][j]-a[i][s]+p)%p;
    }
    int ans=1;
    for(int j=0;j<=s;++j)
    {
        for(int k=0;k<4;++k)
        {
            int res=__builtin_popcount(k^j)&1?p-1:1;
            for(int i=0;i<n;++i)
            {
                int t=j;
                if(k&1)t|=1<<i;
                if(k&2)t|=1<<n-1-i;
                res=res*a[i][t]%p;
            }
            ans=(ans-res+p)%p;
        }
    }
    write(ans,'\n');
}