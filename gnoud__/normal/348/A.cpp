#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
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
const int N=100010;
int n,a[N];
bool kt(int x)
{
    int s=0;
    forinc(i,1,n)
    {
        if(x<a[i]) return 0;
        s+=(x-a[i]);
    }
    forinc(i,1,n) if(s-(x-a[i])<a[i]) return 0;
    return 1;
}
main()
{
    //freopen("348A.inp","r",stdin);
    n=in;
    forinc(i,1,n) a[i]=in;
    int l=1,r=1e13,ans;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(kt(m)) ans=m,r=m-1;
        else l=m+1;
    }
    cout<<ans<<"\n";
}