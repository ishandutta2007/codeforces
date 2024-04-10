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
const int N=101,M=1E5+1;
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
int a[N],b[N],sum[N];
int f[N][N*N],ANS[M<<1];
int main()
{
    const int p=1E9+7;
    int n=read();
    int all=1;
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        all=all*(a[i]+1LL)%p;
        sum[i]=sum[i-1]+a[i];
    }
    sum[n+1]=sum[n];
    for(int i=2;i<=n;++i)b[i]=b[i-1]+read();
    for(int i=2;i<=n;++i)b[i]+=b[i-1];
    int *ans=ANS+M;
    for(int i=-M;i<M;++i)
    {
        if(n*i+b[n]>n*100)continue;
        if(n*i+b[n]<=0)ans[i]=all;
        else
        {
            memset(f,0,sizeof f);
            for(int k=0;k<=sum[1];++k)f[0][k]=1;
            for(int j=1;j<=n;++j)
            {
                int y=max(j*i+b[j],0);
                for(int k=y;k<=sum[j];++k)
                {
                    f[j][k]=f[j-1][k];
                    if(k>a[j])f[j][k]=(f[j][k]-f[j-1][k-a[j]-1]+p)%p;
                }
                for(int k=y+1;k<=sum[j+1];++k)f[j][k]=(f[j][k]+f[j][k-1])%p;
            }
            ans[i]=f[n][sum[n]];
        }
    }
    for(int m=read();m--;)write(ans[read()],'\n');
}