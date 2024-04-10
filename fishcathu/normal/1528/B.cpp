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
const int N=1E6+10;
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
    int n=read();
    for(int i=n>>1;i>=1;--i)
    {
        for(int j=i;(j+=i)<=n;)
        {
            ++a[j];
        }
    }
    const int p=998244353;
    f[0]=1;
    for(int i=1;i<=n;++i)f[i]=(f[i-1]*2%p+a[i])%p;
    write((f[n]-f[n-1]+p)%p,'\n');
}