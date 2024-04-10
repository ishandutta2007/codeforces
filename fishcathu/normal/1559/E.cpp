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
const int N=55,M=1E5+10;
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
int l[N],r[N],mu[M],f[N][M];
int g(int i,int j){return j<0?0:f[i][j];}
vector<int>pri;
int main()
{
    const int p=998244353;
    int n=read(),m=read();
    for(int i=1;i<=n;++i)l[i]=read(),r[i]=read();
    for(int i=1;i<=m;++i)mu[i]=i;
    for(int i=2;i<=m;++i)
    {
        if(mu[i]>1)mu[i]=-1,pri.pb(i);
        for(int t:pri)
        {
            int j=i*t;
            if(j>m)break;
            if(i%t==0){mu[j]=0;break;}
            mu[j]=-mu[i];
        }
    }
    int ans=0;
    for(int j=0;j<=m;++j)f[0][j]=1;
    for(int k=1;k<=m;++k)
    {
        if(!mu[k])continue;
        int s=m/k;
        for(int i=1;i<=n;++i)
        {
            int u=(l[i]-1)/k+1,v=r[i]/k+1;
            for(int j=0;j<=s;++j)f[i][j]=((g(i-1,j-u)-g(i-1,j-v)+g(i,j-1))%p+p)%p;
        }
        ans=((ans+f[n][s]*mu[k])%p+p)%p;
    }
    write(ans,'\n');
}