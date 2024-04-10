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
const int N=1E6+10,M=20;
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

int a[N],b[M],c[M],q[1<<21];
int main()
{
    memset(q,-1,sizeof q);
    int n=read(),ans=0;
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=0;i<=n;++i)
    {
        for(int p=1,j=M;j--;)
        {
            if(a[i]&1<<j)b[j]^=1;
            else c[j]=i;
            p=p<<1|b[j];
            if(q[p]>=c[j])ans=max(ans,i-q[p]);
            else q[p]=i;
        }
    }
    write(ans,'\n');
}