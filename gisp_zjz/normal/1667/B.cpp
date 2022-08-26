#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int inf=1e9;
int n,dp[maxn];
ll a[maxn],s[maxn];
struct bits{
    int b[maxn];
    void init(){
        for (int i=1;i<=n+1;i++) b[i]=-inf;
    }
    int upd(int x,int y){
        while (x<=n+1) b[x]=max(b[x],y),x+=x&(-x);
    }
    int qry(int x){
        int ret=-inf;
        while (x) ret=max(ret,b[x]),x-=x&(-x);
        return ret;
    }
}A,B;
int main(){
    int _; scanf("%d",&_);
    while (_--){
        scanf("%d",&n); A.init(); B.init();
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        vector<ll> S; S.clear();
        for (int i=0;i<=n;i++) S.pb(s[i]);
        sort(S.begin(),S.end());
        S.erase(unique(S.begin(),S.end()),S.end());
        for (int i=0;i<=n;i++){
            auto x=lower_bound(S.begin(),S.end(),s[i])-S.begin()+1;
            if (i>0){
                dp[i]=dp[i-1]-1;
                dp[i]=max(dp[i],A.qry(x-1)+i);
                dp[i]=max(dp[i],B.qry(x));
            }
            A.upd(x,dp[i]-i);
            B.upd(x,dp[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}