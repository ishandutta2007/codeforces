#include<bits/stdc++.h>
#define rep(i,a,n) for(auto i=(a);i<=(n);i++)
#define per(i,a,n) for(auto i=(n);i>=(a);i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int maxn = 300000;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

//header
int a[maxn+5];
int cnt[maxn+5];
bool mark[maxn+5];

bool test(int n,int m,int off)
{
    auto cal=[&](int x) {int y=x+off; return y<=n?y:y-n;};
    int ans=0;
    rep(i,1,n) mark[i]=0;
    rep(i,1,n) if(mark[a[i]]==0)
    {
        int now=a[i],c=0;
        while(mark[now]==0)
        {
            mark[now]=1;
            now=a[cal(now)];
            c++;
        }
        ans+=c-1;
    }
    return ans<=m;
}

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int n,m; scanf("%d%d",&n,&m);
        rep(i,1,n) scanf("%d",&a[i]);
        int fixed=n-m*2;
        rep(i,0,n-1) cnt[i]=0;
        rep(i,1,n) cnt[(i-a[i]+n)%n]++;
        vi ans;
        rep(i,0,n-1) if(cnt[i]>=fixed && test(n,m,i)) ans.pb(i);
        int N=ans.size();
        printf("%d",N);
        for(auto x: ans) printf(" %d",x);
        puts("");
    }
    return 0;
}