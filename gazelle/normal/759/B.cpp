#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> t(n);
	REP(i,n) cin>>t[i];
	vector<ll> dp(n);
	REP(i,n) {
		if(i==0) dp[i]=20;
		else dp[i]=dp[i-1]+20;
		auto ite=lower_bound(ALL(t),t[i]-89);
		ll pos=(ite-t.begin());
		if(pos==0) dp[i]=min(dp[i],50ll);
		else dp[i]=min(dp[i],50ll+dp[pos-1]);
		ite=lower_bound(ALL(t),t[i]-1439);
		pos=(ite-t.begin());
		if(pos==0) dp[i]=min(dp[i],120ll);
		else dp[i]=min(dp[i],120ll+dp[pos-1]);
	}
	ll sum=0;
	REP(i,n) {
		cout<<dp[i]-sum<<endl;
		sum+=dp[i]-sum;
	}
}