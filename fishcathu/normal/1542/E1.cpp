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
const int N=124760;
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
int a[N],b[N],c[N];
int f(int *a,int x)
{
    return x<0?0:a[x];
}
int main()
{
    int n=read(),p=read(),ans=0;
    a[0]=b[0]=c[0]=1;
    for(int i=2,s=1;i<=n;s+=i++)
    {
        ans=ans*1LL*i%p;
        for(int j=1,y=0;j<=s;++j)
        {
            b[j]=(b[j-1]+a[j])%p;
            c[j]=(c[j-1]+b[j])%p;
            y=(y+f(b,j-2)*1LL*i-f(c,j-2)+f(c,j-i-2))%p;
            ans=(ans+a[j]*1LL*y)%p;
            a[j]=(b[j]-f(b,j-i))%p;
        }
    }
    write((ans+p)%p,'\n');
}