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
const int N=510;
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
int a[N],f[N];
int main()
{
    const int p=998244353;
    int n=read();
    for(int i=1;i<=n;++i)
    {
        char c;
        do c=getchar();while(c<43);
        if(c==43)a[i]=read();
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(!a[i])continue;
        memset(f,0,sizeof f);
        f[0]=1;
        for(int j=1;j<=n;++j)
        {
            if(j==i)continue;
            if(!a[j])
            {
                if(j<i)f[0]=f[0]*2%p;
                for(int k=0;k<j;++k)
                {
                    f[k]=(f[k]+f[k+1])%p;
                }
            }
            else if(a[j]<a[i]||a[j]==a[i]&&j<i)
            {
                for(int k=j;k>=1;--k)
                {
                    f[k]=(f[k]+f[k-1])%p;
                }
            }
            else
            {
                for(int k=0;k<j;++k)
                {
                    f[k]=f[k]*2%p;
                }
            }
        }
        int res=0;
        for(int k=0;k<n;++k)res=(res+f[k])%p;
        ans=(ans+res*1LL*a[i])%p;
    }
    write(ans,'\n');
}