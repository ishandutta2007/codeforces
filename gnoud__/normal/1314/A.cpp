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
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
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
const int N=2e5+10;
int n;
pii a[N];
priority_queue<int> heap;
int sum=0,ans=0;
void solve()
{
    int top=1,T=0;
    while(top<=n || heap.size())
    {
        while(top<=n&&a[top].fi==T)
        {
            heap.push(a[top].se);
            sum+=a[top].se;
            ++top;
        }
        if(heap.size())
        {
            sum-=heap.top();heap.pop();
            ans+=sum;
        }
        if(heap.empty()) T=a[top].fi;
        else ++T;
    }
}
main()
{
    n=in;
    forinc(i,1,n) a[i].fi=in;
    forinc(i,1,n) a[i].se=in;
    sort(a+1,a+n+1);
    solve();
    cout<<ans<<"\n";
}