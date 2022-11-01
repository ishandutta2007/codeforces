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
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll N = 100010;
ll bit[100010];
void add(ll a, ll w) {
	a++;
	for (ll x = a; x <= N; x += x & -x) bit[x] += w;
}
ll sum(ll a) {
	a++;
	ll ret = 0;
	for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
 	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> v(n);
	vector<ll> t(n);
	REP(i,n) cin>>v[i];
	REP(i,n) cin>>t[i];
	vector<ll> acm(n);
	vector<ll> ans(n,0);
	acm[0]=t[0];
	FOR(i,1,n) acm[i]=acm[i-1]+t[i];
	REP(i,n) {
		ll up=0; if(i>0) up=acm[i-1];
		auto ite=upper_bound(ALL(acm),up+v[i]);
		add(i,1); add((ite-acm.begin()),-1);
		if(ite==acm.end()) continue;
		if((ite-acm.begin())!=i) ans[ite-acm.begin()]+=(up+v[i])-acm[(ite-acm.begin())-1];
		else ans[ite-acm.begin()]+=v[i];
	}
	REP(i,n) ans[i]+=t[i]*sum(i);
	DUMP(ans);
}