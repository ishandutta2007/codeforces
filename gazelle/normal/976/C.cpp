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
	ll n;
	cin>>n;
	vector<pair<P,ll>> seg(n);
	REP(i,n) cin>>seg[i].first.first>>seg[i].first.second;
	REP(i,n) seg[i].first.second=-seg[i].first.second;
	REP(i,n) seg[i].second=i;
	sort(ALL(seg));
	REP(i,n) seg[i].first.second=-seg[i].first.second;
	set<P> r;
	P ans=P(-2,-2);
	REP(i,n) {
		auto ite=r.lower_bound(P(seg[i].first.second,-1));
		if(ite!=r.end()) {
			ans=P(seg[i].second,(*ite).second);
			break;
		}
		r.insert(P(seg[i].first.second,seg[i].second));
	}
	cout<<ans.first+1<<" "<<ans.second+1<<endl;
}