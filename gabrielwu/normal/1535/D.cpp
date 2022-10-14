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

	int k;
	cin >> k;
	int g = (1<<k)-1;
	vector<char> c(g);
	vector<int> v(2*g+5, 1);
	forn(i, g){
		cin >> c[g-1-i];
	}
	for(int i=g-1; i>=0; i--){
		if(c[i] == '?') v[i] = v[2*i+1] + v[2*i+2];
		if(c[i] == '1') v[i] = v[2*i+1];
		if(c[i] == '0') v[i] = v[2*i+2];
	}
	// cout << v << "\n";
	int q;
	cin >> q;
	forn(qi, q){
		int i;
		cin >> i;
		i = g-i;
		cin >> c[i];
		if(c[i] == '?') v[i] = v[2*i+1] + v[2*i+2];
		if(c[i] == '1') v[i] = v[2*i+1];
		if(c[i] == '0') v[i] = v[2*i+2];
		while(i > 0){
			i = (i-1)/2;
			if(c[i] == '?') v[i] = v[2*i+1] + v[2*i+2];
			if(c[i] == '1') v[i] = v[2*i+1];
			if(c[i] == '0') v[i] = v[2*i+2];
		}
		// cout << v << "\n";
		cout << v[0] << "\n";
	}
}