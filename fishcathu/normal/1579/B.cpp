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
const int N=60;
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
int a[N],b[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    vector<tuple<int,int,int>>ans;
    for(int i=1;i<n;++i)
    {
        int p=i;
        for(int j=i+1;j<=n;++j)if(a[j]<a[p])p=j;
        if(p==i)continue;
        ans.pb({i,p,p-i});
        for(int j=i;j<=p;++j)
        {
            int t=j+p-i;
            if(t>p)t-=p+1-i;
            b[j]=a[t];
        }
        for(int j=i;j<=p;++j)a[j]=b[j];
    }
    write(ans.size(),'\n');
    for(auto [l,r,x]:ans)printf("%d %d %d\n",l,r,x);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}