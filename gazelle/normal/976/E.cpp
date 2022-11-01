#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,a,b;
	cin>>n>>a>>b;
	b=min(b,n);
	vector<ll> hp(n);
	vector<ll> dmg(n);
	REP(i,n) cin>>hp[i]>>dmg[i];
	ll sum=0;
	REP(i,n) sum+=dmg[i];
	vector<ll> diff(n);
	REP(i,n) diff[i]=hp[i]-dmg[i];
	sort(ALL(diff));
	reverse(ALL(diff));
	ll lim=diff[b-1];
	ll diff_sum=0;
	REP(i,b) diff_sum+=max(diff[i],0ll);
	ll ans=sum+diff_sum;
	REP(i,n) {
		if(lim>0) {
			if(hp[i]-dmg[i]>=lim) {
				ans=max(ans,sum+diff_sum-(hp[i]-dmg[i])+(hp[i]*(1ll<<a)-dmg[i]));
			} else {
				ans=max(ans,sum+diff_sum-lim+(hp[i]*(1ll<<a)-dmg[i]));
			}
		} else {
			if(hp[i]-dmg[i]>0) {
				ans=max(ans,sum+diff_sum-(hp[i]-dmg[i])+(hp[i]*(1ll<<a)-dmg[i]));
			} else {
				ans=max(ans,sum+diff_sum+(hp[i]*(1ll<<a)-dmg[i]));
			}
		}
	}
	cout<<ans<<endl;
}