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
int a[N],b[N];
int main()
{
    int n=read(),m=read()+n;
    for(int i=1;i<=n;++i)b[a[i]=read()+1]=i;
    for(int i=1;i<n;++i)
    {
        if(b[a[i]+1]>b[a[i+1]+1])
        {
            --m;
        }
    }
    const int p=998244353;
    int ans0=1,ans1=1;
    for(int i=1;i<=n;++i)
    {
        ans0=ans0*1LL*(m-i)%p;
        ans1=ans1*1LL*i%p;
    }
    for(int i=p-2;i;i>>=1)
    {
        if(i&1)ans0=ans0*1LL*ans1%p;
        ans1=ans1*1LL*ans1%p;
    }
    write(ans0,'\n');
}