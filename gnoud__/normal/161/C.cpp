#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
int sol(int l,int r,int u,int v,int k)
{
    if(l>r||u>v||!k) return 0;
    int L=1<<k,mid=1<<(k-1);
    if(l>L) l-=L,r-=L;
    if(u>L) u-=L,v-=L;
    int ret=max(0,min(r,v)-max(l,u)+1);
    if((l>=u&&r<=v)||(l<=u&&r>=v)) return ret;
    vector<pii> A,B;
    if(l<=mid&&mid<=r) A.pb({l,mid-1}),A.pb({mid+1,r});
    else A.pb({l,r});
    if(u<=mid&&mid<=v) B.pb({u,mid-1}),B.pb({mid+1,v});
    else B.pb({u,v});
    forv(x,A) forv(y,B) ret=max(ret,sol(x.fi,x.se,y.fi,y.se,k-1));
    return ret;
}
int main()
{
    //freopen("161C.inp","r",stdin);
    int l1=in,r1=in,l2=in,r2=in;
    cout<<sol(l1,r1,l2,r2,30)<<"\n";
}