#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int M=20,N=1<<M;
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
char c[400010];
vector<int>a[M];
int b[M],f[N],g[N],h[N];
int main()
{
    int m=read(),n=(1<<m)-1;
    for(int i=0;i<m;++i)
    {
        a[i].pb(0);
        scanf("%s",c);
        for(int j=0;c[j];++j)
        {
            c[j]^'('?++b[i]:--b[i];
            if(b[i]==a[i].size())a[i].pb(1);
            else if(b[i]==a[i].size()-1)++a[i][b[i]];
        }
    }
    for(int k=1;k<=n;++k)
    {
        g[k]=-inf;
        for(int i=0;i<m;++i)
        {
            int j=k^1<<i;
            if(j>k)continue;
            h[k]-=b[i];
            f[k]=max(f[k],f[j]);
            if(h[j]<0)continue;
            if(a[i].size()>h[j]+1)f[k]=max(f[k],g[j]+a[i][h[j]]);
            else
            {
                int t=a[i].size()>h[j]?a[i][h[j]]:0;
                g[k]=max(g[k],g[j]+t);
            }
        }
    }
    write(max(f[n],g[n]),'\n');
}