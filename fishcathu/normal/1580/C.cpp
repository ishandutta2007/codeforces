#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10,M=450;
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
int a[N],b[N],c[N],q[N],f[M][M];
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read(),b[i]=a[i]+read();
    for(int i=1;i<=m;++i)
    {
        int k=read(),x=read();
        if(k==1)
        {
            c[x]=i;
            if(b[x]<M)for(int j=a[x];j<b[x];++j)++f[b[x]][(i+j)%b[x]];
            else for(int l=i+a[x],r=i+b[x];l<=m;l+=b[x],r+=b[x])++q[l],--q[min(r,m+1)];
        }
        else
        {
            if(b[x]<M)for(int j=a[x];j<b[x];++j)--f[b[x]][(c[x]+j)%b[x]];
            else for(int l=c[x]+a[x],r=c[x]+b[x];l<=m;l+=b[x],r+=b[x])--q[max(l,i)],++q[max(min(r,m+1),i)];
        }
        int res=q[i]+=q[i-1];
        for(int j=2;j<M;++j)res+=f[j][i%j];
        write(res,'\n');
    }
}