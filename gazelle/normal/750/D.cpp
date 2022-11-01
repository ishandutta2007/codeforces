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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> t(n);
	REP(i,n) cin>>t[i];
	set<P> used;
	typedef pair<P,ll> pll;
	set<pll> crt;
	crt.insert(pll(P(0,0),0));
	REP(i,n) {
		set<pll> next;
		for(auto tmp: crt) {
			P p=tmp.first;
			ll dx[]={0,1,1,1,0,-1,-1,-1};
			ll dy[]={1,1,0,-1,-1,-1,0,1};
			REP(j,t[i]) {
				p.first+=dx[tmp.second];
				p.second+=dy[tmp.second];
				used.insert(p);
			}
			next.insert(pll(p,((tmp.second-1)%8+8)%8));
			next.insert(pll(p,((tmp.second+1)%8+8)%8));
		}
		crt=next;
	}
	cout<<(ll)used.size()<<endl;
}