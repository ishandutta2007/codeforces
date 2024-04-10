#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<ll>vi;
const int maxn=1e6+100;
const int M=998244353;
int n;
ll a[maxn],sum[maxn],ans;
vi tmp;
ll solve(vi &b,ll tot){
    if (b.size()<2) return 0;
    int m=b.size();
    vi u,v; u.clear(); v.clear();
    ll sum=0;
    for (int i=0;i<m;i+=2) sum+=b[i];
    //u.pb(sum);
    for (int i=0;i<m;i+=2){
		sum-=b[i]*2;
		if (i!=m-1) u.pb(sum);
    }
    sum=0;
    for (int i=1;i<m;i+=2) sum+=b[i];
    v.pb(sum);
    for (int i=1;i<m;i+=2){
        sum-=b[i]*2;
		if (i!=m-1) v.pb(sum);
    }
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    ll res=0;
    int vs=v.size();
    int pos=vs-1;
    for (int i=0;i<u.size();i++){
		while (pos>=0&&u[i]+v[pos]>tot) pos--;
        res+=vs-1-pos;
    }
    return res;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	ans=0;
	tmp.clear(); for (int i=1;i<=n;i++) tmp.pb(a[i]); ans+=solve(tmp,0);
	//cout<<ans<<endl;return;
	tmp.clear(); for (int i=1;i<=n-1;i++) tmp.pb(a[i]); ans+=solve(tmp,a[n]);
	tmp.clear(); for (int i=2;i<=n;i++) tmp.pb(a[i]); ans+=solve(tmp,-a[1]);
	tmp.clear(); for (int i=2;i<=n-1;i++) tmp.pb(a[i]); ans+=solve(tmp,a[n]-a[1]);
	for (int i=1;i<=n;i++) if (sum[i]>sum[n]-sum[i]) ans++;
	printf("%lld\n",ans%M);
}
int main(){
    int _;scanf("%d",&_);
    while (_--) solve();
    return 0;
}