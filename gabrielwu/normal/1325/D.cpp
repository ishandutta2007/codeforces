#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	ll u, v;
	cin >> u >> v;
	if(v < u){
		cout << -1 << "\n";
		return 0;
	}
	if(v==0 && u==0){
		cout << 0 << "\n";
		return 0;
	}
	if(v == u){
		cout << 1 << "\n";
		cout << u << "\n";
		return 0;
	}
	if((v-u)%2){
		cout << -1 << "\n";
		return 0;
	}

	int LG = 60;
	vector<int> cnt(LG);
	forn(i, LG){
		if(u & (1LL << i)) cnt[i]++;
	}
	forn(i, LG-1){
		if((v-u) & (1LL << (i+1))) cnt[i]+=2;
	}
	vector<ll> ans;
	forn(t, 3){
		ll curr = 0;
		forn(i, LG){
			if(cnt[i]){
				cnt[i]--;
				curr += (1LL << i);
			}
		}
		if(curr){
			ans.pb(curr);
		}
	}

	cout << ans.size() << "\n";
	for(ll x: ans){
		cout << x << " ";
	}
	cout << "\n";
}