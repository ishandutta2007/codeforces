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
const int N=2E5+10,M=3E5+10;
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
int a[N],b[N],qa[M],qb[M];
pii qc[M];
void solve()
{
    int n=read(),m=read(),s=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i]=read();
    int sa=0,sb=0,sc=0;
    while(s--)
    {
        int x=read(),y=read();
        int t=lower_bound(a+1,a+1+n,x)-a;
        if(a[t]==x)x=t<<1;
        else qa[++sa]=x=t<<1|1;
        t=lower_bound(b+1,b+1+m,y)-b;
        if(b[t]==y)y=t<<1;
        else qb[++sb]=y=t<<1|1;
        if(x+y&1)qc[++sc]={x,y};
    }
    sort(qa+1,qa+1+sa);
    sort(qb+1,qb+1+sb);
    sort(qc+1,qc+1+sc);
    ll res=0;
    for(int i=2,j=0;i<=sa;++i)qa[i]!=qa[i-1]?j=0:res+=++j;
    for(int i=2,j=0;i<=sb;++i)qb[i]!=qb[i-1]?j=0:res+=++j;
    for(int i=2,j=0;i<=sc;++i)qc[i]!=qc[i-1]?j=0:res-=++j;
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}