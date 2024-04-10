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
const int N=2E5+10,M=17;
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
char a[N<<1];
int n,m,s;
int nex[N][M],f[1<<M];
bool check(int x)
{
    for(int j=0;j<m;++j)
    {
        for(int i=n,k=0;i>=1;--i)
        {
            int t=i+x;
            k+=(a[i]==j||a[i]==m)-(a[t]==j||a[t]==m);
            nex[i][j]=k^x?nex[i+1][j]:t;
        }
    }
    for(int i=1;i<=s;++i)
    {
        f[i]=inf;
        for(int j=0,k=1;j<m;++j,k<<=1)
        {
            if(i&k)
            {
                f[i]=min(f[i],nex[f[i^k]][j]);
            }
        }
    }
    return f[s]<=n;
}
int main()
{
    n=read()+1,m=read(),s=(1<<m)-1;
    memset(a,-1,sizeof a);
    for(int i=0;i<m;++i)nex[n+1][i]=n+1;
    f[0]=1;
    for(int i=1;i<n;++i)
    {
        do a[i]=getchar();while(a[i]<63);
        a[i]=a[i]^63?a[i]-97:m;
    }
    int l=0;
    for(int r=n/m;l^r;)
    {
        int mid=l+r+2>>1;
        check(mid)?l=mid:r=mid-1;
    }
    write(l,'\n');
}