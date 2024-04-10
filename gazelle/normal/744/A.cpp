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

class union_find {
public:
	union_find(int n)
	: par_(n, -1)
	{}
	void init(int n) {
		par_.assign(n, -1);
	}

	int root(int x) {
		return par_[x] < 0 ? x : par_[x] = root(par_[x]);
	}

	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if(x == y) {
			return false;
		} else {
			if(par_[x] < par_[y]) {
				par_[x] += par_[y];
				par_[y] = x;
			} else {
				par_[y] += par_[x];
				par_[x] = y;
			}
			return true;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

	int size(int x) {
		return -par_[root(x)];
	}

private:
	std::vector<int> par_;
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,m,k;
	cin>>n>>m>>k;
	union_find uf(n);
	vector<ll> c(k);
	REP(i,k) cin>>c[i];
	REP(i,k) c[i]--;
	REP(i,m) {
		ll u,v;
		cin>>u>>v;
		u--;
		v--;
		uf.unite(u,v);
	}
	ll sum=0;
	vector<ll> buf(k);
	REP(i,k) {
		sum+=uf.size(c[i]);
		buf[i]=uf.size(c[i]);
	}
	sort(ALL(buf));
	buf[k-1]+=n-sum;
	ll ans=0;
	REP(i,k) {
		ans+=buf[i]*(buf[i]-1)/2;
	}
	ans-=m;
	cout<<ans<<endl;
}