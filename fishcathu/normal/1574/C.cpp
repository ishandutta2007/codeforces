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
const int N=2E5+10;
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
ll a[N];
int main()
{
    int n=read();
    ll s=0;
    for(int i=1;i<=n;++i)s+=a[i]=read();
    sort(a+1,a+1+n);
    for(int m=read();m--;)
    {
        ll l=read(),r=read();
        int i=lower_bound(a+1,a+1+n,l)-a,j=i-1;
        ll res=LLONG_MAX;
        if(i>=1&&i<=n)res=min(res,max(r-s+a[i],0));
        if(j>=1&&j<=n)res=min(res,l-a[j]+max(r-s+a[j],0));
        write(res,'\n');
    }
}